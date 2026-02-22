%{
//**************************************
// lang.l
//
// scanner definition file. flex uses this file to create the scanner
//
// Author: <<<< insert your name here >>>>
//

#include "lex.h"
#include "langparse.h"
#include "cSymbolTable.h"
#include "cDeclNode.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

// Optional lexer debug: enable by running with `LEXDBG=1` in the environment.
static bool LexerDebugEnabled()
{
    static int enabled = -1;
    if (enabled == -1)
    {
        const char *v = std::getenv("LEXDBG");
        enabled = (v != nullptr && v[0] != '\0' && std::strcmp(v, "0") != 0) ? 1 : 0;
    }
    return enabled == 1;
}

// Lab 5A: keep creating symbols in the lexer (stable IDs), but treat them as
// undefined until a declaration node attaches via sym->SetDecl(...).
static cSymbol *GetOrCreateSymbol(const char *text)
{
    std::string name(text);
    cSymbol *sym = g_symbolTable.Find(name);
    if (sym == nullptr)
    {
        sym = new cSymbol(name);
        g_symbolTable.Insert(sym);
    }
    return sym;
}

// Macros that can be used to create debug output from the scanner
// The first one does NOT create debug output, the second does.
// Uncomment one or the other then use DO_RETURN(val) for all your return 
// statements
#define DO_RETURN(a) { return (a); }
//#define DO_RETURN(a) { return Return(a); }

int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


whitespace      [\t\n\r ]+
digit           [0-9]
int_lit         {digit}+
float_lit       {digit}+\.{digit}+

id_start        [A-Za-z_]
id_cont         [A-Za-z0-9_]
identifier      {id_start}{id_cont}*


%%

    // token definitions. I gave "program" as an example
{whitespace}                { /* Ignore whitespace */ }
"//"[^\n]*                { /* Ignore // comments */ }

"program"                   DO_RETURN(PROGRAM);
"print"                     DO_RETURN(PRINT);
"prints"                    DO_RETURN(PRINTS);
"if"                        DO_RETURN(IF);
"endif"                     DO_RETURN(ENDIF);
"else"                      DO_RETURN(ELSE);
"while"                     DO_RETURN(WHILE);
"struct"                    DO_RETURN(STRUCT);
"array"                     DO_RETURN(ARRAY);
"return"                    DO_RETURN(RETURN);

"=="                        DO_RETURN(EQUALS);
"!="                        DO_RETURN(NOT_EQUALS);
"&&"                        DO_RETURN(AND);
"||"                        DO_RETURN(OR);
">="                        DO_RETURN(GE);
"<="                        DO_RETURN(LE);

{float_lit}                  { yylval.float_val = (float)atof(yytext); DO_RETURN(FLOAT_VAL); }
{int_lit}                    { yylval.int_val = atoi(yytext); DO_RETURN(INT_VAL); }

"\""([^\\\n]|\\.)*"\""  { yylval.str_val = new std::string(yytext); DO_RETURN(STRING_LIT); }

"{"                         { g_symbolTable.IncreaseScope(); DO_RETURN('{'); }
"}"                         { g_symbolTable.DecreaseScope(); DO_RETURN('}'); }
"("                         DO_RETURN('(');
")"                         DO_RETURN(')');
"["                         DO_RETURN('[');
"]"                         DO_RETURN(']');
","                         DO_RETURN(',');
";"                         DO_RETURN(';');
"."                         DO_RETURN('.');
"+"                         DO_RETURN('+');
"-"                         DO_RETURN('-');
"/"                         DO_RETURN('/');
"*"                         DO_RETURN('*');
"%"                         DO_RETURN('%');
">"                         DO_RETURN('>');
"<"                         DO_RETURN('<');
"="                         DO_RETURN('=');

"int"|"float"|"char"|"long"|"double"  {
    yylval.symbol = GetOrCreateSymbol(yytext);
    DO_RETURN(TYPE_ID);
}
{identifier} {
    cSymbol *sym = GetOrCreateSymbol(yytext);
    yylval.symbol = sym;

    // DEBUG (temporary): diagnose why 'aaa' at line 13 becomes TYPE_ID.
    if (LexerDebugEnabled() && std::strcmp(yytext, "aaa") == 0 && yylineno == 13)
    {
        std::fprintf(stderr,
            "LEXDBG line %d: '%s' decl=%p isType=%d isVar=%d\n",
            yylineno,
            yytext,
            (void*)sym->GetDecl(),
            (sym->GetDecl() ? sym->GetDecl()->IsType() : -1),
            (sym->GetDecl() ? sym->GetDecl()->IsVar() : -1));
    }

    if (sym->GetDecl() != nullptr && sym->GetDecl()->IsType()) DO_RETURN(TYPE_ID);
    DO_RETURN(IDENTIFIER);
}

.                            DO_RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
