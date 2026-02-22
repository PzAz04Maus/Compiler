#pragma once
#include "cAstNode.h"
#include "cDeclNode.h"

class cArgsNode : public cAstNode
{
public:
    explicit cArgsNode(cDeclNode *first) : cAstNode() { AddChild(first); }
    void Insert(cDeclNode *decl) { AddChild(decl); }

    int NumArgs() { return NumChildren(); }

    virtual string NodeType() { return string("args"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};