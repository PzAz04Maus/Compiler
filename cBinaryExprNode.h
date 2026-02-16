#pragma once
//**************************************
// cBinaryExprNode.h
//
// Defines an AST node for a binary expression.
//
// The XML output matches the lab format:
//   <expr>
//     <expr|int|float|.../>
//     <op value='+'/>
//     <expr|int|float|.../>
//   </expr>
//

#include "cExprNode.h"
#include "cOpNode.h"

class cBinaryExprNode : public cExprNode
{
    public:
        cBinaryExprNode(cExprNode *left, int op, cExprNode *right) : cExprNode()
        {
            AddChild(left);
            AddChild(new cOpNode(op));
            AddChild(right);
        }

        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
