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
    void Visit(cPrintNode *node) override;
    void Visit(cIntExprNode *node) override;
    void Visit(cBinaryExprNode *node) override;

private:
    bool m_ok = false;

    void EmitOp(int op);
};
