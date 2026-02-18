#pragma once

#include <string>
#include "cDeclNode.h"
#include "cSymbol.h"

class cArrayDeclNode : public cDeclNode
{
public:
    cArrayDeclNode(int count, cSymbol *baseType, cSymbol *name)
        : cDeclNode(), m_count(count)
    {
        AddChild(baseType);
        AddChild(name);
    }

    virtual std::string NodeType() { return "array_decl"; }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

protected:
    virtual std::string AttributesToString()
    {
        return " count=\"" + std::to_string(m_count) + "\"";
    }

private:
    int m_count;
};
