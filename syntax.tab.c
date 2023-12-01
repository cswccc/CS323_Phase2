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
#line 1 "syntax.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include <unordered_map>
    #include <list>
    #define true 1
    #define false 0
    using namespace std;

    struct parsetree
    {
        string name;
        string id;
        string type;
        list<string> argsList;
        int dim = -1; //当前数据的维度
        struct parsetree* left_son;
        struct parsetree* right_son;
        struct parsetree* nxt_bro;
        int line;
    };
    #define YYSTYPE struct parsetree*

    int tot = 0;

    unordered_map<string, pair<string, int> > para_type;
    unordered_map<string, string> func_type;
    unordered_map<string, list<string>> func_args;

    void my_yyerror(const string s,int line);
    void yyerror(const string s);
    struct parsetree* create(const string to_name);
    struct parsetree* create_add(const string to_name,const char* to_add);
    void add_son(struct parsetree* parent,struct parsetree* son);

    void decListIt(struct parsetree* root, string type);
    pair<string, int> getType(string id);

    int checkType(const parsetree* p1, const parsetree* p2);
    pair<string, int> getParaType(string id);
    string getFuncType(string id);

    void output(struct parsetree* root,int dep);
    void varListIt(struct parsetree* root,list<string>& re);

    #include "lex.yy.c"

#line 120 "syntax.tab.c"

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
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    FLOAT = 259,
    CHAR = 260,
    ID = 261,
    TYPE = 262,
    STRUCT = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    RETURN = 267,
    DOT = 268,
    SEMI = 269,
    COMMA = 270,
    ASSIGN = 271,
    LT = 272,
    LE = 273,
    GT = 274,
    GE = 275,
    NE = 276,
    EQ = 277,
    PLUS = 278,
    MINUS = 279,
    MUL = 280,
    DIV = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    LP = 285,
    RP = 286,
    LB = 287,
    RB = 288,
    LC = 289,
    RC = 290,
    STRING = 291,
    UNDEFINE = 292,
    BITAND = 293,
    BITOR = 294,
    BITXOR = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    95,    96,    98,    99,   100,   102,   103,
     105,   106,   108,   109,   110,   112,   113,   117,   119,   120,
     121,   122,   124,   125,   127,   129,   131,   133,   134,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   150,   151,   153,   158,   160,   161,   169,   170,   180,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   199,   208,   210,   220,
     230,   234,   238,   240,   242,   244,   253,   258,   263,   268,
     272,   274,   275,   278,   279
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "DOT", "SEMI", "COMMA",
  "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ", "PLUS", "MINUS", "MUL",
  "DIV", "AND", "OR", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "STRING",
  "UNDEFINE", "BITAND", "BITOR", "BITXOR", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Operate", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -54,    14,    45,   -54,    76,   132,   -54,   -22,   -54,
     -54,    13,   -54,    47,   -10,    56,    76,    55,   -54,    83,
      84,    76,   -54,    83,     6,    76,   -54,   -54,    83,    26,
      80,   -54,   -54,    22,   203,    -8,    46,    96,   -54,   -54,
     -54,    64,   -54,   -54,    76,   -54,   -54,   -54,   -54,   -54,
      88,   112,   113,   157,   214,   214,   214,   -54,   -54,    18,
     203,   -54,    12,   165,   -54,   -54,    83,   -54,   149,   214,
     214,   100,    53,   320,   320,    81,   -54,   -54,   -54,   -54,
     133,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   214,   -54,   -54,   -54,   199,
     -54,   320,   -54,   -54,   -54,   236,    57,   109,   264,   -54,
     -54,   -54,   -54,   -54,   -54,   292,   -54,   320,   214,   -54,
     -54,   203,   203,   203,   -54,   -54,   134,   135,   -54,   203,
     203,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    10,     0,     0,     2,     4,     0,    11,    14,     1,
       3,    15,     6,     0,     8,     0,    42,     0,     5,     0,
       0,    42,     7,     0,     0,    42,    21,    20,     0,     0,
      23,    15,     9,     0,    28,    47,     0,    45,    13,    12,
      41,    24,    19,    18,     0,    17,    16,    76,    77,    78,
      75,     0,     0,     0,     0,     0,     0,    79,    32,     0,
      28,    31,     0,     0,    44,    43,     0,    22,     0,     0,
       0,     0,     0,    71,    72,     0,    26,    25,    27,    30,
       0,    29,    50,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    51,    52,     0,    63,    64,    65,     0,
      49,    48,    46,    82,    73,    84,     0,     0,     0,    35,
      34,    33,    81,    70,    74,     0,    80,    69,     0,    67,
      66,     0,     0,     0,    68,    83,    37,    36,    40,     0,
       0,    39,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   146,   -54,   137,     4,   -54,   -17,   -54,   115,
     -54,   142,   104,    -6,    -7,    43,    99,   -54,   -54,   -53,
      49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    23,     7,    14,    15,    29,
      30,    58,    59,    60,    24,    61,    36,    37,    99,    62,
     106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,    73,    74,    75,     6,    19,    35,    38,    63,     6,
     101,    41,    16,    79,    34,   105,   107,   108,    40,    76,
       8,    28,    20,    45,    20,    80,    81,    42,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    39,   115,    17,    95,     9,   117,    64,    28,    35,
      96,    97,    98,    77,   110,    46,    26,    43,   119,    25,
      65,    18,     1,     2,    25,   105,    80,   111,    25,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   112,     1,     2,    95,    27,    33,   120,    31,
      21,    96,    97,    98,    80,    44,    20,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     121,    66,   113,    95,   109,   126,   127,   128,    68,    96,
      97,    98,    80,   131,   132,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    11,   114,
     122,    95,    69,    70,   129,   130,    12,    96,    97,    98,
     103,    10,    47,    48,    49,    50,    32,    22,    71,    67,
      47,    48,    49,    50,    78,   102,   100,   125,    47,    48,
      49,    50,     0,    54,     0,     0,     0,     0,    55,    56,
     104,    54,     0,     0,     0,    57,    55,    56,     0,    54,
       0,     0,     0,    57,    55,    56,     0,     0,     0,     0,
     116,    57,    47,    48,    49,    50,    47,    48,    49,    50,
       1,     2,    51,     0,    52,    53,     0,    47,    48,    49,
      50,     0,     0,    54,     0,     0,     0,    54,    55,    56,
       0,     0,    55,    56,     0,    57,     0,    21,    54,    57,
       0,     0,     0,    55,    56,     0,     0,     0,     0,    80,
      57,   118,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,     0,     0,    95,     0,
       0,     0,     0,     0,    96,    97,    98,    80,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,   123,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    80,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,     0,     0,    95,   124,     0,     0,     0,     0,
      96,    97,    98,    80,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
       0,     0,    95,     0,     0,     0,     0,     0,    96,    97,
      98
};

static const yytype_int16 yycheck[] =
{
      53,    54,    55,    56,     0,    15,    23,     1,    16,     5,
      63,    28,    34,     1,    21,    68,    69,    70,    25,     1,
       6,    17,    32,     1,    32,    13,    14,     1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    35,    95,    30,    32,     0,    99,     1,    44,    66,
      38,    39,    40,    35,     1,    33,     1,    31,     1,    16,
      14,    14,     7,     8,    21,   118,    13,    14,    25,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     1,     7,     8,    32,    31,     3,    31,     6,
      34,    38,    39,    40,    13,    15,    32,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    15,    31,    32,    14,   121,   122,   123,    30,    38,
      39,    40,    13,   129,   130,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     6,     6,
      31,    32,    30,    30,    10,    10,    14,    38,    39,    40,
       1,     5,     3,     4,     5,     6,    19,    15,     1,    44,
       3,     4,     5,     6,    60,    66,     1,   118,     3,     4,
       5,     6,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    24,    -1,    -1,    -1,    36,    29,    30,    -1,    24,
      -1,    -1,    -1,    36,    29,    30,    -1,    -1,    -1,    -1,
       1,    36,     3,     4,     5,     6,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,     3,     4,     5,
       6,    -1,    -1,    24,    -1,    -1,    -1,    24,    29,    30,
      -1,    -1,    29,    30,    -1,    36,    -1,    34,    24,    36,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    13,
      36,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    13,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    42,    43,    44,    46,    47,     6,     0,
      43,     6,    14,    45,    48,    49,    34,    30,    14,    15,
      32,    34,    52,    46,    55,    56,     1,    31,    46,    50,
      51,     6,    45,     3,    55,    48,    57,    58,     1,    35,
      55,    48,     1,    31,    15,     1,    33,     3,     4,     5,
       6,     9,    11,    12,    24,    29,    30,    36,    52,    53,
      54,    56,    60,    16,     1,    14,    15,    50,    30,    30,
      30,     1,    60,    60,    60,    60,     1,    35,    53,     1,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    32,    38,    39,    40,    59,
       1,    60,    57,     1,    31,    60,    61,    60,    60,    14,
       1,    14,     1,    31,     6,    60,     1,    60,    15,     1,
      31,     1,    31,    31,    33,    61,    54,    54,    54,    10,
      10,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      46,    46,    47,    47,    47,    48,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     5,     2,     1,     4,     4,     4,     4,
       3,     3,     3,     1,     2,     4,     4,     2,     0,     2,
       2,     1,     1,     3,     3,     3,     5,     5,     7,     7,
       5,     2,     0,     3,     3,     1,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     3,
       3,     2,     2,     3,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1
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
#line 93 "syntax.y"
                    {yyval = create("Program");add_son(yyval,yyvsp[0]);if(ok) output(yyval,0);}
#line 1523 "syntax.tab.c"
    break;

  case 3:
#line 95 "syntax.y"
                              {yyval = create("ExtDefList"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1529 "syntax.tab.c"
    break;

  case 4:
#line 96 "syntax.y"
      {yyval = NULL;}
#line 1535 "syntax.tab.c"
    break;

  case 5:
#line 98 "syntax.y"
                                  {yyval = create("ExtDef"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1541 "syntax.tab.c"
    break;

  case 6:
#line 99 "syntax.y"
                    {yyval = create("ExtDef"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1547 "syntax.tab.c"
    break;

  case 7:
#line 100 "syntax.y"
                             {yyval = create("ExtDef"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); func_type[yyvsp[-1]->id]=yyvsp[-2]->type;}
#line 1553 "syntax.tab.c"
    break;

  case 8:
#line 102 "syntax.y"
                   {yyval = create("ExtDecList"); add_son(yyval,yyvsp[0]);}
#line 1559 "syntax.tab.c"
    break;

  case 9:
#line 103 "syntax.y"
                             {yyval = create("ExtDecList"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1565 "syntax.tab.c"
    break;

  case 10:
#line 105 "syntax.y"
                {yyval = create("Specifier"); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[0]->type;}
#line 1571 "syntax.tab.c"
    break;

  case 11:
#line 106 "syntax.y"
                     {yyval = create("Specifier"); add_son(yyval,yyvsp[0]);}
#line 1577 "syntax.tab.c"
    break;

  case 12:
#line 108 "syntax.y"
                                         {yyval = create("StructSpecifier"); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1583 "syntax.tab.c"
    break;

  case 13:
#line 109 "syntax.y"
                                {yyval = create("StructSpecifier"); add_son(yyval,yyvsp[-4]); my_yyerror("Missing right curly '}'",yyval->line);}
#line 1589 "syntax.tab.c"
    break;

  case 14:
#line 110 "syntax.y"
               {yyval = create("StructSpecifier"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1595 "syntax.tab.c"
    break;

  case 15:
#line 112 "syntax.y"
           {yyval = create("VarDec"); add_son(yyval,yyvsp[0]); if(yyvsp[0]->dim == -1) yyvsp[0]->dim = 0; yyval->dim = yyvsp[0]->dim; yyval->id=yyvsp[0]->id; yyval->type = "0";}
#line 1601 "syntax.tab.c"
    break;

  case 16:
#line 113 "syntax.y"
                      {yyval = create("VarDec"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); 
                        if(yyvsp[-3]->dim == -1) yyvsp[-3]->dim = 0;
                        yyval->dim = yyvsp[-3]->dim + 1; yyval->id = yyvsp[-3]->id; yyval->type = "0";
                        }
#line 1610 "syntax.tab.c"
    break;

  case 17:
#line 117 "syntax.y"
                         {yyval = create("VarDec"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right brackets ']'",yyval->line);}
#line 1616 "syntax.tab.c"
    break;

  case 18:
#line 119 "syntax.y"
                         {yyval = create("FunDec"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->id=yyvsp[-3]->id; func_args[yyvsp[-3]->id]=yyvsp[-1]->argsList;}
#line 1622 "syntax.tab.c"
    break;

  case 19:
#line 120 "syntax.y"
                         {yyval = create("FunDec"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1628 "syntax.tab.c"
    break;

  case 20:
#line 121 "syntax.y"
              {yyval = create("FunDec"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->id=yyvsp[-2]->id; list<string> argsList;func_args[yyvsp[-2]->id]=argsList;}
#line 1634 "syntax.tab.c"
    break;

  case 21:
#line 122 "syntax.y"
                 {yyval = create("FunDec"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1640 "syntax.tab.c"
    break;

  case 22:
#line 124 "syntax.y"
                                {yyval = create("VarList"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);varListIt(yyval,yyval->argsList);}
#line 1646 "syntax.tab.c"
    break;

  case 23:
#line 125 "syntax.y"
              {yyval = create("VarList"); add_son(yyval,yyvsp[0]);}
#line 1652 "syntax.tab.c"
    break;

  case 24:
#line 127 "syntax.y"
                           {yyval = create("ParamDec"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[-1]->type;}
#line 1658 "syntax.tab.c"
    break;

  case 25:
#line 129 "syntax.y"
                               {yyval = create("CompSt"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1664 "syntax.tab.c"
    break;

  case 26:
#line 131 "syntax.y"
                                  {yyval = create("CompSt"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right curly '}'",yyval->line);}
#line 1670 "syntax.tab.c"
    break;

  case 27:
#line 133 "syntax.y"
                        {yyval = create("StmtList"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1676 "syntax.tab.c"
    break;

  case 28:
#line 134 "syntax.y"
      {yyval = NULL;}
#line 1682 "syntax.tab.c"
    break;

  case 29:
#line 136 "syntax.y"
               {yyval = create("Stmt"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1688 "syntax.tab.c"
    break;

  case 30:
#line 137 "syntax.y"
               {yyval = create("Stmt"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); my_yyerror("Missing semicolon ';'",yyval->line);}
#line 1694 "syntax.tab.c"
    break;

  case 31:
#line 138 "syntax.y"
         {yyval = create("Stmt"); add_son(yyval,yyvsp[0]);}
#line 1700 "syntax.tab.c"
    break;

  case 32:
#line 139 "syntax.y"
            {yyval = create("Stmt"); add_son(yyval,yyvsp[0]);}
#line 1706 "syntax.tab.c"
    break;

  case 33:
#line 140 "syntax.y"
                     {yyval = create("Stmt"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1712 "syntax.tab.c"
    break;

  case 34:
#line 141 "syntax.y"
                      {yyval = create("Stmt"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing semicolon ';'",yyval->line);}
#line 1718 "syntax.tab.c"
    break;

  case 35:
#line 142 "syntax.y"
                       {yyval = create("Stmt"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing Expression",yyval->line);}
#line 1724 "syntax.tab.c"
    break;

  case 36:
#line 143 "syntax.y"
                       {yyval = create("Stmt"); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1730 "syntax.tab.c"
    break;

  case 37:
#line 144 "syntax.y"
                          {yyval = create("Stmt"); add_son(yyval,yyvsp[-4]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1736 "syntax.tab.c"
    break;

  case 38:
#line 145 "syntax.y"
                                 {yyval = create("Stmt"); add_son(yyval,yyvsp[-6]); add_son(yyval,yyvsp[-5]); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1742 "syntax.tab.c"
    break;

  case 39:
#line 146 "syntax.y"
                                    {yyval = create("Stmt"); add_son(yyval,yyvsp[-6]); add_son(yyval,yyvsp[-5]); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1748 "syntax.tab.c"
    break;

  case 40:
#line 147 "syntax.y"
                          {yyval = create("Stmt"); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1754 "syntax.tab.c"
    break;

  case 41:
#line 150 "syntax.y"
                     {yyval = create("DefList"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1760 "syntax.tab.c"
    break;

  case 42:
#line 151 "syntax.y"
      {yyval = NULL;}
#line 1766 "syntax.tab.c"
    break;

  case 43:
#line 153 "syntax.y"
                            {yyval = create("Def"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                            // cerr << $1->type << ' ' << $2->type << endl;
                            if(yyvsp[-2]->type != yyvsp[-1]->type && yyvsp[-1]->type != "0") my_yyerror("para diff type", yyval->line);
                            else decListIt(yyvsp[-1], yyvsp[-2]->type);
                            }
#line 1776 "syntax.tab.c"
    break;

  case 44:
#line 158 "syntax.y"
                             {yyval = create("Def"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing semicolon ';'",yyval->line);}
#line 1782 "syntax.tab.c"
    break;

  case 45:
#line 160 "syntax.y"
             {yyval = create("DecList"); add_son(yyval,yyvsp[0]); yyval->type = yyvsp[0]->type;}
#line 1788 "syntax.tab.c"
    break;

  case 46:
#line 161 "syntax.y"
                       {yyval = create("DecList"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                        if (yyvsp[-2]->type == "0") yyval->type = yyvsp[0]->type;
                        else if (yyvsp[0]->type == "0") yyval->type = yyvsp[-2]->type;
                        else if (yyvsp[-2]->type != yyvsp[0]->type) my_yyerror("para diff type", yyval->line);
                        else
                            yyval->type = yyvsp[-2]->type;
                        }
#line 1800 "syntax.tab.c"
    break;

  case 47:
#line 169 "syntax.y"
            {yyval = create("Dec"); add_son(yyval,yyvsp[0]); yyval->id=yyvsp[0]->id; yyval->dim = yyvsp[0]->dim; yyval->type = "0";}
#line 1806 "syntax.tab.c"
    break;

  case 48:
#line 170 "syntax.y"
                       {yyval = create("Dec"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                        // cerr << $3->dim << ' ' << $3->type << endl;
                        if (yyvsp[0]->dim != yyvsp[-2]->dim) my_yyerror("Miss match type",yyval->line);
                        else
                        {
                            yyval->type = yyvsp[0]->type;
                            yyvsp[-2]->type = yyvsp[0]->type;//此时变量还未获取type
                            yyval->id=yyvsp[-2]->id; yyval->dim = yyvsp[-2]->dim;
                        }
                        }
#line 1821 "syntax.tab.c"
    break;

  case 49:
#line 180 "syntax.y"
                         {yyval = create("Dec"); add_son(yyval,yyvsp[-2]);my_yyerror("Missing Expression ",yyval->line); yyval->id=yyvsp[-2]->id;}
#line 1827 "syntax.tab.c"
    break;

  case 50:
#line 182 "syntax.y"
                {yyval = create("ASSIGN");yyval->line = yyvsp[0]->line;}
#line 1833 "syntax.tab.c"
    break;

  case 51:
#line 183 "syntax.y"
         {yyval = create("AND");yyval->line = yyvsp[0]->line;}
#line 1839 "syntax.tab.c"
    break;

  case 52:
#line 184 "syntax.y"
        {yyval = create("OR");yyval->line = yyvsp[0]->line;}
#line 1845 "syntax.tab.c"
    break;

  case 53:
#line 185 "syntax.y"
        {yyval = create("LT");yyval->line = yyvsp[0]->line;}
#line 1851 "syntax.tab.c"
    break;

  case 54:
#line 186 "syntax.y"
        {yyval = create("LE");yyval->line = yyvsp[0]->line;}
#line 1857 "syntax.tab.c"
    break;

  case 55:
#line 187 "syntax.y"
        {yyval = create("GT");yyval->line = yyvsp[0]->line;}
#line 1863 "syntax.tab.c"
    break;

  case 56:
#line 188 "syntax.y"
        {yyval = create("GE");yyval->line = yyvsp[0]->line;}
#line 1869 "syntax.tab.c"
    break;

  case 57:
#line 189 "syntax.y"
        {yyval = create("NE");yyval->line = yyvsp[0]->line;}
#line 1875 "syntax.tab.c"
    break;

  case 58:
#line 190 "syntax.y"
        {yyval = create("EQ");yyval->line = yyvsp[0]->line;}
#line 1881 "syntax.tab.c"
    break;

  case 59:
#line 191 "syntax.y"
          {yyval = create("PLUS");yyval->line = yyvsp[0]->line;}
#line 1887 "syntax.tab.c"
    break;

  case 60:
#line 192 "syntax.y"
           {yyval = create("MINUS");yyval->line = yyvsp[0]->line;}
#line 1893 "syntax.tab.c"
    break;

  case 61:
#line 193 "syntax.y"
         {yyval = create("MUL");yyval->line = yyvsp[0]->line;}
#line 1899 "syntax.tab.c"
    break;

  case 62:
#line 194 "syntax.y"
         {yyval = create("DIV");yyval->line = yyvsp[0]->line;}
#line 1905 "syntax.tab.c"
    break;

  case 63:
#line 195 "syntax.y"
            {yyval = create("BITAND");yyval->line = yyvsp[0]->line;}
#line 1911 "syntax.tab.c"
    break;

  case 64:
#line 196 "syntax.y"
           {yyval = create("BITOR");yyval->line = yyvsp[0]->line;}
#line 1917 "syntax.tab.c"
    break;

  case 65:
#line 197 "syntax.y"
            {yyval = create("BITXOR");yyval->line = yyvsp[0]->line;}
#line 1923 "syntax.tab.c"
    break;

  case 66:
#line 199 "syntax.y"
                    {yyval = create("Exp"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                    if(getFuncType(yyvsp[-3]->id) == "") my_yyerror("No def for func",yyval->line); /*该函数当前没定义*/
                    else
                    {
                        yyval->dim = 0;
                        yyval->type = getFuncType(yyvsp[-3]->id);
                    }
                    }
#line 1936 "syntax.tab.c"
    break;

  case 67:
#line 208 "syntax.y"
                       {yyval = create("Exp"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right parentheses ')'",yyval->line); }
#line 1942 "syntax.tab.c"
    break;

  case 68:
#line 210 "syntax.y"
                    {yyval = create("Exp"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); 
                    
                    if (yyvsp[-1]->dim != 0 || yyvsp[-1]->type != "int") my_yyerror("Wrong index",yyval->line); /*数组坐标只能是整数*/
                    else
                    {
                        yyval->dim = yyvsp[-3]->dim - 1;
                        yyval->type = yyvsp[-3]->type;
                    }
                    }
#line 1956 "syntax.tab.c"
    break;

  case 69:
#line 220 "syntax.y"
                     {
        yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType(yyvsp[-2], yyvsp[0]) == 0) my_yyerror("diff type", yyval->line);/*数据类型不一致*/
        else {
            yyval->dim = yyvsp[-2]->dim; yyval->type = yyvsp[-2]->type;
        }
        }
#line 1970 "syntax.tab.c"
    break;

  case 70:
#line 230 "syntax.y"
                {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                yyval->dim = yyvsp[-1]->dim; yyval->type = yyvsp[-1]->type;
                }
#line 1978 "syntax.tab.c"
    break;

  case 71:
#line 234 "syntax.y"
               {yyval = create("Exp"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                yyval->dim = yyvsp[0]->dim; yyval->type = yyvsp[0]->type;
                }
#line 1986 "syntax.tab.c"
    break;

  case 72:
#line 238 "syntax.y"
             {yyval = create("Exp"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1992 "syntax.tab.c"
    break;

  case 73:
#line 240 "syntax.y"
              {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1998 "syntax.tab.c"
    break;

  case 74:
#line 242 "syntax.y"
                {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 2004 "syntax.tab.c"
    break;

  case 75:
#line 244 "syntax.y"
        {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
        if(getParaType(yyvsp[0]->id).first == "") my_yyerror("ID no def", yyval->line);
        else
        {
            yyval->dim = getParaType(yyvsp[0]->id).second;
            yyval->type = getParaType(yyvsp[0]->id).first;
        }
        }
#line 2017 "syntax.tab.c"
    break;

  case 76:
#line 253 "syntax.y"
         {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
        yyval->dim = 0; yyval->type = "int";
        yyvsp[0]->dim = 0; yyvsp[0]->type = "int";
        }
#line 2026 "syntax.tab.c"
    break;

  case 77:
#line 258 "syntax.y"
           {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
            yyval->dim = 0; yyval->type = "float";
            yyvsp[0]->dim = 0; yyvsp[0]->type = "float";
            }
#line 2035 "syntax.tab.c"
    break;

  case 78:
#line 263 "syntax.y"
          {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
            yyval->dim = 0; yyval->type = "char";
            yyvsp[0]->dim = 0; yyvsp[0]->type = "char";
    }
#line 2044 "syntax.tab.c"
    break;

  case 79:
#line 268 "syntax.y"
            {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
            yyval->dim = 0; yyval->type = "string";
            yyvsp[0]->dim = 0; yyvsp[0]->type = "string";
    }
#line 2053 "syntax.tab.c"
    break;

  case 80:
#line 272 "syntax.y"
                        {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing expression",yyval->line);}
#line 2059 "syntax.tab.c"
    break;

  case 81:
#line 274 "syntax.y"
                   {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 2065 "syntax.tab.c"
    break;

  case 82:
#line 275 "syntax.y"
                 {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 2071 "syntax.tab.c"
    break;

  case 83:
#line 278 "syntax.y"
                     {yyval = create("Args"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 2077 "syntax.tab.c"
    break;

  case 84:
#line 279 "syntax.y"
         {yyval = create("Args"); add_son(yyval,yyvsp[0]);}
#line 2083 "syntax.tab.c"
    break;


#line 2087 "syntax.tab.c"

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
#line 281 "syntax.y"

void my_yyerror(const string s,int line) {
    fprintf(stderr, "Error type B at Line %d: %s\n",line, s.c_str());
    ok = false;
}
void yyerror(const string s) {
    // fprintf(stderr, "Error %s\n",s);
    // ok = false;
}

struct parsetree* create(const string to_name) {
     struct parsetree* ret = new parsetree();
    ret->id="-1";
    ret->type="-1";
    ret->line = lines;
    ret->left_son = ret->right_son = NULL;
    ret->name = to_name;
    return ret;
}

void add_son(struct parsetree* parent,struct parsetree* son)
{
    if(son == NULL) return;
    if(parent->left_son == NULL)
    {
        parent->left_son = parent->right_son = son;
        parent->line = son->line;
        // printf("%s %d\n",parent->name,parent->line);
    }
    else
    {
        parent->right_son->nxt_bro = son;
        parent->right_son = son;
    }
}

struct parsetree* create_add(const string to_name,const char* to_add)
{
     struct parsetree* ret = new parsetree();
    ret->id="-1";
    ret->type="-1";
    ret->line = lines;
    ret->left_son = ret->right_son = NULL;

    string to_add_ = to_add;
    string name = to_name;
    name += to_add_;
    
    ret->name = name;

    return ret;
}

pair<string, int> getParaType(string id)
{
    return para_type[id];
}

string getFuncType(string id)
{
    return func_type[id];
}

int checkType(const parsetree* p1, const parsetree* p2)
{
    return p1->dim == p2->dim && p1->type == p2->type ? true : false;
}

void output(struct parsetree* root,int dep)
{
    for(int i=0; i<dep; i++)
        printf("  ");
    cout<<root->name;
    if(root->left_son !=NULL) printf(" (%d)",root->line);
    if(root->type!="-1") printf(" (%s)",root->type.c_str());
    // printf("  --dim: %d", root->dim);
    // cout << "  --type:" << root->type;
    // cout << "  --id:" << root->id;
    printf("\n");
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        output(nxt,dep+1);
        nxt = nxt->nxt_bro;
    }
}

void decListIt(struct parsetree* root, string type)
{
    // cerr << root->name << ' ' << type << endl;
    if(root->name == "COMMA") return;
    if(root->name == "Dec")
    {
        // cerr << root->id << " " << root->dim << endl;
        para_type[root->id] = make_pair(type, root->dim);
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        decListIt(nxt, type);
        nxt = nxt->nxt_bro;
    }
}
void varListIt(struct parsetree* root,list<string>& re)
{
    if(root->name == "COMMA") return;
    if(root->name == "ParamDec")
    {
        re.push_back(root->type);
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        varListIt(nxt,re);
        nxt = nxt->nxt_bro;
    }
}

pair<string, int> getType(string id)
{
    return para_type[id];
}

int main(int argc, char **argv) {
     char *file_path;
    if(argc < 2){
          return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        freopen("test.c","r",stdin);
        freopen("test.out","w",stdout);
        yyparse();
         for (const auto& pair : para_type) {
        std::cout << pair.first << ": " << pair.second.first << ' ' << pair.second.second << std::endl;
        }
         for (const auto& pair : func_type) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        }
         for (const auto& pair : func_args) {
        std::cout << pair.first << ": " << std::endl;
         for (string argsType : pair.second) {
        std::cout << argsType << " "<<endl;
         }
         cout<<endl;
        }
    }
    else
    {
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
