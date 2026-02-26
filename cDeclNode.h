#pragma once
//**************************************
// cDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode() {}

    // Lab 5A: declaration classification helpers.
    // Subclasses override the ones that should return true.
    virtual bool IsArray()  { return false; }
    virtual bool IsStruct() { return false; }
    virtual bool IsType()   { return false; }
    virtual bool IsFunc()   { return false; }
    virtual bool IsVar()    { return false; }

    // Base type helpers (only meaningful for base types right now).
    virtual bool IsFloat()  { return false; }
    virtual bool IsInt()    { return false; }
    virtual bool IsChar()   { return false; }

    // Size in bytes (base types override).
    virtual int GetSize()   { return 0; }

    // Lab 5B: provide a name for error messages.
    virtual string GetName() = 0;

    // Lab 5B: type compatibility for assignment and argument passing.
    // Interprets this object as the destination type.
    virtual bool IsCompatibleWith(cDeclNode *type)
    {
        if (type == nullptr) return false;
        if (this == type) return true;

        // Base-type compatibility (char/int/long/float/double).
        if (IsFloat())
        {
            // float/double destinations accept any integer, and same/lesser float.
            if (!type->IsFloat()) return true;

            // float <- double is illegal, double <- float is legal.
            return GetSize() >= type->GetSize();
        }

        // Integer destinations cannot accept floating sources.
        if (type->IsFloat()) return false;

        // char accepts only char.
        if (IsChar()) return type->IsChar();

        // int accepts char/int.
        if (GetSize() == 4) return type->IsChar() || type->GetSize() == 4;

        // long accepts any integer.
        if (GetSize() == 8) return !type->IsFloat();

        return false;
    }
};
