#pragma once
//**************************************
// cVarRefNode.h
//
// AST node for a variable reference (including struct field access and array
// indexing).
//

#include <string>

#include "cExprNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "cArrayDeclNode.h"
#include "cStructDeclNode.h"
#include "cDeclsNode.h"
#include "cVarDeclNode.h"

class cVarRefNode : public cExprNode
{
public:
    explicit cVarRefNode(cSymbol *name) : cExprNode()
    {
        cSymbol *resolved = nullptr;
        if (name != nullptr) resolved = g_symbolTable.Find(name->GetName());

        if (resolved == nullptr || resolved->GetDecl() == nullptr)
        {
            if (name != nullptr)
            {
                SemanticParseError("Symbol " + name->GetName() + " not defined");
            }
            AddChild(name);
        }
        else
        {
            AddChild(resolved);
        }
    }

    void AddField(cSymbol *field) { AddChild(field); }
    void AddIndex(cExprNode *expr) { AddChild(expr); }

    cSymbol *GetBaseSymbol() { return dynamic_cast<cSymbol*>(GetChild(0)); }

    int NumParts() { return NumChildren(); }
    cAstNode *GetPart(int i) { return GetChild(i); }

    int NumSubscripts()
    {
        int count = 0;
        for (int i = 1; i < NumChildren(); i++)
        {
            if (dynamic_cast<cExprNode*>(GetChild(i)) != nullptr) count++;
        }
        return count;
    }

    cExprNode *GetSubscript(int index)
    {
        int seen = 0;
        for (int i = 1; i < NumChildren(); i++)
        {
            auto *expr = dynamic_cast<cExprNode*>(GetChild(i));
            if (expr == nullptr) continue;
            if (seen == index) return expr;
            seen++;
        }
        return nullptr;
    }

    virtual cDeclNode *GetType()
    {
        cSymbol *base = GetBaseSymbol();
        if (base == nullptr || base->GetDecl() == nullptr) return nullptr;

        // Base must be a variable declaration to have a type symbol.
        auto *varDecl = dynamic_cast<cVarDeclNode*>(base->GetDecl());
        if (varDecl == nullptr) return nullptr;

        cSymbol *typeSym = varDecl->GetTypeSym();
        if (typeSym == nullptr || typeSym->GetDecl() == nullptr) return nullptr;

        // Walk additional parts: symbols are struct fields; expressions are array indices.
        for (int i = 1; i < NumChildren(); i++)
        {
            cAstNode *part = GetChild(i);

            if (dynamic_cast<cExprNode*>(part) != nullptr)
            {
                // Indexing peels one array dimension.
                auto *arr = dynamic_cast<cArrayDeclNode*>(typeSym->GetDecl());
                if (arr == nullptr) return nullptr;
                typeSym = arr->GetBaseTypeSym();
                if (typeSym == nullptr || typeSym->GetDecl() == nullptr) return nullptr;
                continue;
            }

            cSymbol *fieldSym = dynamic_cast<cSymbol*>(part);
            if (fieldSym == nullptr) continue;

            auto *st = dynamic_cast<cStructDeclNode*>(typeSym->GetDecl());
            if (st == nullptr) return nullptr;

            // Prefer a resolved field symbol (decl is a cVarDeclNode).
            auto *fieldDecl = dynamic_cast<cVarDeclNode*>(fieldSym->GetDecl());
            if (fieldDecl == nullptr)
            {
                fieldDecl = FindStructField(st, fieldSym->GetName());
            }
            if (fieldDecl == nullptr) return nullptr;

            typeSym = fieldDecl->GetTypeSym();
            if (typeSym == nullptr || typeSym->GetDecl() == nullptr) return nullptr;
        }

        return typeSym->GetDecl();
    }

    virtual std::string NodeType() { return std::string("varref"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

private:
    cVarDeclNode *FindStructField(cStructDeclNode *structDecl, const std::string &name)
    {
        if (structDecl == nullptr) return nullptr;
        cDeclsNode *fields = structDecl->GetFields();
        if (fields == nullptr) return nullptr;

        struct Finder : public cVisitor
        {
            std::string want;
            cVarDeclNode *found = nullptr;
            explicit Finder(std::string n) : want(std::move(n)) {}
            void Visit(cVarDeclNode *n) override
            {
                if (n == nullptr) return;
                cSymbol *nm = n->GetNameSym();
                if (nm != nullptr && nm->GetName() == want) found = n;
            }
        };

        Finder f(name);
        fields->VisitAllChildren(&f);
        return f.found;
    }
};
