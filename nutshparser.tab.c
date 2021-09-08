/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "nutshparser.y"


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "global.h"
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <fcntl.h>
#include <wordexp.h>


#include <stdbool.h>
int parsePath(void);
int yylex(void);
int yyerror(char *s);
int runCD(char* dir);
int runSetAlias(char *name, char *word);
int runLS(void);
int runEcho(char *s);
int runPrintEnv(void);
int runSetEnv(char *name, char *value);
int runUnsetEnv(char *var);
int unAlias(char* al);
int printAl(void);
int cmndLong2(void);
char* hasFile(char* file);

int addToCommand(char* cm);
int pipefunction(void);
int  wildcardFunc();
bool aliasLoopDetect(char* name, char* word);
char* Alexpansion(char* word);
char* envExpansion(char* cmnd);
char* envExpansionForUnset(char* cmnd);


#line 110 "nutshparser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_NUTSHPARSER_TAB_H_INCLUDED
# define YY_YY_NUTSHPARSER_TAB_H_INCLUDED
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
    BYE = 258,
    CD = 259,
    UNSETENV = 260,
    ANYSTRING = 261,
    ALIASCOM = 262,
    LEFTCURLY = 263,
    END = 264,
    PIPE = 265,
    UNALIAS = 266,
    INPUT = 267,
    AND = 268,
    RIGHTCURLY = 269,
    STRING = 270,
    SETENV = 271,
    ALIAS = 272,
    OUTPUT = 273,
    BACKSLASH = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "nutshparser.y"
char* string;

#line 185 "nutshparser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NUTSHPARSER_TAB_H_INCLUDED  */



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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   20

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  20
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  12
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  26

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    51,    51,    52,    56,    57,    59,    60,    61,    62,
      63,    66,    67
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BYE", "CD", "UNSETENV", "ANYSTRING",
  "ALIASCOM", "LEFTCURLY", "END", "PIPE", "UNALIAS", "INPUT", "AND",
  "RIGHTCURLY", "STRING", "SETENV", "ALIAS", "OUTPUT", "BACKSLASH",
  "$accept", "cmd_line", "myCommand", "built_in", "nonBuilt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274
};
# endif

#define YYPACT_NINF (-11)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,    -5,   -10,    -9,    -8,   -11,    -4,    10,     5,     6,
      -6,   -11,     7,     8,     9,     4,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,    11,   -11
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     1,     2,     5,     3,
      12,     7,     9,    10,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -11,   -11,   -11,   -11,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,     2,     3,    19,    11,    12,    13,    14,     4,    20,
      16,    15,     5,     6,    17,    18,    21,    22,    23,    24,
      25
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     9,     9,    15,    15,    15,    11,    15,
       0,    15,    15,    16,     9,     9,     9,     9,     9,    15,
       9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    11,    15,    16,    21,    22,    23,
      24,     9,    15,    15,    15,    15,     0,     9,     9,     9,
      15,     9,     9,     9,    15,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    20,    21,    21,    22,    22,    23,    23,    23,    23,
      23,    24,    24
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     0,     3,     4,     3,
       3,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 51 "nutshparser.y"
                                                                {return 1;}
#line 1365 "nutshparser.tab.c"
    break;

  case 3:
#line 52 "nutshparser.y"
                                                                        {cmndLong2(); return 1;}
#line 1371 "nutshparser.tab.c"
    break;

  case 4:
#line 56 "nutshparser.y"
                                                {exit(1); return 1; }
#line 1377 "nutshparser.tab.c"
    break;

  case 5:
#line 57 "nutshparser.y"
                                        {return 1;}
#line 1383 "nutshparser.tab.c"
    break;

  case 7:
#line 60 "nutshparser.y"
                                                {runCD((yyvsp[-1].string)); return 1;}
#line 1389 "nutshparser.tab.c"
    break;

  case 8:
#line 61 "nutshparser.y"
                                                {runSetEnv((yyvsp[-2].string), (yyvsp[-1].string)); return 1;}
#line 1395 "nutshparser.tab.c"
    break;

  case 9:
#line 62 "nutshparser.y"
                                                {runUnsetEnv((yyvsp[-1].string)); return 1;}
#line 1401 "nutshparser.tab.c"
    break;

  case 10:
#line 63 "nutshparser.y"
                                                {unAlias((yyvsp[-1].string)); return 1;}
#line 1407 "nutshparser.tab.c"
    break;

  case 11:
#line 66 "nutshparser.y"
                                                                                                {addToCommand((yyvsp[0].string));}
#line 1413 "nutshparser.tab.c"
    break;

  case 12:
#line 67 "nutshparser.y"
                                                                                        {addToCommand((yyvsp[0].string));}
#line 1419 "nutshparser.tab.c"
    break;


#line 1423 "nutshparser.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 70 "nutshparser.y"


int yyerror(char *s) {
  printf("%s\n",s);
  return 0;
  }

int runCD(char* dir) {
	char* temp= Alexpansion(dir);
	char* arg=envExpansion(temp);
	wordexp_t patt;
    char **words;
	bool wild=false;
	char getrid;
	for (int i=0; i<strlen(dir); i++){
		if (dir[i]=='*'|| dir[i]=='?'){
			wild = true;
			getrid=dir[i];
		}
	}
	if (wild == true){
    if (wordexp(dir, &patt, 0) != 0){
		printf("error in expanding wildcard");
	}
    words = patt.we_wordv;
	if (patt.we_wordc==0){
		char * t=malloc(sizeof(dir)+1);
		strcpy(t,dir);
		char *src, *dst;
    	for (src = dst = t; *src != '\0'; src++) {
        	*dst = *src;
        	if (*dst != getrid) dst++;
    	}
    	*dst = '\0';
		arg=t;
	}
	else{
		arg = words[0];
	}
	}



	if (arg[0] != '/') { // arg is relative path
		strcat(varTable.word[0], "/");
		strcat(varTable.word[0], arg);

		if(chdir(varTable.word[0]) == 0) {
			return 1;
		}
		else {
			getcwd(cwd, sizeof(cwd));
			strcpy(varTable.word[0], cwd);
			printf("Directory not found\n");
			return 1;
		}
	}
	else { // arg is absolute path
		if(chdir(arg) == 0){
			strcpy(varTable.word[0], arg);
			return 1;
		}
		else {
			printf("Directory not found\n");
                       	return 1;
		}
	}
}

bool aliasLoopDetect(char* name, char* word){
	bool here=false;
	int index=0;
	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(name, word) == 0){
			return true;
		}
		else if((strcmp(aliasTable.name[i], name) == 0) && (strcmp(aliasTable.word[i], word) == 0)){
			return true;
		}
	}
	
	return false;

}



int runSetAlias(char *name, char *word) {
	
	if (aliasLoopDetect(name,word)==false){
	strcpy(aliasTable.name[aliasIndex], name);
	strcpy(aliasTable.word[aliasIndex], word);
	aliasIndex++;}
	else{
		printf("Error, expansion of \"%s\" would create a loop.\n", name);
	}

	return 1;
}


int runPrintEnv() {
	for(int i = 0; i < varIndex; i++)
		printf("%s = %s\n", varTable.var[i], varTable.word[i]);
	return 1;
}

int runSetEnv(char *variable, char *word) {
	if(strcmp(varTable.var[0], variable) == 0)
		printf("cannot set this variable\n");
	if(strcmp(varTable.var[1], variable) == 0)
		printf("cannot set this variable\n");
	if(strcmp(varTable.var[2], variable) == 0)
		printf("cannot set this variable\n");
	if(strcmp(varTable.var[3], variable) == 0) {
		if(strcmp(varTable.word[3], "") != 0)
			strcat(varTable.word[3], ":");
		strcat(varTable.word[3], word);
	}
	
	else {
		setenv(variable, word, 1);
		strcpy(varTable.var[varIndex], variable);
		strcpy(varTable.word[varIndex], word);
		varIndex++;
	}
}

int runUnsetEnv(char *var) {
	char* variable= Alexpansion(var);
	bool present = false;
	int currIndex = 0;
	for(int i = 0; i < varIndex; i++) {
		if(strcmp(varTable.var[i], variable) == 0) {
			present = true;
			currIndex = i;
			break;
		}
	}
	if(present) {
		if(strcmp(varTable.var[0], variable) == 0)
			printf("cannot unset this variable\n");
		else if (strcmp(varTable.var[1], variable) == 0)
			printf("cannot unset this variable\n");
		else if (strcmp(varTable.var[2], variable) == 0)
			printf("cannot unset this variable\n");
		else if (strcmp(varTable.var[3], variable) == 0)
			printf("cannot unset this variable\n");
		else {
			strcpy(varTable.var[currIndex], "");
			strcpy(varTable.word[currIndex], "");
			varIndex--;
		}
		return 1;
	}
	else {
		printf("environment variable does not exist\n");
		return -1;
	}

}

int unAlias(char* al){
	char * word=envExpansionForUnset(al);
	for (int i=0; i<aliasIndex; i++){
		if (strcmp(aliasTable.name[i],word)==0){
			strcpy(aliasTable.name[i], "");
			strcpy(aliasTable.word[i], "");
			if (aliasIndex>1){
			for (int k=i+1; k<aliasIndex; k++){
				strcpy(aliasTable.name[k-1], aliasTable.name[k]);
				strcpy(aliasTable.word[k-1], aliasTable.word[k]);
			}
			}
			aliasIndex--;
			break;
		}

	}
	return 1;


}


int printAl(void){
	for (int i=0; i<aliasIndex; i++){
		printf("%s=%s \n",aliasTable.name[i], aliasTable.word[i]);
	}

	return 1;

}




int cmndLong2(void){
	char* pa;
	parsePath();
	bool foundPath=true;

	if (numPipes==0){
	if (commandStructTable.printenv[0]==false && commandStructTable.printalias[0]==false){
	if (commandStructTable.path[0]==true){
		foundPath=false;
		pa =hasFile(commandStructTable.command[0][0]);
		if (strcmp(pa,"none")!=0){
			foundPath=true;
		}
	}
	else{
		pa=malloc(sizeof(commandStructTable.command[0][0])+1);
		strcpy(pa,commandStructTable.command[0][0]);
		foundPath=true;
	}}
	if (foundPath==false){
		printf("could not find the executable in the path \n");
		return 1;
	}

	int status;
	int pid=fork();
	if (pid==0){
		if (commandStructTable.output[0]==true) { 
        	int fil = creat(commandStructTable.fileOut[0], O_TRUNC);
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.append[0]==true) { 
        	int fil = open(commandStructTable.fileOut[0], 'a');
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.input[0]==true) { 
        	int fil = open(commandStructTable.fileIn[0], O_RDONLY);
        	dup2(fil, STDIN_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.fileEr[0]==true){
			int fil = creat(commandStructTable.fileError[0], O_TRUNC);
			dup2(fil, STDERR_FILENO);
			close(fil);
		}
		else if (commandStructTable.errorOut[0]==true){
			dup2(STDOUT_FILENO, STDERR_FILENO);
		}



		if (commandStructTable.printalias[0]==true && commandStructTable.size[0]>0 && strcmp(commandStructTable.command[0][0],">")!=0&&strcmp(commandStructTable.command[0][0],">>")!=0){
			runSetAlias(commandStructTable.command[0][0],commandStructTable.command[0][1]);
		}
		else if (commandStructTable.printalias[0]==true){
			printAl();
		}
		else if (commandStructTable.printenv[0]==true){
			runPrintEnv();
		}
		else {
			execv(pa,commandStructTable.command[0]);
		}
		}
	else{
		if (background==false){
		waitpid(-1, NULL, 0);}
	}
	for (int i=0; i<commandStructTable.size[0]; i++){
		commandStructTable.command[0][i]=NULL;
	}
		commandStructTable.size[0]=0;
		commandStructTable.output[0]=false;
		commandStructTable.input[0]=false;
		commandStructTable.fileIn[0]=NULL;
		commandStructTable.fileOut[0]=NULL;
		commandStructTable.fileError[0]=false;
		commandStructTable.errorOut[0]=false;
		commandStructTable.fileError[0]=NULL;
		commandStructTable.printenv[0]=false;
		commandStructTable.printalias[0]=false;
		commandStructTable.path[0]=false;

	}


	else{
	pipefunction();
	}
	background=false;
	numPipes=0;
	return 1;
}

int pipefunction(void){
	bool foundPath=true;
	int count=0;
	int pipeOutside[numPipes][2];
	for (int i=0; i<numPipes;i++){
	if (pipe(pipeOutside[i])<0){
		printf("error in creating pipes");
		return 1;
	}}

	for (int i=0; i<numPipes+1;i++){
		count++;

		char* pa;
		if (commandStructTable.printenv[i]==false && commandStructTable.printalias[i]==false){
		if (commandStructTable.path[i]==true){
			pa =hasFile(commandStructTable.command[i][0]);
			if (strcmp(pa,"none")!=0){
				foundPath=true;
			}
		}
		else{
			pa=malloc(sizeof(commandStructTable.command[i][0])+1);
			strcpy(pa,commandStructTable.command[i][0]);
			
			foundPath=true;
		}}

		if (foundPath==false){
			printf("could not find executable in the path");
			return 1;
		}

		if (fork()==0){
			 if (i != numPipes){
				dup2(pipeOutside[i][1],STDOUT_FILENO);
			}
			if (i !=0){
				dup2(pipeOutside[i-1][0],STDIN_FILENO);
			}

			if (commandStructTable.output[i]==true) { 
        		int fil = creat(commandStructTable.fileOut[i], O_TRUNC);
        		dup2(fil, STDOUT_FILENO);
        		close(fil);
    		}   
			if (commandStructTable.append[i]==true) { 
        		int fil = open(commandStructTable.fileOut[i], 'a');
        		dup2(fil, STDOUT_FILENO);
        		close(fil);
    		}   
			if (commandStructTable.input[i]==true) { 
        		int fil = open(commandStructTable.fileIn[i], O_RDONLY);
        		dup2(fil, STDIN_FILENO);
        		close(fil);
    		}   
			if (commandStructTable.fileEr[i]==true){
				int fil = creat(commandStructTable.fileError[i], O_TRUNC);
				dup2(fil, STDERR_FILENO);
				close(fil);
			}
			else if (commandStructTable.errorOut[i]==true){
				dup2(STDOUT_FILENO, STDERR_FILENO);
			}

			if (commandStructTable.printalias[i]==true){
				printAl();
			}
			else if (commandStructTable.printenv[i]==true){
				runPrintEnv();
			}
			else{
				execv(pa,commandStructTable.command[i]);
			}
		}
	else{
			if (i != numPipes){
				close(pipeOutside[i][1]);
			}
			if (i==numPipes && background==false){
				waitpid(-1,NULL,0);
			}
	}	
	}
	for (int i=0; i<numPipes+1;i++){
		for (int j=0; j<commandStructTable.size[i];j++){
			commandStructTable.command[i][j]=NULL;
		}
		commandStructTable.size[i]=0;
		commandStructTable.output[i]=false;
		commandStructTable.input[i]=false;
		commandStructTable.fileIn[i]=NULL;
		commandStructTable.fileOut[i]=NULL;
		commandStructTable.fileError[i]=false;
		commandStructTable.errorOut[i]=false;
		commandStructTable.fileError[i]=NULL;
		commandStructTable.printenv[i]=false;
		commandStructTable.printalias[i]=false;
		commandStructTable.path[i]=false;
	}
	numPipes=0;
	if (background==false){
	waitpid(-1, NULL, 0);}
	background=false;

	return 0;


}



int parsePath(void)
{
	char * cmnd = malloc(strlen(varTable.word[3]) + 1); 
	strcpy(cmnd, varTable.word[3]);

	int count=1;
	for (int i=0; i<strlen(cmnd); i++){
		if (cmnd[i]==':'){
			numPaths++;
			count++;
		}
	}
	numPaths=count;
	int size=count+1;
	count=0;
	char* ptr= strtok(cmnd, ":");
	while (ptr!=NULL){
		pathsVar[count]=ptr;
		count++;
		ptr= strtok(NULL, ":");
	}
	for (int i=0; i<numPaths;i++){
		pathsVar[i];
	}	
	return 1;
}


char* hasFile(char* file)
{
	struct stat   buffer;
	bool found=false;
	for (int i=0; i<numPaths; i++){
		char* temp=malloc(sizeof(pathsVar[i])+sizeof(file)+sizeof("/")+1);
		strcpy(temp,pathsVar[i]);
		strcat(temp,"/");
		strcat(temp,file);
		if (stat (temp, &buffer) == 0){
			found=true;
			return temp;
		}
	}  
  return "none";

}

int addToCommand(char* cm)
{
	if (strcmp(cm," ")==0){
		return 1;
	}
	char * temp=Alexpansion(cm);
	char * temp2=envExpansion(temp);
	if (addFileIn==true  && strcmp(temp2,">>")!=0 && strcmp(temp2,">")!=0){
		commandStructTable.fileIn[numPipes]=temp2;
		addFileIn=false;
		//printf("in file :%s \n",temp2);
	}
	else if (addFileOut==true && strcmp(temp2,"<")!=0){
		commandStructTable.fileOut[numPipes]=temp2;
		addFileOut=false;
		//printf("out file :%s \n",temp2);
	}
	else if (strcmp(temp2,">")==0){
		commandStructTable.output[numPipes]=true;
		addFileOut=true;
	}
	else if (strcmp(temp2,">>")==0){
		commandStructTable.append[numPipes]=true;
		addFileOut=true;
	}
	else if (strcmp(temp2,"<")==0){
		commandStructTable.input[numPipes]=true;
		addFileIn=true;
	}
	else if (strcmp(temp2, "2>&1")==0){
		commandStructTable.errorOut[numPipes]=true;
	}
	else if (temp2[0]=='2' && temp2[1]=='>'){
		commandStructTable.errorOut[numPipes]=true;
		char* fil= calloc(strlen(temp2)-2,sizeof(char));
		for (int i=2; i<strlen(temp2);i++){
			fil[i-2]=temp2[i];
		}
		commandStructTable.fileEr[numPipes]=true;
		commandStructTable.fileError[numPipes]=fil;
	}
	else if (strcmp(temp2,"&")==0){
		background=true;
	}
	else if (strcmp(temp2,"printenv")==0){
		commandStructTable.printenv[numPipes]=true;
		commandStructTable.path[numPipes]=false;
	}
	else if (strcmp(temp2,"alias")==0){
		commandStructTable.printalias[numPipes]=true;
		commandStructTable.path[numPipes]=false;
	}
	else if (strcmp(temp2,"|")!=0){
		if (commandStructTable.size[numPipes]==0){
			addFileIn=false;
			addFileOut=false;
			if (temp2[0]=='/' || temp2[0]=='.' || commandStructTable.printalias[numPipes]==true || commandStructTable.printenv[numPipes]==true){
				commandStructTable.path[numPipes]=false;}
			else {
				commandStructTable.path[numPipes]=true;
			}
		}
		char* command;
		int start=0;
		for (int i=0; i<strlen(temp2);i++){
			if (temp2[i]=='*'|| temp2[i]=='?'){
				return wildcardFunc(temp2);
			}
			if (temp2[i]==' '){
				char* tempCommand=calloc(i-start,sizeof(char));
				for (int j=start;j<i;j++ ){
					tempCommand[j-start]=temp2[j];
				}
				start=i+1;
				commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=tempCommand;
				commandStructTable.size[numPipes]++;
			}
		}
		if (start==0){
			commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=temp2;
			commandStructTable.size[numPipes]++;}
		else{
				char* tempCommand=calloc(strlen(temp2)-start,sizeof(char));
				for (int j=start;j<strlen(temp2);j++ ){
					tempCommand[j-start]=temp2[j];
				}
				commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=tempCommand;
				commandStructTable.size[numPipes]++;
		}
	}
	else if (strcmp(temp2,"|")==0){
		numPipes++;
		commandStructTable.size[numPipes]=0;
		commandIndex=0;
	}
	else {
		printf("error input %s \n",temp2);
	}
	commandIndex++;
	return 1;
}


char* Alexpansion(char* cmnd) {

		int start=0;
		int end=strlen(cmnd);
		bool starting=false;
		for (int j=0; j<strlen(cmnd); j++){
			if (starting==false && (isalpha(cmnd[j]) || isdigit(cmnd[j])) ){
				start=j;
				starting=true;
			}
			if (starting==true && (isalpha(cmnd[j])==false && isdigit(cmnd[j])==false) ){
				end=j;
				break;
			}
		}
		char* begging=calloc(start,sizeof(char));
		char* ending=calloc(strlen(cmnd)-end+1,sizeof(char));
		for (int i=0; i<strlen(cmnd);i++){
			if (i<start){
				begging[i]=cmnd[i];
			}
			if (i>=end){
				ending[i-end]=cmnd[i];
			}
		}

		char* check=calloc(end-start,sizeof(char));
		for (int i=0; i<(end-start); i++){
			check[i]=cmnd[start+i];
		}
			for (int i = 0; i < aliasIndex; i++) {
				if(strcmp(aliasTable.name[i], check) == 0){
					char* middle= Alexpansion(aliasTable.word[i]);
					char* whole=malloc(sizeof(middle)+sizeof(begging)+sizeof(ending)+1);
					strcpy(whole,begging);
					strcat(whole,middle);
					strcat(whole,ending);
					return whole;
				}
			}
			return cmnd;

}


char* envExpansion(char* cmnd) {
	int iDelete=100;
	int indexC=0;
	bool startString=false;
	bool first=false;
	for (int i=0; i<strlen(cmnd); i++){
		if (cmnd[i]=='$' && startString==false){
			startString=true;
			iDelete=i;
		}
		if (cmnd[i]=='}' && startString==true && first==false){
			first=true;
			indexC=i;
		}
	}

	

	if (startString==true){
		bool startword=false;
		bool endWord=false;
		char* begging=calloc(iDelete,sizeof(char));
		char* word=calloc(indexC-iDelete-2,sizeof(char));
		char* end=calloc(strlen(cmnd)-indexC,sizeof(char));
		for (int i=0;i<iDelete;i++){
			begging[i]=cmnd[i];
		}
		int counter=0;
		for (int i=iDelete+2; i<indexC;i++){
			if (cmnd[i]=='{'){}
			else if (cmnd[i]=='}'){
				indexC=i;
				break;
			}
			else{
				word[counter]=cmnd[i];
				counter++;
			}
		}
		counter=0;
		for (int i=indexC+1; i<strlen(cmnd);i++){
			end[counter]=cmnd[i];
			counter++;
		}

		bool not=true;
		for(int i = 0; i < varIndex; i++) {
			if(strcmp(varTable.var[i], word) == 0) {
				char* temperary=malloc(sizeof(varTable.word[i])+1);
				strcpy(temperary,varTable.word[i]);
				word=Alexpansion(temperary);
				not=false;
			}
		}
		if (not==true){
			return cmnd;
		}		
		char* r=calloc(strlen(begging)+strlen(word)+strlen(end),sizeof(char));
		strcpy(r,begging);
		strcat(r,word);

		strcat(r,end);
		return envExpansion(r);


	}

	return cmnd;

}

char* envExpansionForUnset(char* cmnd){
	int iDelete=100;
	int indexC=0;
	bool startString=false;
	bool first=false;
	for (int i=0; i<strlen(cmnd); i++){
		if (cmnd[i]=='$' && startString==false){
			startString=true;
			iDelete=i;
		}
		if (cmnd[i]=='}' && startString==true && first==false){
			first=true;
			indexC=i;
		}
	}

	

	if (startString==true){
		bool startword=false;
		bool endWord=false;
		char* begging=calloc(iDelete,sizeof(char));
		char* word=calloc(indexC-iDelete-2,sizeof(char));
		char* end=calloc(strlen(cmnd)-indexC,sizeof(char));
		for (int i=0;i<iDelete;i++){
			begging[i]=cmnd[i];
		}
		int counter=0;
		for (int i=iDelete+2; i<indexC;i++){
			if (cmnd[i]=='{'){}
			else if (cmnd[i]=='}'){
				indexC=i;
				break;
			}
			else{
				word[counter]=cmnd[i];
				counter++;
			}
		}
		counter=0;
		for (int i=indexC+1; i<strlen(cmnd);i++){
			end[counter]=cmnd[i];
			counter++;
		}

		bool not=true;
		for(int i = 0; i < varIndex; i++) {
			if(strcmp(varTable.var[i], word) == 0) {
				word=malloc(sizeof(varTable.word[i])+1);
				strcpy(word,varTable.word[i]);
				not=false;
			}
		}
		if (not==true){
			return cmnd;
		}		
		char* r=calloc(strlen(begging)+strlen(word)+strlen(end),sizeof(char));
		strcpy(r,begging);
		strcat(r,word);

		strcat(r,end);
		return envExpansion(r);


	}

	return cmnd;
}


int wildcardFunc(char* cm){
    wordexp_t patt;
    char **words;
	char getrid;
	for (int i=0; i<strlen(cm); i++){
		if (cm[i]=='*'|| cm[i]=='?'){
			getrid=cm[i];
		}
	}

    if (wordexp(cm, &patt, 0) != 0){
		printf("error in expanding wildcard");
	}
    words = patt.we_wordv;
	if (patt.we_wordc==0){
		char * t=malloc(sizeof(cm)+1);
		strcpy(t,cm);
		char *src, *dst;
    	for (src = dst = t; *src != '\0'; src++) {
        	*dst = *src;
        	if (*dst != getrid) dst++;
    	}
    	*dst = '\0';
		printf("%s \n",t);
		commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=t;
		commandStructTable.size[numPipes]++;
		return 1;
	}
    for (int i = 0; i < patt.we_wordc; i++){
		commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=words[i];
		commandStructTable.size[numPipes]++;
	}
	return 1;
}
