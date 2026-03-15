#include "cCodeGen.h"

#include <string>

#include "astnodes.h"
#include "emit.h"

namespace
{
    // Emits a single instruction string followed by a newline to the output file.
    // s: instruction string to emit.
    void EmitInstr(const std::string &s)
    {
        EmitString(s);
        EmitString("\n");
    }

    // Emits a PUSH instruction for an integer value.
    // v: integer value to push onto the stack.
    void EmitPushInt(int v)
    {
        EmitString("PUSH");
        EmitInt(v);
        EmitString("\n");
    }

    // Rounds up a value to the nearest word boundary (4 bytes).
    // v: value in bytes.
    // Returns the rounded-up value.
    long long RoundUpToWord(long long v)
    {
        const long long kWord = 4;
        if (v <= 0) return 0;
        long long rem = v % kWord;
        if (rem == 0) return v;
        return v + (kWord - rem);
    }

    // Emits code to compute the address at FP + offset and leaves it on the stack.
    // offset: byte offset from frame pointer.
    void EmitAddrFromOffset(long long offset)
    {
        // Leaves address (FP + offset) on stack.
        EmitString("PUSH");
        EmitInt((int)offset);
        EmitString("\n");
        EmitInstr("PUSHFP");
        EmitInstr("PLUS");
    }
}

// Constructor: initializes code generation and opens the output file.
// outputFile: name of the file to write generated code to.
cCodeGen::cCodeGen(const std::string &outputFile)
{
    m_ok = InitOutput(outputFile);
}

// Destructor: finalizes output if initialization succeeded.
cCodeGen::~cCodeGen()
{
    if (m_ok) (void)FinalizeOutput();
}

// Visits the root program node and emits code for all functions and the main program.
// node: root AST node for the program.
void cCodeGen::Visit(cProgramNode *node)
{
    if (!m_ok || node == nullptr) return;

    // 1) Emit all function definitions first (so calls from main resolve).
    m_mode = Mode::EmitFunctions;
    node->VisitAllChildren(this);

    // 2) Emit the implicit main function.
    m_mode = Mode::EmitMain;

    EmitInstr(".function main");
    EmitInstr("main:");

    // Emit the program body (top-level block will allocate locals).
    node->VisitAllChildren(this);

    // Return 0.
    EmitPushInt(0);
    EmitInstr("RETURNV");
}

// Visits a block node, emitting code for local variable allocation and contained statements.
// node: AST node for a block.
void cCodeGen::Visit(cBlockNode *node)
{
    if (!m_ok || node == nullptr) return;

    // In function-emission mode, the top-level program block should only be
    // used to discover declarations (e.g., func defs). Don't emit runtime code.
    if (m_mode == Mode::EmitFunctions)
    {
        if (node->GetDecls() != nullptr) node->GetDecls()->Visit(this);
        return;
    }

    // Only allocate once for the top-most block in the current frame.
    if (m_blockDepth == 0)
    {
        long long localsSize = node->GetComputedAttributeInt("size", 0);
        localsSize = RoundUpToWord(localsSize);
        EmitString("ADJSP");
        EmitInt((int)localsSize);
        EmitString("\n");
    }

    m_blockDepth++;
    cVisitor::Visit(node);
    m_blockDepth--;
}

// Visits a list of statements, handling function-call statements specially to pop return values.
// node: AST node representing a list of statements.
void cCodeGen::Visit(cStmtsNode *node)
{
    if (!m_ok || node == nullptr) return;

    // We need special handling for function-call statements so they don't
    // leave their return value on the stack.
    // Expressions only appear as statements via the grammar's func_call ';'.
    for (int i = 0; i < node->NumStmts(); i++)
    {
        cStmtNode *stmt = node->GetStmt(i);
        if (stmt == nullptr) continue;

        stmt->Visit(this);

        if (dynamic_cast<cFuncCallNode*>(stmt) != nullptr)
        {
            EmitInstr("POP");
        }
    }
}

// Visits a print statement node and emits code to call the print function and clean up the stack.
// node: AST node for a print statement.
void cCodeGen::Visit(cPrintNode *node)
{
    if (!m_ok || node == nullptr) return;

    // print(expr);
    cVisitor::Visit(node);

    EmitInstr("CALL @print");
    // io320.sl's @print expects one 32-bit argument in the caller frame.
    // Clean up the argument (leave return value on top), then discard return.
    EmitString("POPARGS");
    EmitInt(4);
    EmitString("\n");
    EmitInstr("POP");
}

// Visits an integer expression node and emits code to push its value onto the stack.
// node: AST node for an integer constant.
void cCodeGen::Visit(cIntExprNode *node)
{
    if (!m_ok || node == nullptr) return;
    EmitPushInt(node->GetValue());
}

// Emits the appropriate instruction for a binary operator.
// op: operator code (e.g., '+', '-', EQUALS, etc.).
void cCodeGen::EmitOp(int op)
{
    switch (op)
    {
        case '+': EmitInstr("PLUS"); break;
        case '-': EmitInstr("MINUS"); break;
        case '*': EmitInstr("TIMES"); break;
        case '/': EmitInstr("DIVIDE"); break;
        case '%': EmitInstr("MOD"); break;
        case '>': EmitInstr("GT"); break;
        case '<': EmitInstr("LT"); break;
        case EQUALS: EmitInstr("EQ"); break;
        case NOT_EQUALS: EmitInstr("NE"); break;
        case GE: EmitInstr("GE"); break;
        case LE: EmitInstr("LE"); break;
        case AND: EmitInstr("AND"); break;
        case OR: EmitInstr("OR"); break;
        default:
            // Unknown op: emit nothing.
            break;
    }
}

// Visits a binary expression node and emits code for its operands and operator.
// node: AST node for a binary expression.
void cCodeGen::Visit(cBinaryExprNode *node)
{
    if (!m_ok || node == nullptr) return;

    cExprNode *left = node->GetLeft();
    cExprNode *right = node->GetRight();
    cOpNode *opNode = node->GetOpNode();

    if (left != nullptr) left->Visit(this);
    if (right != nullptr) right->Visit(this);

    int op = (opNode != nullptr) ? opNode->GetOp() : 0;
    EmitOp(op);
}

// Computes the size in bytes of a type declaration (base, array, or struct).
// decl: type declaration node.
// Returns the size in bytes.
long long cCodeGen::GetTypeSizeBytes(cDeclNode *decl)
{
    if (decl == nullptr) return 0;

    if (auto *bt = dynamic_cast<cBaseTypeNode*>(decl))
    {
        return bt->GetSize();
    }

    if (auto *arr = dynamic_cast<cArrayDeclNode*>(decl))
    {
        cSymbol *base = arr->GetBaseTypeSym();
        cDeclNode *baseDecl = (base != nullptr) ? base->GetDecl() : nullptr;
        long long elem = GetTypeSizeBytes(baseDecl);
        if (elem <= 0) return 0;
        return elem * arr->GetCount();
    }

    if (auto *st = dynamic_cast<cStructDeclNode*>(decl))
    {
        return st->GetComputedAttributeInt("size", 0);
    }

    // Fallback: treat as word.
    return 4;
}

// Emits code to compute the address of a variable reference (including arrays/structs).
// node: variable reference AST node.
// outElemSize: set to the size of the referenced element.
// Returns true on success, false on error.
bool cCodeGen::EmitVarRefAddress(cVarRefNode *node, long long &outElemSize)
{
    outElemSize = 0;
    if (node == nullptr) return false;

    auto FindStructField = [&](cStructDeclNode *structDecl, const std::string &fieldName) -> cVarDeclNode*
    {
        if (structDecl == nullptr) return nullptr;
        cDeclsNode *fields = structDecl->GetFields();
        if (fields == nullptr) return nullptr;

        struct Finder : public cVisitor
        {
            std::string want;
            cVarDeclNode *found = nullptr;
            explicit Finder(std::string n) : want(std::move(n)) {}
            void Visit(cVarDeclNode *n) override
            {
                if (n == nullptr) return;
                cSymbol *nm = n->GetNameSym();
                if (nm != nullptr && nm->GetName() == want) found = n;
            }
        };

        Finder f(fieldName);
        fields->VisitAllChildren(&f);
        return f.found;
    };

    cSymbol *baseSym = node->GetBaseSymbol();
    if (baseSym == nullptr) return false;

    auto *baseDecl = dynamic_cast<cVarDeclNode*>(baseSym->GetDecl());
    if (baseDecl == nullptr) return false;

    long long baseOffset = baseDecl->GetComputedAttributeInt("offset", 0);
    bool baseByRef = (baseDecl->GetComputedAttributeInt("byref", 0) != 0);
    cSymbol *typeSym = baseDecl->GetTypeSym();
    cDeclNode *typeDecl = (typeSym != nullptr) ? typeSym->GetDecl() : nullptr;
    if (typeDecl == nullptr) return false;

    // Start with address of the base variable.
    EmitAddrFromOffset(baseOffset);

    // If this variable is a by-reference parameter, the slot contains a pointer
    // to the actual object. Load that pointer so indexing uses the pointee base.
    if (baseByRef)
    {
        EmitInstr("PUSHVARIND");
    }

    // Walk fields and indices in-order.
    cDeclNode *curType = typeDecl;

    for (int i = 1; i < node->NumParts(); i++)
    {
        cAstNode *part = node->GetPart(i);
        if (part == nullptr) return false;

        if (auto *idx = dynamic_cast<cExprNode*>(part))
        {
            auto *arr = dynamic_cast<cArrayDeclNode*>(curType);
            if (arr == nullptr) return false;

            cSymbol *elemSym = arr->GetBaseTypeSym();
            cDeclNode *elemDecl = (elemSym != nullptr) ? elemSym->GetDecl() : nullptr;
            long long elemSize = GetTypeSizeBytes(elemDecl);
            if (elemSize <= 0) return false;

            // Stack before: [baseAddr]
            // Evaluate idx, scale, add -> [baseAddr + idx*elemSize]
            idx->Visit(this);            // [baseAddr, idx]
            EmitPushInt((int)elemSize);  // [baseAddr, idx, elemSize]
            EmitInstr("TIMES");         // [baseAddr, offsetBytes]
            EmitInstr("PLUS");          // [elemAddr]

            curType = elemDecl;
            continue;
        }

        if (auto *fieldSym = dynamic_cast<cSymbol*>(part))
        {
            auto *st = dynamic_cast<cStructDeclNode*>(curType);
            if (st == nullptr) return false;

            auto *fieldVar = dynamic_cast<cVarDeclNode*>(fieldSym->GetDecl());
            if (fieldVar == nullptr)
            {
                fieldVar = FindStructField(st, fieldSym->GetName());
                if (fieldVar == nullptr) return false;
            }

            long long fieldOffset = fieldVar->GetComputedAttributeInt("offset", 0);
            EmitPushInt((int)fieldOffset);
            EmitInstr("PLUS");

            cSymbol *fieldTypeSym = fieldVar->GetTypeSym();
            curType = (fieldTypeSym != nullptr) ? fieldTypeSym->GetDecl() : nullptr;
            if (curType == nullptr) return false;
            continue;
        }

        return false;
    }

    outElemSize = GetTypeSizeBytes(curType);

    return true;
}

// Visits a variable reference node and emits code to load its value from memory.
// node: AST node for a variable reference.
void cCodeGen::Visit(cVarRefNode *node)
{
    if (!m_ok || node == nullptr) return;

    long long elemSize = 0;
    if (!EmitVarRefAddress(node, elemSize)) return;

    // Load from the address.
    if (elemSize == 1)
        EmitInstr("PUSHCVARIND");
    else
        EmitInstr("PUSHVARIND");
}

// Visits an assignment statement node and emits code to store the right-hand value into the left-hand variable.
// node: AST node for an assignment statement.
void cCodeGen::Visit(cAssignNode *node)
{
    if (!m_ok || node == nullptr) return;

    cExprNode *lhs = node->GetLhs();
    cExprNode *rhs = node->GetRhs();
    if (lhs == nullptr || rhs == nullptr) return;

    // Compute RHS value first.
    rhs->Visit(this);

    // Support varrefs (simple vars and array elements).
    auto *lhsVar = dynamic_cast<cVarRefNode*>(lhs);
    if (lhsVar == nullptr) return;

    long long elemSize = 0;
    if (!EmitVarRefAddress(lhsVar, elemSize)) return;

    // Store: stack has [value]. Address is pushed after; POP*IND consumes both.
    if (elemSize == 1)
        EmitInstr("POPCVARIND");
    else
        EmitInstr("POPVARIND");
}

// Visits a function declaration node and emits code for the function body if it has a definition.
// node: AST node for a function declaration.
void cCodeGen::Visit(cFuncDeclNode *node)
{
    if (!m_ok || node == nullptr) return;

    if (m_mode != Mode::EmitFunctions) return;
    if (!node->HasDefinition()) return;

    cSymbol *name = node->GetSemanticSym();
    if (name == nullptr) return;

    EmitInstr(std::string(".function ") + name->GetName());
    EmitInstr(name->GetName() + ":");

    long long localsSize = node->GetComputedAttributeInt("size", 0);
    localsSize = RoundUpToWord(localsSize);
    EmitString("ADJSP");
    EmitInt((int)localsSize);
    EmitString("\n");

    // Visit statements; disable block allocations inside functions (func size
    // already accounts for nested blocks).
    int savedDepth = m_blockDepth;
    m_blockDepth = 1;
    if (node->GetStmtsNode() != nullptr) node->GetStmtsNode()->Visit(this);
    m_blockDepth = savedDepth;

    // Default return 0 if control falls off.
    EmitPushInt(0);
    EmitInstr("RETURNV");
}

// Visits a function call node and emits code to push arguments, call the function, and clean up the stack.
// node: AST node for a function call.
void cCodeGen::Visit(cFuncCallNode *node)
{
    if (!m_ok || node == nullptr) return;

    cSymbol *fn = node->GetFuncSymbol();
    if (fn == nullptr) return;

    cParamsNode *params = node->GetParamsNode();
    int argc = (params != nullptr) ? params->NumParams() : 0;

    if (params != nullptr)
    {
        // Push actual parameters in source order.
        // Extra credit (Lab7): arrays are passed by reference, so when an
        // argument expression has an array type we push its base address (not
        // the value of its first element).
        for (int i = 0; i < params->NumParams(); i++)
        {
            cExprNode *arg = params->GetParam(i);
            if (arg == nullptr) continue;

            cDeclNode *argType = arg->GetType();
            if (argType != nullptr && argType->IsArray())
            {
                if (auto *vr = dynamic_cast<cVarRefNode*>(arg))
                {
                    long long ignored = 0;
                    if (!EmitVarRefAddress(vr, ignored)) return;
                    continue;
                }
            }

            arg->Visit(this);
        }
    }

    EmitInstr(std::string("CALL @") + fn->GetName());

    // Stack preservation: remove arguments while keeping return value on top.
    // Prefer POPARGS with the byte size computed during cComputeSize (mirrors
    // the older Lab7/cParamSize.h logic and matches the STACKL guide).
    int argBytes = 0;
    if (fn->GetDecl() != nullptr)
    {
        auto *fnDecl = dynamic_cast<cFuncDeclNode*>(fn->GetDecl());
        if (fnDecl != nullptr && fnDecl->GetArgsNode() != nullptr)
        {
            argBytes = fnDecl->GetArgsNode()->GetComputedAttributeInt("size", 0);
        }
    }
    if (argBytes <= 0) argBytes = argc * 4;

    if (argBytes > 0)
    {
        EmitString("POPARGS");
        EmitInt(argBytes);
        EmitString("\n");
    }
}

// Visits a return statement node and emits code to return a value from a function.
// node: AST node for a return statement.
void cCodeGen::Visit(cReturnNode *node)
{
    if (!m_ok || node == nullptr) return;

    // Visit child expression (push return value), then return.
    cVisitor::Visit(node);
    EmitInstr("RETURNV");
}

// Visits an if statement node and emits code for condition, then, and else branches.
// node: AST node for an if statement.
void cCodeGen::Visit(cIfNode *node)
{
    if (!m_ok || node == nullptr) return;

    cExprNode *cond = node->GetCond();
    cStmtsNode *thenStmts = node->GetThen();
    cStmtsNode *elseStmts = node->GetElse();

    std::string elseLabel = GenerateLabel();
    std::string endLabel = GenerateLabel();

    if (cond != nullptr) cond->Visit(this);

    // If condition == 0, jump to else (or end).
    if (elseStmts != nullptr)
        EmitInstr("JUMPE @" + elseLabel);
    else
        EmitInstr("JUMPE @" + endLabel);

    if (thenStmts != nullptr) thenStmts->Visit(this);

    if (elseStmts != nullptr)
    {
        EmitInstr("JUMP @" + endLabel);
        EmitInstr(elseLabel + ":");
        elseStmts->Visit(this);
    }

    EmitInstr(endLabel + ":");
}

// Visits a while statement node and emits code for the loop condition and body.
// node: AST node for a while statement.
void cCodeGen::Visit(cWhileNode *node)
{
    if (!m_ok || node == nullptr) return;

    cExprNode *cond = node->GetCond();
    cStmtNode *body = node->GetBody();

    std::string startLabel = GenerateLabel();
    std::string endLabel = GenerateLabel();

    EmitInstr(startLabel + ":");

    if (cond != nullptr) cond->Visit(this);
    EmitInstr("JUMPE @" + endLabel);

    if (body != nullptr) body->Visit(this);
    EmitInstr("JUMP @" + startLabel);

    EmitInstr(endLabel + ":");
}
