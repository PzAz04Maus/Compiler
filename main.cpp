//**************************************
// main.cpp
//
// Main function for lang compiler
//
// Author: Phil Howard
// Modified by: Stephen Carter - 2/11/26
//

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "astnodes.h"
#include "cCodeGen.h"
#include "cComputeSize.h"
#include "cSemantics.h"
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "langparse.h"
#include "lex.h"

// Global variables used across the compiler.
long long cSymbol::nextId;
std::vector<cSemanticErrorEntry> g_semanticErrors;
std::int64_t g_semanticErrorSeq = 0;

namespace
{
    void AddBaseType(const std::string &name, int size, bool isFloat)
    {
        cSymbol *sym = new cSymbol(name);
        sym->SetDecl(new cBaseTypeNode(name, size, isFloat));
        g_symbolTable.Insert(sym);
    }

    void EmitSemanticErrors()
    {
        std::stable_sort(g_semanticErrors.begin(), g_semanticErrors.end(),
            [](const cSemanticErrorEntry &a, const cSemanticErrorEntry &b)
            {
                if (a.line != b.line) return a.line < b.line;
                return a.seq < b.seq;
            });

        for (const auto &e : g_semanticErrors)
        {
            std::cerr << "ERROR: " << e.message << " near line " << e.line << "\n";
        }
    }
}

// takes two string args: input_file, and output_file
int main(int argc, char **argv)
{
    std::cout << "Stephen Carter" << std::endl;

    std::string outfile_base = "langout";

    // Primitive types (stable insertion order).
    AddBaseType("char", 1, false);
    AddBaseType("int", 4, false);
    AddBaseType("float", 8, true);

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == nullptr)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            return 1;
        }
    }

    if (argc > 2)
    {
        outfile_base = argv[2];
    }

    int parseResult = yyparse();

    if (yyast_root != nullptr && parseResult == 0)
    {
        cSemantics semantics;
        semantics.VisitAllNodes(yyast_root);

        if (yynerrs == 0)
        {
            cComputeSize sizer;
            sizer.VisitAllNodes(yyast_root);

            // Generate Stackl assembly. The provided Lab7 scripts assemble/run it.
            {
                cCodeGen coder(outfile_base + ".sl");
                coder.VisitAllNodes(yyast_root);
            }
        }
    }

    if (yynerrs != 0)
    {
        EmitSemanticErrors();
        std::cerr << yynerrs << " Errors in compile\n";
    }

    if (parseResult == 0 && yylex() != 0)
    {
        std::cerr << "Junk at end of program\n";
    }

    return (parseResult == 0 && yynerrs == 0) ? 0 : 1;
}
