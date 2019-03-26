/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "new_yacc.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "structinfo.h"
#include "symboltable.h"
#include "functiontable.h"
#include "unmatched.h"
extern FILE *fp;
FILE * f1;

int pcount=-1;
int gscope = 0;
char lasttype[csize]; //the last datatype encountered in the program. needed for when multiple variables declared in the same line
char returntype[csize];	//the return type of the function

char funcname[20];
char paras[3][20];

char tstr[10]={'N','U','L','L','\0'};	//set identifier in stmt_assign

char laststruct[20];
char structparas[8][20];
char structparastype[8][20];
int spcount = -1;	//struct-parameter count
char currentstructvar[20];

#line 93 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    VOID = 259,
    FLOAT = 260,
    STRUCT = 261,
    WHILE = 262,
    IF = 263,
    ELSE = 264,
    SWITCH = 265,
    CASE = 266,
    BREAK = 267,
    DEFAULT = 268,
    RETURN = 269,
    CONTINUE = 270,
    INT_CONST = 271,
    FLOAT_CONST = 272,
    ID = 273,
    STRUCTMEM = 274,
    ADDR = 275,
    FORMAT = 276,
    INCOMPLETE_STRING = 277,
    OPENING_COMMENT = 278,
    CLOSING_COMMENT = 279,
    ERR_NOT_IDENTIFER = 280,
    LEX_ERROR = 281,
    SINGLECOMMENT = 282,
    MULTICOMMENT = 283,
    STRING = 284,
    PRINT = 285,
    SCAN = 286,
    HEADER = 287,
    ASGN = 288,
    LOPS = 289,
    AOPS = 290,
    ROPS = 291,
    IFX = 292,
    IFX1 = 293
  };
#endif
/* Tokens.  */
#define INT 258
#define VOID 259
#define FLOAT 260
#define STRUCT 261
#define WHILE 262
#define IF 263
#define ELSE 264
#define SWITCH 265
#define CASE 266
#define BREAK 267
#define DEFAULT 268
#define RETURN 269
#define CONTINUE 270
#define INT_CONST 271
#define FLOAT_CONST 272
#define ID 273
#define STRUCTMEM 274
#define ADDR 275
#define FORMAT 276
#define INCOMPLETE_STRING 277
#define OPENING_COMMENT 278
#define CLOSING_COMMENT 279
#define ERR_NOT_IDENTIFER 280
#define LEX_ERROR 281
#define SINGLECOMMENT 282
#define MULTICOMMENT 283
#define STRING 284
#define PRINT 285
#define SCAN 286
#define HEADER 287
#define ASGN 288
#define LOPS 289
#define AOPS 290
#define ROPS 291
#define IFX 292
#define IFX1 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 217 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    56,    57,    58,    59,
      62,    62,    62,    66,    66,    67,    68,    69,    70,    71,
      72,    73,    78,    78,    79,    80,    82,    83,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   101,
     102,   105,   106,   107,   108,   109,   118,   118,   119,   120,
     121,   122,   123,   124,   128,   128,   129,   129,   130,   131,
     134,   134,   135,   135,   138,   138,   139,   139,   140,   144,
     145,   148,   152,   152,   155,   155,   156,   159,   159,   164,
     164,   165,   165,   166,   166,   167,   168,   169,   170,   174,
     175,   176,   179,   179,   180,   182,   182,   183,   183,   186,
     186,   189,   190,   193,   194,   197,   198,   202,   202,   202,
     206,   207,   212,   212,   213,   215,   216,   216,   217,   217,
     218,   222,   222,   222,   225,   226,   226,   230,   230,   234,
     235,   238,   238,   239,   239,   243,   244,   245,   250,   250,
     250,   253,   253,   253,   254,   254,   258,   258,   259,   263,
     263,   264,   264,   265,   270,   270,   270,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "FLOAT", "STRUCT",
  "WHILE", "IF", "ELSE", "SWITCH", "CASE", "BREAK", "DEFAULT", "RETURN",
  "CONTINUE", "INT_CONST", "FLOAT_CONST", "ID", "STRUCTMEM", "ADDR",
  "FORMAT", "INCOMPLETE_STRING", "OPENING_COMMENT", "CLOSING_COMMENT",
  "ERR_NOT_IDENTIFER", "LEX_ERROR", "SINGLECOMMENT", "MULTICOMMENT",
  "STRING", "PRINT", "SCAN", "HEADER", "ASGN", "LOPS", "AOPS", "ROPS",
  "IFX", "IFX1", "'('", "')'", "','", "'{'", "'}'", "';'", "':'",
  "$accept", "pgmstart", "FUNC", "$@1", "$@2", "PARAMETER", "$@3", "STMTS",
  "$@4", "STMT1", "STMT", "RETURNSTMT", "VALUES", "AEXP", "$@5", "EXP",
  "$@6", "$@7", "STMT_PRINT", "$@8", "$@9", "OPTIONEND", "$@10", "$@11",
  "ADDRS", "STMT_SCAN", "STMT_IF", "$@12", "ELSESTMT", "$@13",
  "STMT_SWITCH", "$@14", "swEXP", "$@15", "$@16", "$@17", "SWITCHBODY",
  "CASES", "$@18", "BREAKSTMT", "$@19", "$@20", "DEFAULTSTMT", "$@21",
  "DE", "STMT_COMMENT", "SWITCHEXP", "STMT_WHILE", "$@22", "$@23",
  "WHILEBODY", "whileSTMTS", "$@24", "whileSTMT1", "$@25", "$@26",
  "STMT_DECLARE", "$@27", "$@28", "IDS", "$@29", "STMT_ASSGN", "$@30",
  "ANY", "TEMP", "$@31", "$@32", "TYPE", "STRUCT_DECLARE", "$@33", "$@34",
  "STRUCT_DEF_DEC", "$@35", "$@36", "$@37", "MULTIPLE_STRUCT_DEF_DEC",
  "$@38", "CONT", "$@39", "$@40", "STRUCT_PARAMETER", "$@41", "$@42", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    40,
      41,    44,   123,   125,    59,    58
};
# endif

#define YYPACT_NINF -180

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-180)))

#define YYTABLE_NINF -121

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     201,  -180,  -180,  -180,  -180,  -180,   201,   201,   201,  -180,
    -180,     5,   201,   201,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,   183,  -180,  -180,  -180,    41,     2,     6,  -180,    -5,
    -180,    23,  -180,  -180,    20,    24,  -180,    27,   183,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,    78,  -180,  -180,  -180,
    -180,  -180,    13,  -180,  -180,  -180,    76,    32,    84,  -180,
    -180,  -180,  -180,   199,    93,    -3,   124,  -180,  -180,   126,
      32,  -180,  -180,  -180,  -180,    13,  -180,   165,   155,   122,
    -180,  -180,  -180,  -180,  -180,  -180,    32,   116,    56,    60,
     163,  -180,  -180,  -180,   167,    32,   102,  -180,   172,  -180,
      13,   204,  -180,  -180,    -9,    42,   114,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,    60,    69,   186,   191,   193,   212,
     140,  -180,    13,   195,  -180,  -180,  -180,  -180,  -180,  -180,
     207,    32,    32,   133,    81,  -180,  -180,  -180,   197,  -180,
    -180,   152,   198,   200,  -180,  -180,  -180,   122,   151,   103,
     207,  -180,   206,  -180,   228,  -180,    60,    60,    60,   196,
    -180,  -180,  -180,   220,   210,   125,  -180,   226,  -180,  -180,
    -180,   208,    42,  -180,  -180,   143,   216,  -180,   239,   213,
     244,   193,   193,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
     240,  -180,   133,  -180,  -180,  -180,  -180,  -180,  -180,    83,
     151,  -180,    -4,  -180,   214,   215,  -180,  -180,    83,   218,
    -180,   219,  -180,   246,   221,   154,   154,    83,    83,  -180,
    -180,   103,    -4,  -180,  -180,    10,  -180,  -180,   250,   254,
    -180,  -180,  -180,  -180,    -4,   223,   257,   257,   225,  -180,
    -180,  -180,  -180,  -180,  -180,   257,  -180
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,   135,   136,   137,   129,   130,     9,     9,     9,    22,
      24,     0,     9,     9,     7,     8,   127,    10,     5,     4,
       6,    27,     1,     2,     3,     0,     0,     0,   138,     0,
      77,    45,   103,   104,     0,     0,    38,     0,    27,    36,
      34,    32,    30,    33,    35,    31,     0,    28,    29,   121,
      37,   131,    21,   128,    11,   122,     0,     0,     0,    43,
      44,    41,    42,    45,     0,     0,     0,    23,    26,     0,
       0,    19,    20,    17,    18,    21,   133,    16,     0,     0,
     139,    49,    50,    48,    52,    51,     0,    58,     0,     0,
       0,    39,    62,    60,     0,     0,   132,    15,     0,    13,
      21,     0,   124,   123,     0,    58,     0,    46,    56,    54,
      72,    88,    86,    87,     0,     0,     0,     0,    68,     0,
       0,   134,    21,     0,   125,   144,   141,   140,    53,    59,
       0,     0,     0,    25,     0,    81,    83,    79,     0,    40,
      63,     0,     0,    70,   108,    14,    12,     0,     0,   157,
       0,    47,    57,    55,    76,    85,     0,     0,     0,    91,
      64,    66,    61,     0,     0,   114,   126,     0,   148,   145,
     154,     0,     0,    74,    73,    82,    84,    80,     0,     0,
      89,    68,    68,    69,    71,   112,   111,   109,   110,   146,
       0,   142,    25,    92,    78,    99,    90,    65,    67,   107,
       0,   155,   153,    75,     0,     0,   116,   118,   107,     0,
     147,     0,   149,     0,     0,    25,    25,   107,   107,   115,
     113,   157,   153,   151,   143,    38,   105,   106,    97,   102,
     117,   119,   156,   150,   153,     0,    94,    94,     0,   100,
     152,    95,    93,    98,   101,    94,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,   241,  -180,  -180,  -180,   -64,  -180,  -132,  -180,   -11,
    -161,  -180,   209,   -84,  -180,   -67,  -180,  -180,  -180,  -180,
    -180,    18,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,   -89,  -180,  -180,  -180,  -180,  -164,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,    54,  -180,  -180,  -180,
    -180,  -180,  -180,  -173,  -180,  -180,   112,  -180,  -180,   127,
    -180,   134,  -180,  -180,  -180,  -180,  -180,     0,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,    71,  -180,  -179,  -180,  -180,
      52,  -180,  -180
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    26,    78,    76,   122,    13,    21,   227,
      38,    39,    64,    87,   130,    88,   132,   131,    40,   118,
     117,   142,   181,   182,   164,    41,    42,   133,   174,   192,
      43,    58,   115,   158,   156,   157,   179,   180,   204,   236,
     245,   237,   196,   205,   239,    44,   228,    45,    46,   165,
     187,   188,   199,   209,   217,   218,    47,    27,    79,   103,
     147,    48,    25,    16,    53,    70,    98,    49,    50,    56,
     104,   127,   149,   202,   148,   169,   200,   214,   222,   234,
     171,   190,   211
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   154,   105,    96,   186,    22,    17,    17,    17,   125,
      37,    97,    17,    17,   212,    92,     1,     2,     3,   106,
      54,   -24,   -24,   -24,    55,   134,    93,    68,   120,    71,
      72,    73,    74,   126,    57,   219,   123,   213,   208,    59,
      60,    61,    62,   233,   230,   231,   151,   208,    81,    82,
      83,    84,    77,   -24,    75,   240,   208,   208,   145,    65,
     203,    85,    63,    66,   152,   153,   172,   175,   176,   177,
      67,    86,   242,   243,    51,    77,   111,   107,   112,   113,
      52,   246,   128,   226,   226,    69,     1,     2,     3,    28,
     108,    29,   109,    30,    80,   206,   110,    31,   207,   114,
      77,     4,     5,   135,   136,   137,     1,     2,     3,   138,
      32,    33,    14,    34,    35,   135,   136,   137,    14,    14,
      14,   155,    77,    89,    14,    14,  -120,    36,     1,     2,
       3,    28,  -107,    29,    15,    30,   108,    91,   109,    31,
      15,    15,    15,     4,     5,    94,    15,    15,   108,   170,
     109,   107,    32,    33,   129,    34,    35,     1,     2,     3,
      28,  -107,    29,   101,    30,    95,   102,   185,    31,    36,
     160,   161,     4,     5,   108,     9,   109,    10,   136,   137,
     144,    32,    33,    99,    34,    35,     1,     2,     3,    28,
    -107,    29,   167,    30,   100,   168,     9,    31,   225,   197,
     198,     4,     5,   116,     1,     2,     3,   178,   119,   -94,
      32,    33,   121,    34,    35,    59,    60,    61,    62,     4,
       5,   170,   124,    81,    82,    83,    84,    36,     6,     7,
     139,   140,   143,     8,   141,   146,    85,   173,   162,   159,
     183,   163,   109,     9,   189,    10,   150,    18,    19,    20,
     184,   191,   137,    23,    24,   193,   194,   195,   201,   215,
     216,   220,   235,   221,   223,   224,   238,   241,   178,   244,
     229,   210,    90,   232,   166
};

static const yytype_uint8 yycheck[] =
{
       0,   133,    86,    70,   165,     0,     6,     7,     8,    18,
      21,    75,    12,    13,    18,    18,     3,     4,     5,    86,
      18,    11,    12,    13,    18,   114,    29,    38,    95,    16,
      17,    18,    19,    42,    39,   208,   100,    41,   199,    16,
      17,    18,    19,   222,   217,   218,   130,   208,    16,    17,
      18,    19,    52,    43,    41,   234,   217,   218,   122,    39,
     192,    29,    39,    39,   131,   132,   150,   156,   157,   158,
      43,    39,   236,   237,    33,    75,    16,    35,    18,    19,
      39,   245,    40,   215,   216,     7,     3,     4,     5,     6,
      34,     8,    36,    10,    18,    12,    40,    14,    15,    39,
     100,    18,    19,    34,    35,    36,     3,     4,     5,    40,
      27,    28,     0,    30,    31,    34,    35,    36,     6,     7,
       8,    40,   122,    39,    12,    13,    43,    44,     3,     4,
       5,     6,     7,     8,     0,    10,    34,    44,    36,    14,
       6,     7,     8,    18,    19,    21,    12,    13,    34,   149,
      36,    35,    27,    28,    40,    30,    31,     3,     4,     5,
       6,     7,     8,    41,    10,    39,    44,    42,    14,    44,
      18,    19,    18,    19,    34,    42,    36,    44,    35,    36,
      40,    27,    28,    18,    30,    31,     3,     4,     5,     6,
       7,     8,    41,    10,    39,    44,    42,    14,    44,   181,
     182,    18,    19,    40,     3,     4,     5,    11,    41,    13,
      27,    28,    40,    30,    31,    16,    17,    18,    19,    18,
      19,   221,    18,    16,    17,    18,    19,    44,    27,    28,
      44,    40,    20,    32,    41,    40,    29,     9,    40,    42,
      20,    41,    36,    42,    18,    44,    39,     6,     7,     8,
      40,    43,    36,    12,    13,    16,    43,    13,    18,    45,
      45,    43,    12,    44,    18,    44,    12,    44,    11,    44,
     216,   200,    63,   221,   147
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    18,    19,    27,    28,    32,    42,
      44,    47,    48,    53,   102,   107,   109,   113,    47,    47,
      47,    54,     0,    47,    47,   108,    49,   103,     6,     8,
      10,    14,    27,    28,    30,    31,    44,    55,    56,    57,
      64,    71,    72,    76,    91,    93,    94,   102,   107,   113,
     114,    33,    39,   110,    18,    18,   115,    39,    77,    16,
      17,    18,    19,    39,    58,    39,    39,    43,    55,     7,
     111,    16,    17,    18,    19,    41,    51,   113,    50,   104,
      18,    16,    17,    18,    19,    29,    39,    59,    61,    39,
      58,    44,    18,    29,    21,    39,    61,    51,   112,    18,
      39,    41,    44,   105,   116,    59,    61,    35,    34,    36,
      40,    16,    18,    19,    39,    78,    40,    66,    65,    41,
      61,    40,    52,    51,    18,    18,    42,   117,    40,    40,
      60,    63,    62,    73,    78,    34,    35,    36,    40,    44,
      40,    41,    67,    20,    40,    51,    40,   106,   120,   118,
      39,    59,    61,    61,    53,    40,    80,    81,    79,    42,
      18,    19,    40,    41,    70,    95,   105,    41,    44,   121,
     113,   126,    59,     9,    74,    78,    78,    78,    11,    82,
      83,    68,    69,    20,    40,    42,    56,    96,    97,    18,
     127,    43,    75,    16,    43,    13,    88,    67,    67,    98,
     122,    18,   119,    53,    84,    89,    12,    15,    56,    99,
     121,   128,    18,    41,   123,    45,    45,   100,   101,    99,
      43,    44,   124,    18,    44,    44,    53,    55,    92,    92,
      99,    99,   126,   123,   125,    12,    85,    87,    12,    90,
     123,    44,    83,    83,    44,    86,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    47,    47,    47,    47,
      49,    50,    48,    52,    51,    51,    51,    51,    51,    51,
      51,    51,    54,    53,    53,    53,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    60,    59,    59,    59,
      59,    59,    59,    59,    62,    61,    63,    61,    61,    61,
      65,    64,    66,    64,    68,    67,    69,    67,    67,    70,
      70,    71,    73,    72,    75,    74,    74,    77,    76,    79,
      78,    80,    78,    81,    78,    78,    78,    78,    78,    82,
      82,    82,    84,    83,    83,    86,    85,    87,    85,    89,
      88,    90,    90,    91,    91,    92,    92,    94,    95,    93,
      96,    96,    98,    97,    97,    99,   100,    99,   101,    99,
      99,   103,   104,   102,   105,   106,   105,   108,   107,   109,
     109,   111,   110,   112,   110,   113,   113,   113,   115,   116,
     114,   118,   119,   117,   120,   117,   122,   121,   121,   124,
     123,   125,   123,   123,   127,   128,   126,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     1,     1,     0,
       0,     0,     7,     0,     4,     2,     1,     1,     1,     1,
       1,     0,     0,     4,     1,     0,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     1,     1,     1,     1,     0,     0,     4,     1,     1,
       1,     1,     1,     3,     0,     4,     0,     4,     1,     3,
       0,     6,     0,     5,     0,     4,     0,     4,     0,     2,
       0,     7,     0,     7,     0,     3,     0,     0,     8,     0,
       4,     0,     4,     0,     4,     3,     1,     1,     1,     1,
       2,     0,     0,     7,     0,     0,     4,     0,     2,     0,
       5,     2,     0,     1,     1,     1,     1,     0,     0,     7,
       1,     1,     0,     4,     0,     2,     0,     3,     0,     3,
       0,     0,     0,     5,     1,     0,     4,     0,     3,     1,
       1,     0,     3,     0,     4,     1,     1,     1,     0,     0,
       5,     0,     0,     7,     0,     3,     0,     4,     1,     0,
       3,     0,     4,     0,     0,     0,     6,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:
#line 62 "new_yacc.y" /* yacc.c:1646  */
    {setrettype();}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "new_yacc.y" /* yacc.c:1646  */
    {setfuncname();}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 62 "new_yacc.y" /* yacc.c:1646  */
    {pushfunc(); func_label2(); pcount=-1; }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 66 "new_yacc.y" /* yacc.c:1646  */
    {pcount++; addpara();}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 69 "new_yacc.y" /* yacc.c:1646  */
    {checknew(); pcount++;}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 70 "new_yacc.y" /* yacc.c:1646  */
    {setstructvariable(); checkstructvar();pcount++;}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 71 "new_yacc.y" /* yacc.c:1646  */
    {pcount++;}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "new_yacc.y" /* yacc.c:1646  */
    {pcount++;}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "new_yacc.y" /* yacc.c:1646  */
    {gscope++;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 78 "new_yacc.y" /* yacc.c:1646  */
    {invalidate(gscope); invalidatestruct(gscope); gscope--;}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 94 "new_yacc.y" /* yacc.c:1646  */
    {fprintf(f1,"return\n");}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 105 "new_yacc.y" /* yacc.c:1646  */
    {check1(); checkret(0);}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 106 "new_yacc.y" /* yacc.c:1646  */
    {setstructvariable(); checkstructvar(); checkret(0);}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 107 "new_yacc.y" /* yacc.c:1646  */
    {checkret(1);}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 108 "new_yacc.y" /* yacc.c:1646  */
    {checkret(2);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 109 "new_yacc.y" /* yacc.c:1646  */
    {checkret(3);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 118 "new_yacc.y" /* yacc.c:1646  */
    {push();pushop(0);}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 118 "new_yacc.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 119 "new_yacc.y" /* yacc.c:1646  */
    {  push(); check1();}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 120 "new_yacc.y" /* yacc.c:1646  */
    {push();}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 121 "new_yacc.y" /* yacc.c:1646  */
    {push();}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 122 "new_yacc.y" /* yacc.c:1646  */
    {push();}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 123 "new_yacc.y" /* yacc.c:1646  */
    { push(); setstructvariable(); checkstructvar(); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 128 "new_yacc.y" /* yacc.c:1646  */
    {push();pushop(2);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 128 "new_yacc.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 129 "new_yacc.y" /* yacc.c:1646  */
    {push();pushop(1);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 129 "new_yacc.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 134 "new_yacc.y" /* yacc.c:1646  */
    {print_func();}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 135 "new_yacc.y" /* yacc.c:1646  */
    {print_func();}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 138 "new_yacc.y" /* yacc.c:1646  */
    {check1();}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 139 "new_yacc.y" /* yacc.c:1646  */
    {setstructvariable(); checkstructvar();}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 152 "new_yacc.y" /* yacc.c:1646  */
    {if_label1();}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 155 "new_yacc.y" /* yacc.c:1646  */
    {if_label2();}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 155 "new_yacc.y" /* yacc.c:1646  */
    {if_label3();}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 156 "new_yacc.y" /* yacc.c:1646  */
    {if_label3();}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 159 "new_yacc.y" /* yacc.c:1646  */
    {switch_start();}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 159 "new_yacc.y" /* yacc.c:1646  */
    {switch_end();}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 164 "new_yacc.y" /* yacc.c:1646  */
    {pushop(2);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 165 "new_yacc.y" /* yacc.c:1646  */
    {pushop(1);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 166 "new_yacc.y" /* yacc.c:1646  */
    {pushop(0);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 168 "new_yacc.y" /* yacc.c:1646  */
    {check1(); checkint();}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 169 "new_yacc.y" /* yacc.c:1646  */
    {setstructvariable(); checkstructvar(); checkintstruct();}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 179 "new_yacc.y" /* yacc.c:1646  */
    {switch_case();}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 182 "new_yacc.y" /* yacc.c:1646  */
    {switch_break();}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 183 "new_yacc.y" /* yacc.c:1646  */
    {switch_nobreak();}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 186 "new_yacc.y" /* yacc.c:1646  */
    {switch_default();}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 202 "new_yacc.y" /* yacc.c:1646  */
    {while_start();}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 202 "new_yacc.y" /* yacc.c:1646  */
    {while_rep();}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 206 "new_yacc.y" /* yacc.c:1646  */
    {while_end();}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 207 "new_yacc.y" /* yacc.c:1646  */
    {while_end();}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 212 "new_yacc.y" /* yacc.c:1646  */
    {gscope++;}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 212 "new_yacc.y" /* yacc.c:1646  */
    {invalidate(gscope); invalidatestruct(gscope); gscope--;}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 216 "new_yacc.y" /* yacc.c:1646  */
    {while_break();}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 217 "new_yacc.y" /* yacc.c:1646  */
    {while_continue();}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 222 "new_yacc.y" /* yacc.c:1646  */
    {settype();}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 222 "new_yacc.y" /* yacc.c:1646  */
    {check2(); pushid(0);push();}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 226 "new_yacc.y" /* yacc.c:1646  */
    { check2(); pushid(0);push();}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 230 "new_yacc.y" /* yacc.c:1646  */
    {push(); setstring();}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 230 "new_yacc.y" /* yacc.c:1646  */
    {resetstring();}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 235 "new_yacc.y" /* yacc.c:1646  */
    {setstructvariable();}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 238 "new_yacc.y" /* yacc.c:1646  */
    {push();  pushop(3); check_var_or_structvar();}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 238 "new_yacc.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 239 "new_yacc.y" /* yacc.c:1646  */
    {checkfunc(); func_label1(); pcount=-1;}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 250 "new_yacc.y" /* yacc.c:1646  */
    {settype();}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 250 "new_yacc.y" /* yacc.c:1646  */
    { settype(); storestructname(); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 253 "new_yacc.y" /* yacc.c:1646  */
    { gscope++;}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 253 "new_yacc.y" /* yacc.c:1646  */
    {invalidate(gscope); gscope--; checkifstruct2(); specialsettype(); pushid(1); settypetostruct(); addstructdefn(); spcount=-1;}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 254 "new_yacc.y" /* yacc.c:1646  */
    {checkifstruct(); check2(); pushid(0);}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 258 "new_yacc.y" /* yacc.c:1646  */
    {check2(); pushid(0);}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 263 "new_yacc.y" /* yacc.c:1646  */
    {check2(); pushid(0);}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 264 "new_yacc.y" /* yacc.c:1646  */
    {check2(); pushid(0);}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 270 "new_yacc.y" /* yacc.c:1646  */
    {spcount++; addstructparatype();}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 270 "new_yacc.y" /* yacc.c:1646  */
    {addstructpara();}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1930 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 275 "new_yacc.y" /* yacc.c:1906  */


#include<string.h>
#include"lex.yy.c"
int count=0;

char st[1000][10];
int top=0;
int i=1, test=0;
char temp[2]="t";

int label[200];
int flabel[200];				
int lnum=0;
int ltop=0;
int switch_stack[1000];
int stop=0;
char type[10];

struct Table
{
	char id[20];
}table[100];

int tableCount=0;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	f1=fopen("output","w");
	printf("\n\n");
	yyparse();

	if(test!=0)
	{
		printf("\nThe code could not be parsed.\n\n");
		exit(0);
	}
	
	fclose(yyin);
	fclose(f1);
	printf("\n\n\n\n");
	printf("Symbol table\n");
	printtable();
	printf("\n\n\n\n");
	printf("Function table\n");
	printfunctable();
	printf("\n\n\n\n");
	printf("Struct table\n");
	printstructtable();
	printf("\n\n\n\n");
	printf("Intermediate Code\n\n");
	intermediateCode();
    return 0;
}
         
yyerror(char *s) 
{
	test=1;
	printf("Error in line number : %d : %s %s\n", yylineno, s, yytext );
}
   

pushop(int type) //push operators
{
	//0 - AOPs 
	//1 - LOPs
	//2 - ROPs
	//3 - Assignment
	struct symtab temp;
	strcpy(temp.token, "operator");
	strcpy(temp.name, yytext);
	temp.scope = gscope;	
	
	switch(type)
	{
		case 0:	strcpy(temp.type, "arithmetic");  break;
		case 1: strcpy(temp.type, "logical");	break;
		case 2: strcpy(temp.type, "relational");	break;
		case 3: strcpy(temp.type, "assignment");	break;
		default : strcpy(temp.type, "other");	break;
	}
	pushsymtable(temp);
}


settype()
{
	strcpy(lasttype, yytext);
}

setrettype()
{
	strcpy(returntype, yytext);
}

setfuncname()
{
	strcpy(funcname, yytext);
}

storestructname()
{
	strcpy(laststruct, yytext);
}

setstructvariable()
{
	strcpy(currentstructvar, yytext);
}


settypetostruct()
{
//	printf("\nAre we here?\n\n");
	strcpy(lasttype, laststruct);
}

specialsettype()
{
	strcpy(lasttype, "struct");
}

setstring()
{
	strcpy(tstr, yytext);
}

resetstring()
{
	strcpy(tstr, "NULL");
}


pushid(int num) //pushing an identifier
{
//	printf("\n\nAre we in pushid?\n\n");

	struct symtab temp;
	strcpy(temp.token, "identifier");

	strcpy(temp.name, laststruct);

	if(num==0)
		strcpy(temp.name, yytext);
	
	strcpy(temp.type, lasttype);
	temp.scope = gscope;	
	pushsymtable(temp);
//	printf("\n\nHave we made it out of pushid?\n\n");


/*	printf("\n\n\n\n");
	printf("Symbol table\n");
	printtable();
	printf("\n\n\n\n");
*/

}

pushfunc()
{

	int flag = lookupfunctable(funcname, pcount+1);

	if(flag!=-1)
		return;

	struct func_table temp;
	strcpy(temp.type, returntype);
	strcpy(temp.name, funcname);
	temp.nparam = pcount+1;
	int i;
	for(i=0;i<=pcount;i++)
	{
		strcpy(temp.param[i],paras[i]);
	}
	pushfunctable(temp);
}


addstructdefn()
{
	struct structvar temp;
	strcpy(temp.structname, laststruct);
	temp.nparam = spcount+1;
	temp.scope = gscope;

	int i;
	for(i=0;i<=spcount;i++)
	{
		strcpy(temp.membertype[i],structparastype[i]);
		strcpy(temp.member[i],structparas[i]);
	}
		
	pushstructinfo(temp);
}



push()
{
  	strcpy(st[++top],yytext);
}

codegen_logical()
{
	int kop;
	char vio,x[10]="";
// 	printf("Line %d: Logical statement.\n", yylineno);
 	strcpy(temp,"$t");
	kop=i;
	while(kop!=0)
	{
		kop=kop%10;
		switch(kop)
		{
			case 1:strcat(x,"1");
			break;
			case 2:strcat(x,"2");
			break;
			case 3:strcat(x,"3");
			break;
			case 4:strcat(x,"4");
			break;
			case 5:strcat(x,"5");
			break;
			case 6:strcat(x,"6");
			break;
			case 7:strcat(x,"7");
			break;
			case 8:strcat(x,"8");
			break;
			case 9:strcat(x,"9");
			break;
			case 0:strcat(x,"0");
			break;
		}
		kop=kop/10;
	}
	for(kop=0;kop=(strlen(x)/2);kop++)
	{
		vio=x[kop];
		x[kop]=x[strlen(x)-kop];
		x[strlen(x)-kop]=vio;
	}
	strcat(temp,x);
  	fprintf(f1,"$t%d\t=\t%s\t%s\t%s\n",i,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

codegen_algebric()
{
	int kop;
	char vio,x[10]="";
// 	printf("Line %d: Algebraic expression.\n", yylineno);
 	strcpy(temp,"$t");
	kop=i;
	while(kop!=0)
	{
		kop=kop%10;
		switch(kop)
		{
			case 1:strcat(x,"1");
			break;
			case 2:strcat(x,"2");
			break;
			case 3:strcat(x,"3");
			break;
			case 4:strcat(x,"4");
			break;
			case 5:strcat(x,"5");
			break;
			case 6:strcat(x,"6");
			break;
			case 7:strcat(x,"7");
			break;
			case 8:strcat(x,"8");
			break;
			case 9:strcat(x,"9");
			break;
			case 0:strcat(x,"0");
			break;
		}
		kop=kop/10;
	}
for(kop=0;kop=(strlen(x)/2);kop++)
	{
		vio=x[kop];
		x[kop]=x[strlen(x)-kop];
		x[strlen(x)-kop]=vio;
	}
	strcat(temp,x);
  	fprintf(f1,"$t%d\t=\t%s\t%s\t%s\n",i,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}
codegen_assign()
{
// 	printf("Line %d: Assignment statement.\n", yylineno);
 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
 	top-=3;
}
 
if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}

if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\t\tgoto $L%d\n",lnum);
	fprintf(f1,"$L%d: \n",x); 
	label[++ltop]=lnum;
}

if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"$L%d: \n",y);
	top--;
}

func_label1()
{
	int flag = lookupfunctable(tstr, pcount+1);
	fprintf(f1,"call $F%d: \n",flag);
	
}

func_label2()
{
	int flag = lookupfunctable(funcname, pcount+1);
	fprintf(f1,"$F%d: \n",flag);
}
print_func()
{
	fprintf(f1,"print statement\n");
}


comment()
{
	fprintf(f1,"Comment");
}
while_start()
{
//	printf("Line %d: While loop.\n", yylineno);
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"$L%d:\n",lnum);
}
while_rep()
{
	lnum++;
 	fprintf(f1,"if( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
 	label[++ltop]=lnum;
}

while_break()
{
 	fprintf(f1,"\tgoto $L%d\n",lnum);
}




while_end()
{
	int x,y;
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\t\tgoto $L%d\n",x);
	fprintf(f1,"$L%d: \n",y);
	top--;
}


while_continue()
{
	int x;
	x=label[ltop-1];
	fprintf(f1,"\t\tgoto $L%d\n",x);
}


switch_start()
{
//	printf("Line %d: Switch case.\n", yylineno);
	lnum++;
	label[++ltop]=lnum;
	lnum++;
	label[++ltop]=lnum;
	switch_stack[++stop]=1;
}
switch_case()
{
	int x,y,z;
	z=switch_stack[stop--];
	if(z==1)
	{
		x=label[ltop--];
	}
	else if(z==2)
	{
		y=label[ltop--];
		x=label[ltop--];
	}
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
 	fprintf(f1,"if(%s != %s)",st[top],yytext);
 	fprintf(f1,"\tgoto $L%d\n",label[ltop]);
 	if(z==2)
 	{
 		fprintf(f1,"$L%d:\n",y);
 	}
}
switch_default()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
}
switch_break()
{
	switch_stack[++stop]=1;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop-1]);
}
switch_nobreak()
{
	switch_stack[++stop]=2;
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop]);
}
switch_end()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	top--;
	stop--;
}


/* for symbol table*/

pushTable()
{
	strcpy(table[tableCount++].id,yytext);
}


check2()
{

	int flagfunc = lookuppara(funcname, yytext);

	int flag = lookupsymtable2(yytext, gscope);
 
	if(flag==1 || flagfunc==1)
	{
		yyerror("Variable redeclared");
		exit(0);
	}
	
	
}

check1()
{
	if(strcmp(tstr, "NULL")!=0)
		strcpy(yytext, tstr);
	
	int flag = lookupsymtable1(yytext, gscope); 

	int flagfunc = lookuppara(funcname, yytext);

	if(flag==0 && flagfunc==0)
	{
		yyerror("Variable not declared");
		exit(0);	
	}
	
} 


checknew()
{

	int flag = lookupsymtable1(yytext, gscope); 
	if(flag==0)
	{
		yyerror("Variable not declared");
		exit(0);	
	}
	
}



checkifstruct() //in struct student stud, check if student exists
{
/*	char temp[20];
	printf("\n\nError0\n\n");
	strcpy(temp, yytext);
	printf("\n\nError1\n\n");
	strcpy(yytext, laststruct);
	printf("\n\nError2\n\n");
	check1();
	strcpy(yytext, temp);
	printf("\n\nError3\n\n");

*/
	int flag = lookupsymtable1(laststruct, gscope); 
	if(flag==0)
	{
		test=1;
		printf("\nError in linenumber %d: struct not declared %s\n\n", yylineno, laststruct);
		exit(0);	
	}
}

checkifstruct2() //in struct student stud, see if student is being redeclared
{
/*	char temp[20];
	printf("\n\n2Error0\n\n");
	strcpy(temp, yytext);
	printf("\n\n2Error1\n\n");
	strcpy(yytext, laststruct);
	printf("\n\n2Error2\n\n");
	check2();
	strcpy(yytext, temp);
	printf("\n\n2Error3\t%s\n\n", yytext);
*/
	int flag = lookupsymtable2(laststruct, gscope); 
	if(flag==1)
	{
		test=1;
		printf("\nError in linenumber %d: struct redeclared %s\n\n", yylineno, laststruct);
		exit(0);
	}
	



}

checkstructvar()
{
	char sname[sizec], mname[sizec]; //struct-name, member-name

	int i, k=0;
	for(i=0; currentstructvar[i]!='.';i++)
	{
		sname[k] = currentstructvar[i];
		k++;
	}
	sname[k]='\0';

	i++; k=0;

	for(;currentstructvar[i]!='\0';i++)
	{
		mname[k] = currentstructvar[i];
		k++;
	}
	mname[k]='\0';

	int flag = lookupsymtable1(sname, gscope); 
	if(flag==0)
	{
		test=1;
		printf("\nError in linenumber %d: variable not declared %s\n\n", yylineno, sname);
		exit(0);	
	}



	char stype[sizec]; //type of struct variable
	strcpy(stype, getreturntype(sname,gscope));
	
//	printf("\n\nReturn type = %s\n", stype);

	flag = lookupstructinfo(stype, mname, gscope); 
	if(flag==0)
	{
		test=1;
		printf("\nError in linenumber %d: This member is not a part of the struct %s\n\n", yylineno, stype);
		exit(0);	
	}

}


check_var_or_structvar()
{
	if(strchr(tstr, '.')!=NULL)
	{
//		printf("\n\nChecking for struct member line %d\n\n", yylineno);
		checkstructvar();
//		printf("\n\nDone checking for struct member\n\n");
	}		
	else
		check1();
}


checkret(int what)
{
	int flag=1;

	if(strcmp(returntype,"void")==0)
	{
		if(what!=3)
			flag=0;
	}

	if(flag==0)
	{
		yyerror("\nError: return type mismatch\n");
		exit(0);
	}
	return;
}


checkfunc()
{
	int flag = lookupfunctable(tstr, pcount+1);
	if(flag==-1)
	{
		yyerror("\nError: function not declared\n");
		exit(0);
	}
}

addpara()
{
	strcpy(paras[pcount], yytext);
}

addstructpara()
{
	strcpy(structparas[spcount], yytext);
}

addstructparatype()
{
	strcpy(structparastype[spcount], yytext);
}



checkint()
{
	char typeofid[10];
	strcpy(typeofid, getreturntype(yytext, gscope));
	if(strcmp(typeofid, "int")!=0)
	{
		yyerror("\nSwitch expression should be of int type\n");
		exit(0);
	}
}

checkintstruct()
{
	char typeofid[10];
	char sname[sizec], mname[sizec];  //struct-name and member-name

	int i, k=0;
	for(i=0; currentstructvar[i]!='.';i++)
	{
		sname[k] = currentstructvar[i];
		k++;
	}
	sname[k]='\0';

	i++; k=0;
	for(;currentstructvar[i]!='\0';i++)
	{
		mname[k] = currentstructvar[i];
		k++;
	}
	mname[k]='\0';


	char stype[sizec]; //type of struct variable
	strcpy(stype, getreturntype(sname,gscope));	

	strcpy(typeofid, structgetreturntype(stype, mname, gscope));

	if(strcmp(typeofid, "int")!=0)
	{
		yyerror("\nSwitch expression should be of int type\n");
		exit(0);
	}
}


intermediateCode()
{
	char buf[100];
	f1=fopen("output","r");
	int lineno=1;
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		printf("%3d :\t%s",lineno,buf);
		lineno++;
	}

	++lineno;
	printf("  end\n");
	
//	printf("%3d :\tend\n",++lineno);
	fclose(f1);
}
