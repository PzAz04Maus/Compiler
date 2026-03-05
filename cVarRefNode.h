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
#include "cStructDeclNode.h"

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
        // Lab 6+ supports both field access (.) and subscripting ([]).
        // The original NumSubscripts() assumed every extra child was an index;
        // in reality some are symbols (fields). These helpers distinguish them.
        int NumParts() { return NumChildren(); }
        cAstNode *GetPart(int index) { return GetChild(index); }

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
                cExprNode *expr = dynamic_cast<cExprNode*>(GetChild(i));
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

            // Start with the variable's declared type.
            cDeclNode *decl = base->GetDecl();
            auto *varDecl = dynamic_cast<cVarDeclNode*>(decl);
            if (varDecl == nullptr) return nullptr;

            cSymbol *typeSym = varDecl->GetTypeSym();
            cDeclNode *typeDecl = (typeSym != nullptr) ? typeSym->GetDecl() : nullptr;

            // Walk the access chain. Parts can be:
            //  - cSymbol (field access)
            //  - cExprNode (array index)
            for (int i = 1; i < NumChildren(); i++)
            {
                cAstNode *part = GetChild(i);
                if (part == nullptr) continue;

                if (dynamic_cast<cExprNode*>(part) != nullptr)
                {
                    // Indexing: type must be an array.
                    auto *arr = dynamic_cast<cArrayDeclNode*>(typeDecl);
                    if (arr == nullptr) return nullptr;
                    cSymbol *baseTypeSym = arr->GetBaseTypeSym();
                    typeDecl = (baseTypeSym != nullptr) ? baseTypeSym->GetDecl() : nullptr;
                    continue;
                }

                auto *fieldSym = dynamic_cast<cSymbol*>(part);
                if (fieldSym != nullptr)
                {
                    // Field: type must be a struct, and the field symbol should
                    // have a var declaration attached.
                    auto *st = dynamic_cast<cStructDeclNode*>(typeDecl);
                    if (st == nullptr) return nullptr;

                    // Field symbols are declared in the struct's field scope,
                    // which has already been popped from the symbol table. So
                    // this symbol often has no decl attached; fall back to
                    // searching the struct's field decls by name.
                    cVarDeclNode *fieldDecl = dynamic_cast<cVarDeclNode*>(fieldSym->GetDecl());
                    if (fieldDecl == nullptr)
                    {
                        fieldDecl = nullptr;
                        cDeclsNode *fields = st->GetFields();
                        if (fields == nullptr) return nullptr;

                        struct Finder : public cVisitor
                        {
                            std::string want;
                            cVarDeclNode *found = nullptr;
                            explicit Finder(std::string n) : want(std::move(n)) {}
                            void Visit(cVarDeclNode *n) override
                            {
                                if (n == nullptr) return;
                                cSymbol *ns = n->GetNameSym();
                                if (ns != nullptr && ns->GetName() == want) found = n;
                            }
                        };

                        Finder f(fieldSym->GetName());
                        fields->VisitAllChildren(&f);
                        fieldDecl = f.found;
                    }

                    if (fieldDecl == nullptr) return nullptr;

                    // Replace the field symbol child with the canonical symbol
                    // used in the struct declaration so XML symbol IDs match
                    // the expected output.
                    if (fieldDecl->GetNameSym() != nullptr)
                    {
                        SetChild(i, fieldDecl->GetNameSym());
                    }

                    cSymbol *fieldTypeSym = fieldDecl->GetTypeSym();
                    typeDecl = (fieldTypeSym != nullptr) ? fieldTypeSym->GetDecl() : nullptr;
                    continue;
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
