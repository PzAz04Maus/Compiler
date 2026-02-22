/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '['  */
  YYSYMBOL_30_ = 30,                       /* ']'  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_block = 43,                     /* block  */
  YYSYMBOL_open = 44,                      /* open  */
  YYSYMBOL_close = 45,                     /* close  */
  YYSYMBOL_decls = 46,                     /* decls  */
  YYSYMBOL_decl = 47,                      /* decl  */
  YYSYMBOL_var_decl = 48,                  /* var_decl  */
  YYSYMBOL_struct_decl = 49,               /* struct_decl  */
  YYSYMBOL_array_decl = 50,                /* array_decl  */
  YYSYMBOL_func_decl = 51,                 /* func_decl  */
  YYSYMBOL_func_header = 52,               /* func_header  */
  YYSYMBOL_func_prefix = 53,               /* func_prefix  */
  YYSYMBOL_paramsspec = 54,                /* paramsspec  */
  YYSYMBOL_paramspec = 55,                 /* paramspec  */
  YYSYMBOL_stmts = 56,                     /* stmts  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_func_call = 58,                 /* func_call  */
  YYSYMBOL_varref = 59,                    /* varref  */
  YYSYMBOL_varpart = 60,                   /* varpart  */
  YYSYMBOL_lval = 61,                      /* lval  */
  YYSYMBOL_params = 62,                    /* params  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_addit = 65,                     /* addit  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_fact = 67                       /* fact  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 69 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;
    

#line 204 "langparse.c"


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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      32,    31,    38,    36,    33,    37,    35,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   129,   129,   137,   139,   142,   145,   148,   150,   152,
     154,   156,   158,   161,   181,   209,   235,   237,   253,   270,
     282,   296,   353,   355,   359,   361,   363,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   388,   390,   395,
     397,   399,   402,   405,   409,   411,   415,   419,   421,   424,
     426,   428,   431,   433,   435,   437,   440,   442,   444,   446,
     448
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
  "JUNK_TOKEN", "'{'", "'}'", "';'", "'['", "']'", "')'", "'('", "','",
  "'='", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
  "block", "open", "close", "decls", "decl", "var_decl", "struct_decl",
  "array_decl", "func_decl", "func_header", "func_prefix", "paramsspec",
  "paramspec", "stmts", "stmt", "func_call", "varref", "varpart", "lval",
  "params", "param", "expr", "addit", "term", "fact", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -22,     9,   -30,   -30,   146,   -30,    14,    32,    80,
      58,    60,    69,    71,   -22,   109,    11,   -30,   146,   -30,
      97,   101,   102,   -30,    28,    16,    88,   -30,   112,    30,
     -30,   110,   -30,     5,   116,    11,   137,    11,    11,    12,
     123,   -30,   -30,    11,   -30,    30,    39,    91,    56,   -30,
     -30,    88,   -30,   -30,   -30,   146,   -30,   150,   -30,   -30,
      35,   -30,   -30,   -30,   -30,   -30,    11,   151,    11,   -30,
      40,   -30,   143,   -30,     7,   125,    13,    27,     6,   153,
      29,    11,   -30,    11,    11,    11,    11,    11,   -30,   146,
     115,   -30,   -30,   162,    33,   -30,   -30,    41,   -30,    11,
     129,   133,   190,   190,   164,   141,   -30,    91,    56,    56,
     -30,   -30,   -30,   119,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   157,   -30,   176,   -30,   190,   156,   -30,   179,
     -30,   158,   -30
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
       0,    57,    58,     0,    60,    59,     0,    48,    51,    55,
       7,     0,     9,    11,    10,     0,    16,     0,    20,    24,
       0,    23,     6,     4,    25,    33,     0,     0,     0,    38,
       0,    45,    46,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     3,     0,
       0,    13,    19,     0,     0,    42,    39,     0,    37,     0,
       0,     0,     0,     0,     0,     0,    56,    47,    49,    50,
      52,    53,    54,     0,    18,    22,    40,    32,    44,    30,
      31,    29,     0,    14,     0,    17,     0,     0,    15,     0,
      27,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -30,   -30,   184,   173,   -29,    23,   -17,   -18,   -30,   -30,
     -30,   -30,   -30,   -30,    95,   -15,   -20,    -5,    -3,   122,
     -30,   -30,    93,   -11,   113,    -7,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    17,     5,    63,    18,    19,    20,    21,    22,
      23,    24,    25,    60,    61,    26,    27,    44,    45,    30,
      31,    70,    71,    72,    47,    48,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    50,    29,    51,     3,    46,    64,    59,     8,     6,
       9,    41,    42,    28,     8,    29,     9,    41,    42,    81,
      57,    28,    88,    29,    74,    81,    76,    77,    14,    15,
       1,    64,    80,    62,    14,    15,    69,    43,   100,    81,
      90,    81,    32,    43,   102,    81,    28,    58,    29,   104,
      28,    81,    29,    81,    55,    94,    56,    97,   103,    66,
     106,    50,    78,   116,    33,    67,    92,    82,    93,   117,
      64,    98,    50,    99,   113,    59,   108,   109,    89,   110,
     111,   112,   121,    34,    28,    28,    29,    29,   122,     7,
      35,     8,    36,    64,    85,    86,    87,    28,    28,    29,
      29,    37,    64,    38,    10,    11,    12,    13,    28,    64,
      29,   129,    16,    40,     3,    62,     7,    28,     8,    29,
       7,    28,     8,    29,    28,    52,    29,    83,    84,    53,
      54,    10,    11,    12,    13,    10,    11,    12,    13,    16,
      65,     3,   114,    16,    68,     3,   125,     7,    73,     8,
       9,    75,    79,    91,    95,    81,   101,   119,     7,   105,
       8,   120,    10,    11,    12,    13,    57,   123,    14,    15,
      16,   124,     3,    10,    11,    12,    13,   126,   127,   128,
       7,    16,     8,     3,   130,     4,   132,    39,   115,    96,
       0,     7,   118,     8,   107,    10,    11,    12,    13,     0,
     131,     0,     0,    16,     0,     3,    10,    11,    12,    13,
       0,     0,     0,     0,    16,     0,     3
};

static const yytype_int16 yycheck[] =
{
       5,    18,     5,    18,    26,    16,    26,    25,     3,     0,
       4,     6,     7,    18,     3,    18,     4,     6,     7,    12,
       4,    26,    51,    26,    35,    12,    37,    38,    22,    23,
      15,    51,    43,    27,    22,    23,    31,    32,    31,    12,
      55,    12,    28,    32,    31,    12,    51,    31,    51,    78,
      55,    12,    55,    12,    26,    66,    28,    68,    31,    29,
      31,    78,    39,    30,    32,    35,    31,    28,    33,    28,
      90,    31,    89,    33,    89,    93,    83,    84,    55,    85,
      86,    87,   102,     3,    89,    90,    89,    90,   103,     1,
      32,     3,    32,   113,    38,    39,    40,   102,   103,   102,
     103,    32,   122,    32,    16,    17,    18,    19,   113,   129,
     113,   126,    24,     4,    26,    27,     1,   122,     3,   122,
       1,   126,     3,   126,   129,    28,   129,    36,    37,    28,
      28,    16,    17,    18,    19,    16,    17,    18,    19,    24,
      28,    26,    27,    24,    34,    26,    27,     1,    32,     3,
       4,    14,    29,     3,     3,    12,    31,    28,     1,     6,
       3,    28,    16,    17,    18,    19,     4,     3,    22,    23,
      24,    30,    26,    16,    17,    18,    19,    20,    21,     3,
       1,    24,     3,    26,    28,     1,    28,    14,    93,    67,
      -1,     1,    99,     3,    81,    16,    17,    18,    19,    -1,
      21,    -1,    -1,    24,    -1,    26,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    24,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    42,    26,    43,    44,     0,     1,     3,     4,
      16,    17,    18,    19,    22,    23,    24,    43,    46,    47,
      48,    49,    50,    51,    52,    53,    56,    57,    58,    59,
      60,    61,    28,    32,     3,    32,    32,    32,    32,    44,
       4,     6,     7,    32,    58,    59,    64,    65,    66,    67,
      47,    56,    28,    28,    28,    26,    28,     4,    31,    48,
      54,    55,    27,    45,    57,    28,    29,    35,    34,    31,
      62,    63,    64,    32,    64,    14,    64,    64,    46,    29,
      64,    12,    28,    36,    37,    38,    39,    40,    45,    46,
      56,     3,    31,    33,    64,     3,    60,    64,    31,    33,
      31,    31,    31,    31,    45,     6,    31,    65,    66,    66,
      67,    67,    67,    56,    27,    55,    30,    28,    63,    28,
      28,    57,    56,     3,    30,    27,    20,    21,     3,    56,
      28,    21,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    46,    46,    47,
      47,    47,    47,    48,    49,    50,    51,    51,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     5,     6,     2,     5,     4,     3,
       2,     3,     3,     1,     1,     2,     1,     7,     9,     5,
       5,     5,     4,     2,     1,     3,     2,     4,     3,     3,
       4,     1,     1,     1,     3,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


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
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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

  YYLOCATION_PRINT (yyo, yylocationp);
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
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
#line 130 "lang.y"
                                { (yyval.program_node) = new cProgramNode((yyvsp[0].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1381 "langparse.c"
    break;

  case 3: /* block: open decls stmts close  */
#line 138 "lang.y"
                                { (yyval.block_node) = new cBlockNode((yyvsp[-2].decls_node), (yyvsp[-1].stmts_node)); }
#line 1387 "langparse.c"
    break;

  case 4: /* block: open stmts close  */
#line 140 "lang.y"
                                { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[-1].stmts_node)); }
#line 1393 "langparse.c"
    break;

  case 5: /* open: '{'  */
#line 143 "lang.y"
                                { /* $$ = g_SymbolTable.IncreaseScope(); */ }
#line 1399 "langparse.c"
    break;

  case 6: /* close: '}'  */
#line 146 "lang.y"
                                { /* $$ = g_SymbolTable.DecreaseScope(); */ }
#line 1405 "langparse.c"
    break;

  case 7: /* decls: decls decl  */
#line 149 "lang.y"
                                { (yyvsp[-1].decls_node)->Insert((yyvsp[0].decl_node)); (yyval.decls_node) = (yyvsp[-1].decls_node); }
#line 1411 "langparse.c"
    break;

  case 8: /* decls: decl  */
#line 151 "lang.y"
                                { (yyval.decls_node) = new cDeclsNode((yyvsp[0].decl_node)); }
#line 1417 "langparse.c"
    break;

  case 9: /* decl: var_decl ';'  */
#line 153 "lang.y"
                                { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1423 "langparse.c"
    break;

  case 10: /* decl: array_decl ';'  */
#line 155 "lang.y"
                            { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1429 "langparse.c"
    break;

  case 11: /* decl: struct_decl ';'  */
#line 157 "lang.y"
                            { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1435 "langparse.c"
    break;

  case 12: /* decl: func_decl  */
#line 159 "lang.y"
                            { (yyval.decl_node) = (yyvsp[0].func_node); }
#line 1441 "langparse.c"
    break;

  case 13: /* var_decl: TYPE_ID IDENTIFIER  */
#line 162 "lang.y"
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
#line 1465 "langparse.c"
    break;

  case 14: /* struct_decl: STRUCT open decls close IDENTIFIER  */
#line 182 "lang.y"
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
#line 1496 "langparse.c"
    break;

  case 15: /* array_decl: ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER  */
#line 210 "lang.y"
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
#line 1525 "langparse.c"
    break;

  case 16: /* func_decl: func_header ';'  */
#line 236 "lang.y"
                                { (yyval.func_node) = (yyvsp[-1].func_node); g_symbolTable.DecreaseScope(); }
#line 1531 "langparse.c"
    break;

  case 17: /* func_decl: func_header '{' decls stmts '}'  */
#line 238 "lang.y"
        {
            cSymbol *sem = (yyvsp[-4].func_node)->GetSemanticSym();
            cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
            if (canon != nullptr && canon != (yyvsp[-4].func_node) && canon->HasDefinition())
            {
                SemanticParseError(sem->GetName() + " already has a definition");
                CHECK_ERROR();
            }

            (yyvsp[-4].func_node)->SetDecls((yyvsp[-2].decls_node));
            (yyvsp[-4].func_node)->SetStmts((yyvsp[-1].stmts_node));
            if (sem != nullptr) sem->SetDecl((yyvsp[-4].func_node));
            (yyval.func_node) = (yyvsp[-4].func_node);
            g_symbolTable.DecreaseScope();
        }
#line 1551 "langparse.c"
    break;

  case 18: /* func_decl: func_header '{' stmts '}'  */
#line 254 "lang.y"
        {
            cSymbol *sem = (yyvsp[-3].func_node)->GetSemanticSym();
            cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
            if (canon != nullptr && canon != (yyvsp[-3].func_node) && canon->HasDefinition())
            {
                SemanticParseError(sem->GetName() + " already has a definition");
                CHECK_ERROR();
            }

            (yyvsp[-3].func_node)->SetStmts((yyvsp[-1].stmts_node));
            if (sem != nullptr) sem->SetDecl((yyvsp[-3].func_node));
            (yyval.func_node) = (yyvsp[-3].func_node);
            g_symbolTable.DecreaseScope();
        }
#line 1570 "langparse.c"
    break;

  case 19: /* func_header: func_prefix paramsspec ')'  */
#line 271 "lang.y"
                                {
                                    (yyvsp[-2].func_node)->SetArgs((yyvsp[-1].args_node));
                                    cSymbol *sem = (yyvsp[-2].func_node)->GetSemanticSym();
                                    cFuncDeclNode *canon = (sem != nullptr) ? dynamic_cast<cFuncDeclNode*>(sem->GetDecl()) : nullptr;
                                    if (canon != nullptr && canon != (yyvsp[-2].func_node) && canon->GetParamCount() != (yyvsp[-2].func_node)->GetParamCount())
                                    {
                                        SemanticParseError(sem->GetName() + " redeclared with a different number of parameters");
                                        CHECK_ERROR();
                                    }
                                    (yyval.func_node) = (yyvsp[-2].func_node);
                                }
#line 1586 "langparse.c"
    break;

  case 20: /* func_header: func_prefix ')'  */
#line 283 "lang.y"
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
#line 1602 "langparse.c"
    break;

  case 21: /* func_prefix: TYPE_ID IDENTIFIER '('  */
#line 297 "lang.y"
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
        SemanticParseError("Symbol " + nameTok->GetName() + " already defined in current scope");
        CHECK_ERROR();
    }

    // Return type must match previous declarations/definitions.
    if (prevFunc != nullptr)
    {
        cSymbol *prevRet = prevFunc->GetReturnSym();
        if (prevRet != nullptr && (yyvsp[-2].symbol) != nullptr && prevRet->GetName() != (yyvsp[-2].symbol)->GetName())
        {
            SemanticParseError(nameTok->GetName() + " previously declared with different return type");
            CHECK_ERROR();
        }
    }

    // If there is already a definition, later prototypes should reuse it.
    if (prevFunc != nullptr && prevFunc->HasDefinition())
    {
        (yyval.func_node) = prevFunc;
    }
    else
    {
        (yyval.func_node) = new cFuncDeclNode((yyvsp[-2].symbol), printSym, semSym);
        if (semSym->GetDecl() == nullptr) semSym->SetDecl((yyval.func_node));
    }

    // parameter scope (so params don't reuse global 'a')
    g_symbolTable.IncreaseScope();
}
#line 1660 "langparse.c"
    break;

  case 22: /* paramsspec: paramsspec ',' paramspec  */
#line 354 "lang.y"
        { (yyvsp[-2].args_node)->Insert((yyvsp[0].decl_node)); (yyval.args_node) = (yyvsp[-2].args_node); }
#line 1666 "langparse.c"
    break;

  case 23: /* paramsspec: paramspec  */
#line 356 "lang.y"
        { (yyval.args_node) = new cArgsNode((yyvsp[0].decl_node)); }
#line 1672 "langparse.c"
    break;

  case 24: /* paramspec: var_decl  */
#line 359 "lang.y"
                    { (yyval.decl_node) = (yyvsp[0].decl_node); }
#line 1678 "langparse.c"
    break;

  case 25: /* stmts: stmts stmt  */
#line 362 "lang.y"
                                { (yyvsp[-1].stmts_node)->Insert((yyvsp[0].stmt_node)); (yyval.stmts_node) = (yyvsp[-1].stmts_node); }
#line 1684 "langparse.c"
    break;

  case 26: /* stmts: stmt  */
#line 364 "lang.y"
                            { (yyval.stmts_node) = new cStmtsNode((yyvsp[0].stmt_node)); }
#line 1690 "langparse.c"
    break;

  case 27: /* stmt: IF '(' expr ')' stmts ENDIF ';'  */
#line 367 "lang.y"
                                { (yyval.stmt_node) = new cIfNode((yyvsp[-4].expr_node), (yyvsp[-2].stmts_node), nullptr); }
#line 1696 "langparse.c"
    break;

  case 28: /* stmt: IF '(' expr ')' stmts ELSE stmts ENDIF ';'  */
#line 369 "lang.y"
                                { (yyval.stmt_node) = new cIfNode((yyvsp[-6].expr_node), (yyvsp[-4].stmts_node), (yyvsp[-2].stmts_node)); }
#line 1702 "langparse.c"
    break;

  case 29: /* stmt: WHILE '(' expr ')' stmt  */
#line 371 "lang.y"
                                { (yyval.stmt_node) = new cWhileNode((yyvsp[-2].expr_node), (yyvsp[0].stmt_node));  }
#line 1708 "langparse.c"
    break;

  case 30: /* stmt: PRINT '(' expr ')' ';'  */
#line 373 "lang.y"
                                { (yyval.stmt_node) = new cPrintNode((yyvsp[-2].expr_node)); }
#line 1714 "langparse.c"
    break;

  case 31: /* stmt: PRINTS '(' STRING_LIT ')' ';'  */
#line 375 "lang.y"
                                { (yyval.stmt_node) = new cPrintsNode(*(yyvsp[-2].str_val)); delete (yyvsp[-2].str_val); }
#line 1720 "langparse.c"
    break;

  case 32: /* stmt: lval '=' expr ';'  */
#line 377 "lang.y"
                            { (yyval.stmt_node) = new cAssignNode((yyvsp[-3].expr_node), (yyvsp[-1].expr_node)); }
#line 1726 "langparse.c"
    break;

  case 33: /* stmt: func_call ';'  */
#line 379 "lang.y"
                            { (yyval.stmt_node) = (yyvsp[-1].expr_node); }
#line 1732 "langparse.c"
    break;

  case 34: /* stmt: block  */
#line 381 "lang.y"
                            { (yyval.stmt_node) = (yyvsp[0].block_node); }
#line 1738 "langparse.c"
    break;

  case 35: /* stmt: RETURN expr ';'  */
#line 383 "lang.y"
                            { (yyval.stmt_node) = new cReturnNode((yyvsp[-1].expr_node)); }
#line 1744 "langparse.c"
    break;

  case 36: /* stmt: error ';'  */
#line 385 "lang.y"
                            {}
#line 1750 "langparse.c"
    break;

  case 37: /* func_call: IDENTIFIER '(' params ')'  */
#line 389 "lang.y"
    { (yyval.expr_node) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].params_node)); CHECK_ERROR(); }
#line 1756 "langparse.c"
    break;

  case 38: /* func_call: IDENTIFIER '(' ')'  */
#line 391 "lang.y"
    { (yyval.expr_node) = new cFuncCallNode((yyvsp[-2].symbol), nullptr); CHECK_ERROR(); }
#line 1762 "langparse.c"
    break;

  case 39: /* varref: varref '.' varpart  */
#line 396 "lang.y"
    { ((cVarRefNode*)(yyvsp[-2].expr_node))->AddField((yyvsp[0].symbol)); (yyval.expr_node) = (yyvsp[-2].expr_node); }
#line 1768 "langparse.c"
    break;

  case 40: /* varref: varref '[' expr ']'  */
#line 398 "lang.y"
    { ((cVarRefNode*)(yyvsp[-3].expr_node))->AddIndex((yyvsp[-1].expr_node)); (yyval.expr_node) = (yyvsp[-3].expr_node); }
#line 1774 "langparse.c"
    break;

  case 41: /* varref: varpart  */
#line 400 "lang.y"
        { (yyval.expr_node) = new cVarRefNode((yyvsp[0].symbol)); CHECK_ERROR(); }
#line 1780 "langparse.c"
    break;

  case 42: /* varpart: IDENTIFIER  */
#line 403 "lang.y"
                                { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1786 "langparse.c"
    break;

  case 43: /* lval: varref  */
#line 406 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1792 "langparse.c"
    break;

  case 44: /* params: params ',' param  */
#line 410 "lang.y"
                                { (yyvsp[-2].params_node)->Insert((yyvsp[0].expr_node)); (yyval.params_node) = (yyvsp[-2].params_node); }
#line 1798 "langparse.c"
    break;

  case 45: /* params: param  */
#line 412 "lang.y"
                            { (yyval.params_node) = new cParamsNode((yyvsp[0].expr_node)); }
#line 1804 "langparse.c"
    break;

  case 46: /* param: expr  */
#line 416 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1810 "langparse.c"
    break;

  case 47: /* expr: expr EQUALS addit  */
#line 420 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node),EQUALS,(yyvsp[0].expr_node)); }
#line 1816 "langparse.c"
    break;

  case 48: /* expr: addit  */
#line 422 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1822 "langparse.c"
    break;

  case 49: /* addit: addit '+' term  */
#line 425 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '+', (yyvsp[0].expr_node)); }
#line 1828 "langparse.c"
    break;

  case 50: /* addit: addit '-' term  */
#line 427 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '-', (yyvsp[0].expr_node)); }
#line 1834 "langparse.c"
    break;

  case 51: /* addit: term  */
#line 429 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1840 "langparse.c"
    break;

  case 52: /* term: term '*' fact  */
#line 432 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '*', (yyvsp[0].expr_node)); }
#line 1846 "langparse.c"
    break;

  case 53: /* term: term '/' fact  */
#line 434 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '/', (yyvsp[0].expr_node)); }
#line 1852 "langparse.c"
    break;

  case 54: /* term: term '%' fact  */
#line 436 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), '%', (yyvsp[0].expr_node)); }
#line 1858 "langparse.c"
    break;

  case 55: /* term: fact  */
#line 438 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1864 "langparse.c"
    break;

  case 56: /* fact: '(' expr ')'  */
#line 441 "lang.y"
                                { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 1870 "langparse.c"
    break;

  case 57: /* fact: INT_VAL  */
#line 443 "lang.y"
                            { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1876 "langparse.c"
    break;

  case 58: /* fact: FLOAT_VAL  */
#line 445 "lang.y"
                            { (yyval.expr_node) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1882 "langparse.c"
    break;

  case 59: /* fact: varref  */
#line 447 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1888 "langparse.c"
    break;

  case 60: /* fact: func_call  */
#line 449 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1894 "langparse.c"
    break;


#line 1898 "langparse.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 452 "lang.y"


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
    std::cout << "ERROR: " << error << " near line " 
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
