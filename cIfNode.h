#pragma once
//**************************************
// cIfNode.h
//
// Defines AST node for if statements
//

#include "cStmtNode.h"
#include "cExprNode.h"
#include "cStmtsNode.h"

class cIfNode : public cStmtNode
{
    public:
        cIfNode(cExprNode *condition, cStmtsNode *thenStmts, cStmtsNode *elseStmts) : cStmtNode()
        {
            AddChild(condition);
            AddChild(thenStmts);
            if (elseStmts != nullptr) AddChild(elseStmts);
        }

        cExprNode *GetCond() { return dynamic_cast<cExprNode*>(GetChild(0)); }
        cStmtsNode *GetThen() { return dynamic_cast<cStmtsNode*>(GetChild(1)); }
        cStmtsNode *GetElse() { return dynamic_cast<cStmtsNode*>(GetChild(2)); }

        virtual string NodeType() { return string("if"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
