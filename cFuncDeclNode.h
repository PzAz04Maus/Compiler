#pragma once
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cArgsNode.h"

class cFuncDeclNode : public cDeclNode
{
public:
    cFuncDeclNode(cSymbol *retType, cSymbol *src, cSymbol *semanticSym = nullptr)
        : cDeclNode(), m_semanticSym(semanticSym)
    {
        AddChild(retType);
        AddChild(src);

        if (m_semanticSym == nullptr) m_semanticSym = src;

        // Attach this declaration to the semantic symbol if it doesn't already
        // have one.
        if (m_semanticSym != nullptr && m_semanticSym->GetDecl() == nullptr)
            m_semanticSym->SetDecl(this);
    }

    virtual bool IsFunc() { return true; }

    virtual string GetName()
    {
        cSymbol *sym = GetSemanticSym();
        return (sym != nullptr) ? sym->GetName() : string("");
    }

    void SetArgs(cArgsNode *args)
    {
        if (m_argsSet) return;
        m_argsSet = true;

        if (args)
        {
            m_paramCount = args->NumArgs();
            AddChild(args);
        }
        else
        {
            m_paramCount = 0;
        }
    }

    void SetDecls(cDeclsNode *decls)
    {
        if (m_declsSet) return;
        m_declsSet = true;
        if (decls) AddChild(decls);
    }

    void SetStmts(cStmtsNode *stmts)
    {
        if (m_stmtsSet) return;
        m_stmtsSet = true;
        if (stmts) AddChild(stmts);
        m_hasDefinition = true;
    }

    cSymbol *GetSemanticSym() { return m_semanticSym; }
    cSymbol *GetReturnSym() { return (cSymbol*)GetChild(0); }
    cSymbol *GetPrintSym() { return (cSymbol*)GetChild(1); }
    cArgsNode *GetArgsNode()
    {
        // children: return type, printed symbol, optional args, optional decls, optional stmts
        return dynamic_cast<cArgsNode*>(GetChild(2));
    }

    cDeclsNode *GetDeclsNode()
    {
        // children: ret, print, [args], [decls], [stmts]
        for (int i = 2; i < NumChildren(); i++)
        {
            if (dynamic_cast<cDeclsNode*>(GetChild(i)) != nullptr)
                return dynamic_cast<cDeclsNode*>(GetChild(i));
        }
        return nullptr;
    }

    cStmtsNode *GetStmtsNode()
    {
        for (int i = 2; i < NumChildren(); i++)
        {
            if (dynamic_cast<cStmtsNode*>(GetChild(i)) != nullptr)
                return dynamic_cast<cStmtsNode*>(GetChild(i));
        }
        return nullptr;
    }
    int GetParamCount() { return m_paramCount; }
    bool HasDefinition() { return m_hasDefinition; }

    virtual string NodeType() { return string("func"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

private:
    cSymbol *m_semanticSym = nullptr;
    int m_paramCount = 0;
    bool m_argsSet = false;
    bool m_declsSet = false;
    bool m_stmtsSet = false;
    bool m_hasDefinition = false;
};