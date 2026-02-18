#pragma once
//**************************************
// cPrintsNode.h
//
// Defines AST node for printing string literals (prints("..."))
//

#include <string>
#include "cAstNode.h"
#include "cStmtNode.h"

class cPrintsNode : public cStmtNode
{
    public:
        explicit cPrintsNode(const std::string &rawStringLit) : cStmtNode(), m_value(Normalize(rawStringLit)) {}

        virtual std::string NodeType() { return std::string("prints"); }
        virtual std::string AttributesToString() { return std::string(" value=\"") + EscapeXml(m_value) + "\""; }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    private:
        std::string m_value;

        static std::string Normalize(const std::string &raw)
        {
            // Lexer includes surrounding quotes; strip them if present.
            std::string s = raw;
            if (s.size() >= 2 && s.front() == '"' && s.back() == '"')
            {
                s = s.substr(1, s.size() - 2);
            }

            // Unescape a minimal set of common sequences.
            std::string out;
            out.reserve(s.size());
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i] == '\\' && i + 1 < s.size())
                {
                    char c = s[i + 1];
                    switch (c)
                    {
                        case 'n': out.push_back('\n'); i++; continue;
                        case 't': out.push_back('\t'); i++; continue;
                        case 'r': out.push_back('\r'); i++; continue;
                        case '\\': out.push_back('\\'); i++; continue;
                        case '"': out.push_back('"'); i++; continue;
                        default:
                            // Preserve unknown escapes as-is.
                            out.push_back('\\');
                            continue;
                    }
                }
                out.push_back(s[i]);
            }
            return out;
        }

        static std::string EscapeXml(const std::string &s)
        {
            std::string out;
            out.reserve(s.size());
            for (char c : s)
            {
                switch (c)
                {
                    case '&': out += "&amp;"; break;
                    case '<': out += "&lt;"; break;
                    case '>': out += "&gt;"; break;
                    case '\"': out += "&quot;"; break;
                    default: out.push_back(c); break;
                }
            }
            return out;
        }
};
