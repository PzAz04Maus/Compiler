#pragma once

//**************************************
// tokens.h
//
// Defines the values for the tokens returned by yylex
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

// #define IDENTIFIER  1114        // <a C style identifier>
#define LOCAL       1115
#define GLOBAL      1116
#define LOOKUP      1117
#define INSERT      1118
#define OPEN        1119
#define CLOSE       1120

#define IDENTIFIER  1216        // <a C style identifier>
#define PROGRAM     1200        // program
#define IF          1201        // if
#define ELSE        1202        // else
#define ENDIF       1203        // endif
#define WHILE       1204        // while
#define PRINT       1205        // print
#define CHAR        1206        // char
#define INT         1207        // int
#define LONG        1208        // Wlong
#define FLOAT       1209        // float
#define DOUBLE      1210        // double
#define INT_VAL     1211        // <an integer constant>
#define FLOAT_VAL   1212        // <a float constant>
#define STRUCT      1213        // struct
#define ARRAY       1214        // array
#define RETURN      1215        // return
#define NOT_EQUALS  1217        // !=
#define EQUALS      1218        // ==
#define AND         1219        // &&
#define OR          1220        // ||
#define GE          1221        // >=
#define LE          1222        // <=
#define PRINTS      1223        // prints
#define STRING_LIT  1224        // "stuff..."

#define JUNK_TOKEN  2000

