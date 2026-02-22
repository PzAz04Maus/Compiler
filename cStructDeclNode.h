#pragma once

#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"

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

    virtual string NodeType() { return string("struct_decl"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
