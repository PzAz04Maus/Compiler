#pragma once
#include "cAstNode.h"
#include "cExprNode.h"

// cParamsNode represents a list of parameter expressions for a function or procedure call in the AST.
// Inherits from cAstNode and manages a list of cExprNode children, each representing an argument expression.
class cParamsNode : public cAstNode
{
public:
    explicit cParamsNode(cExprNode *first) : cAstNode() { AddChild(first); }
    void Insert(cExprNode *expr) { AddChild(expr); }

    int NumParams() { return NumChildren(); }
    cExprNode *GetParam(int index) { return dynamic_cast<cExprNode*>(GetChild(index)); }

    virtual string NodeType() { return string("params"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};