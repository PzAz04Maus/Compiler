/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"

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

static bool g_semanticErrorHappened = false;

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR; } }




#line 96 "langparse.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "langparse.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_ID = 4,                    /* TYPE_ID  */
  YYSYMBOL_CHAR_VAL = 5,                   /* CHAR_VAL  */
  YYSYMBOL_INT_VAL = 6,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 7,                  /* FLOAT_VAL  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_EQUALS = 12,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 13,                /* NOT_EQUALS  */
  YYSYMBOL_STRING_LIT = 14,                /* STRING_LIT  */
  YYSYMBOL_PROGRAM = 15,                   /* PROGRAM  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_PRINTS = 17,                    /* PRINTS  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ENDIF = 21,                     /* ENDIF  */
  YYSYMBOL_STRUCT = 22,                    /* STRUCT  */
  YYSYMBOL_ARRAY = 23,                     /* ARRAY  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_JUNK_TOKEN = 25,                /* JUNK_TOKEN  */
  YYSYMBOL_UMINUS = 26,                    /* UMINUS  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_36_ = 36,                       /* '.'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_block = 46,                     /* block  */
  YYSYMBOL_open = 47,                      /* open  */
  YYSYMBOL_close = 48,                     /* close  */
  YYSYMBOL_decls = 49,                     /* decls  */
  YYSYMBOL_decl = 50,                      /* decl  */
  YYSYMBOL_var_decl = 51,                  /* var_decl  */
  YYSYMBOL_struct_decl = 52,               /* struct_decl  */
  YYSYMBOL_array_decl = 53,                /* array_decl  */
  YYSYMBOL_func_decl = 54,                 /* func_decl  */
  YYSYMBOL_func_header = 55,               /* func_header  */
  YYSYMBOL_func_prefix = 56,               /* func_prefix  */
  YYSYMBOL_paramsspec = 57,                /* paramsspec  */
  YYSYMBOL_paramspec = 58,                 /* paramspec  */
  YYSYMBOL_stmts = 59,                     /* stmts  */
  YYSYMBOL_stmt = 60,                      /* stmt  */
  YYSYMBOL_func_call = 61,                 /* func_call  */
  YYSYMBOL_varref = 62,                    /* varref  */
  YYSYMBOL_varpart = 63,                   /* varpart  */
  YYSYMBOL_lval = 64,                      /* lval  */
  YYSYMBOL_params = 65,                    /* params  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_expr = 67,                      /* expr  */
  YYSYMBOL_or_expr = 68,                   /* or_expr  */
  YYSYMBOL_and_expr = 69,                  /* and_expr  */
  YYSYMBOL_rel_expr = 70,                  /* rel_expr  */
  YYSYMBOL_addit = 71,                     /* addit  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_fact = 73                       /* fact  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 69 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;
    

#line 210 "langparse.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      33,    32,    41,    39,    34,    40,    36,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
      38,    35,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   142,   144,   147,   150,   153,   155,   157,
     159,   161,   163,   166,   186,   214,   240,   242,   261,   281,
     317,   331,   386,   388,   392,   394,   396,   399,   401,   403,
     405,   407,   409,   411,   413,   415,   417,   421,   423,   428,
     430,   432,   435,   438,   442,   444,   448,   452,   455,   457,
     460,   462,   465,   467,   469,   471,   473,   475,   477,   480,
     482,   484,   487,   489,   491,   493,   496,   498,   500,   502,
     504,   506
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPE_ID", "CHAR_VAL", "INT_VAL", "FLOAT_VAL", "LE", "GE", "AND", "OR",
  "EQUALS", "NOT_EQUALS", "STRING_LIT", "PROGRAM", "PRINT", "PRINTS",
  "WHILE", "IF", "ELSE", "ENDIF", "STRUCT", "ARRAY", "RETURN",
  "JUNK_TOKEN", "UMINUS", "'{'", "'}'", "';'", "'['", "']'", "')'", "'('",
  "','", "'='", "'.'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "$accept", "program", "block", "open", "close", "decls", "decl",
  "var_decl", "struct_decl", "array_decl", "func_decl", "func_header",
  "func_prefix", "paramsspec", "paramspec", "stmts", "stmt", "func_call",
  "varref", "varpart", "lval", "params", "param", "expr", "or_expr",
  "and_expr", "rel_expr", "addit", "term", "fact", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   123,   125,    59,
      91,    93,    41,    40,    44,    61,    46,    62,    60,    43,
      45,    42,    47,    37
};
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,     2,    34,   -47,   -47,   187,   -47,    10,    22,    58,
      33,    43,    47,    48,     2,    67,    13,   -47,   187,   -47,
      44,    55,    59,   -47,    40,     3,   130,   -47,    72,    -4,
     -47,    70,   -47,     5,    69,    13,    92,    13,    13,    18,
      78,   -47,   -47,    13,    13,   -47,    -4,    84,   103,   105,
      66,   -22,    16,   -47,   -47,   130,   -47,   -47,   -47,   187,
     -47,   114,   -47,   -47,    15,   -47,   -47,   -47,   -47,   -47,
      13,   115,    13,   -47,    38,   -47,   -47,   -47,    87,    88,
      89,    90,    20,   118,    93,   -47,   -47,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     -47,   187,   149,   -47,   -47,   122,    97,   -47,   -47,   106,
     -47,    13,   108,   110,   233,   233,   129,   113,   -47,   105,
      66,   -22,   -22,   -22,   -22,   -22,   -22,    16,    16,   -47,
     -47,   -47,   168,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   199,   -47,   131,   -47,   233,   112,   -47,   221,   -47,
     124,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     2,     0,     1,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     8,
       0,     0,     0,    12,     0,     0,     0,    26,     0,    43,
      41,     0,    36,     0,    13,     0,     0,     0,     0,     0,
       0,    68,    69,     0,     0,    71,    70,     0,    47,    49,
      51,    58,    61,    65,     7,     0,     9,    11,    10,     0,
      16,     0,    20,    24,     0,    23,     6,     4,    25,    33,
       0,     0,     0,    38,     0,    45,    46,    21,     0,     0,
       0,     0,     0,     0,     0,    67,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,    13,    19,     0,     0,    42,    39,     0,
      37,     0,     0,     0,     0,     0,     0,     0,    66,    48,
      50,    55,    54,    56,    57,    52,    53,    59,    60,    62,
      63,    64,     0,    18,    22,    40,    32,    44,    30,    31,
      29,     0,    14,     0,    17,     0,     0,    15,     0,    27,
       0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   150,   141,   -46,    -8,   -14,   -20,   -47,   -47,
     -47,   -47,   -47,   -47,    51,   -15,   -25,    -5,    -3,    91,
     -47,   -47,    49,   -10,   -47,    74,    71,     1,   -13,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    17,     5,    67,    18,    19,    20,    21,    22,
      23,    24,    25,    64,    65,    26,    27,    45,    46,    30,
      31,    74,    75,    76,    48,    49,    50,    51,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    68,    29,    55,    54,    63,    47,    61,     8,   100,
      85,    41,    42,    28,     1,    29,     8,    95,    96,    41,
      42,    28,     9,    29,     9,    78,    70,    80,    81,     3,
      68,    82,    71,    84,     6,    62,   116,    73,    43,    32,
      14,    15,    14,    15,   102,    44,    43,   104,    66,   105,
      28,   101,    29,    44,    28,    33,    29,    97,    98,    99,
     106,    34,   109,   129,   130,   131,    35,    59,    54,    60,
     110,    40,   111,    56,    89,    90,    36,    68,    91,    92,
      37,    38,   127,   128,    57,    63,   132,    54,    58,   140,
     121,   122,   123,   124,   125,   126,    28,    28,    29,    29,
     141,    69,    77,    93,    94,    72,    79,    68,    83,    28,
      28,    29,    29,    86,    87,    88,    68,   103,   107,   112,
     113,   114,   115,    68,   117,   118,    61,    28,   135,    29,
     148,     7,   142,     8,   147,   136,    28,   138,    29,   139,
      28,   149,    29,    28,   143,    29,    10,    11,    12,    13,
       7,     4,     8,   151,    16,    39,   134,     3,    66,   120,
     137,   119,   108,     0,     0,    10,    11,    12,    13,     7,
       0,     8,     0,    16,     0,     0,     3,   133,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     7,     0,
       8,     9,    16,     0,     0,     3,   144,     0,     0,     0,
       7,     0,     8,    10,    11,    12,    13,     0,     0,    14,
      15,    16,     0,     0,     3,    10,    11,    12,    13,   145,
     146,     0,     7,    16,     8,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,    10,    11,    12,
      13,     0,   150,     0,     0,    16,     0,     0,     3,    10,
      11,    12,    13,     0,     0,     0,     0,    16,     0,     0,
       3
};

static const yytype_int16 yycheck[] =
{
       5,    26,     5,    18,    18,    25,    16,     4,     3,    55,
      44,     6,     7,    18,    15,    18,     3,    39,    40,     6,
       7,    26,     4,    26,     4,    35,    30,    37,    38,    27,
      55,    39,    36,    43,     0,    32,    82,    32,    33,    29,
      22,    23,    22,    23,    59,    40,    33,    32,    28,    34,
      55,    59,    55,    40,    59,    33,    59,    41,    42,    43,
      70,     3,    72,    97,    98,    99,    33,    27,    82,    29,
      32,     4,    34,    29,     8,     9,    33,   102,    12,    13,
      33,    33,    95,    96,    29,   105,   101,   101,    29,   114,
      89,    90,    91,    92,    93,    94,   101,   102,   101,   102,
     115,    29,    33,    37,    38,    35,    14,   132,    30,   114,
     115,   114,   115,    29,    11,    10,   141,     3,     3,    32,
      32,    32,    32,   148,     6,    32,     4,   132,    31,   132,
     145,     1,     3,     3,     3,    29,   141,    29,   141,    29,
     145,    29,   145,   148,    31,   148,    16,    17,    18,    19,
       1,     1,     3,    29,    24,    14,   105,    27,    28,    88,
     111,    87,    71,    -1,    -1,    16,    17,    18,    19,     1,
      -1,     3,    -1,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,     1,    -1,
       3,     4,    24,    -1,    -1,    27,    28,    -1,    -1,    -1,
       1,    -1,     3,    16,    17,    18,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    27,    16,    17,    18,    19,    20,
      21,    -1,     1,    24,     3,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    24,    -1,    -1,    27,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    45,    27,    46,    47,     0,     1,     3,     4,
      16,    17,    18,    19,    22,    23,    24,    46,    49,    50,
      51,    52,    53,    54,    55,    56,    59,    60,    61,    62,
      63,    64,    29,    33,     3,    33,    33,    33,    33,    47,
       4,     6,     7,    33,    40,    61,    62,    67,    68,    69,
      70,    71,    72,    73,    50,    59,    29,    29,    29,    27,
      29,     4,    32,    51,    57,    58,    28,    48,    60,    29,
      30,    36,    35,    32,    65,    66,    67,    33,    67,    14,
      67,    67,    49,    30,    67,    73,    29,    11,    10,     8,
       9,    12,    13,    37,    38,    39,    40,    41,    42,    43,
      48,    49,    59,     3,    32,    34,    67,     3,    63,    67,
      32,    34,    32,    32,    32,    32,    48,     6,    32,    69,
      70,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    59,    28,    58,    31,    29,    66,    29,    29,
      60,    59,     3,    31,    28,    20,    21,     3,    59,    29,
      21,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    48,    49,    49,    50,
      50,    50,    50,    51,    52,    53,    54,    54,    54,    55,
      55,    56,    57,    57,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    62,    63,    64,    65,    65,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     5,     6,     2,     5,     4,     3,
       2,     3,     3,     1,     1,     2,     1,     7,     9,     5,
       5,     5,     4,     2,     1,     3,     2,     4,     3,     3,
       4,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     2,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM block  */
#line 135 "lang.y"
                                { (yyval.program_node) = new cProgramNode((yyvsp[0].block_node));
                                  yyast_root = (yyval.program_node);
                                  // Even if semantic errors were detected during parsing,
                                  // continue so later phases (Lab 5B/6 visitors) can run and
                                  // report additional errors. Some test cases expect this.
                                  YYACCEPT;
                                }
#line 1388 "langparse.c"
    break;

  case 3: /* block: open decls stmts close  */
#line 143 "lang.y"
                                { (yyval.block_node) = new cBlockNode((yyvsp[-2].decls_node), (yyvsp[-1].stmts_node)); }
#line 1394 "langparse.c"
    break;

  case 4: /* block: open stmts close  */
#line 145 "lang.y"
                                { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[-1].stmts_node)); }
#line 1400 "langparse.c"
    break;

  case 5: /* open: '{'  */
#line 148 "lang.y"
                                { /* $$ = g_SymbolTable.IncreaseScope(); */ }
#line 1406 "langparse.c"
    break;

  case 6: /* close: '}'  */
#line 151 "lang.y"
                                { /* $$ = g_SymbolTable.DecreaseScope(); */ }
#line 1412 "langparse.c"
    break;

  case 7: /* decls: decls decl  */
#line 154 "lang.y"
                                { (yyvsp[-1].decls_node)->Insert((yyvsp[0].decl_node)); (yyval.decls_node) = (yyvsp[-1].decls_node); }
#line 1418 "langparse.c"
    break;

  case 8: /* decls: decl  */
#line 156 "lang.y"
                                { (yyval.decls_node) = new cDeclsNode((yyvsp[0].decl_node)); }
#line 1424 "langparse.c"
    break;

  case 9: /* decl: var_decl ';'  */
#line 158 "lang.y"
                                { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1430 "langparse.c"
    break;

  case 10: /* decl: array_decl ';'  */
#line 160 "lang.y"
                            { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1436 "langparse.c"
    break;

  case 11: /* decl: struct_decl ';'  */
#line 162 "lang.y"
                            { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1442 "langparse.c"
    break;

  case 12: /* decl: func_decl  */
#line 164 "lang.y"
                            { (yyval.decl_node) = (yyvsp[0].func_node); }
#line 1448 "langparse.c"
    break;

  case 13: /* var_decl: TYPE_ID IDENTIFIER  */
#line 167 "lang.y"
                                    { 
                                        cSymbol *idTok = (yyvsp[0].symbol);
                                        cSymbol *existing = g_symbolTable.FindLocal(idTok->GetName());

                                        cSymbol *id = existing;
                                        if (existing == nullptr)
                                        {
                                            // Create a new symbol for this scope (supports shadowing).
                                            id = new cSymbol(idTok->GetName());
                                            g_symbolTable.Insert(id);
                                        }
                                        else if (existing->GetDecl() != nullptr)
                                        {
                                            SemanticParseError("Symbol " + idTok->GetName() + " already defined in current scope");
                                            CHECK_ERROR();
                                        }

                                        (yyval.decl_node) = new cVarDeclNode((yyvsp[-1].symbol), id);
                                    }
#line 1472 "langparse.c"
    break;

  case 14: /* struct_decl: STRUCT open decls close IDENTIFIER  */
#line 187 "lang.y"
    {
        cSymbol *nameTok = (yyvsp[0].symbol);
        cSymbol *existing = g_symbolTable.FindLocal(nameTok->GetName());

        cSymbol *typeSym = existing;
        if (existing == nullptr)
        {
            typeSym = new cSymbol(nameTok->GetName());
            g_symbolTable.Insert(typeSym);
            (yyval.decl_node) = new cStructDeclNode((yyvsp[-2].decls_node), typeSym);
        }
        else if (existing->GetDecl() != nullptr)
        {
            // Don't declare as a type if it conflicts; otherwise lexer will
            // tokenize later uses as TYPE_ID and cause syntax errors.
            SemanticParseError("Symbol " + nameTok->GetName() + " already defined in current scope");
            CHECK_ERROR();
            (yyval.decl_node) = new cStructDeclNode((yyvsp[-2].decls_node), typeSym);
        }
        else
        {
            // Placeholder symbol (created by lexer). This is the first real
            // definition in this scope.
            (yyval.decl_node) = new cStructDeclNode((yyvsp[-2].decls_node), typeSym);
        }
    }
#line 1503 "langparse.c"
    break;

  case 15: /* array_decl: ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER  */
#line 215 "lang.y"
    {
        cSymbol *nameTok = (yyvsp[0].symbol);
        cSymbol *existing = g_symbolTable.FindLocal(nameTok->GetName());

        cSymbol *newTypeSym = existing;
        if (existing == nullptr)
        {
            newTypeSym = new cSymbol(nameTok->GetName());
            g_symbolTable.Insert(newTypeSym);
            (yyval.decl_node) = new cArrayDeclNode((yyvsp[-2].int_val), (yyvsp[-4].symbol), newTypeSym);  // count, base type, new type name
        }
        else if (existing->GetDecl() != nullptr)
        {
            SemanticParseError("Symbol " + nameTok->GetName() + " already defined in current scope");
            CHECK_ERROR();
            // Still build a node so later processing doesn't crash.
            (yyval.decl_node) = new cArrayDeclNode((yyvsp[-2].int_val), (yyvsp[-4].symbol), newTypeSym);
        }
        else
        {
            // Placeholder symbol (created by lexer). First real definition.
            (yyval.decl_node) = new cArrayDeclNode((yyvsp[-2].int_val), (yyvsp[-4].symbol), newTypeSym);
        }
    }
#line 1532 "langparse.c"
    break;

  case 16: /* func_decl: func_header ';'  */
#line 241 "lang.y"
                                { (yyval.func_node) = (yyvsp[-1].func_node); g_symbolTable.DecreaseScope(); }
#line 1538 "langparse.c"
    break;

  case 17: /* func_decl: func_header '{' decls stmts '}'  */
#line 243 "lang.y"
        {
            cSymbol *sem = (yyvsp[-4].func_node)->GetSemanticSym();
            cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
            if (canon != nullptr && canon->HasDefinition())
            {
                SemanticParseError(sem->GetName() + " already has a definition");
                CHECK_ERROR();
            }

            if (canon == nullptr || !canon->HasDefinition())
            {
                (yyvsp[-4].func_node)->SetDecls((yyvsp[-2].decls_node));
                (yyvsp[-4].func_node)->SetStmts((yyvsp[-1].stmts_node));
                if (sem != nullptr) sem->SetDecl((yyvsp[-4].func_node));
            }
            (yyval.func_node) = (yyvsp[-4].func_node);
            g_symbolTable.DecreaseScope();
        }
#line 1561 "langparse.c"
    break;

  case 18: /* func_decl: func_header '{' stmts '}'  */
#line 262 "lang.y"
        {
            cSymbol *sem = (yyvsp[-3].func_node)->GetSemanticSym();
            cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
            if (canon != nullptr && canon->HasDefinition())
            {
                SemanticParseError(sem->GetName() + " already has a definition");
                CHECK_ERROR();
            }

            if (canon == nullptr || !canon->HasDefinition())
            {
                (yyvsp[-3].func_node)->SetStmts((yyvsp[-1].stmts_node));
                if (sem != nullptr) sem->SetDecl((yyvsp[-3].func_node));
            }
            (yyval.func_node) = (yyvsp[-3].func_node);
            g_symbolTable.DecreaseScope();
        }
#line 1583 "langparse.c"
    break;

  case 19: /* func_header: func_prefix paramsspec ')'  */
#line 282 "lang.y"
                                {
                                    (yyvsp[-2].func_node)->SetArgs((yyvsp[-1].args_node));
                                    cSymbol *sem = (yyvsp[-2].func_node)->GetSemanticSym();
                                    cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
                                    if (canon != nullptr && canon != (yyvsp[-2].func_node))
                                    {
                                        if (canon->GetParamCount() != (yyvsp[-2].func_node)->GetParamCount())
                                        {
                                            SemanticParseError(sem->GetName() + " redeclared with a different number of parameters");
                                            CHECK_ERROR();
                                        }
                                        else
                                        {
                                            // Same number of parameters: ensure the parameter types match.
                                            cArgsNode *a1 = canon->GetArgsNode();
                                            cArgsNode *a2 = (yyvsp[-2].func_node)->GetArgsNode();
                                            bool mismatch = false;
                                            for (int i = 0; i < canon->GetParamCount(); i++)
                                            {
                                                cVarDeclNode *v1 = (a1 != nullptr) ? dynamic_cast<cVarDeclNode*>(a1->GetArg(i)) : nullptr;
                                                cVarDeclNode *v2 = (a2 != nullptr) ? dynamic_cast<cVarDeclNode*>(a2->GetArg(i)) : nullptr;
                                                cSymbol *t1 = (v1 != nullptr) ? v1->GetTypeSym() : nullptr;
                                                cSymbol *t2 = (v2 != nullptr) ? v2->GetTypeSym() : nullptr;
                                                if (t1 == nullptr || t2 == nullptr) continue;
                                                if (t1->GetName() != t2->GetName()) { mismatch = true; break; }
                                            }
                                            if (mismatch)
                                            {
                                                SemanticParseError(sem->GetName() + " previously defined with different parameters");
                                                CHECK_ERROR();
                                            }
                                        }
                                    }
                                    (yyval.func_node) = (yyvsp[-2].func_node);
                                }
#line 1623 "langparse.c"
    break;

  case 20: /* func_header: func_prefix ')'  */
#line 318 "lang.y"
                                {
                                    (yyvsp[-1].func_node)->SetArgs(nullptr);
                                    cSymbol *sem = (yyvsp[-1].func_node)->GetSemanticSym();
                                    cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
                                    if (canon != nullptr && canon != (yyvsp[-1].func_node) && canon->GetParamCount() != (yyvsp[-1].func_node)->GetParamCount())
                                    {
                                        SemanticParseError(sem->GetName() + " redeclared with a different number of parameters");
                                        CHECK_ERROR();
                                    }
                                    (yyval.func_node) = (yyvsp[-1].func_node);
                                }
#line 1639 "langparse.c"
    break;

  case 21: /* func_prefix: TYPE_ID IDENTIFIER '('  */
#line 332 "lang.y"
{
    cSymbol *nameTok = (yyvsp[-1].symbol);

    // Semantic symbol: represents the function in the current scope.
    cSymbol *localSym = g_symbolTable.FindLocal(nameTok->GetName());
    cSymbol *semSym = localSym;
    if (semSym == nullptr)
    {
        semSym = new cSymbol(nameTok->GetName());
        g_symbolTable.Insert(semSym);
    }

    // Printed symbol: use outer-most match to reproduce expected XML in
    // shadowing scenarios (see test4b).
    cSymbol *printSym = g_symbolTable.FindOuter(nameTok->GetName());
    if (printSym == nullptr) printSym = nameTok;

    cFuncDeclNode *prevFunc = nullptr;
    if (semSym->GetDecl() != nullptr)
        prevFunc = dynamic_cast<cFuncDeclNode*>(semSym->GetDecl());

    // Conflict with a non-function in the same scope.
    if (semSym->GetDecl() != nullptr && prevFunc == nullptr)
    {
        SemanticParseError(nameTok->GetName() + " previously defined as other than a function");
        CHECK_ERROR();
    }

    // Return type must match previous declarations/definitions.
    if (prevFunc != nullptr)
    {
        cSymbol *prevRet = prevFunc->GetReturnSym();
        if (prevRet != nullptr && (yyvsp[-2].symbol) != nullptr && prevRet->GetName() != (yyvsp[-2].symbol)->GetName())
        {
            SemanticParseError(nameTok->GetName() + " previously defined with different return type");
            CHECK_ERROR();
        }
    }

    // If there is already a definition, later prototypes should reuse it.
    // Always create a node for this appearance so we can validate and report
    // mismatches (e.g., a prototype after a definition).
    (yyval.func_node) = new cFuncDeclNode((yyvsp[-2].symbol), printSym, semSym);

    // Only set the semantic symbol if this is the first declaration in scope.
    // Otherwise keep the existing canonical declaration/definition.
    if (semSym->GetDecl() == nullptr) semSym->SetDecl((yyval.func_node));

    // parameter scope (so params don't reuse global 'a')
    g_symbolTable.IncreaseScope();
}
#line 1695 "langparse.c"
    break;

  case 22: /* paramsspec: paramsspec ',' paramspec  */
#line 387 "lang.y"
        { (yyvsp[-2].args_node)->Insert((yyvsp[0].decl_node)); (yyval.args_node) = (yyvsp[-2].args_node); }
#line 1701 "langparse.c"
    break;

  case 23: /* paramsspec: paramspec  */
#line 389 "lang.y"
        { (yyval.args_node) = new cArgsNode((yyvsp[0].decl_node)); }
#line 1707 "langparse.c"
    break;

  case 24: /* paramspec: var_decl  */
#line 392 "lang.y"
                    { (yyval.decl_node) = (yyvsp[0].decl_node); }
#line 1713 "langparse.c"
    break;

  case 25: /* stmts: stmts stmt  */
#line 395 "lang.y"
                                { (yyvsp[-1].stmts_node)->Insert((yyvsp[0].stmt_node)); (yyval.stmts_node) = (yyvsp[-1].stmts_node); }
#line 1719 "langparse.c"
    break;

  case 26: /* stmts: stmt  */
#line 397 "lang.y"
                            { (yyval.stmts_node) = new cStmtsNode((yyvsp[0].stmt_node)); }
#line 1725 "langparse.c"
    break;

  case 27: /* stmt: IF '(' expr ')' stmts ENDIF ';'  */
#line 400 "lang.y"
                                { (yyval.stmt_node) = new cIfNode((yyvsp[-4].expr_node), (yyvsp[-2].stmts_node), nullptr); }
#line 1731 "langparse.c"
    break;

  case 28: /* stmt: IF '(' expr ')' stmts ELSE stmts ENDIF ';'  */
#line 402 "lang.y"
                                { (yyval.stmt_node) = new cIfNode((yyvsp[-6].expr_node), (yyvsp[-4].stmts_node), (yyvsp[-2].stmts_node)); }
#line 1737 "langparse.c"
    break;

  case 29: /* stmt: WHILE '(' expr ')' stmt  */
#line 404 "lang.y"
                                { (yyval.stmt_node) = new cWhileNode((yyvsp[-2].expr_node), (yyvsp[0].stmt_node));  }
#line 1743 "langparse.c"
    break;

  case 30: /* stmt: PRINT '(' expr ')' ';'  */
#line 406 "lang.y"
                                { (yyval.stmt_node) = new cPrintNode((yyvsp[-2].expr_node)); }
#line 1749 "langparse.c"
    break;

  case 31: /* stmt: PRINTS '(' STRING_LIT ')' ';'  */
#line 408 "lang.y"
                                { (yyval.stmt_node) = new cPrintsNode(*(yyvsp[-2].str_val)); delete (yyvsp[-2].str_val); }
#line 1755 "langparse.c"
    break;

  case 32: /* stmt: lval '=' expr ';'  */
#line 410 "lang.y"
                            { (yyval.stmt_node) = new cAssignNode((yyvsp[-3].expr_node), (yyvsp[-1].expr_node)); }
#line 1761 "langparse.c"
    break;

  case 33: /* stmt: func_call ';'  */
#line 412 "lang.y"
                            { (yyval.stmt_node) = (yyvsp[-1].expr_node); }
#line 1767 "langparse.c"
    break;

  case 34: /* stmt: block  */
#line 414 "lang.y"
                            { (yyval.stmt_node) = (yyvsp[0].block_node); }
#line 1773 "langparse.c"
    break;

  case 35: /* stmt: RETURN expr ';'  */
#line 416 "lang.y"
                            { (yyval.stmt_node) = new cReturnNode((yyvsp[-1].expr_node)); }
#line 1779 "langparse.c"
    break;

  case 36: /* stmt: error ';'  */
#line 418 "lang.y"
                            {}
#line 1785 "langparse.c"
    break;

  case 37: /* func_call: IDENTIFIER '(' params ')'  */
#line 422 "lang.y"
    { (yyval.expr_node) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].params_node)); CHECK_ERROR(); }
#line 1791 "langparse.c"
    break;

  case 38: /* func_call: IDENTIFIER '(' ')'  */
#line 424 "lang.y"
    { (yyval.expr_node) = new cFuncCallNode((yyvsp[-2].symbol), nullptr); CHECK_ERROR(); }
#line 1797 "langparse.c"
    break;

  case 39: /* varref: varref '.' varpart  */
#line 429 "lang.y"
    { ((cVarRefNode*)(yyvsp[-2].expr_node))->AddField((yyvsp[0].symbol)); (yyval.expr_node) = (yyvsp[-2].expr_node); }
#line 1803 "langparse.c"
    break;

  case 40: /* varref: varref '[' expr ']'  */
#line 431 "lang.y"
    { ((cVarRefNode*)(yyvsp[-3].expr_node))->AddIndex((yyvsp[-1].expr_node)); (yyval.expr_node) = (yyvsp[-3].expr_node); }
#line 1809 "langparse.c"
    break;

  case 41: /* varref: varpart  */
#line 433 "lang.y"
        { (yyval.expr_node) = new cVarRefNode((yyvsp[0].symbol)); CHECK_ERROR(); }
#line 1815 "langparse.c"
    break;

  case 42: /* varpart: IDENTIFIER  */
#line 436 "lang.y"
                                { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1821 "langparse.c"
    break;

  case 43: /* lval: varref  */
#line 439 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1827 "langparse.c"
    break;

  case 44: /* params: params ',' param  */
#line 443 "lang.y"
                                { (yyvsp[-2].params_node)->Insert((yyvsp[0].expr_node)); (yyval.params_node) = (yyvsp[-2].params_node); }
#line 1833 "langparse.c"
    break;

  case 45: /* params: param  */
#line 445 "lang.y"
                            { (yyval.params_node) = new cParamsNode((yyvsp[0].expr_node)); }
#line 1839 "langparse.c"
    break;

  case 46: /* param: expr  */
#line 449 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1845 "langparse.c"
    break;

  case 47: /* expr: or_expr  */
#line 453 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1851 "langparse.c"
    break;

  case 48: /* or_expr: or_expr OR and_expr  */
#line 456 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), OR, (yyvsp[0].expr_node)); }
#line 1857 "langparse.c"
    break;

  case 49: /* or_expr: and_expr  */
#line 458 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1863 "langparse.c"
    break;

  case 50: /* and_expr: and_expr AND rel_expr  */
#line 461 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), AND, (yyvsp[0].expr_node)); }
#line 1869 "langparse.c"
    break;

  case 51: /* and_expr: rel_expr  */
#line 463 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1875 "langparse.c"
    break;

  case 52: /* rel_expr: rel_expr '>' addit  */
#line 466 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '>', (yyvsp[0].expr_node)); }
#line 1881 "langparse.c"
    break;

  case 53: /* rel_expr: rel_expr '<' addit  */
#line 468 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '<', (yyvsp[0].expr_node)); }
#line 1887 "langparse.c"
    break;

  case 54: /* rel_expr: rel_expr GE addit  */
#line 470 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), GE, (yyvsp[0].expr_node)); }
#line 1893 "langparse.c"
    break;

  case 55: /* rel_expr: rel_expr LE addit  */
#line 472 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), LE, (yyvsp[0].expr_node)); }
#line 1899 "langparse.c"
    break;

  case 56: /* rel_expr: rel_expr EQUALS addit  */
#line 474 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), EQUALS, (yyvsp[0].expr_node)); }
#line 1905 "langparse.c"
    break;

  case 57: /* rel_expr: rel_expr NOT_EQUALS addit  */
#line 476 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), NOT_EQUALS, (yyvsp[0].expr_node)); }
#line 1911 "langparse.c"
    break;

  case 58: /* rel_expr: addit  */
#line 478 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1917 "langparse.c"
    break;

  case 59: /* addit: addit '+' term  */
#line 481 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '+', (yyvsp[0].expr_node)); }
#line 1923 "langparse.c"
    break;

  case 60: /* addit: addit '-' term  */
#line 483 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '-', (yyvsp[0].expr_node)); }
#line 1929 "langparse.c"
    break;

  case 61: /* addit: term  */
#line 485 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1935 "langparse.c"
    break;

  case 62: /* term: term '*' fact  */
#line 488 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '*', (yyvsp[0].expr_node)); }
#line 1941 "langparse.c"
    break;

  case 63: /* term: term '/' fact  */
#line 490 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '/', (yyvsp[0].expr_node)); }
#line 1947 "langparse.c"
    break;

  case 64: /* term: term '%' fact  */
#line 492 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '%', (yyvsp[0].expr_node)); }
#line 1953 "langparse.c"
    break;

  case 65: /* term: fact  */
#line 494 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1959 "langparse.c"
    break;

  case 66: /* fact: '(' expr ')'  */
#line 497 "lang.y"
                                { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 1965 "langparse.c"
    break;

  case 67: /* fact: '-' fact  */
#line 499 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode(new cIntExprNode(0), '-', (yyvsp[0].expr_node)); }
#line 1971 "langparse.c"
    break;

  case 68: /* fact: INT_VAL  */
#line 501 "lang.y"
                            { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1977 "langparse.c"
    break;

  case 69: /* fact: FLOAT_VAL  */
#line 503 "lang.y"
                            { (yyval.expr_node) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1983 "langparse.c"
    break;

  case 70: /* fact: varref  */
#line 505 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1989 "langparse.c"
    break;

  case 71: /* fact: func_call  */
#line 507 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1995 "langparse.c"
    break;


#line 1999 "langparse.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 510 "lang.y"


// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticParseError(std::string error)
{
    g_semanticErrors.push_back({yylineno, ++g_semanticErrorSeq, error});
    g_semanticErrorHappened = true;
    yynerrs++;
}
