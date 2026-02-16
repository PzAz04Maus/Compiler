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

#include <cstdio>
#include <cstdlib>
#include <string>

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

"int"|"float"|"char"|"long"|"double"  { yylval.symbol = GetOrCreateSymbol(yytext); DO_RETURN(TYPE_ID); }
{identifier}                 { yylval.symbol = GetOrCreateSymbol(yytext); DO_RETURN(IDENTIFIER); }

.                            DO_RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
