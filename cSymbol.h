#pragma once
//**************************************
// cSymbol.h
//
// Defines class used to represent symbols.
// Later labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include <string>

using std::string;

#include "cAstNode.h"

class cDeclNode;

class cSymbol : public cAstNode
{
    public:
        // param is name of symbol
        cSymbol(string name) : cAstNode()
        {
            m_id = ++nextId;        // get next available ID
            m_name = name;
        }

        // Attach/retrieve the declaration associated with this symbol.
        // (Lab 5A: used to determine whether the symbol is a type/var/func/etc.)
        void SetDecl(cDeclNode *decl) { m_decl = decl; }
        cDeclNode* GetDecl() const { return m_decl; }

        // return name of symbol
        string GetName() { return m_name; }

        virtual string AttributesToString()
        {
            string result(" id=\"");
            result += std::to_string(m_id);
            result += "\" name=\"" + m_name + "\"";
            return result;
        }
        virtual string NodeType() { return string("sym"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        static long long nextId;        // Next avail symbol ID
        long long m_id;                 // Unique ID for this symbol
        string m_name;                  // name of symbol
        cDeclNode *m_decl = nullptr;    // declaration of this symbol
};
