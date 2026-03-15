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
    // Adds a primitive base type (char, int, float) to the symbol table.
    // name: type name; size: bytes; isFloat: true if floating point.
    void AddBaseType(const std::string &name, int size, bool isFloat)
    {
        cSymbol *sym = new cSymbol(name);
        sym->SetDecl(new cBaseTypeNode(name, size, isFloat));
        g_symbolTable.Insert(sym);
    }

    // Prints all collected semantic errors to stderr, sorted by line and sequence.
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

// Main entry point for the lang compiler.
// argc: argument count; argv: argument vector (expects input and output file names).
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

            // Assemble the output so the Lab7 test harness can run it.
            std::string cmd = "slasm " + outfile_base + ".sl io320.sl";
            int asmResult = system(cmd.c_str());
            if (asmResult != 0)
            {
                std::cerr << "ERROR: slasm failed\n";
                return 1;
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
