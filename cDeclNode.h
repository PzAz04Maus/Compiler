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
};
