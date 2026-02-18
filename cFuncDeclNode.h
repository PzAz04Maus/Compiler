#pragma once
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cArgsNode.h"

class cFuncDeclNode : public cDeclNode
{
public:
    cFuncDeclNode(cSymbol *retType, cSymbol *name) : cDeclNode()
    {
        AddChild(retType);
        AddChild(name);
    }

    void SetArgs(cArgsNode *args) { if (args) AddChild(args); }
    void SetDecls(cDeclsNode *decls) { if (decls) AddChild(decls); }
    void SetStmts(cStmtsNode *stmts) { if (stmts) AddChild(stmts); }

    virtual string NodeType() { return string("func"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};