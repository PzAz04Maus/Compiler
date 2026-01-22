%{
//**************************************
// lang.l
//
// Scanner definition file
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

// Illustration showing how to use {} to control scope
// NOTE: this is pseudo-code illustrating how you can adapt your current lang.l

#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "tokens.h"

// Macros that can be used to create debug output from the scanner
// Uncomment the next line of code to generate debug output.
// Note: for this to work, use DO_RETURN(val) for all the return statements
//       for your tokens. See sample below for "program"
//#define DEBUG_OUTPUT
#ifdef DEBUG_OUTPUT
    #define DO_RETURN(a) { return Return(a); }
#else
    #define DO_RETURN(a) { return (a); }
#endif

static int ProcessID();

int Return(int val);


%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here. whitespace is an example. */
whitespace      [\t\n\r ]+

digit           [0-9]
int_lit         {digit}+
float_lit       {digit}+\.{digit}+

id_start        [A-Za-z_]
id_cont         [A-Za-z0-9_]
identifier      {id_start}{id_cont}*

%%
{whitespace}                { /* Ignore whitespace */ }
"//"[^\n]*                { /* Ignore // comments */ }

"program"                   DO_RETURN(PROGRAM);
"if"                        DO_RETURN(IF);
"else"                      DO_RETURN(ELSE);
"endif"                     DO_RETURN(ENDIF);
"while"                     DO_RETURN(WHILE);
"print"                     DO_RETURN(PRINT);
"prints"                    DO_RETURN(PRINTS);
"char"                      DO_RETURN(CHAR);
"int"                       DO_RETURN(INT);
"long"                      DO_RETURN(LONG);
"float"                     DO_RETURN(FLOAT);
"double"                    DO_RETURN(DOUBLE);
"struct"                    DO_RETURN(STRUCT);
"array"                     DO_RETURN(ARRAY);
"return"                    DO_RETURN(RETURN);

"=="                        DO_RETURN(EQUALS);
"!="                        DO_RETURN(NOT_EQUALS);
"&&"                        DO_RETURN(AND);
"||"                        DO_RETURN(OR);
">="                        DO_RETURN(GE);
"<="                        DO_RETURN(LE);

{float_lit}                  DO_RETURN(FLOAT_VAL);
{int_lit}                    DO_RETURN(INT_VAL);

"\""([^\\\n]|\\.)*"\""   DO_RETURN(STRING_LIT);

"{"                         { g_symbolTable.IncreaseScope(); return '{'; }
"}"                         { g_symbolTable.DecreaseScope(); return '}'; }
"("                         return '(';
")"                         return ')';
"["                         return '[';
"]"                         return ']';
","                         return ',';
";"                         return ';';
"."                         return '.';
"+"                         return '+';
"-"                         return '-';
"/"                         return '/';
"*"                         return '*';
"%"                         return '%';
">"                         return '>';
"<"                         return '<';
"="                         return '=';

LOCAL                        return LOCAL;
GLOBAL                       return GLOBAL;
LOOKUP                       return LOOKUP;
INSERT                       return INSERT;

{identifier}                 {
                                return ProcessID();
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

//******************************************************
// ProcessID: create symbols in symbol table
static int ProcessID()
{
    string name(yytext);
    cSymbol *sym;

    if (g_insert)
    {
        sym = g_symbolTable.FindLocal(name);
        if (sym == nullptr)
        {
            sym = new cSymbol(name);
            g_symbolTable.Insert(sym);
        }
    }
    else
    {
        sym = new cSymbol(name);
    }
    yylval.symbol = sym;

    return IDENTIFIER;
}
