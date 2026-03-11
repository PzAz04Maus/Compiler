#include "cCodeGen.h"

#include <string>

#include "astnodes.h"
#include "emit.h"

namespace
{
    void EmitInstr(const std::string &s)
    {
        EmitString(s);
        EmitString("\n");
    }

    void EmitPushInt(int v)
    {
        EmitString("PUSH");
        EmitInt(v);
        EmitString("\n");
    }

    long long RoundUpToWord(long long v)
    {
        const long long kWord = 4;
        if (v <= 0) return 0;
        long long rem = v % kWord;
        if (rem == 0) return v;
        return v + (kWord - rem);
    }

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

cCodeGen::cCodeGen(const std::string &outputFile)
{
    m_ok = InitOutput(outputFile);
}

cCodeGen::~cCodeGen()
{
    if (m_ok) (void)FinalizeOutput();
}

void cCodeGen::Visit(cProgramNode *node)
{
    if (!m_ok || node == nullptr) return;

    EmitInstr(".function main");
    EmitInstr("main:");

    // Emit the program body (top-level block will allocate locals).
    node->VisitAllChildren(this);

    // Return 0.
    EmitPushInt(0);
    EmitInstr("RETURNV");
}

void cCodeGen::Visit(cBlockNode *node)
{
    if (!m_ok || node == nullptr) return;

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

void cCodeGen::Visit(cPrintNode *node)
{
    if (!m_ok || node == nullptr) return;

    // print(expr);
    cVisitor::Visit(node);

    EmitInstr("CALL @print");
    EmitInstr("POP");
}

void cCodeGen::Visit(cIntExprNode *node)
{
    if (!m_ok || node == nullptr) return;
    EmitPushInt(node->GetValue());
}

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

void cCodeGen::Visit(cVarRefNode *node)
{
    if (!m_ok || node == nullptr) return;

    // For now, support simple locals: a
    // (struct fields and array indexing will be added later).
    if (node->NumParts() != 1 || node->NumSubscripts() != 0) return;

    cSymbol *base = node->GetBaseSymbol();
    if (base == nullptr) return;

    auto *decl = dynamic_cast<cVarDeclNode*>(base->GetDecl());
    if (decl == nullptr) return;

    long long offset = decl->GetComputedAttributeInt("offset", 0);
    long long size = decl->GetComputedAttributeInt("size", 4);

    if (size == 1)
    {
        EmitAddrFromOffset(offset);
        EmitInstr("PUSHCVARIND");
        return;
    }

    EmitString("PUSHVAR");
    EmitInt((int)offset);
    EmitString("\n");
}

void cCodeGen::Visit(cAssignNode *node)
{
    if (!m_ok || node == nullptr) return;

    cExprNode *lhs = node->GetLhs();
    cExprNode *rhs = node->GetRhs();
    if (lhs == nullptr || rhs == nullptr) return;

    // Compute RHS value first.
    rhs->Visit(this);

    // Support only simple variable lvalues for now.
    auto *lhsVar = dynamic_cast<cVarRefNode*>(lhs);
    if (lhsVar == nullptr) return;
    if (lhsVar->NumParts() != 1 || lhsVar->NumSubscripts() != 0) return;

    cSymbol *base = lhsVar->GetBaseSymbol();
    if (base == nullptr) return;

    auto *decl = dynamic_cast<cVarDeclNode*>(base->GetDecl());
    if (decl == nullptr) return;

    long long offset = decl->GetComputedAttributeInt("offset", 0);
    long long size = decl->GetComputedAttributeInt("size", 4);

    // Store: stack has [value]. Push address, then store indirect.
    EmitAddrFromOffset(offset);
    if (size == 1)
        EmitInstr("POPCVARIND");
    else
        EmitInstr("POPVARIND");
}
