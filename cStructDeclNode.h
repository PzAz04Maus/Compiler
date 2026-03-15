#pragma once

#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"

// cStructDeclNode represents a struct type declaration in the AST.
// Inherits from cDeclNode and manages the list of fields and the struct type symbol.
class cStructDeclNode : public cDeclNode
{
public:
    cStructDeclNode(cDeclsNode *fields, cSymbol *src) : cDeclNode()
    {
        AddChild(fields);
        AddChild(src);

        // Attach this declaration to the struct type symbol.
        if (src != nullptr && src->GetDecl() == nullptr) src->SetDecl(this);
    }

    virtual bool IsType() { return true; }
    virtual bool IsStruct() { return true; }

    virtual string GetName()
    {
        cSymbol *sym = dynamic_cast<cSymbol*>(GetChild(1));
        return (sym != nullptr) ? sym->GetName() : string("");
    }

    cDeclsNode *GetFields() { return dynamic_cast<cDeclsNode*>(GetChild(0)); }
    cSymbol *GetTypeSym() { return dynamic_cast<cSymbol*>(GetChild(1)); }

    virtual string NodeType() { return string("struct_decl"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
