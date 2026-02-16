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
        }

        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
