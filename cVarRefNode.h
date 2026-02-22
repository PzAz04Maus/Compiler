#pragma once
//**************************************
// cVarRefNode.h
//
// AST node for a variable reference.
//

#include "cExprNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cVarRefNode : public cExprNode
{
    public:
        explicit cVarRefNode(cSymbol *sym) : cExprNode()
        {
            cSymbol *resolved = nullptr;
            if (sym != nullptr) resolved = g_symbolTable.Find(sym->GetName());

            if (resolved == nullptr || resolved->GetDecl() == nullptr || !resolved->GetDecl()->IsVar())
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

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        void AddField(cSymbol *sym) { AddChild(sym); }
        void AddIndex(cExprNode *expr) { AddChild(expr); }

    private:

};
