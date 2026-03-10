#pragma once
//**************************************
// cIntExprNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbolTable.h"

class cIntExprNode : public cExprNode
{
    public:
        // param is the value of the integer constant
        cIntExprNode(int value) : cExprNode()
        {
            m_value = value;
        }

        int GetValue() const { return m_value; }

        virtual cDeclNode *GetType()
        {
            // Lab 5B: treat small integer literals as char so expressions like
            //   a_char = 2 * a_char;
            // are assignment-compatible in the provided tests.
            const char *typeName = (m_value >= -128 && m_value <= 127) ? "char" : "int";
            cSymbol *sym = g_symbolTable.Find(typeName);
            return (sym != nullptr) ? sym->GetDecl() : nullptr;
        }

        virtual string AttributesToString() 
        {
            return " value=\"" + std::to_string(m_value) + "\"";
        }
        virtual string NodeType() { return string("int"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        int m_value;        // value of integer constant (literal)
};
