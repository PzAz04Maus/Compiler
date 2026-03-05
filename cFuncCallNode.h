#pragma once
#include "cExprNode.h"
#include "cSymbol.h"
#include "cParamsNode.h"
#include "cSymbolTable.h"
#include "cFuncDeclNode.h"

class cFuncCallNode : public cExprNode
{
public:
    cFuncCallNode(cSymbol *name, cParamsNode *params = nullptr) : cExprNode()
    {
        cSymbol *resolved = nullptr;
        if (name != nullptr) resolved = g_symbolTable.Find(name->GetName());

        if (resolved == nullptr || resolved->GetDecl() == nullptr)
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

    cSymbol *GetFuncSymbol() { return dynamic_cast<cSymbol*>(GetChild(0)); }
    cParamsNode *GetParamsNode() { return dynamic_cast<cParamsNode*>(GetChild(1)); }

    virtual cDeclNode *GetType()
    {
        cSymbol *sym = GetFuncSymbol();
        if (sym == nullptr || sym->GetDecl() == nullptr) return nullptr;
        cFuncDeclNode *fn = dynamic_cast<cFuncDeclNode*>(sym->GetDecl());
        if (fn == nullptr) return nullptr;
        cSymbol *ret = fn->GetReturnSym();
        return (ret != nullptr) ? ret->GetDecl() : nullptr;
    }
};
