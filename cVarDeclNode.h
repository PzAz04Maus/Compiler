#pragma once
//**************************************
// cVarDeclNode.h
//
// AST node for a variable declaration.
//

#include "cDeclNode.h"
#include "cSymbol.h"

class cVarDeclNode : public cDeclNode
{
    public:
        cVarDeclNode(cSymbol *typeSym, cSymbol *nameSym) : cDeclNode()
        {
            AddChild(typeSym);
            AddChild(nameSym);

            // Attach this declaration to the variable symbol.
            if (nameSym != nullptr && nameSym->GetDecl() == nullptr) nameSym->SetDecl(this);
        }

        virtual bool IsVar() { return true; }

        virtual string GetName()
        {
            cSymbol *sym = GetNameSym();
            return (sym != nullptr) ? sym->GetName() : string("");
        }

        cSymbol *GetTypeSym() { return dynamic_cast<cSymbol*>(GetChild(0)); }
        cSymbol *GetNameSym() { return dynamic_cast<cSymbol*>(GetChild(1)); }

        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
