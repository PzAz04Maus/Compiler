#pragma once
#include "cAstNode.h"
#include "cDeclNode.h"

// cArgsNode represents a list of argument declarations for a function or procedure in the AST.
// Inherits from cAstNode and manages a list of cDeclNode children, each representing an argument.
class cArgsNode : public cAstNode
{
public:
    explicit cArgsNode(cDeclNode *first) : cAstNode() { AddChild(first); }
    void Insert(cDeclNode *decl) { AddChild(decl); }

    int NumArgs() { return NumChildren(); }
    cDeclNode *GetArg(int index) { return dynamic_cast<cDeclNode*>(GetChild(index)); }

    virtual string NodeType() { return string("args"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};