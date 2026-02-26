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
#include "cSymbolTable.h"

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

        cExprNode *GetLeft() { return dynamic_cast<cExprNode*>(GetChild(0)); }
        cOpNode *GetOpNode() { return dynamic_cast<cOpNode*>(GetChild(1)); }
        cExprNode *GetRight() { return dynamic_cast<cExprNode*>(GetChild(2)); }

        virtual cDeclNode *GetType()
        {
            cOpNode *opNode = GetOpNode();
            int op = (opNode != nullptr) ? opNode->GetOp() : 0;

            // Relational/logical always return int.
            if (op == '>' || op == '<' || op == GE || op == LE || op == EQUALS || op == NOT_EQUALS || op == AND || op == OR)
            {
                cSymbol *intSym = g_symbolTable.Find("int");
                return (intSym != nullptr) ? intSym->GetDecl() : nullptr;
            }

            cDeclNode *lt = (GetLeft() != nullptr) ? GetLeft()->GetType() : nullptr;
            cDeclNode *rt = (GetRight() != nullptr) ? GetRight()->GetType() : nullptr;
            if (lt == nullptr) return rt;
            if (rt == nullptr) return lt;

            auto rank = [](cDeclNode *t) -> int {
                if (t == nullptr) return -1;
                if (t->IsFloat()) return (t->GetSize() >= 8) ? 4 : 3; // double : float
                if (t->IsChar()) return 0;
                if (t->GetSize() >= 8) return 2; // long
                return 1; // int
            };

            int lr = rank(lt);
            int rr = rank(rt);
            int best = (lr > rr) ? lr : rr;

            const char *name = "int";
            if (best == 0) name = "char";
            else if (best == 1) name = "int";
            else if (best == 2) name = "long";
            else if (best == 3) name = "float";
            else if (best == 4) name = "double";

            cSymbol *sym = g_symbolTable.Find(name);
            return (sym != nullptr) ? sym->GetDecl() : nullptr;
        }
};
