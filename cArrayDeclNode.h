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

    virtual std::string GetName()
    {
        cSymbol *sym = GetNameSym();
        return (sym != nullptr) ? sym->GetName() : std::string("");
    }

    cSymbol *GetBaseTypeSym() { return dynamic_cast<cSymbol*>(GetChild(0)); }
    cSymbol *GetNameSym() { return dynamic_cast<cSymbol*>(GetChild(1)); }

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
