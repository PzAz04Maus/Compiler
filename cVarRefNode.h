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
            AddField(sym);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        void AddField(cSymbol *sym) { AddChild(sym); }
        void AddIndex(cExprNode *expr) { AddChild(expr); }

    private:

};
