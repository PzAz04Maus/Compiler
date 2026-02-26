#pragma once
#include "cAstNode.h"
#include "cExprNode.h"

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