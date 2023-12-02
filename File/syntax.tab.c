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
    #include <utility>
    #define true 1
    #define false 0
    using namespace std;

    struct parsetree
    {
        string name;
        string id;
        string type;

        list<pair<string, string>> argsList;
        unordered_map<string, pair<string, int> > varsInStruct;
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
    unordered_map<string, list<pair<string, string>>> func_args;
    unordered_map<string, unordered_map<string, pair<string, int> > > struct_vars;

    void my_yyerror(const string s,int line);
    void my_yyerror2(const string s, int line, int type);
    void yyerror(const string s);
    struct parsetree* create(const string to_name);
    struct parsetree* create_add(const string to_name,const char* to_add);
    void add_son(struct parsetree* parent,struct parsetree* son);

    void decListIt(struct parsetree* root, string type);
    pair<string, int> getType(string id);

    int checkType(const parsetree* p1, const parsetree* p2);
    pair<string, int> getParaType(string id);
    string getFuncType(string id);
    int isNotStruct(string type);

    void output(struct parsetree* root,int dep);
    void varListIt(struct parsetree* root,list<pair<string, string>>& re);
   void varInStructListIt(struct parsetree* root,unordered_map<string, pair<string, int> >& varsInStruct);
    void decListItForStruct(struct parsetree* root,string type,unordered_map<string, pair<string, int> >& varsInStruct);
     void argsListIt(struct parsetree* root,list<string>& argsList);
     void checkReturnStmtListIt(struct parsetree* root,string type);
     void checkReturnStmtIt(struct parsetree* root,string type);  

    #include "lex.yy.c"

#line 131 "syntax.tab.c"

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
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

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
       0,   104,   104,   106,   107,   109,   110,   111,   125,   126,
     128,   129,   131,   135,   136,   142,   143,   147,   149,   151,
     152,   153,   155,   156,   158,   160,   162,   164,   171,   173,
     174,   175,   176,   177,   182,   187,   188,   189,   190,   191,
     194,   195,   198,   199,   201,   207,   209,   213,   221,   222,
     232,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   267,   274,   282,   297,   306,   310,   344,   346,
     356,   367,   371,   375,   377,   385,   399,   409,   414,   419,
     424,   428,   430,   431,   434,   435
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
  "DefList", "Def", "DecList", "Dec", "Operate", "Operate2", "LVAL",
  "Assign", "Exp", "Args", YY_NULLPTR
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

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -54,    27,    47,   -54,    18,   162,   -54,    38,   -54,
     -54,    23,   -54,    59,    12,    43,    18,    21,   -54,    73,
     100,    18,   -54,    73,     7,    18,   -54,   -54,    73,     6,
      61,   -54,   -54,     5,   208,    69,    99,    89,   -54,   -54,
     -54,    74,   -54,   -54,    18,   -54,   -54,   -54,   -54,   -54,
     169,    75,    77,   166,   157,   157,   157,   -54,   -54,    22,
     208,   -54,    19,   114,    42,   174,   -54,   -54,    73,   -54,
      10,   157,   157,   120,    82,    70,   342,   342,    98,   -54,
     -54,   -54,   129,   157,   157,   -54,   -54,   149,   -54,   157,
     155,   158,   172,   173,   183,   188,   190,   193,   196,   199,
     204,   205,   157,   206,   207,   217,   220,   157,   -54,   342,
     -54,   -54,   -54,   230,    44,   126,   258,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   342,   286,   -54,   342,   314,   -54,
     342,   157,   -54,   -54,   208,   208,   208,   -54,   -54,   -54,
     212,   213,   -54,   208,   208,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    10,     0,     0,     2,     4,     0,    11,    14,     1,
       3,    15,     6,     0,     8,     0,    43,     0,     5,     0,
       0,    43,     7,     0,     0,    43,    21,    20,     0,     0,
      23,    15,     9,     0,    28,    48,     0,    46,    13,    12,
      42,    24,    19,    18,     0,    17,    16,    97,    98,    99,
      96,     0,     0,     0,     0,     0,     0,   100,    33,     0,
      28,    32,     0,     0,     0,     0,    45,    44,     0,    22,
       0,     0,     0,     0,    96,     0,    92,    93,     0,    26,
      25,    27,     0,     0,     0,    30,    31,     0,    29,    51,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      67,    68,     0,    79,    80,    81,     0,     0,    50,    49,
      47,   103,    94,   105,     0,     0,     0,    36,    35,    34,
      51,   102,    91,    84,    85,     0,    95,    86,     0,   101,
      90,     0,    88,    87,     0,     0,     0,    83,    89,   104,
      38,    37,    41,     0,     0,    40,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   219,   -54,   209,     4,   -54,   -18,   -54,   165,
     -54,   210,   170,    -3,    -1,   167,   159,   -54,   -54,   -54,
     -54,   -54,   -53,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    23,     7,    14,    15,    29,
      30,    58,    59,    60,    24,    61,    36,    37,   106,   107,
      62,    63,    64,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    76,    77,    78,     6,    35,    45,    42,    38,     6,
      41,   111,   109,    47,    48,    49,    74,   113,   115,   116,
      34,    28,    26,    79,    40,     1,     2,    19,     1,     2,
     124,   125,    82,     8,    54,    83,   127,    43,    46,    55,
      56,   112,    39,    86,    20,   132,    57,     9,    28,   128,
      35,    84,    27,    17,   130,    87,    88,    80,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   118,    16,    18,   102,   133,    44,    21,   113,    31,
     103,   104,   105,    87,   119,    65,   120,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   121,
      66,    20,   102,    33,    68,    71,    20,    72,   103,   104,
     105,    87,    70,    67,   120,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   134,    85,   122,
     102,   140,   141,   142,   117,   123,   103,   104,   105,    87,
     145,   146,   120,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   126,   -54,   135,   102,   -55,
      47,    48,    49,    74,   103,   104,   105,    73,    11,    47,
      48,    49,    74,   -56,   -57,   108,    12,    47,    48,    49,
      74,    54,   -82,    25,   -58,   -82,    55,    56,    25,   -59,
      54,   -60,    25,    57,   -61,    55,    56,   -62,    54,    70,
     -63,   -82,    57,    55,    56,   -52,   -53,   -64,   -65,    69,
      57,    47,    48,    49,    50,     1,     2,    51,   -66,    52,
      53,   129,   143,   144,    10,    22,   139,   110,    32,     0,
      81,     0,    54,     0,     0,     0,     0,    55,    56,     0,
       0,     0,    21,    87,    57,   131,   120,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
       0,     0,   102,     0,     0,     0,     0,     0,   103,   104,
     105,    87,     0,     0,   120,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,   136,
     102,     0,     0,     0,     0,     0,   103,   104,   105,    87,
       0,     0,   120,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     0,     0,     0,   102,   137,
       0,     0,     0,     0,   103,   104,   105,    87,     0,     0,
     120,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,   102,   138,     0,     0,
       0,     0,   103,   104,   105,    87,     0,     0,   120,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,     0,     0,   102,     0,     0,     0,     0,     0,
     103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      53,    54,    55,    56,     0,    23,     1,     1,     1,     5,
      28,     1,    65,     3,     4,     5,     6,    70,    71,    72,
      21,    17,     1,     1,    25,     7,     8,    15,     7,     8,
      83,    84,    13,     6,    24,    16,    89,    31,    33,    29,
      30,    31,    35,     1,    32,     1,    36,     0,    44,   102,
      68,    32,    31,    30,   107,    13,    14,    35,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    34,    14,    32,    31,    15,    34,   131,     6,
      38,    39,    40,    13,    14,    16,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     1,
       1,    32,    32,     3,    15,    30,    32,    30,    38,    39,
      40,    13,    30,    14,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    14,    31,
      32,   134,   135,   136,    14,     6,    38,    39,    40,    13,
     143,   144,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     6,     1,    31,    32,     1,
       3,     4,     5,     6,    38,    39,    40,     1,     6,     3,
       4,     5,     6,     1,     1,     1,    14,     3,     4,     5,
       6,    24,    13,    16,     1,    16,    29,    30,    21,     1,
      24,     1,    25,    36,     1,    29,    30,     1,    24,    30,
       1,    32,    36,    29,    30,     1,     1,     1,     1,    44,
      36,     3,     4,     5,     6,     7,     8,     9,     1,    11,
      12,     1,    10,    10,     5,    15,   131,    68,    19,    -1,
      60,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,    13,    36,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    13,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    40,    13,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40
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
      54,    56,    61,    62,    63,    16,     1,    14,    15,    50,
      30,    30,    30,     1,     6,    63,    63,    63,    63,     1,
      35,    53,    13,    16,    32,    14,     1,    13,    14,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    32,    38,    39,    40,    59,    60,     1,    63,
      57,     1,    31,    63,    64,    63,    63,    14,     1,    14,
      16,     1,    31,     6,    63,    63,     6,    63,    63,     1,
      63,    15,     1,    31,     1,    31,    31,    33,    33,    64,
      54,    54,    54,    10,    10,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      46,    46,    47,    47,    47,    48,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     5,     2,     1,     4,     4,     4,     4,
       3,     3,     3,     1,     2,     4,     4,     2,     0,     2,
       2,     2,     1,     1,     3,     3,     3,     5,     5,     7,
       7,     5,     2,     0,     3,     3,     1,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     3,     4,     4,     4,
       3,     3,     2,     2,     3,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1
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
#line 104 "syntax.y"
                    {yyval = create("Program");add_son(yyval,yyvsp[0]);if(ok) output(yyval,0);}
#line 1548 "syntax.tab.c"
    break;

  case 3:
#line 106 "syntax.y"
                              {yyval = create("ExtDefList"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1554 "syntax.tab.c"
    break;

  case 4:
#line 107 "syntax.y"
      {yyval = NULL;}
#line 1560 "syntax.tab.c"
    break;

  case 5:
#line 109 "syntax.y"
                                  {yyval = create("ExtDef"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1566 "syntax.tab.c"
    break;

  case 6:
#line 110 "syntax.y"
                    {yyval = create("ExtDef"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1572 "syntax.tab.c"
    break;

  case 7:
#line 111 "syntax.y"
                             {yyval = create("ExtDef"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                            if(getFuncType(yyvsp[-1]->id) != "") my_yyerror2('"' + yyvsp[-1]->id + '"' + " is redefined", yyval->line, 4);
                            else func_type[yyvsp[-1]->id] = yyvsp[-2]->type;
                            // cerr<<"函数体返回值"<<$3->type<<endl;
                            // cerr<<"函数定义返回值"<<$1->type<<endl;

                            //comst->stmtlist->stmt->return 检查函数返回值类型
                            //拿到stmtlist
                            checkReturnStmtListIt(yyvsp[0]->left_son->nxt_bro,yyvsp[-2]->type);
                            checkReturnStmtListIt(yyvsp[0]->left_son->nxt_bro->nxt_bro,yyvsp[-2]->type);


                            }
#line 1590 "syntax.tab.c"
    break;

  case 8:
#line 125 "syntax.y"
                   {yyval = create("ExtDecList"); add_son(yyval,yyvsp[0]);}
#line 1596 "syntax.tab.c"
    break;

  case 9:
#line 126 "syntax.y"
                             {yyval = create("ExtDecList"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1602 "syntax.tab.c"
    break;

  case 10:
#line 128 "syntax.y"
                {yyval = create("Specifier"); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[0]->type;}
#line 1608 "syntax.tab.c"
    break;

  case 11:
#line 129 "syntax.y"
                     {yyval = create("Specifier"); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[0]->type;}
#line 1614 "syntax.tab.c"
    break;

  case 12:
#line 131 "syntax.y"
                                         {yyval = create("StructSpecifier"); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); struct_vars[yyvsp[-3]->id]=yyvsp[-1]->varsInStruct;
                                        if (struct_vars[yyvsp[-3]->id].empty()) {} // 当前结构体类型不存在
                                        yyval->type = yyval->id;
                                        }
#line 1623 "syntax.tab.c"
    break;

  case 13:
#line 135 "syntax.y"
                                {yyval = create("StructSpecifier"); add_son(yyval,yyvsp[-4]); my_yyerror("Missing right curly '}'",yyval->line);}
#line 1629 "syntax.tab.c"
    break;

  case 14:
#line 136 "syntax.y"
               {yyval = create("StructSpecifier"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                if (struct_vars[yyvsp[0]->id].empty()) {} // 当前结构体类型不存在
                yyval->type = yyvsp[0]->id;
                // cerr << $$->type << endl;
                }
#line 1639 "syntax.tab.c"
    break;

  case 15:
#line 142 "syntax.y"
           {yyval = create("VarDec"); add_son(yyval,yyvsp[0]); if(yyvsp[0]->dim == -1) yyvsp[0]->dim = 0; yyval->dim = yyvsp[0]->dim; yyval->id=yyvsp[0]->id; yyval->type = "0";}
#line 1645 "syntax.tab.c"
    break;

  case 16:
#line 143 "syntax.y"
                      {yyval = create("VarDec"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); 
                        if(yyvsp[-3]->dim == -1) yyvsp[-3]->dim = 0;
                        yyval->dim = yyvsp[-3]->dim + 1; yyval->id = yyvsp[-3]->id; yyval->type = "0";
                        }
#line 1654 "syntax.tab.c"
    break;

  case 17:
#line 147 "syntax.y"
                         {yyval = create("VarDec"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right brackets ']'",yyval->line);}
#line 1660 "syntax.tab.c"
    break;

  case 18:
#line 149 "syntax.y"
                         {yyval = create("FunDec"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->id=yyvsp[-3]->id; func_args[yyvsp[-3]->id]=yyvsp[-1]->argsList;
                        }
#line 1667 "syntax.tab.c"
    break;

  case 19:
#line 151 "syntax.y"
                         {yyval = create("FunDec"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1673 "syntax.tab.c"
    break;

  case 20:
#line 152 "syntax.y"
              {yyval = create("FunDec"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->id=yyvsp[-2]->id; list<pair<string, string>> argsList;func_args[yyvsp[-2]->id]=argsList;}
#line 1679 "syntax.tab.c"
    break;

  case 21:
#line 153 "syntax.y"
                 {yyval = create("FunDec"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1685 "syntax.tab.c"
    break;

  case 22:
#line 155 "syntax.y"
                                {yyval = create("VarList"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);varListIt(yyval,yyval->argsList);}
#line 1691 "syntax.tab.c"
    break;

  case 23:
#line 156 "syntax.y"
              {yyval = create("VarList"); add_son(yyval,yyvsp[0]);varListIt(yyval,yyval->argsList);}
#line 1697 "syntax.tab.c"
    break;

  case 24:
#line 158 "syntax.y"
                           {yyval = create("ParamDec"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[-1]->type; yyval->id=yyvsp[0]->id;yyval->dim = yyvsp[0]->dim;}
#line 1703 "syntax.tab.c"
    break;

  case 25:
#line 160 "syntax.y"
                               {yyval = create("CompSt"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[-1]->type; }
#line 1709 "syntax.tab.c"
    break;

  case 26:
#line 162 "syntax.y"
                                  {yyval = create("CompSt"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right curly '}'",yyval->line);}
#line 1715 "syntax.tab.c"
    break;

  case 27:
#line 164 "syntax.y"
                        {yyval = create("StmtList"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); 

if (yyvsp[0]==NULL){yyval->type=yyvsp[-1]->type;}
else{
    yyval->type=yyvsp[0]->type;
}
}
#line 1727 "syntax.tab.c"
    break;

  case 28:
#line 171 "syntax.y"
      {yyval = NULL;}
#line 1733 "syntax.tab.c"
    break;

  case 29:
#line 173 "syntax.y"
               {yyval = create("Stmt"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1739 "syntax.tab.c"
    break;

  case 30:
#line 174 "syntax.y"
                 {yyval = create("Stmt"); add_son(yyval, yyvsp[-1]); add_son(yyval, yyvsp[0]);}
#line 1745 "syntax.tab.c"
    break;

  case 31:
#line 175 "syntax.y"
               {yyval = create("Stmt"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); my_yyerror("Missing semicolon ';'",yyval->line);}
#line 1751 "syntax.tab.c"
    break;

  case 32:
#line 176 "syntax.y"
         {yyval = create("Stmt"); add_son(yyval,yyvsp[0]);}
#line 1757 "syntax.tab.c"
    break;

  case 33:
#line 177 "syntax.y"
            {yyval = create("Stmt"); add_son(yyval,yyvsp[0]);
    //考虑返回值在if else语句中
    yyval->type=yyvsp[0]->type;
    // cerr<<$1->type<<endl;
    }
#line 1767 "syntax.tab.c"
    break;

  case 34:
#line 182 "syntax.y"
                     {yyval = create("Stmt"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[-1]->type; 
     //返回值的维度不是0就报错
     if(yyvsp[-1]->dim!=0) {my_yyerror2(" return type wrong", yyval->line, 8);
                     my_yyerror2(" indexing on non-array variable", yyval->line, 10);}
      }
#line 1777 "syntax.tab.c"
    break;

  case 35:
#line 187 "syntax.y"
                      {yyval = create("Stmt"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing semicolon ';'",yyval->line);}
#line 1783 "syntax.tab.c"
    break;

  case 36:
#line 188 "syntax.y"
                       {yyval = create("Stmt"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing Expression",yyval->line);}
#line 1789 "syntax.tab.c"
    break;

  case 37:
#line 189 "syntax.y"
                       {yyval = create("Stmt"); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); yyval->type=yyvsp[0]->type;}
#line 1795 "syntax.tab.c"
    break;

  case 38:
#line 190 "syntax.y"
                          {yyval = create("Stmt"); add_son(yyval,yyvsp[-4]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1801 "syntax.tab.c"
    break;

  case 39:
#line 191 "syntax.y"
                                 {yyval = create("Stmt"); add_son(yyval,yyvsp[-6]); add_son(yyval,yyvsp[-5]); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);

    }
#line 1809 "syntax.tab.c"
    break;

  case 40:
#line 194 "syntax.y"
                                    {yyval = create("Stmt"); add_son(yyval,yyvsp[-6]); add_son(yyval,yyvsp[-5]); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 1815 "syntax.tab.c"
    break;

  case 41:
#line 195 "syntax.y"
                          {yyval = create("Stmt"); add_son(yyval,yyvsp[-4]); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 1821 "syntax.tab.c"
    break;

  case 42:
#line 198 "syntax.y"
                     {yyval = create("DefList"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); varInStructListIt(yyval,yyval->varsInStruct);}
#line 1827 "syntax.tab.c"
    break;

  case 43:
#line 199 "syntax.y"
      {yyval = NULL;}
#line 1833 "syntax.tab.c"
    break;

  case 44:
#line 201 "syntax.y"
                            {yyval = create("Def"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                            // cerr << $1->type << ' ' << $2->type << endl;
                            if(yyvsp[-2]->type != yyvsp[-1]->type && yyvsp[-1]->type != "0") my_yyerror2("unmatching types on both sides of assignment", yyval->line, 5);
                            // else 
                            decListIt(yyvsp[-1], yyvsp[-2]->type); yyval->type=yyvsp[-2]->type;
                            }
#line 1844 "syntax.tab.c"
    break;

  case 45:
#line 207 "syntax.y"
                             {yyval = create("Def"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing semicolon ';'",yyval->line);}
#line 1850 "syntax.tab.c"
    break;

  case 46:
#line 209 "syntax.y"
             {yyval = create("DecList"); add_son(yyval,yyvsp[0]); yyval->type = yyvsp[0]->type;
            // cerr << $$->type << endl;
            if (getParaType(yyvsp[0]->id).first != "") my_yyerror2('"' + yyvsp[0]->id + '"' + " is redefined", yyval->line, 3); // 重复定义
            }
#line 1859 "syntax.tab.c"
    break;

  case 47:
#line 213 "syntax.y"
                       {yyval = create("DecList"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                        if (yyvsp[-2]->type == "0") yyval->type = yyvsp[0]->type;
                        else if (yyvsp[0]->type == "0") yyval->type = yyvsp[-2]->type;
                        else if (yyvsp[-2]->type != yyvsp[0]->type) yyval->type = "-1"; // 定义的变量类型不同
                        else
                            yyval->type = yyvsp[-2]->type;
                        }
#line 1871 "syntax.tab.c"
    break;

  case 48:
#line 221 "syntax.y"
            {yyval = create("Dec"); add_son(yyval,yyvsp[0]); yyval->id=yyvsp[0]->id; yyval->dim = yyvsp[0]->dim; yyval->type = "0";}
#line 1877 "syntax.tab.c"
    break;

  case 49:
#line 222 "syntax.y"
                       {yyval = create("Dec"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                        // cerr << $3->dim << ' ' << $3->type << endl;
                        if (yyvsp[0]->dim != yyvsp[-2]->dim) {my_yyerror2("unmatching types on both sides of assignment", yyval->line, 5); yyval->type = "0";}
                        else
                        {
                            yyval->type = yyvsp[0]->type;
                            yyvsp[-2]->type = yyvsp[0]->type;//此时变量还未获取type
                            yyval->id=yyvsp[-2]->id; yyval->dim = yyvsp[-2]->dim;
                        }
                        }
#line 1892 "syntax.tab.c"
    break;

  case 50:
#line 232 "syntax.y"
                         {yyval = create("Dec"); add_son(yyval,yyvsp[-2]);my_yyerror("Missing Expression ",yyval->line); yyval->id=yyvsp[-2]->id;}
#line 1898 "syntax.tab.c"
    break;

  case 51:
#line 234 "syntax.y"
                {yyval = create("ASSIGN");yyval->line = yyvsp[0]->line;}
#line 1904 "syntax.tab.c"
    break;

  case 52:
#line 235 "syntax.y"
         {yyval = create("AND");yyval->line = yyvsp[0]->line;}
#line 1910 "syntax.tab.c"
    break;

  case 53:
#line 236 "syntax.y"
        {yyval = create("OR");yyval->line = yyvsp[0]->line;}
#line 1916 "syntax.tab.c"
    break;

  case 54:
#line 237 "syntax.y"
        {yyval = create("LT");yyval->line = yyvsp[0]->line;}
#line 1922 "syntax.tab.c"
    break;

  case 55:
#line 238 "syntax.y"
        {yyval = create("LE");yyval->line = yyvsp[0]->line;}
#line 1928 "syntax.tab.c"
    break;

  case 56:
#line 239 "syntax.y"
        {yyval = create("GT");yyval->line = yyvsp[0]->line;}
#line 1934 "syntax.tab.c"
    break;

  case 57:
#line 240 "syntax.y"
        {yyval = create("GE");yyval->line = yyvsp[0]->line;}
#line 1940 "syntax.tab.c"
    break;

  case 58:
#line 241 "syntax.y"
        {yyval = create("NE");yyval->line = yyvsp[0]->line;}
#line 1946 "syntax.tab.c"
    break;

  case 59:
#line 242 "syntax.y"
        {yyval = create("EQ");yyval->line = yyvsp[0]->line;}
#line 1952 "syntax.tab.c"
    break;

  case 60:
#line 243 "syntax.y"
          {yyval = create("PLUS");yyval->line = yyvsp[0]->line;}
#line 1958 "syntax.tab.c"
    break;

  case 61:
#line 244 "syntax.y"
           {yyval = create("MINUS");yyval->line = yyvsp[0]->line;}
#line 1964 "syntax.tab.c"
    break;

  case 62:
#line 245 "syntax.y"
         {yyval = create("MUL");yyval->line = yyvsp[0]->line;}
#line 1970 "syntax.tab.c"
    break;

  case 63:
#line 246 "syntax.y"
         {yyval = create("DIV");yyval->line = yyvsp[0]->line;}
#line 1976 "syntax.tab.c"
    break;

  case 64:
#line 247 "syntax.y"
            {yyval = create("BITAND");yyval->line = yyvsp[0]->line;}
#line 1982 "syntax.tab.c"
    break;

  case 65:
#line 248 "syntax.y"
           {yyval = create("BITOR");yyval->line = yyvsp[0]->line;}
#line 1988 "syntax.tab.c"
    break;

  case 66:
#line 249 "syntax.y"
            {yyval = create("BITXOR");yyval->line = yyvsp[0]->line;}
#line 1994 "syntax.tab.c"
    break;

  case 67:
#line 251 "syntax.y"
              {yyval = create("AND");yyval->line = yyvsp[0]->line;}
#line 2000 "syntax.tab.c"
    break;

  case 68:
#line 252 "syntax.y"
        {yyval = create("OR");yyval->line = yyvsp[0]->line;}
#line 2006 "syntax.tab.c"
    break;

  case 69:
#line 253 "syntax.y"
        {yyval = create("LT");yyval->line = yyvsp[0]->line;}
#line 2012 "syntax.tab.c"
    break;

  case 70:
#line 254 "syntax.y"
        {yyval = create("LE");yyval->line = yyvsp[0]->line;}
#line 2018 "syntax.tab.c"
    break;

  case 71:
#line 255 "syntax.y"
        {yyval = create("GT");yyval->line = yyvsp[0]->line;}
#line 2024 "syntax.tab.c"
    break;

  case 72:
#line 256 "syntax.y"
        {yyval = create("GE");yyval->line = yyvsp[0]->line;}
#line 2030 "syntax.tab.c"
    break;

  case 73:
#line 257 "syntax.y"
        {yyval = create("NE");yyval->line = yyvsp[0]->line;}
#line 2036 "syntax.tab.c"
    break;

  case 74:
#line 258 "syntax.y"
        {yyval = create("EQ");yyval->line = yyvsp[0]->line;}
#line 2042 "syntax.tab.c"
    break;

  case 75:
#line 259 "syntax.y"
          {yyval = create("PLUS");yyval->line = yyvsp[0]->line;}
#line 2048 "syntax.tab.c"
    break;

  case 76:
#line 260 "syntax.y"
           {yyval = create("MINUS");yyval->line = yyvsp[0]->line;}
#line 2054 "syntax.tab.c"
    break;

  case 77:
#line 261 "syntax.y"
         {yyval = create("MUL");yyval->line = yyvsp[0]->line;}
#line 2060 "syntax.tab.c"
    break;

  case 78:
#line 262 "syntax.y"
         {yyval = create("DIV");yyval->line = yyvsp[0]->line;}
#line 2066 "syntax.tab.c"
    break;

  case 79:
#line 263 "syntax.y"
            {yyval = create("BITAND");yyval->line = yyvsp[0]->line;}
#line 2072 "syntax.tab.c"
    break;

  case 80:
#line 264 "syntax.y"
           {yyval = create("BITOR");yyval->line = yyvsp[0]->line;}
#line 2078 "syntax.tab.c"
    break;

  case 81:
#line 265 "syntax.y"
            {yyval = create("BITXOR");yyval->line = yyvsp[0]->line;}
#line 2084 "syntax.tab.c"
    break;

  case 82:
#line 267 "syntax.y"
          {yyval = create("LVAL"); add_son(yyval, yyvsp[0]);
            // if (getParaType($1->id).first != "")
            // {
                yyval->type = getParaType(yyvsp[0]->id).first;
                yyval->dim = getParaType(yyvsp[0]->id).second;
            // }
            }
#line 2096 "syntax.tab.c"
    break;

  case 83:
#line 274 "syntax.y"
                     {yyval = create("LVAL"); add_son(yyval, yyvsp[-3]); add_son(yyval, yyvsp[-2]); add_son(yyval, yyvsp[-1]);
                    if (yyvsp[-1]->type != "int" && yyvsp[-1]->dim != 0) my_yyerror2("indexing by non-integer", yyval->line, 12);
                    else
                    {
                        yyval->type = yyvsp[-3]->type;
                        yyval->dim = yyvsp[-3]->dim - 1;
                    }
                    }
#line 2109 "syntax.tab.c"
    break;

  case 84:
#line 282 "syntax.y"
                  {yyval = create("LVAL"); add_son(yyval, yyvsp[-2]); add_son(yyval, yyvsp[-1]); add_son(yyval, yyvsp[0]);//结构体取参
        if (struct_vars[yyvsp[-2]->type][yyvsp[0]->id].first == "")
        {
            if (isNotStruct(getParaType(yyvsp[0]->id).first) == 1) my_yyerror2("accessing with non-struct variable", yyval->line, 13);
            else my_yyerror2("ccessing an undefined structure member", yyval->line, 14);
            yyval->dim = 0;
        }
        else
        {
            // cerr << $1->type << ' ' << $3->id << endl;
            yyval->type = struct_vars[yyvsp[-2]->type][yyvsp[0]->id].first;
            yyval->dim = struct_vars[yyvsp[-2]->type][yyvsp[0]->id].second;
        }
    }
#line 2128 "syntax.tab.c"
    break;

  case 85:
#line 297 "syntax.y"
                         {
        yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
        if (checkType(yyvsp[-2], yyvsp[0]) == 0) { my_yyerror2("unmatching types on both sides of assignment", yyval->line, 5);}/*数据类型不一致*/
        else if (yyvsp[-2]->dim < 0 || yyvsp[0]->dim < 0) my_yyerror2("indexing on non-array variable", yyval->line, 12);
        else 
        {
            yyval->dim = yyvsp[-2]->dim; yyval->type = yyvsp[-2]->type;
        }
    }
#line 2142 "syntax.tab.c"
    break;

  case 86:
#line 306 "syntax.y"
                    {//右值在左侧
        my_yyerror2("rvalue appears on the left-side of assignment", yyval->line, 6);
    }
#line 2150 "syntax.tab.c"
    break;

  case 87:
#line 310 "syntax.y"
                    {yyval = create("Exp"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); //函数有参调用
                    if(getFuncType(yyvsp[-3]->id) == "") my_yyerror2('"' + yyvsp[-3]->id + '"' + " is invoked without a definition", yyval->line, 2); /*该函数当前没定义*/
                    // else
                    // {

                    //需要递归args 去看它是不是匹配函数的参数
                    list<string> argsList; //存args的类型 左到右
                    argsListIt(yyvsp[-1],argsList);
                    list<pair<string,string>> func_argsList=func_args[yyvsp[-3]->id];
                    //长度判断
                    if(argsList.size()!=func_argsList.size()) {my_yyerror2("invalid argument number, except"+to_string(func_argsList.size())+", got "+to_string(argsList.size()), yyval->line, 9);}
                    else{
                    //类型判断
                     // 获取索引为2的元素
                     list<string>::iterator itargs = argsList.begin();
                    //  std::advance(it, 2); // 将迭代器移动到索引为2的位置
                    // int value = *it; // 获取该位置的值
                     list<pair<string,string>>::iterator itfunc_args = func_argsList.begin();
                    for(int i=0;i<argsList.size();i++){
                        std::advance(itargs, i);
                        std::advance(itfunc_args, i);
                        string argsType=*itargs;
                        pair<string,string> func_argsPair=*itfunc_args;
                        if(argsType!=func_argsPair.second){
                            my_yyerror2("invalid argument type at "+to_string(i)+", except "+func_argsPair.second+", got "+argsType, yyval->line, 9);
                        }
                    }
                    }

                        yyval->dim = 0;
                        yyval->type = getFuncType(yyvsp[-3]->id);
                    // }
                    }
#line 2188 "syntax.tab.c"
    break;

  case 88:
#line 344 "syntax.y"
                       {yyval = create("Exp"); add_son(yyval,yyvsp[-3]); my_yyerror("Missing right parentheses ')'",yyval->line); }
#line 2194 "syntax.tab.c"
    break;

  case 89:
#line 346 "syntax.y"
                    {yyval = create("Exp"); add_son(yyval,yyvsp[-3]); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]); 
                    
                    if (yyvsp[-1]->dim != 0 || yyvsp[-1]->type != "int") my_yyerror2("indexing by non-integer", yyval->line, 12); /*数组坐标只能是整数*/
                    else
                    {
                        yyval->dim = yyvsp[-3]->dim - 1;
                        yyval->type = yyvsp[-3]->type;
                    }
                    }
#line 2208 "syntax.tab.c"
    break;

  case 90:
#line 356 "syntax.y"
                      {
        yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType(yyvsp[-2], yyvsp[0]) == 0) my_yyerror2("unmatching operand", yyval->line, 7);/*数据类型不一致*/
        else 
        {
            yyval->dim = yyvsp[-2]->dim; yyval->type = yyvsp[-2]->type;
        }
        }
#line 2223 "syntax.tab.c"
    break;

  case 91:
#line 367 "syntax.y"
                {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                yyval->dim = yyvsp[-1]->dim; yyval->type = yyvsp[-1]->type;
                }
#line 2231 "syntax.tab.c"
    break;

  case 92:
#line 371 "syntax.y"
               {yyval = create("Exp"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                yyval->dim = yyvsp[0]->dim; yyval->type = yyvsp[0]->type;
                }
#line 2239 "syntax.tab.c"
    break;

  case 93:
#line 375 "syntax.y"
             {yyval = create("Exp"); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 2245 "syntax.tab.c"
    break;

  case 94:
#line 377 "syntax.y"
              {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);  //函数无参调用 
     yyval->dim = 0;
     yyval->type = getFuncType(yyvsp[-2]->id);
     list<pair<string,string>> func_argsList=func_args[yyvsp[-2]->id];
    //长度判断
    if(func_argsList.size()!=0) {my_yyerror2("invalid argument number, except "+to_string(func_argsList.size())+", got 0", yyval->line, 9);}
     }
#line 2257 "syntax.tab.c"
    break;

  case 95:
#line 385 "syntax.y"
                {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);
                if (struct_vars[yyvsp[-2]->type][yyvsp[0]->id].first == "")
                {
                    if (isNotStruct(getParaType(yyvsp[0]->id).first) == 1) my_yyerror2("accessing with non-struct variable", yyval->line, 13);
                    else my_yyerror2("ccessing an undefined structure member", yyval->line, 14);
                    yyval->dim = 0;
                }//结构体没这个变量
                else
                {
                    yyval->type = struct_vars[yyvsp[-2]->type][yyvsp[0]->id].first;
                    yyval->dim = struct_vars[yyvsp[-2]->type][yyvsp[0]->id].second;
                }
                }
#line 2275 "syntax.tab.c"
    break;

  case 96:
#line 399 "syntax.y"
        {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
        if(getParaType(yyvsp[0]->id).first == "") my_yyerror2('"' + yyvsp[0]->id + '"' + " is used without a definition", yyval->line, 1);
        else
        {
            yyval->dim = getParaType(yyvsp[0]->id).second;
            yyval->type = getParaType(yyvsp[0]->id).first;
            yyval->id = yyvsp[0]->id;
        }
        }
#line 2289 "syntax.tab.c"
    break;

  case 97:
#line 409 "syntax.y"
         {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
        yyval->dim = 0; yyval->type = "int";
        yyvsp[0]->dim = 0; yyvsp[0]->type = "int";
        }
#line 2298 "syntax.tab.c"
    break;

  case 98:
#line 414 "syntax.y"
           {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
            yyval->dim = 0; yyval->type = "float";
            yyvsp[0]->dim = 0; yyvsp[0]->type = "float";
            }
#line 2307 "syntax.tab.c"
    break;

  case 99:
#line 419 "syntax.y"
          {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
            yyval->dim = 0; yyval->type = "char";
            yyvsp[0]->dim = 0; yyvsp[0]->type = "char";
    }
#line 2316 "syntax.tab.c"
    break;

  case 100:
#line 424 "syntax.y"
            {yyval = create("Exp"); add_son(yyval,yyvsp[0]);
            yyval->dim = 0; yyval->type = "string";
            yyvsp[0]->dim = 0; yyvsp[0]->type = "string";
    }
#line 2325 "syntax.tab.c"
    break;

  case 101:
#line 428 "syntax.y"
                        {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing expression",yyval->line);}
#line 2331 "syntax.tab.c"
    break;

  case 102:
#line 430 "syntax.y"
                   {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 2337 "syntax.tab.c"
    break;

  case 103:
#line 431 "syntax.y"
                 {yyval = create("Exp"); add_son(yyval,yyvsp[-2]); my_yyerror("Missing right parentheses ')'",yyval->line);}
#line 2343 "syntax.tab.c"
    break;

  case 104:
#line 434 "syntax.y"
                     {yyval = create("Args"); add_son(yyval,yyvsp[-2]); add_son(yyval,yyvsp[-1]); add_son(yyval,yyvsp[0]);}
#line 2349 "syntax.tab.c"
    break;

  case 105:
#line 435 "syntax.y"
         {yyval = create("Args"); add_son(yyval,yyvsp[0]);}
#line 2355 "syntax.tab.c"
    break;


#line 2359 "syntax.tab.c"

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
#line 437 "syntax.y"

void my_yyerror(const string s,int line) {
    fprintf(stderr, "Error type B at Line %d: %s\n",line, s.c_str());
    ok = false;
}

void my_yyerror2(const string s, int line, int type)
{
    fprintf(stderr, "Error type %d at Line %d: %s\n", type, line, s.c_str());
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

int isNotStruct(string type)
{
    return (type == "int" || type == "char" || type == "float" || type == "string") ? true : false;
}

void output(struct parsetree* root,int dep)
{
    for(int i=0; i<dep; i++)
        printf("  ");
    cout<<root->name;
    if(root->left_son !=NULL) printf(" (%d)",root->line);
    if(root->type!="-1") printf(" (%s)",root->type.c_str());
    printf("  --dim: %d", root->dim);
    cout << "  --type:" << root->type;
    cout << "  --id:" << root->id;
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
        root->left_son->type = type;
        root->type = type;
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
void varListIt(struct parsetree* root,list<pair<string, string>>& re)
{
    if(root->name == "COMMA") return;
    if(root->name == "ParamDec")
    {
         para_type[root->id]=make_pair(root->type,0);
        //这里是函数参数是不是要唯一的  不判断就不会显示 现在是没判断的
        re.push_back(make_pair(root->id,root->type));
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        varListIt(nxt,re);
        nxt = nxt->nxt_bro;
    }
}

void decListItForStruct(struct parsetree* root,string type,unordered_map<string, pair<string, int> >& varsInStruct)
{
    if(root->name == "COMMA") return;
    if(root->name == "Dec")
    {

        varsInStruct[root->id]= make_pair(type, root->dim);
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        decListItForStruct(nxt,type,varsInStruct);
        nxt = nxt->nxt_bro;
    }
}

void varInStructListIt(struct parsetree* root,unordered_map<string, pair<string, int> >& varsInStruct)
{
    if(root->name == "Def")
    {
       string type=root->type;
       struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        if(nxt->name=="DecList"){
        decListItForStruct(nxt,type,varsInStruct);
        break;
        }
        nxt = nxt->nxt_bro;
    }
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        varInStructListIt(nxt,varsInStruct);
        nxt = nxt->nxt_bro;
    }
}
void argsListIt(struct parsetree* root,list<string>& argsList)
{
    // cerr << root->name << ' ' << type << endl;
    if(root->name == "COMMA") return;
    if(root->name == "Exp")
    {
        // cerr << root->id << " " << root->dim << endl;
        argsList.push_back(para_type[root->id].first);
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        argsListIt(nxt,argsList);
        nxt = nxt->nxt_bro;
    }
}

void checkReturnStmtListIt(struct parsetree* root,string type) //一个stmtlist
{
    
    if(root->name == "Stmt")
    {
        // cout<<"hhh"<<endl;
        checkReturnStmtIt(root,type);
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        checkReturnStmtListIt(nxt,type);
        nxt = nxt->nxt_bro;
    }
}
void checkReturnStmtIt(struct parsetree* root,string type) //一个stmt
{
    //  cerr<<root->name<<endl;
      if(root->name=="RETURN"){
            // cerr << type << endl;
            if(root->nxt_bro->type != type){
                my_yyerror2(" return type wrong", root->nxt_bro->line, 8);//3是函数体返回值类型 1是定义返回值类型
            }
            return;
        }  
    struct parsetree* nxt = root->left_son;
    // cerr<<nxt->line<<endl;
    while(nxt!=NULL)
    {
         
       
        if(root->name == "Stmt" || root->name=="CompSt" || root->name=="StmtList")
        {
           
            checkReturnStmtIt(nxt,type);
        } 
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
        cout<<"para_type------------"<<endl;
         for (const auto& pair : para_type) {
        std::cout << pair.first << ": " << pair.second.first << ' ' << pair.second.second << std::endl;
        }
        
        cout<<"func_type------------"<<endl;
         for (const auto& pair : func_type) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        }
        
        cout<<"para_args------------"<<endl;
         for (const auto& pair : func_args) {
        std::cout << pair.first << ": " << std::endl;
        for (const auto& pair1: pair.second) {
        std::cout << pair1.first << ' ' << pair1.second <<  endl;
         cout<<endl;
        }
         }
        
        cout<<"struct_vars------------"<<endl;
          for (const auto& pair : struct_vars) {
        std::cout << pair.first << ": "<<std::endl;
        for (const auto& pair1: pair.second) {
        std::cout << pair1.first << ' ' << pair1.second.first << " " << pair1.second.second<< endl;

        // cerr << getParaType("amy").second << endl;
    }
    }
    }
    else
    {
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
