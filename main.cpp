//**************************************
// main.cpp
//
// Main function for lang compiler
//
// Author: Phil Howard 
//Modified by: Stephen Carter - 2/11/26
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
//#include "cSymbol.h"
#include "cSymbolTable.h"
#include "cBaseTypeNode.h"
#include "lex.h"
#include "astnodes.h"
#include "langparse.h"
//#include "tokens.h"

// define global variables
//cSymbolTable g_SymbolTable;
long long cSymbol::nextId;

// takes two string args: input_file, and output_file
int main(int argc, char **argv)
{
    const char *outfile_name;
    int result = 0;

    // Preload primitive types so they have stable IDs and can be reused.
    // This matches the expected AST output for declarations.
    auto addBaseType = [](const std::string& name, int size, bool isFloat)
    {
        cSymbol* sym = new cSymbol(name);
        sym->SetDecl(new cBaseTypeNode(name, size, isFloat));  // attach decl here
        g_symbolTable.Insert(sym);
    };

    // Keep insertion order stable so symbol IDs match expected test outputs.
    addBaseType("char",   1, false);
    addBaseType("int",    4, false);
    addBaseType("float",  4, true);
    addBaseType("long",   8, false);
    addBaseType("double", 8, true);

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == nullptr)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    // Setup the output. If empty, use stdout (which may be redirected)
    if (argc > 2)
    {
        outfile_name = argv[2];

        FILE *output = fopen(outfile_name, "w");
        if (output == nullptr)
        {
            std::cerr << "Unable to open output file " << outfile_name << "\n";
            exit(-1);
        }

        // redirect stdout to the output file
        int output_fd = fileno(output);
        if (dup2(output_fd, 1) != 1)
        {
            std::cerr << "Unable configure output stream\n";
            exit(-1);
        }
    }

    result = yyparse();
    if (yyast_root != nullptr)
    {
        if (result == 0)
        {
            std::cout << yyast_root->ToString();
        } else {
            std::cout << yynerrs << " Errors in compile\n";
        }
    }

    if (result == 0 && yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    return result;
}
