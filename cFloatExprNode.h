#pragma once
//**************************************
// cFloatExprNode.h
//
// Defines an AST node for a floating point constant (literals).
//
// Inherits from cExprNode so that float constants can be used anywhere
// expressions are used.
//

#include <iomanip>
#include <sstream>

#include "cExprNode.h"

class cFloatExprNode : public cExprNode
{
    public:
        explicit cFloatExprNode(double value) : cExprNode(), m_value(value) {}

        virtual string AttributesToString()
        {
            std::ostringstream out;
            out.setf(std::ios::fixed);
            out << std::setprecision(6) << m_value;
            return " value=\"" + out.str() + "\"";
        }

        virtual string NodeType() { return string("float"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        virtual cDeclNode *GetType()
        {
            cSymbol *sym = g_symbolTable.Find("float");
            return (sym != nullptr) ? sym->GetDecl() : nullptr;
        }

    protected:
        double m_value;
};
