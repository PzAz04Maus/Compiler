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

    int GetBlockSize(/*cBlockNode *block*/)
    {
        // Current Lab7 visible tests don't declare locals; ADJSP 0 is correct.
        // If you later add query accessors for computed size/offset attributes,
        // this can be upgraded to allocate locals based on the computed sizes.
        return 0;
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

    // Allocate locals for the (implicit) main function.
    int localsSize = GetBlockSize();

    EmitString("ADJSP");
    EmitInt(localsSize);
    EmitString("\n");

    // Emit the program body.
    cVisitor::Visit(node);

    // Return 0.
    EmitPushInt(0);
    EmitInstr("RETURNV");
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
