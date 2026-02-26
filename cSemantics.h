#pragma once

#include "cVisitor.h"

class cAssignNode;
class cFuncCallNode;
class cVarRefNode;

// Lab 5B: semantic analysis visitor.
class cSemantics : public cVisitor
{
public:
    cSemantics() = default;

    void Visit(cAssignNode *node) override;
    void Visit(cVarRefNode *node) override;
    void Visit(cFuncCallNode *node) override;
};
