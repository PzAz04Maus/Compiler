#pragma once
#include "cExprNode.h"
#include "cSymbol.h"
#include "cParamsNode.h"
#include "cSymbolTable.h"

class cFuncCallNode : public cExprNode
{
public:
    cFuncCallNode(cSymbol *name, cParamsNode *params = nullptr) : cExprNode()
    {
        cSymbol *resolved = nullptr;
        if (name != nullptr) resolved = g_symbolTable.Find(name->GetName());

        if (resolved == nullptr || resolved->GetDecl() == nullptr || !resolved->GetDecl()->IsFunc())
        {
            if (name != nullptr)
                SemanticParseError("Symbol " + name->GetName() + " not defined");
            AddChild(name);
        }
        else
        {
            AddChild(resolved);
        }
        if (params) AddChild(params);
    }

    virtual string NodeType() { return string("funcCall"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
