#pragma once
#include "cAstNode.h"
#include "cExprNode.h"

class cParamsNode : public cAstNode
{
public:
    explicit cParamsNode(cExprNode *first) : cAstNode() { AddChild(first); }
    void Insert(cExprNode *expr) { AddChild(expr); }

    virtual string NodeType() { return string("params"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};