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
    void Visit(cStmtsNode *node) override;
    void Visit(cPrintNode *node) override;
    void Visit(cIntExprNode *node) override;
    void Visit(cBinaryExprNode *node) override;
    void Visit(cVarRefNode *node) override;
    void Visit(cAssignNode *node) override;
    void Visit(cFuncDeclNode *node) override;
    void Visit(cFuncCallNode *node) override;
    void Visit(cReturnNode *node) override;
    void Visit(cIfNode *node) override;
    void Visit(cWhileNode *node) override;

private:
    bool m_ok = false;

    enum class Mode
    {
        EmitFunctions,
        EmitMain,
    };

    Mode m_mode = Mode::EmitMain;

    // Tracks whether we've already emitted the prologue allocation for the
    // current frame. For now, only the program's top-level block allocates;
    // function frames allocate at function entry.
    int m_blockDepth = 0;

    void EmitOp(int op);

    // Emits address of a varref target (base + optional indices). Leaves the
    // address on the stack. Returns the final element size in bytes.
    // Currently supports:
    //  - simple vars: a
    //  - 1-D and nested indexing: a[i], a[i][j] (when element type is array)
    // Does not support struct field access yet.
    bool EmitVarRefAddress(cVarRefNode *node, long long &outElemSize);

    static long long GetTypeSizeBytes(cDeclNode *decl);
};
