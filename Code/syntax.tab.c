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
#line 2 "./syntax.y"

    #include "lex.yy.c"
    #include <stdarg.h>
    void yyerror(char* msg);
    struct node* makeNode(char* name, int ruleId, int line, int childCnt, ...);

#line 78 "./syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_SEMI = 5,                       /* SEMI  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 7,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 8,                      /* RELOP  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_DOT = 15,                       /* DOT  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_TYPE = 17,                      /* TYPE  */
  YYSYMBOL_LP = 18,                        /* LP  */
  YYSYMBOL_RP = 19,                        /* RP  */
  YYSYMBOL_LB = 20,                        /* LB  */
  YYSYMBOL_RB = 21,                        /* RB  */
  YYSYMBOL_LC = 22,                        /* LC  */
  YYSYMBOL_RC = 23,                        /* RC  */
  YYSYMBOL_STRUCT = 24,                    /* STRUCT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_Program = 31,                   /* Program  */
  YYSYMBOL_ExtDefList = 32,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 33,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 34,                /* ExtDecList  */
  YYSYMBOL_Specifier = 35,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 36,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 37,                    /* OptTag  */
  YYSYMBOL_Tag = 38,                       /* Tag  */
  YYSYMBOL_VarDec = 39,                    /* VarDec  */
  YYSYMBOL_FunDec = 40,                    /* FunDec  */
  YYSYMBOL_VarList = 41,                   /* VarList  */
  YYSYMBOL_ParamDec = 42,                  /* ParamDec  */
  YYSYMBOL_CompSt = 43,                    /* CompSt  */
  YYSYMBOL_StmtList = 44,                  /* StmtList  */
  YYSYMBOL_Stmt = 45,                      /* Stmt  */
  YYSYMBOL_DefList = 46,                   /* DefList  */
  YYSYMBOL_Def = 47,                       /* Def  */
  YYSYMBOL_DecList = 48,                   /* DecList  */
  YYSYMBOL_Dec = 49,                       /* Dec  */
  YYSYMBOL_Exp = 50,                       /* Exp  */
  YYSYMBOL_Args = 51                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    21,    21,    26,    27,    29,    30,    31,    32,    33,
      42,    43,    45,    46,    48,    49,    51,    52,    54,    56,
      57,    59,    60,    62,    63,    65,    67,    69,    70,    72,
      73,    74,    75,    76,    77,    78,    90,    91,    93,    94,
     106,   107,   109,   110,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   131,   132
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "SEMI",
  "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND",
  "OR", "DOT", "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "ID", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -52,   -52,   -17,    15,   -52,    16,     8,   -52,    -4,
      21,   -52,   -52,   -52,   -52,    29,    41,     2,     1,    53,
      25,   -52,    26,    59,   -52,    35,   -52,   -52,    26,    43,
      35,   -52,    26,    50,    69,   -52,   -52,    60,    64,    28,
      78,    79,   -52,   -52,    68,   -52,   -10,   -52,   -52,   -52,
     -52,   120,   120,   120,   120,    66,    73,    80,   -52,    76,
      64,   132,   120,   -52,    26,   -52,   114,    58,   190,   146,
     120,   120,    98,   -52,   -52,   -52,   120,   120,   120,   120,
     120,   120,   120,   120,    75,   120,   232,   -52,   -52,   -52,
     204,   218,   -52,   161,    86,   245,   278,   114,   114,    58,
      58,   271,   258,   -52,   175,    93,    93,   120,   -52,   -52,
      83,   -52,   -52,    93,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    12,    16,     0,     2,     0,     0,    13,    18,
       0,    14,     1,     4,     6,    19,     0,    10,     0,     0,
       0,     5,     0,     0,     8,     0,     7,    39,     0,     0,
       0,    22,     0,     0,    24,    19,    11,     0,     0,    42,
       0,    40,    15,    37,    25,    21,     0,    20,    35,    60,
      61,     0,     0,     0,     0,     0,     0,    59,    30,     0,
       0,     0,     0,    38,     0,    23,    53,    54,     0,     0,
       0,     0,     0,    26,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    41,    52,    31,
       0,     0,    56,    63,     0,    44,    47,    48,    49,    50,
      51,    45,    46,    58,     0,     0,     0,     0,    55,    57,
      32,    34,    62,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   100,   -52,    85,     4,   -52,   -52,   -52,   -23,
     -52,    67,   -52,    94,    71,   -34,    70,   -52,    56,   -52,
     -51,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    16,    28,     8,    10,    11,    17,
      18,    33,    34,    58,    59,    60,    29,    30,    40,    41,
      61,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,    67,    68,    69,     7,    39,    24,     2,    22,    44,
       7,    86,     9,    14,     3,    12,    -3,     1,   -17,    90,
      91,    93,    23,    25,    32,    95,    96,    97,    98,    99,
     100,   101,   102,     2,   104,    62,    27,    15,   -36,   -36,
       3,    39,     2,    19,    31,   -36,    21,    20,    23,     3,
      32,   -36,     2,   -36,    27,    35,    93,   -36,   -36,     3,
     -36,   -36,    37,   -36,   -36,    48,    42,    49,    50,    45,
       2,   110,   111,    84,    51,    46,   -36,     3,    85,   114,
      52,    47,    53,    63,    70,    64,    25,   -27,    23,    54,
      55,    71,    56,    57,    48,    38,    49,    50,    72,    73,
      43,    49,    50,    51,   103,   108,    13,    36,    51,    52,
     113,    53,    26,    65,    52,    25,    53,    92,    54,    55,
      87,    56,    57,    49,    50,    80,    81,    57,     0,    84,
      51,    74,     0,     0,    85,     0,    52,    75,    53,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    57,
       0,    89,    85,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   112,     0,     0,     0,    85,   107,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,    85,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,    85,   109,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,    88,
      85,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,   105,    85,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,   106,    85,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,    85,    77,    78,    79,    80,
      81,    82,     0,    84,     0,     0,     0,     0,    85,    77,
      78,    79,    80,    81,     0,     0,    84,    78,    79,    80,
      81,    85,     0,    84,     0,     0,     0,     0,    85
};

static const yytype_int8 yycheck[] =
{
      51,    52,    53,    54,     0,    28,     5,    17,     6,    32,
       6,    62,    29,     5,    24,     0,     0,     1,    22,    70,
      71,    72,    20,    22,    20,    76,    77,    78,    79,    80,
      81,    82,    83,    17,    85,     7,     1,    29,     3,     4,
      24,    64,    17,    22,    19,    10,     5,    18,    20,    24,
      46,    16,    17,    18,     1,    29,   107,    22,    23,    24,
      25,    26,     3,    28,    29,     1,    23,     3,     4,    19,
      17,   105,   106,    15,    10,     6,    23,    24,    20,   113,
      16,    21,    18,     5,    18,     6,    22,    23,    20,    25,
      26,    18,    28,    29,     1,    25,     3,     4,    18,    23,
      30,     3,     4,    10,    29,    19,     6,    22,    10,    16,
      27,    18,    18,    46,    16,    22,    18,    19,    25,    26,
      64,    28,    29,     3,     4,    11,    12,    29,    -1,    15,
      10,    60,    -1,    -1,    20,    -1,    16,     5,    18,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    29,
      -1,     5,    20,     7,     8,     9,    10,    11,    12,    13,
      14,    15,   107,    -1,    -1,    -1,    20,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    21,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      20,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,     8,     9,    10,    11,
      12,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,     8,
       9,    10,    11,    12,    -1,    -1,    15,     9,    10,    11,
      12,    20,    -1,    15,    -1,    -1,    -1,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    17,    24,    31,    32,    33,    35,    36,    29,
      37,    38,     0,    32,     5,    29,    34,    39,    40,    22,
      18,     5,     6,    20,     5,    22,    43,     1,    35,    46,
      47,    19,    35,    41,    42,    29,    34,     3,    46,    39,
      48,    49,    23,    46,    39,    19,     6,    21,     1,     3,
       4,    10,    16,    18,    25,    26,    28,    29,    43,    44,
      45,    50,     7,     5,     6,    41,    50,    50,    50,    50,
      18,    18,    18,    23,    44,     5,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    20,    50,    48,    19,     5,
      50,    50,    19,    50,    51,    50,    50,    50,    50,    50,
      50,    50,    50,    29,    50,    19,    19,     6,    19,    21,
      45,    45,    51,    27,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      34,    34,    35,    35,    36,    36,    37,    37,    38,    39,
      39,    40,    40,    41,    41,    42,    43,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     3,     1,
       1,     3,     1,     1,     2,     5,     0,     1,     1,     1,
       4,     4,     3,     3,     1,     2,     4,     0,     2,     2,
       1,     3,     5,     7,     5,     1,     0,     2,     3,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     3,     1
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
  case 2: /* Program: ExtDefList  */
#line 21 "./syntax.y"
                     {
        yyval = makeNode("Program", 1, (yyloc).first_line, 1, yyvsp[0]);
        root = yyval;
    }
#line 1342 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: %empty  */
#line 26 "./syntax.y"
             { yyval = makeNode("ExtDefList", 2, (yyloc).first_line, 0); }
#line 1348 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: ExtDef ExtDefList  */
#line 27 "./syntax.y"
                        { yyval = makeNode("ExtDefList", 3, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1354 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 29 "./syntax.y"
                                   { yyval = makeNode("ExtDef", 4, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1360 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 30 "./syntax.y"
                     { yyval = makeNode("ExtDef", 5, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1366 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 31 "./syntax.y"
                              { yyval = makeNode("ExtDef", 6, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1372 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier FunDec SEMI  */
#line 32 "./syntax.y"
                            { yyval = makeNode("ExtDef", 7, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1378 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: error  */
#line 33 "./syntax.y"
            {
        errorCnt++;
        if (isErrorLine[(yyloc).first_line] == 0)
        {
            printf("Error type: B at Line %d: Wrong extern Definition.\n", (yyloc).first_line);
            isErrorLine[(yyloc).first_line] = 1;
        }
    }
#line 1391 "./syntax.tab.c"
    break;

  case 10: /* ExtDecList: VarDec  */
#line 42 "./syntax.y"
                    { yyval = makeNode("ExtDecList", 8, (yyloc).first_line, 1, yyvsp[0]); }
#line 1397 "./syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 43 "./syntax.y"
                              { yyval = makeNode("ExtDecList", 9, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1403 "./syntax.tab.c"
    break;

  case 12: /* Specifier: TYPE  */
#line 45 "./syntax.y"
                 { yyval = makeNode("Specifier", 10, (yyloc).first_line, 1, yyvsp[0]); }
#line 1409 "./syntax.tab.c"
    break;

  case 13: /* Specifier: StructSpecifier  */
#line 46 "./syntax.y"
                      { yyval = makeNode("Specifier", 11, (yyloc).first_line, 1, yyvsp[0]); }
#line 1415 "./syntax.tab.c"
    break;

  case 14: /* StructSpecifier: STRUCT Tag  */
#line 48 "./syntax.y"
                             { yyval = makeNode("StructSpecifier", 12, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1421 "./syntax.tab.c"
    break;

  case 15: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 49 "./syntax.y"
                                  { yyval = makeNode("StructSpecifier", 13, (yyloc).first_line, 5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1427 "./syntax.tab.c"
    break;

  case 16: /* OptTag: %empty  */
#line 51 "./syntax.y"
          { yyval = makeNode("OptTag", 14, (yyloc).first_line, 0); }
#line 1433 "./syntax.tab.c"
    break;

  case 17: /* OptTag: ID  */
#line 52 "./syntax.y"
         { yyval = makeNode("OptTag", 15, (yyloc).first_line, 1, yyvsp[0]); }
#line 1439 "./syntax.tab.c"
    break;

  case 18: /* Tag: ID  */
#line 54 "./syntax.y"
         { yyval = makeNode("Tag", 16, (yyloc).first_line, 1, yyvsp[0]); }
#line 1445 "./syntax.tab.c"
    break;

  case 19: /* VarDec: ID  */
#line 56 "./syntax.y"
            { yyval = makeNode("VarDec", 17, (yyloc).first_line, 1, yyvsp[0]); }
#line 1451 "./syntax.tab.c"
    break;

  case 20: /* VarDec: VarDec LB INT RB  */
#line 57 "./syntax.y"
                       { yyval = makeNode("VarDec", 18, (yyloc).first_line, 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1457 "./syntax.tab.c"
    break;

  case 21: /* FunDec: ID LP VarList RP  */
#line 59 "./syntax.y"
                          { yyval = makeNode("FunDec", 19, (yyloc).first_line, 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1463 "./syntax.tab.c"
    break;

  case 22: /* FunDec: ID LP RP  */
#line 60 "./syntax.y"
               { yyval = makeNode("FunDec", 20, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1469 "./syntax.tab.c"
    break;

  case 23: /* VarList: ParamDec COMMA VarList  */
#line 62 "./syntax.y"
                                 { yyval = makeNode("VarList", 21, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1475 "./syntax.tab.c"
    break;

  case 24: /* VarList: ParamDec  */
#line 63 "./syntax.y"
               { yyval = makeNode("VarList", 22, (yyloc).first_line, 1, yyvsp[0]); }
#line 1481 "./syntax.tab.c"
    break;

  case 25: /* ParamDec: Specifier VarDec  */
#line 65 "./syntax.y"
                            { yyval = makeNode("ParamDec", 23, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1487 "./syntax.tab.c"
    break;

  case 26: /* CompSt: LC DefList StmtList RC  */
#line 67 "./syntax.y"
                                { yyval = makeNode("CompSt", 24, (yyloc).first_line, 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1493 "./syntax.tab.c"
    break;

  case 27: /* StmtList: %empty  */
#line 69 "./syntax.y"
            { yyval = makeNode("StmtList", 25, (yyloc).first_line, 0); }
#line 1499 "./syntax.tab.c"
    break;

  case 28: /* StmtList: Stmt StmtList  */
#line 70 "./syntax.y"
                    { yyval = makeNode("StmtList", 26, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1505 "./syntax.tab.c"
    break;

  case 29: /* Stmt: Exp SEMI  */
#line 72 "./syntax.y"
                { yyval = makeNode("Stmt", 27, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1511 "./syntax.tab.c"
    break;

  case 30: /* Stmt: CompSt  */
#line 73 "./syntax.y"
             { yyval = makeNode("Stmt", 28, (yyloc).first_line, 1, yyvsp[0]); }
#line 1517 "./syntax.tab.c"
    break;

  case 31: /* Stmt: RETURN Exp SEMI  */
#line 74 "./syntax.y"
                      { yyval = makeNode("Stmt", 29, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1523 "./syntax.tab.c"
    break;

  case 32: /* Stmt: IF LP Exp RP Stmt  */
#line 75 "./syntax.y"
                        { yyval = makeNode("Stmt", 30, (yyloc).first_line, 5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1529 "./syntax.tab.c"
    break;

  case 33: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 76 "./syntax.y"
                                  { yyval = makeNode("Stmt", 31, (yyloc).first_line, 7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1535 "./syntax.tab.c"
    break;

  case 34: /* Stmt: WHILE LP Exp RP Stmt  */
#line 77 "./syntax.y"
                           { yyval = makeNode("Stmt", 32, (yyloc).first_line, 5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1541 "./syntax.tab.c"
    break;

  case 35: /* Stmt: error  */
#line 78 "./syntax.y"
            {
        for (int i = (yyloc).first_line; i <= (yyloc).last_line; i++)
        {
            errorCnt++;
            if (isErrorLine[i] == 0)
            {
                printf("Error type: B at Line %d: Wrong Statements.\n", i);
                isErrorLine[i] = 1;
            }
        }
    }
#line 1557 "./syntax.tab.c"
    break;

  case 36: /* DefList: %empty  */
#line 90 "./syntax.y"
           { yyval = makeNode("DefList", 33, (yyloc).first_line, 0); }
#line 1563 "./syntax.tab.c"
    break;

  case 37: /* DefList: Def DefList  */
#line 91 "./syntax.y"
                  { yyval = makeNode("DefList", 34, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1569 "./syntax.tab.c"
    break;

  case 38: /* Def: Specifier DecList SEMI  */
#line 93 "./syntax.y"
                             { yyval = makeNode("Def", 35, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1575 "./syntax.tab.c"
    break;

  case 39: /* Def: error  */
#line 94 "./syntax.y"
            {
        for (int i = (yyloc).first_line; i <= (yyloc).last_line; i++)
        {
            errorCnt++;
            if (isErrorLine[i] == 0)
            {
                printf("Error type: B at Line %d: Wrong Statements.\n", i);
                isErrorLine[i] = 1;
            }
        }
    }
#line 1591 "./syntax.tab.c"
    break;

  case 40: /* DecList: Dec  */
#line 106 "./syntax.y"
              { yyval = makeNode("DecList", 36, (yyloc).first_line, 1, yyvsp[0]); }
#line 1597 "./syntax.tab.c"
    break;

  case 41: /* DecList: Dec COMMA DecList  */
#line 107 "./syntax.y"
                        { yyval = makeNode("DecList", 37, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1603 "./syntax.tab.c"
    break;

  case 42: /* Dec: VarDec  */
#line 109 "./syntax.y"
             { yyval = makeNode("Dec", 38, (yyloc).first_line, 1, yyvsp[0]); }
#line 1609 "./syntax.tab.c"
    break;

  case 43: /* Dec: VarDec ASSIGNOP Exp  */
#line 110 "./syntax.y"
                          { yyval = makeNode("Dec", 39, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1615 "./syntax.tab.c"
    break;

  case 44: /* Exp: Exp ASSIGNOP Exp  */
#line 112 "./syntax.y"
                       { yyval = makeNode("Exp", 40, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1621 "./syntax.tab.c"
    break;

  case 45: /* Exp: Exp AND Exp  */
#line 113 "./syntax.y"
                  { yyval = makeNode("Exp", 41, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1627 "./syntax.tab.c"
    break;

  case 46: /* Exp: Exp OR Exp  */
#line 114 "./syntax.y"
                 { yyval = makeNode("Exp", 42, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1633 "./syntax.tab.c"
    break;

  case 47: /* Exp: Exp RELOP Exp  */
#line 115 "./syntax.y"
                    { yyval = makeNode("Exp", 43, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1639 "./syntax.tab.c"
    break;

  case 48: /* Exp: Exp PLUS Exp  */
#line 116 "./syntax.y"
                   { yyval = makeNode("Exp", 44, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1645 "./syntax.tab.c"
    break;

  case 49: /* Exp: Exp MINUS Exp  */
#line 117 "./syntax.y"
                    { yyval = makeNode("Exp", 45, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1651 "./syntax.tab.c"
    break;

  case 50: /* Exp: Exp STAR Exp  */
#line 118 "./syntax.y"
                   { yyval = makeNode("Exp", 46, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1657 "./syntax.tab.c"
    break;

  case 51: /* Exp: Exp DIV Exp  */
#line 119 "./syntax.y"
                  { yyval = makeNode("Exp", 47, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1663 "./syntax.tab.c"
    break;

  case 52: /* Exp: LP Exp RP  */
#line 120 "./syntax.y"
                { yyval = makeNode("Exp", 48, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1669 "./syntax.tab.c"
    break;

  case 53: /* Exp: MINUS Exp  */
#line 121 "./syntax.y"
                { yyval = makeNode("Exp", 49, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1675 "./syntax.tab.c"
    break;

  case 54: /* Exp: NOT Exp  */
#line 122 "./syntax.y"
              { yyval = makeNode("Exp", 50, (yyloc).first_line, 2, yyvsp[-1], yyvsp[0]); }
#line 1681 "./syntax.tab.c"
    break;

  case 55: /* Exp: ID LP Args RP  */
#line 123 "./syntax.y"
                    { yyval = makeNode("Exp", 51, (yyloc).first_line, 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1687 "./syntax.tab.c"
    break;

  case 56: /* Exp: ID LP RP  */
#line 124 "./syntax.y"
               { yyval = makeNode("Exp", 52, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1693 "./syntax.tab.c"
    break;

  case 57: /* Exp: Exp LB Exp RB  */
#line 125 "./syntax.y"
                    { yyval = makeNode("Exp", 53, (yyloc).first_line, 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1699 "./syntax.tab.c"
    break;

  case 58: /* Exp: Exp DOT ID  */
#line 126 "./syntax.y"
                 { yyval = makeNode("Exp", 54, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1705 "./syntax.tab.c"
    break;

  case 59: /* Exp: ID  */
#line 127 "./syntax.y"
         { yyval = makeNode("Exp", 55, (yyloc).first_line, 1, yyvsp[0]); }
#line 1711 "./syntax.tab.c"
    break;

  case 60: /* Exp: INT  */
#line 128 "./syntax.y"
          { yyval = makeNode("Exp", 56, (yyloc).first_line, 1, yyvsp[0]); }
#line 1717 "./syntax.tab.c"
    break;

  case 61: /* Exp: FLOAT  */
#line 129 "./syntax.y"
            { yyval = makeNode("Exp", 57, (yyloc).first_line, 1, yyvsp[0]); }
#line 1723 "./syntax.tab.c"
    break;

  case 62: /* Args: Exp COMMA Args  */
#line 131 "./syntax.y"
                      { yyval = makeNode("Args", 58, (yyloc).first_line, 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1729 "./syntax.tab.c"
    break;

  case 63: /* Args: Exp  */
#line 132 "./syntax.y"
          { yyval = makeNode("Args", 59, (yyloc).first_line, 1, yyvsp[0]); }
#line 1735 "./syntax.tab.c"
    break;


#line 1739 "./syntax.tab.c"

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

#line 134 "./syntax.y"

void yyerror(char* msg) {
    //printf("%s\n", msg);
}
struct node* makeNode(char* name, int ruleId, int line, int childCnt, ...)
{
    struct node* now = (struct node*)malloc(sizeof(struct node));
    now->line = line;
    now->ruleId = ruleId;
    now->type = SYNTAX_UNIT;
    now->name = name;
    now->childCnt = childCnt;
    memset(now->data.strVal, 0, sizeof(now->data.strVal));
    va_list ap;
    va_start(ap, childCnt);
    for (int i = 0; i < childCnt; i++)
        now->child[i] = va_arg(ap, struct node*);
    return now;
}
