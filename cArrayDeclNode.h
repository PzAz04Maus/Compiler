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

        // Attach this declaration to the array type symbol.
        if (name != nullptr && name->GetDecl() == nullptr) name->SetDecl(this);
    }

    virtual bool IsType() { return true; }
    virtual bool IsArray() { return true; }

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
