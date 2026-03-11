#pragma once

#include <string>

#include "cVisitor.h"

// Lab 7: Stackl code generation visitor.
// Generates a .sl program that can be assembled with slasm and run with stackl.
class cCodeGen : public cVisitor
{
public:
    explicit cCodeGen(const std::string &outputFile);
    ~cCodeGen();

    void Visit(cProgramNode *node) override;
    void Visit(cBlockNode *node) override;
    void Visit(cPrintNode *node) override;
    void Visit(cIntExprNode *node) override;
    void Visit(cBinaryExprNode *node) override;
    void Visit(cVarRefNode *node) override;
    void Visit(cAssignNode *node) override;

private:
    bool m_ok = false;

    // Tracks whether we've already emitted the prologue allocation for the
    // current frame. For now, only the program's top-level block allocates.
    int m_blockDepth = 0;

    void EmitOp(int op);
};
