%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
//

#include <iostream>
#include <string>
#include "lex.h"
#include "astnodes.h"


%}

%code requires {
    #include <string>

    class cAstNode;
    class cProgramNode;
    class cBlockNode;
    class cDeclsNode;
    class cDeclNode;
    class cStmtsNode;
    class cStmtNode;
    class cExprNode;
    class cIntExprNode;
    class cSymbol;
    class cStructDeclNode;
    class cArgsNode;
    class cFuncCallNode;
    class cFuncDeclNode;
    class cParamsNode;
}

%locations

 /* union defines the type for lexical values */
%union{
    int             int_val;
    float           float_val;
    std::string*    str_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cDeclsNode*     decls_node;
    cDeclNode*      decl_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    //cPrintNode*   stmt_node;
    cExprNode*      expr_node;
    cIntExprNode*   int_node;
    cSymbol*        symbol;
    cFuncDeclNode*  func_node;
    cArgsNode*      args_node;
    cParamsNode*    params_node;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   CHAR_VAL
%token <int_val>   INT_VAL
%token <float_val> FLOAT_VAL
%token <int_val>   LE
%token <int_val>   GE
%token <int_val>   AND
%token <int_val>   OR
%token <int_val>   EQUALS
%token <int_val>   NOT_EQUALS
%token <str_val>   STRING_LIT

%token  PROGRAM
%token  PRINT PRINTS
%token  WHILE IF ELSE ENDIF
%token  STRUCT ARRAY
%token  RETURN
%token  JUNK_TOKEN

%type <program_node> program
%type <block_node> block

%type <decls_node> decls
%type <decl_node> decl

%type <ast_node> open
%type <ast_node> close
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> array_decl
%type <func_node> func_decl
%type <func_node> func_header
%type <func_node> func_prefix
%type <expr_node> func_call
%type <args_node> paramsspec
%type <decl_node> paramspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> lval
%type <params_node> params
%type <expr_node> param
%type <expr_node> expr
%type <expr_node> addit
%type <expr_node> term
%type <expr_node> fact
%type <expr_node> varref
%type <symbol> varpart

%%

program: PROGRAM block
                                { $$ = new cProgramNode($2);
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close
                                { $$ = new cBlockNode($2, $3); }
    |   open stmts close
                                { $$ = new cBlockNode(nullptr, $2); }

open:   '{'
                                { /* $$ = g_SymbolTable.IncreaseScope(); */ }

close:  '}'
                                { /* $$ = g_SymbolTable.DecreaseScope(); */ }

decls:      decls decl
                                { $1->Insert($2); $$ = $1; }
        |   decl
                                { $$ = new cDeclsNode($1); }
decl:       var_decl ';'
                                { $$ = $1; }
        |   array_decl ';'
                            { $$ = $1; }
        |   struct_decl ';'
                            { $$ = $1; }
        |   func_decl
                            { $$ = $1; }

var_decl:   TYPE_ID IDENTIFIER
                                    { 
                                        cSymbol *id = $2;

                                        if(g_symbolTable.FindLocal(id->GetName())==nullptr)
                                        {
                                            id = new cSymbol(id->GetName());
                                            g_symbolTable.Insert(id);
                                        }
                                        $$ = new cVarDeclNode($1, id);
                                    }
struct_decl: STRUCT open decls close IDENTIFIER
    {
        cSymbol *typeSym = $5;
        if (g_symbolTable.FindLocal(typeSym->GetName()) == nullptr)
        {
            typeSym = new cSymbol(typeSym->GetName());
            g_symbolTable.Insert(typeSym);
        }
        g_symbolTable.DeclareType(typeSym);
        $$ = new cStructDeclNode($3, typeSym);
    }
                                
array_decl:   ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER
    {
        cSymbol *newTypeSym = $6;   // <-- int10 or s (THIS becomes a TYPE_ID later)

        if (g_symbolTable.FindLocal(newTypeSym->GetName()) == nullptr)
        {
            newTypeSym = new cSymbol(newTypeSym->GetName());
            g_symbolTable.Insert(newTypeSym);
        }

        g_symbolTable.DeclareType(newTypeSym);   // <-- critical: makes lexer return TYPE_ID later

        $$ = new cArrayDeclNode($4, $2, newTypeSym);  // count, base type, new type name
    }

func_decl:  func_header ';'
                                { $$ = $1; g_symbolTable.DecreaseScope(); }
    | func_header '{' decls stmts '}'
        { $1->SetDecls($3); $1->SetStmts($4); $$ = $1; g_symbolTable.DecreaseScope(); }
    | func_header '{' stmts '}'
        { $1->SetStmts($3); $$ = $1; g_symbolTable.DecreaseScope(); }
;

func_header: func_prefix paramsspec ')'
                                { $1->SetArgs($2); $$ = $1; }
    | func_prefix ')'
                                { $$ = $1; }
;

func_prefix: TYPE_ID IDENTIFIER '('
{
    cSymbol *fn = $2;
    if (g_symbolTable.FindLocal(fn->GetName()) == nullptr)
    {
        fn = new cSymbol(fn->GetName());
        g_symbolTable.Insert(fn);
    }
    $$ = new cFuncDeclNode($1, fn);

    // parameter scope (so params don't reuse global 'a')
    g_symbolTable.IncreaseScope();
}
;

paramsspec:
      paramsspec ',' paramspec
        { $1->Insert($3); $$ = $1; }
    | paramspec
        { $$ = new cArgsNode($1); }
;

paramspec: var_decl { $$ = $1; };

stmts:      stmts stmt
                                { $1->Insert($2); $$ = $1; }
        |   stmt
                            { $$ = new cStmtsNode($1); }

stmt:       IF '(' expr ')' stmts ENDIF ';'
                                { $$ = new cIfNode($3, $5, nullptr); }
        |   IF '(' expr ')' stmts ELSE stmts ENDIF ';'
                                { $$ = new cIfNode($3, $5, $7); }
        |   WHILE '(' expr ')' stmt
                                { $$ = new cWhileNode($3, $5);  }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   PRINTS '(' STRING_LIT ')' ';'
                                { $$ = new cPrintsNode(*$3); delete $3; }
        |   lval '=' expr ';'
                            { $$ = new cAssignNode($1, $3); }
        |   func_call ';'
                            { $$ = $1; }
        |   block
                            { $$ = $1; }
        |   RETURN expr ';'
                            { $$ = new cReturnNode($2); }
        |   error ';'
                            {}

func_call:
      IDENTIFIER '(' params ')'
        { $$ = new cFuncCallNode($1, $3); }
    | IDENTIFIER '(' ')'
        { $$ = new cFuncCallNode($1, nullptr); }
;


varref: varref '.' varpart
    { ((cVarRefNode*)$1)->AddField($3); $$ = $1; }
  | varref '[' expr ']'
    { ((cVarRefNode*)$1)->AddIndex($3); $$ = $1; }
  | varpart
    { $$ = new cVarRefNode($1); }

varpart:  IDENTIFIER
                                { $$ = $1; }

lval:     varref
                                { $$ = $1; }


params:   params ',' param
                                { $1->Insert($3); $$ = $1; }
        |   param
                            { $$ = new cParamsNode($1); }
;

param:      expr
                                { $$ = $1; }
;

expr:       expr EQUALS addit
                                { $$ = new cBinaryExprNode($1,EQUALS,$3); }
        |   addit
                            { $$ = $1; }

addit:      addit '+' term
                                { $$ = new cBinaryExprNode($1, '+', $3); }
        |   addit '-' term
                            { $$ = new cBinaryExprNode($1, '-', $3); }
        |   term
                            { $$ = $1; }

term:       term '*' fact
                                { $$ = new cBinaryExprNode($1, '*', $3); }
        |   term '/' fact
                            { $$ = new cBinaryExprNode($1, '/', $3); }
        |   term '%' fact
                            { $$ = new cBinaryExprNode($1, '%', $3); }
        |   fact
                            { $$ = $1; }

fact:       '(' expr ')'
                                { $$ = $2; }
        |   INT_VAL
                            { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL
                            { $$ = new cFloatExprNode($1); }
        |   varref
                            { $$ = $1; }
        |   func_call
                            { $$ = $1; }
;

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
