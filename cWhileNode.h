#pragma once
//**************************************
// cWhileNode.h
//
// Defines AST node for while statements
//

#include "cStmtNode.h"
#include "cExprNode.h"

class cWhileNode : public cStmtNode
{
    public:
        cWhileNode(cExprNode *condition, cStmtNode *body) : cStmtNode()
        {
            AddChild(condition);
            AddChild(body);
        }

        cExprNode *GetCond() { return dynamic_cast<cExprNode*>(GetChild(0)); }
        cStmtNode *GetBody() { return dynamic_cast<cStmtNode*>(GetChild(1)); }

        virtual string NodeType() { return string("while"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};