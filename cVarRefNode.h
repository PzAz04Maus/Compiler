#pragma once
//**************************************
// cVarRefNode.h
//
// AST node for a variable reference.
//

#include "cExprNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "cVarDeclNode.h"
#include "cArrayDeclNode.h"

class cVarRefNode : public cExprNode
{
    public:
        explicit cVarRefNode(cSymbol *sym) : cExprNode()
        {
            cSymbol *resolved = nullptr;
            if (sym != nullptr) resolved = g_symbolTable.Find(sym->GetName());

            // For Lab 5B, semantic checks (function-as-variable, array usage, etc.)
            // are performed by the semantic visitor. At parse-time we only flag
            // truly undefined symbols.
            if (resolved == nullptr || resolved->GetDecl() == nullptr)
            {
                if (sym != nullptr)
                    SemanticParseError("Symbol " + sym->GetName() + " not defined");
                AddField(sym);
            }
            else
            {
                AddField(resolved);
            }
        }

        cSymbol *GetBaseSymbol() { return dynamic_cast<cSymbol*>(GetChild(0)); }
        int NumSubscripts()
        {
            int n = NumChildren();
            // child[0] is the base symbol
            return (n > 1) ? (n - 1) : 0;
        }
        cExprNode *GetSubscript(int index)
        {
            return dynamic_cast<cExprNode*>(GetChild(index + 1));
        }

        virtual cDeclNode *GetType()
        {
            cSymbol *base = GetBaseSymbol();
            if (base == nullptr || base->GetDecl() == nullptr) return nullptr;

            // Variable reference: type is the variable's declared type.
            // If indexed, type is the array's base type.
            cDeclNode *decl = base->GetDecl();
            cVarDeclNode *varDecl = dynamic_cast<cVarDeclNode*>(decl);
            if (varDecl == nullptr) return nullptr;

            cSymbol *typeSym = varDecl->GetTypeSym();
            cDeclNode *typeDecl = (typeSym != nullptr) ? typeSym->GetDecl() : nullptr;

            if (NumSubscripts() > 0)
            {
                cArrayDeclNode *arr = dynamic_cast<cArrayDeclNode*>(typeDecl);
                if (arr != nullptr)
                {
                    cSymbol *baseTypeSym = arr->GetBaseTypeSym();
                    return (baseTypeSym != nullptr) ? baseTypeSym->GetDecl() : nullptr;
                }
            }
            return typeDecl;
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        void AddField(cSymbol *sym) { AddChild(sym); }
        void AddIndex(cExprNode *expr) { AddChild(expr); }

    private:

};
