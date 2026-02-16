#pragma once
//**************************************
// cVarRefNode.h
//
// AST node for a variable reference.
//

#include "cExprNode.h"
#include "cSymbol.h"

class cVarRefNode : public cExprNode
{
    public:
        explicit cVarRefNode(cSymbol *sym) : cExprNode()
        {
            AddChild(sym);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
