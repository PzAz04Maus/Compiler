#pragma once
//**************************************
// cAssignNode.h
//
// Defines AST node for assignment statements
//

#include "cStmtNode.h"
#include "cExprNode.h"

// cAssignNode represents an assignment statement in the AST.
// Inherits from cStmtNode and manages the left-hand side and right-hand side expressions.
class cAssignNode : public cStmtNode
{
    public:
        cAssignNode(cExprNode *lhs, cExprNode *rhs) : cStmtNode()
        {
            AddChild(lhs);
            AddChild(rhs);
        }

        cExprNode *GetLhs() { return dynamic_cast<cExprNode*>(GetChild(0)); }
        cExprNode *GetRhs() { return dynamic_cast<cExprNode*>(GetChild(1)); }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};