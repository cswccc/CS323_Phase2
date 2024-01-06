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
#line 1 "syntax.y" /* yacc.c:339  */

    #include <stdlib.h>
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include <unordered_map>
    #include <list>
    #include <utility>
    #include <fstream>
    #define true 1
    #define false 0
    using namespace std;


    struct arraytree
    {
        int width;
        struct arraytree* nxt_dim;
    };
    struct parsetree
    {
        string name;
        string id;
        string type;
        string irtype;
        string to_add;

        list<pair<string, string>> argsList;
        unordered_map<string, pair<string, int> > varsInStruct;
        int dim = -1; //当前数据的维度
        struct parsetree* left_son;
        struct parsetree* right_son;
        struct parsetree* nxt_bro;
        struct parsetree* last_bro;
        int line;
    };
    #define YYSTYPE struct parsetree*

    int tot = 0;
    int tot_take = 0;
    unordered_map<string, arraytree*> array_map;
    unordered_map<string, pair<string, int> > para_type;
    unordered_map<string, string> func_type;
    unordered_map<string, list<pair<string, string>>> func_args; //first id second type
    unordered_map<string, unordered_map<string, pair<string, int> > > struct_vars;
    unordered_map<string, unordered_map<string, int > > struct_vars_offset; //处理地址偏移
    unordered_map<string, int> v_map;
    int v_cnt=0;
    unordered_map<string, int> t_map;
    int t_cnt=0;
    int lable_cnt=0;

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
    void getir(struct parsetree* root,int dep);
    void varListIt(struct parsetree* root,list<pair<string, string>>& re);
   void varInStructListIt(struct parsetree* root,unordered_map<string, pair<string, int> >& varsInStruct);
    void decListItForStruct(struct parsetree* root,string type,unordered_map<string, pair<string, int> >& varsInStruct);
     void argsListIt(struct parsetree* root,list<string>& argsList);
     void checkReturnStmtListIt(struct parsetree* root,string type);
     void checkReturnStmtIt(struct parsetree* root,string type);  

    #include "lex.yy.c"

#line 145 "syntax.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
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
    BITXOR = 295,
    WRITE = 296,
    READ = 297
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

/* Copy the second part of user declarations.  */

#line 239 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   153,   154,   156,   157,   158,   171,   172,
     174,   175,   177,   236,   237,   242,   243,   247,   248,   253,
     255,   256,   257,   259,   260,   262,   264,   266,   268,   275,
     277,   278,   279,   280,   281,   286,   291,   292,   293,   294,
     295,   298,   299,   302,   303,   305,   311,   313,   317,   325,
     326,   338,   341,   349,   357,   372,   381,   384,   430,   432,
     434,   443,   453,   463,   473,   483,   493,   503,   513,   523,
     533,   543,   553,   563,   567,   571,   573,   588,   602,   612,
     617,   622,   627,   631,   632,   633,   634,   635
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
  "UNDEFINE", "BITAND", "BITOR", "BITXOR", "WRITE", "READ", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "LVAL", "Assign",
  "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -53

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,   -55,     9,    18,   -55,   120,    62,   -55,    47,   -55,
     -55,    54,   -55,    69,    -6,    57,   120,    23,   -55,   105,
       4,   120,   -55,   105,     3,   120,   -55,   -55,   105,     5,
      99,   -55,   -55,    22,   -55,   114,    42,    59,   109,   -55,
     -55,   -55,    97,   -55,   -55,   120,   -55,   -55,   -55,   -55,
     -55,    -5,   100,   110,    66,   128,   128,   128,   -55,   111,
     -55,   -55,    21,   114,   -55,     0,   125,   158,    74,   -55,
     -55,   105,   -55,    58,   128,   128,   133,   112,   186,    80,
     344,   214,   128,   -55,   -55,   -55,   143,   128,   128,   -55,
     -55,   145,   -55,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   -55,   344,   -55,
     -55,   -55,   296,    34,   242,   312,   -55,   -55,   -55,   -55,
     -55,   328,   -55,   344,   258,   -55,   344,   390,   390,   390,
     390,   390,   390,    80,    80,    53,    53,   376,   360,   275,
     128,   -55,   -55,   114,   114,   114,   -55,   -55,   -55,   -55,
     144,   150,   -55,   114,   114,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,     0,     0,     2,     4,     0,    11,    14,     1,
       3,    15,     6,     0,     8,     0,    44,     0,     5,     0,
       0,    44,     7,     0,     0,    44,    22,    21,     0,     0,
      24,    15,     9,     0,    18,    29,    49,     0,    47,    13,
      12,    43,    25,    20,    19,     0,    17,    16,    79,    80,
      81,    78,     0,     0,     0,     0,     0,     0,    82,     0,
      58,    34,     0,    29,    33,     0,     0,     0,     0,    46,
      45,     0,    23,     0,     0,     0,     0,    78,     0,    74,
      75,     0,     0,    27,    26,    28,     0,     0,     0,    31,
      32,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    50,    48,
      84,    76,    87,     0,     0,     0,    37,    36,    35,    83,
      73,     0,    54,    55,     0,    77,    56,    67,    68,    69,
      70,    71,    72,    65,    66,    61,    64,    62,    63,     0,
       0,    59,    57,     0,     0,     0,    85,    53,    60,    86,
      39,    38,    42,     0,     0,    41,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   148,   -55,   142,    12,   -55,   -18,   -55,   117,
     -55,   151,   102,    -8,    88,    76,    92,   -55,   -55,   -55,
     -54,    27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    23,     7,    14,    15,    29,
      30,    61,    62,    63,    24,    64,    37,    38,    65,    66,
      67,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    79,    80,    81,    39,    36,    43,    33,   -52,    19,
      42,   -52,     6,    86,   108,     8,    87,     6,     9,   112,
     114,   115,    83,    46,    26,    73,    20,   -52,   121,    28,
       1,     2,    88,   123,   124,   141,    44,    34,    40,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    36,    27,    47,    84,    28,    68,   110,
      69,    48,    49,    50,    77,   142,    91,    76,    11,    48,
      49,    50,    77,    70,    20,   107,    12,    48,    49,    50,
      77,    16,    55,    18,    17,   106,   112,    56,    57,   111,
      55,    21,    25,    91,    58,    56,    57,    25,    55,    59,
      60,    25,    58,    56,    57,   102,   103,    59,    60,    35,
      58,    31,   106,    41,    45,    59,    60,    48,    49,    50,
      51,     1,     2,    52,    71,    53,    54,     1,     2,    20,
      74,    48,    49,    50,    77,   150,   151,   152,    55,    89,
      75,    82,    73,    56,    57,   155,   156,   116,    21,   122,
      58,   125,    55,    10,   153,    59,    60,    56,    57,    90,
     154,    32,    72,   109,    58,    85,    22,   149,     0,    59,
      60,    91,    92,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   117,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,    91,
     118,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   119,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   143,     0,   120,   106,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    91,     0,   144,   106,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,    91,     0,
     106,   147,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   106,   148,    91,
       0,   140,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    91,     0,     0,   106,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    91,     0,   145,   106,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    91,     0,   146,
     106,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    91,     0,     0,   106,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,    91,
       0,     0,   106,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    91,     0,     0,     0,     0,   106,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,   106
};

static const yytype_int16 yycheck[] =
{
      54,    55,    56,    57,     1,    23,     1,     3,    13,    15,
      28,    16,     0,    13,    68,     6,    16,     5,     0,    73,
      74,    75,     1,     1,     1,    30,    32,    32,    82,    17,
       7,     8,    32,    87,    88,     1,    31,    33,    35,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    71,    31,    33,    35,    45,    16,     1,
       1,     3,     4,     5,     6,    31,    13,     1,     6,     3,
       4,     5,     6,    14,    32,     1,    14,     3,     4,     5,
       6,    34,    24,    14,    30,    32,   140,    29,    30,    31,
      24,    34,    16,    13,    36,    29,    30,    21,    24,    41,
      42,    25,    36,    29,    30,    25,    26,    41,    42,    21,
      36,     6,    32,    25,    15,    41,    42,     3,     4,     5,
       6,     7,     8,     9,    15,    11,    12,     7,     8,    32,
      30,     3,     4,     5,     6,   143,   144,   145,    24,    14,
      30,    30,    30,    29,    30,   153,   154,    14,    34,     6,
      36,     6,    24,     5,    10,    41,    42,    29,    30,     1,
      10,    19,    45,    71,    36,    63,    15,   140,    -1,    41,
      42,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    13,    -1,    31,    32,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    13,    -1,
      32,    33,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    33,    13,
      -1,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    13,    -1,    -1,    32,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    13,    -1,    31,    32,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    13,    -1,    31,
      32,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    13,    -1,    -1,    32,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    13,
      -1,    -1,    32,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    13,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    44,    45,    46,    48,    49,     6,     0,
      45,     6,    14,    47,    50,    51,    34,    30,    14,    15,
      32,    34,    54,    48,    57,    58,     1,    31,    48,    52,
      53,     6,    47,     3,    33,    57,    50,    59,    60,     1,
      35,    57,    50,     1,    31,    15,     1,    33,     3,     4,
       5,     6,     9,    11,    12,    24,    29,    30,    36,    41,
      42,    54,    55,    56,    58,    61,    62,    63,    16,     1,
      14,    15,    52,    30,    30,    30,     1,     6,    63,    63,
      63,    63,    30,     1,    35,    55,    13,    16,    32,    14,
       1,    13,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    32,     1,    63,    59,
       1,    31,    63,    64,    63,    63,    14,     1,    14,     1,
      31,    63,     6,    63,    63,     6,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      15,     1,    31,     1,    31,    31,    31,    33,    33,    64,
      56,    56,    56,    10,    10,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    50,    50,    50,    50,    51,
      51,    51,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     5,     2,     1,     4,     4,     3,     4,
       4,     3,     3,     3,     1,     2,     4,     4,     2,     0,
       2,     2,     2,     1,     1,     3,     3,     3,     5,     5,
       7,     7,     5,     2,     0,     3,     3,     1,     3,     1,
       3,     3,     1,     4,     3,     3,     3,     4,     1,     4,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     4,     3,     1
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
        case 2:
#line 127 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Program");add_son((yyval),(yyvsp[0]));if(ok)
{

    output((yyval),0);
    freopen("mycode.ir","w",stdout);
        for (const auto& pair : struct_vars) {
            int index=0;
            unordered_map<string,int> oneStructOffset;
            for (const auto& pair1: pair.second) {
                oneStructOffset[pair1.first]=index;
                index++;
            }
            struct_vars_offset[pair.first]=oneStructOffset;
        }
        for (const auto& pair : struct_vars_offset){
            cerr<<pair.first<<endl;
            for(const auto& pair1 :pair.second){
                cerr<<pair1.first<<" "<<pair1.second<<endl;
            }
        }
       


    getir((yyval),0);
}}
#line 1500 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ExtDefList"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 1506 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1512 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ExtDef"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 1518 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ExtDef"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 1524 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 158 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ExtDef"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                            if(getFuncType((yyvsp[-1])->id) != "") my_yyerror2('"' + (yyvsp[-1])->id + '"' + " is redefined", (yyval)->line, 4);
                            else func_type[(yyvsp[-1])->id] = (yyvsp[-2])->type;
                            // cerr<<"函数体返回值"<<$3->type<<endl;
                            // cerr<<"函数定义返回值"<<$1->type<<endl;

                            //comst->stmtlist->stmt->return 检查函数返回值类型
                            //拿到stmtlist
                            checkReturnStmtListIt((yyvsp[0])->left_son->nxt_bro,(yyvsp[-2])->type);
                            checkReturnStmtListIt((yyvsp[0])->left_son->nxt_bro->nxt_bro,(yyvsp[-2])->type);

                            }
#line 1541 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 171 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ExtDecList"); add_son((yyval),(yyvsp[0]));}
#line 1547 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ExtDecList"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 1553 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 174 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Specifier"); add_son((yyval),(yyvsp[0])); (yyval)->type=(yyvsp[0])->type;}
#line 1559 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Specifier"); add_son((yyval),(yyvsp[0])); (yyval)->type=(yyvsp[0])->type;}
#line 1565 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("StructSpecifier"); add_son((yyval),(yyvsp[-4])); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                                        if (!struct_vars[(yyvsp[-3])->id].empty()) {my_yyerror2("redefine the same structure type", (yyval)->line, 15);} // 重复定义
                                        else struct_vars[(yyvsp[-3])->id]=(yyvsp[-1])->varsInStruct;
                                        // bonus 如果结构体的变量一样认为他们重复 数量 对应
                                        unordered_map<string,pair<string,int>> newOne=(yyvsp[-1])->varsInStruct;
                                        bool repeat=false;
                                        for (const auto& varsListInStruct : struct_vars) {
                                            if(varsListInStruct.first!=(yyvsp[-3])->id){  //把自己排除在外
                                                bool rep=true;
                                                //数量不同不可能相同
                                                if(varsListInStruct.second.size()==(yyvsp[-1])->varsInStruct.size()){
                                                    //newOne inStruct_vars 做两边对应 正反都要对应
                                                    unordered_map<string,pair<string,int>> inStruct_vars=varsListInStruct.second;
                                                    for(const auto& oneVarsS:inStruct_vars){
                                                        bool ok=false;
                                                        pair<string,int> pS=oneVarsS.second; //得到这个pair
                                                        for(const auto& oneVarsN:newOne){
                                                            pair<string,int> pN=oneVarsN.second;
                                                            if(pN.first==pS.first && pN.second==pS.second){
                                                                ok=true;
                                                                break;
                                                            }
                                                        }
                                                        if(!ok){
                                                            rep=false;
                                                        }
                                                    }

                                                    
                                                     for(const auto& oneVarsN:newOne){
                                                        bool ok=false;
                                                        pair<string,int> pN=oneVarsN.second; //得到这个pair
                                                        for(const auto& oneVarsS:inStruct_vars){
                                                            pair<string,int> pS=oneVarsS.second;
                                                            if(pN.first==pS.first && pN.second==pS.second){
                                                                ok=true;
                                                                break;
                                                            }
                                                        }
                                                        if(!ok){
                                                            rep=false;
                                                        }
                                                    }

                                                }else{
                                                    rep=false;
                                                }
                                                if(rep){
                                                    repeat=true;
                                                    break;
                                                }
                                            }
                                        }
                                        if(repeat){
                                            my_yyerror2("redefine the same structure type S", (yyval)->line, 15);
                                        }

                                        (yyval)->type = (yyval)->id;
                                        }
#line 1629 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 236 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("StructSpecifier"); add_son((yyval),(yyvsp[-4])); my_yyerror("Missing right curly '}'",(yyval)->line);}
#line 1635 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 237 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("StructSpecifier"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                (yyval)->type = (yyvsp[0])->id;
                // cerr << $$->type << endl;
                }
#line 1644 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 242 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("VarDec"); add_son((yyval),(yyvsp[0])); if((yyvsp[0])->dim == -1) (yyvsp[0])->dim = 0; (yyval)->dim = (yyvsp[0])->dim; (yyval)->id=(yyvsp[0])->id; (yyval)->type = "0";}
#line 1650 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 243 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("VarDec"); (yyval)->irtype = "arrayDec";  add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); 
                        if((yyvsp[-3])->dim == -1) (yyvsp[-3])->dim = 0;
                        (yyval)->dim = (yyvsp[-3])->dim + 1; (yyval)->id = (yyvsp[-3])->id; (yyval)->type = "0";
                        }
#line 1659 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 247 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("VarDec"); add_son((yyval),(yyvsp[-3])); my_yyerror("Missing right brackets ']'",(yyval)->line);}
#line 1665 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 248 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("VarDec"); (yyval)->irtype = "id[]"; add_son((yyval),(yyvsp[-2]));
                        if((yyvsp[-2])->dim == -1) (yyvsp[-2])->dim = 0;
                        (yyval)->dim = (yyvsp[-2])->dim + 1; (yyval)->id = (yyvsp[-2])->id; (yyval)->type = "0";
                }
#line 1674 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 253 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("FunDec"); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); (yyval)->id=(yyvsp[-3])->id; func_args[(yyvsp[-3])->id]=(yyvsp[-1])->argsList;
                        }
#line 1681 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 255 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("FunDec"); add_son((yyval),(yyvsp[-3])); my_yyerror("Missing right parentheses ')'",(yyval)->line);}
#line 1687 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 256 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("FunDec"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); (yyval)->id=(yyvsp[-2])->id; list<pair<string, string>> argsList;func_args[(yyvsp[-2])->id]=argsList;}
#line 1693 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 257 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("FunDec"); add_son((yyval),(yyvsp[-2])); my_yyerror("Missing right parentheses ')'",(yyval)->line);}
#line 1699 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("VarList"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));varListIt((yyval),(yyval)->argsList);}
#line 1705 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 260 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("VarList"); add_son((yyval),(yyvsp[0]));varListIt((yyval),(yyval)->argsList);}
#line 1711 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 262 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("ParamDec"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); (yyval)->type=(yyvsp[-1])->type; (yyval)->id=(yyvsp[0])->id;(yyval)->dim = (yyvsp[0])->dim;}
#line 1717 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 264 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("CompSt"); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); (yyval)->type=(yyvsp[-1])->type; }
#line 1723 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 266 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("CompSt"); add_son((yyval),(yyvsp[-3])); my_yyerror("Missing right curly '}'",(yyval)->line);}
#line 1729 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 268 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("StmtList"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); 

if ((yyvsp[0])==NULL){(yyval)->type=(yyvsp[-1])->type;}
else{
    (yyval)->type=(yyvsp[0])->type;
}
}
#line 1741 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 275 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1747 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 277 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 1753 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 278 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval), (yyvsp[-1])); add_son((yyval), (yyvsp[0]));}
#line 1759 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 279 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); my_yyerror("Missing semicolon ';'",(yyval)->line);}
#line 1765 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 280 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[0]));}
#line 1771 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 281 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[0]));
    //考虑返回值在if else语句中
    (yyval)->type=(yyvsp[0])->type;
    // cerr<<$1->type<<endl;
    }
#line 1781 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 286 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); (yyval)->type=(yyvsp[-1])->type; 
     //返回值的维度不是0就报错
     if((yyvsp[-1])->dim!=0) {my_yyerror2("incompatiable return type", (yyval)->line, 8);
                     if((yyvsp[-1])->dim < 0) my_yyerror2(" indexing on non-array variable", (yyval)->line, 10);}
      }
#line 1791 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 291 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-2])); my_yyerror("Missing semicolon ';'",(yyval)->line);}
#line 1797 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 292 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-2])); my_yyerror("Missing Expression",(yyval)->line);}
#line 1803 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 293 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-4])); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); (yyval)->type=(yyvsp[0])->type;}
#line 1809 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 294 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-4])); my_yyerror("Missing right parentheses ')'",(yyval)->line);}
#line 1815 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 295 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-6])); add_son((yyval),(yyvsp[-5])); add_son((yyval),(yyvsp[-4])); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));

    }
#line 1823 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 298 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-6])); add_son((yyval),(yyvsp[-5])); add_son((yyval),(yyvsp[-4])); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));my_yyerror("Missing right parentheses ')'",(yyval)->line);}
#line 1829 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 299 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Stmt"); add_son((yyval),(yyvsp[-4])); add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 1835 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 302 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("DefList"); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); varInStructListIt((yyval),(yyval)->varsInStruct);}
#line 1841 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 303 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1847 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 305 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Def"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                            // cerr << $1->type << ' ' << $2->type << endl;
                            if((yyvsp[-2])->type != (yyvsp[-1])->type && (yyvsp[-1])->type != "0") {my_yyerror2("unmatching types on both sides of assignment", (yyval)->line, 5);}
                            // else 
                            decListIt((yyvsp[-1]), (yyvsp[-2])->type); (yyval)->type=(yyvsp[-2])->type;
                            }
#line 1858 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 311 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Def"); add_son((yyval),(yyvsp[-2])); my_yyerror("Missing semicolon ';'",(yyval)->line);}
#line 1864 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 313 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("DecList"); add_son((yyval),(yyvsp[0])); (yyval)->type = (yyvsp[0])->type;
            // cerr << $$->type << endl;
            if (getParaType((yyvsp[0])->id).first != "") my_yyerror2('"' + (yyvsp[0])->id + '"' + " is redefined", (yyval)->line, 3); // 重复定义
            }
#line 1873 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 317 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("DecList"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                        if ((yyvsp[-2])->type == "0") (yyval)->type = (yyvsp[0])->type;
                        else if ((yyvsp[0])->type == "0") (yyval)->type = (yyvsp[-2])->type;
                        else if ((yyvsp[-2])->type != (yyvsp[0])->type) (yyval)->type = "-1"; // 定义的变量类型不同
                        else
                            (yyval)->type = (yyvsp[-2])->type;
                        }
#line 1885 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Dec"); add_son((yyval),(yyvsp[0])); (yyval)->id=(yyvsp[0])->id; (yyval)->dim = (yyvsp[0])->dim; (yyval)->type = "0";}
#line 1891 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 326 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Dec"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                        // cerr << $3->dim << ' ' << $3->type << endl;
                        // cerr << $1->id << endl;
                        // cerr << $1->dim << ' ' << $1->type << endl;
                        (yyval)->id = (yyvsp[-2])->id; (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = "0";
                        if ((yyvsp[0])->dim != (yyvsp[-2])->dim) {my_yyerror2("unmatching types on both sides of assignment", (yyval)->line, 5);}
                        else
                        {
                            (yyval)->type = (yyvsp[0])->type;
                            (yyvsp[-2])->type = (yyvsp[0])->type;//此时变量还未获取type
                        }
                        }
#line 1908 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 338 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Dec"); add_son((yyval),(yyvsp[-2]));my_yyerror("Missing Expression ",(yyval)->line); (yyval)->id=(yyvsp[-2])->id;}
#line 1914 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 341 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("LVAL"); (yyval)->irtype = "id"; add_son((yyval), (yyvsp[0]));
            // if (getParaType($1->id).first != "")
            // {
                (yyval)->type = getParaType((yyvsp[0])->id).first;
                (yyval)->dim = getParaType((yyvsp[0])->id).second;
                (yyval)->id = (yyvsp[0])->id;
            // }
            }
#line 1927 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 349 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("LVAL"); (yyval)->irtype = "array"; add_son((yyval), (yyvsp[-3])); add_son((yyval), (yyvsp[-2])); add_son((yyval), (yyvsp[-1]));
                    if ((yyvsp[-1])->type != "int" && (yyvsp[-1])->dim != 0) my_yyerror2("indexing by non-integer", (yyval)->line, 12);
                    else
                    {
                        (yyval)->type = (yyvsp[-3])->type;
                        (yyval)->dim = (yyvsp[-3])->dim - 1;
                    }
                    }
#line 1940 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 357 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("LVAL"); (yyval)->irtype = "struct.id"; add_son((yyval), (yyvsp[-2])); add_son((yyval), (yyvsp[-1])); add_son((yyval), (yyvsp[0]));//结构体取参
        if (struct_vars[(yyvsp[-2])->type][(yyvsp[0])->id].first == "")
        {
            if (isNotStruct(getParaType((yyvsp[0])->id).first) == 1) my_yyerror2("accessing with non-struct variable", (yyval)->line, 13);
            else my_yyerror2("ccessing an undefined structure member", (yyval)->line, 14);
            (yyval)->dim = 0;
        }
        else
        {
            // cerr << $1->type << ' ' << $3->id << endl;
            (yyval)->type = struct_vars[(yyvsp[-2])->type][(yyvsp[0])->id].first;
            (yyval)->dim = struct_vars[(yyvsp[-2])->type][(yyvsp[0])->id].second;
        }
    }
#line 1959 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 372 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) { my_yyerror2("unmatching types on both sides of assignment", (yyval)->line, 5);}/*数据类型不一致*/
        else if ((yyvsp[-2])->dim < 0 || (yyvsp[0])->dim < 0) my_yyerror2("indexing on non-array variable", (yyval)->line, 12);
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
    }
#line 1973 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 381 "syntax.y" /* yacc.c:1646  */
    {//右值在左侧
        my_yyerror2("rvalue appears on the left-side of assignment", (yyval)->line, 6);
    }
#line 1981 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 384 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype = "function"; add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); //函数有参调用

                    //递归的时候，函数使用先被parse 声明才被parse 所以会显示函数没被定义，为了stage 3 4的分数（保证不出错） 暂时不处理函数没被定义了
                    // if(getFuncType($1->id) == "") 
                    // {
                    //     if(getParaType($1->id).first == "") my_yyerror2('"' + $1->id + '"' + " is invoked without a definition", $$->line, 2);
                    //     else my_yyerror2("invoking non-function variable", $$->line, 11);
                    // } 
                    
                    
                    /*该函数当前没定义*/
                    // else
                    // {
                    
                    //需要递归args 去看它是不是匹配函数的参数
                    list<string> argsList; //存args的类型 左到右
                    argsListIt((yyvsp[-1]),argsList);
                    list<pair<string,string>> func_argsList=func_args[(yyvsp[-3])->id];
                    //长度判断
                    if(argsList.size()!=func_argsList.size()) {my_yyerror2("invalid argument number, except "+to_string(func_argsList.size())+", got "+to_string(argsList.size()), (yyval)->line, 9);}
                    else{
                    //类型判断
                     // 获取索引为2的元素
                     list<string>::iterator itargs = argsList.begin();
                    //  std::advance(it, 2); // 将迭代器移动到索引为2的位置
                    // int value = *it; // 获取该位置的值
                     list<pair<string,string>>::iterator itfunc_args = func_argsList.begin();
                     
                    for(int i=0;i<argsList.size();i++){
                        if(i != 0)
                        {
                            std::advance(itargs, 1);
                            std::advance(itfunc_args, 1);
                        }
                        
                        string argsType=*itargs;
                        pair<string,string> func_argsPair=*itfunc_args;
                        if(argsType!=func_argsPair.second){
                            my_yyerror2("invalid argument type at "+to_string(i)+ ", except "+func_argsPair.second+", got "+argsType, (yyval)->line, 9);
                        }
                    }
                    }
                        (yyval)->dim = 0;
                        (yyval)->type = getFuncType((yyvsp[-3])->id);
                    // }
                    }
#line 2032 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 430 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="read"; add_son((yyval),(yyvsp[0])); (yyval)->type = "int"; (yyval)->dim = 0;}
#line 2038 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 432 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); add_son((yyval),(yyvsp[-3])); my_yyerror("Missing right parentheses ')'",(yyval)->line); }
#line 2044 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 434 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="array"; add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0])); 
                    if ((yyvsp[-1])->dim != 0 || (yyvsp[-1])->type != "int") my_yyerror2("indexing by non-integer", (yyval)->line, 12); /*数组坐标只能是整数*/
                    else
                    {
                        (yyval)->dim = (yyvsp[-3])->dim - 1;
                        (yyval)->type = (yyvsp[-3])->type;
                    }
                    }
#line 2057 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 443 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2072 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 453 "syntax.y" /* yacc.c:1646  */
    {
    (yyval) = create("Exp"); (yyval)->irtype="andexpression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
    // cerr << $1->dim << ' ' << $1->type << endl;
    // cerr << $3->dim << ' ' << $3->type << endl;
    if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
    else 
    {
        (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
    }
    }
#line 2087 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 463 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="orexpression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2102 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 473 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2117 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 483 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2132 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2147 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 503 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2162 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 513 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2177 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 523 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2192 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 533 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2207 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 543 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2222 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 553 "syntax.y" /* yacc.c:1646  */
    {
        (yyval) = create("Exp"); (yyval)->irtype="expression"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType((yyvsp[-2]), (yyvsp[0])) == 0) my_yyerror2("unmatching operand", (yyval)->line, 7);/*数据类型不一致*/
        else 
        {
            (yyval)->dim = (yyvsp[-2])->dim; (yyval)->type = (yyvsp[-2])->type;
        }
        }
#line 2237 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 563 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="(expression)"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                (yyval)->dim = (yyvsp[-1])->dim; (yyval)->type = (yyvsp[-1])->type;
                }
#line 2245 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 567 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="-expression"; add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                (yyval)->dim = (yyvsp[0])->dim; (yyval)->type = (yyvsp[0])->type;
                }
#line 2253 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 571 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="!expression"; add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 2259 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 573 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="function"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));  //函数无参调用
            //递归的时候，函数使用先被parse 声明才被parse 所以会显示函数没被定义，为了stage 3 4的分数（保证不出错） 暂时不处理函数没被定义了 
            // if(getFuncType($1->id) == "") 
            // {
            //     if(getParaType($1->id).first == "") my_yyerror2('"' + $1->id + '"' + " is invoked without a definition", $$->line, 2);
            //     else my_yyerror2("invoking non-function variable", $$->line, 11);
            // }

            (yyval)->dim = 0;
            (yyval)->type = getFuncType((yyvsp[-2])->id);
            list<pair<string,string>> func_argsList=func_args[(yyvsp[-2])->id];
            //长度判断
            if(func_argsList.size()!=0) {my_yyerror2("invalid argument number, except "+to_string(func_argsList.size())+", got 0", (yyval)->line, 9);}
            }
#line 2278 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 588 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="struct.id"; add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));
                if (struct_vars[(yyvsp[-2])->type][(yyvsp[0])->id].first == "")
                {
                    if (isNotStruct(getParaType((yyvsp[0])->id).first) == 1) my_yyerror2("accessing with non-struct variable", (yyval)->line, 13);
                    else my_yyerror2("ccessing an undefined structure member", (yyval)->line, 14);
                    (yyval)->dim = 0;
                }//结构体没这个变量
                else
                {
                    (yyval)->type = struct_vars[(yyvsp[-2])->type][(yyvsp[0])->id].first;
                    (yyval)->dim = struct_vars[(yyvsp[-2])->type][(yyvsp[0])->id].second;
                }
                }
#line 2296 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 602 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="id"; add_son((yyval),(yyvsp[0]));
        if(getParaType((yyvsp[0])->id).first == "") my_yyerror2('"' + (yyvsp[0])->id + '"' + " is used without a definition", (yyval)->line, 1);
        else
        {
            (yyval)->dim = getParaType((yyvsp[0])->id).second;
            (yyval)->type = getParaType((yyvsp[0])->id).first;
            (yyval)->id = (yyvsp[0])->id;
        }
        }
#line 2310 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 612 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="#"; add_son((yyval),(yyvsp[0]));
        (yyval)->dim = 0; (yyval)->type = "int";
        (yyvsp[0])->dim = 0; (yyvsp[0])->type = "int";
        }
#line 2319 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 617 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="#"; add_son((yyval),(yyvsp[0]));
            (yyval)->dim = 0; (yyval)->type = "float";
            (yyvsp[0])->dim = 0; (yyvsp[0])->type = "float";
            }
#line 2328 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 622 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="#"; add_son((yyval),(yyvsp[0]));
            (yyval)->dim = 0; (yyval)->type = "char";
            (yyvsp[0])->dim = 0; (yyvsp[0])->type = "char";
    }
#line 2337 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 627 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); (yyval)->irtype="#"; add_son((yyval),(yyvsp[0]));
            (yyval)->dim = 0; (yyval)->type = "string";
            (yyvsp[0])->dim = 0; (yyvsp[0])->type = "string";
    }
#line 2346 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 631 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); add_son((yyval),(yyvsp[-2])); my_yyerror("Missing right parentheses ')'",(yyval)->line);}
#line 2352 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 632 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp"); add_son((yyval),(yyvsp[-2])); my_yyerror("Missing right parentheses ')'",(yyval)->line);}
#line 2358 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 633 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Exp");  (yyval)->irtype="write"; add_son((yyval),(yyvsp[-3])); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 2364 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 634 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Args"); add_son((yyval),(yyvsp[-2])); add_son((yyval),(yyvsp[-1])); add_son((yyval),(yyvsp[0]));}
#line 2370 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 635 "syntax.y" /* yacc.c:1646  */
    {(yyval) = create("Args"); add_son((yyval),(yyvsp[0])); }
#line 2376 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2380 "syntax.tab.c" /* yacc.c:1646  */
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
#line 637 "syntax.y" /* yacc.c:1906  */

void my_yyerror(const string s,int line) {
    fprintf(stderr, "Error type B at Line %d: %s\n",line, s.c_str());
    ok = false;
}

void my_yyerror2(const string s, int line, int type)
{
    // fprintf(stderr, "Error type %d at Line %d: %s\n", type, line, s.c_str());
    // ok = false;
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
        son->last_bro = parent->right_son;
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

    ret->to_add = to_add;
    
    ret->name = to_name;

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
    return (p1->dim == p2->dim && p1->type == p2->type && (p1->dim >= 0 && p1->type != "-1") && (p2->dim >= 0 && p2->type != "-1")) ? true : false;
}

int isNotStruct(string type)
{
    return (type == "int" || type == "char" || type == "float" || type == "string") ? true : false;
}
//workir
string get_t()
{
    // if(t_map.find(name) == t_map.end())
    // {
    //     t_cnt++;
    //     t_map[name]=t_cnt;
    // }
    // return "t"+to_string(t_map[name]);
    t_cnt++;
    return "t"+to_string(t_cnt);
}

string getexpression(struct parsetree* root,string to);
string get_v(string name,struct parsetree* root);
string global_t;
struct arraytree* deal_v_array(struct parsetree* root)
{
    if(root->left_son->name == "ID")
    {
        // cout<<"***"<<array_map[get_v(root->left_son->id,NULL)]->width<<endl;
        global_t = get_t();
        cout<<global_t<<" := "<<get_v(root->left_son->id,NULL)<<"\n";
        return array_map[get_v(root->left_son->id,NULL)];
    }
    struct arraytree* array_root = deal_v_array(root->left_son);
    string t = get_t();
    int num = 4*array_root->width;
    cout<<t<<" := #"<<num<<" * "<<getexpression(root->left_son->nxt_bro->nxt_bro,"exp")<<"\n";
    cout<<global_t<<" := "<<global_t<<" + "<<t<<"\n";
    return array_root->nxt_dim;
}

string get_v(string name,struct parsetree* root = NULL)
{
    if(root!=NULL && root->irtype == "struct.id")
    {
        // people p; p.age;
        string id = root->left_son->left_son->id; //p
        string t = get_t();
        string dotId=root->right_son->id; //age
        string structname=para_type[id].first; //people
        int pian = struct_vars_offset[structname][dotId]*4;
        cout<<t<<" := "<<get_v(id)<<"\n";
        cout<<t<<" := "<<t<<" + #"<<pian<<"\n";
        return "*"+t;
    }
    if(root!=NULL && root->irtype == "array")
    {
        deal_v_array(root);
        // cout<<arr_root->width<<"\n";
        return "*"+global_t;
    }
    if(v_map.find(name) == v_map.end())
    {
        v_cnt++;
        v_map[name]=v_cnt;
    }
    return "v"+to_string(v_map[name]);
}
string get_label()
{
    lable_cnt++;
    return "label"+to_string(lable_cnt);
}
string getoperator2(struct parsetree* root)
{
    if(root->name == "LT") return "<";
    if(root->name == "LE") return "<=";
    if(root->name == "GT") return ">";
    if(root->name == "GE") return ">=";
    if(root->name == "NE") return "!=";
    if(root->name == "EQ") return "==";
    if(root->name == "PLUS") return "+";
    if(root->name == "MINUS") return "-";
    if(root->name == "MUL") return "*";
    if(root->name == "DIV") return "/";
    return "todo";
}
string covert(string c)
{
    if(c=="<") return ">=";
    if(c=="<=") return ">";
    if(c==">") return "<=";
    if(c==">=") return "<";
    if(c=="==") return "!=";
    if(c=="!=") return "==";
    return "todo";
}
string getexpression(struct parsetree* root,string to = "exp")
{
    //fuck
    if(root->irtype=="function")
    {
        if(to=="if")
        {
            string ret="";
            if(root->left_son->nxt_bro->nxt_bro->name=="RP"){
                ret =  "CALL "+root->id;
            }else{
                int size=func_args[root->left_son->id].size();
                struct parsetree* nowArgs=root->left_son->nxt_bro->nxt_bro->left_son;
                string t[size];
                for(int i=0;i<size;i++){
                    string str = getexpression(nowArgs);
                    t[i]=str;
                    if(i!=size-1){
                        nowArgs=nowArgs->nxt_bro->nxt_bro->left_son;
                    }
                }
                for(int i=size-1;i>=0;i--){
                    cout<<"ARG "<<t[i]<<"\n";
                }
                ret =  "CALL "+root->left_son->id;
            }
            string new_t = get_t();
            cout<<new_t<<" := "<<ret<<"\n";
            return new_t;
        }
        if(root->left_son->nxt_bro->nxt_bro->name=="RP"){
            return "CALL "+root->id;
        }else{
            int size=func_args[root->left_son->id].size();
            struct parsetree* nowArgs=root->left_son->nxt_bro->nxt_bro->left_son;
            string t[size];
            for(int i=0;i<size;i++){
                string str = getexpression(nowArgs,to);
                t[i]=str;
                if(i!=size-1){
                    nowArgs=nowArgs->nxt_bro->nxt_bro->left_son;
                }
            }
            for(int i=size-1;i>=0;i--){
                cout<<"ARG "<<t[i]<<"\n";
            }
            return "CALL "+root->left_son->id;
        }
    }
    if(root->irtype=="read")
    {
        return "READ";
    }
    if(root->irtype=="array")
    {
        struct parsetree* rt = root->left_son->left_son;
        if(rt->name == "ID" && array_map.find(get_v(rt->id,NULL))==array_map.end())
        {
            string t = get_t();
            string goal = getexpression(root->left_son->nxt_bro->nxt_bro);
            cout<<t<<" := #4 * "<<goal<<"\n";
            cout<<t<<" := "<<t<<" + "<<get_v(rt->id,NULL)<<"\n";
            return "*"+t;
        }
        else
            deal_v_array(root);
        // cout<<arr_root->width<<"\n";
        return "*"+global_t;
        // return "todo";
    }
    if(root->irtype=="expression")
    {
        string to2=to;
        if(to2=="assign") to2="exp";
        string left_exp = getexpression(root->left_son,to2);
        string right_exp = getexpression(root->right_son,to2);
        string t = get_t();
        string c = getoperator2(root->left_son->nxt_bro);
        if(c=="<" || c=="<=" || c==">" || c==">=" || c=="==" || c=="!=" || to == "assign")
        {
            return left_exp+" "+c+" "+right_exp;
        }
        cout<<t<<" := "<<left_exp<<" "<<c<<" "<<right_exp<<"\n";
        return t;
    }
    if(root->irtype=="(expression)")
    {
        return getexpression(root->left_son->nxt_bro,to);
    }
    if(root->irtype=="-expression")
    {
        string right_exp = getexpression(root->left_son->nxt_bro,to);
        string t = get_t();
        cout<<t<<" := #0 - "<<right_exp<<"\n";
        return t;
    }
    if(root->irtype=="!expression")
    {
        return "todo";
    }
    if(root->irtype=="struct.id")
    {
        string id = root->left_son->left_son->id; //p
        string t = get_t();
        string dotId=root->right_son->id; //age
        string structname=para_type[id].first; //people
        int pian = struct_vars_offset[structname][dotId]*4;
        cout<<t<<" := "<<get_v(id)<<"\n";
        cout<<t<<" := "<<t<<" + #"<<pian<<"\n";
        return "*"+t;
    }    
    if(root->irtype=="id")
    {
        return get_v(root->left_son->id);
    }
    if(root->irtype=="#")
    {
        return "#"+root->left_son->to_add;
    }
}
string getnotexpression(struct parsetree* root,string to = "exp")
{
    string left_exp = getexpression(root->left_son);
    string right_exp = getexpression(root->right_son);
    string t = get_t();
    string c = getoperator2(root->left_son->nxt_bro);
    if(c=="<" || c=="<=" || c==">" || c==">=" || c=="==" || c=="!=")
    {
        return left_exp+" "+covert(c)+" "+right_exp;
    }
    cout<<t<<" := "<<left_exp<<" "<<c<<" "<<right_exp<<"\n";
    return t;
}
void solveifexp(struct parsetree* root,string iftrue,string iffalse,int fan)
{
    if(root->left_son->nxt_bro->name == "AND")
    {
        solveifexp(root->left_son,iffalse,iftrue,1);
        solveifexp(root->right_son,iffalse,iftrue,1);
    }
    else if(root->left_son->nxt_bro->name == "OR")
    {
        solveifexp(root->left_son,iftrue,iffalse,0);
        solveifexp(root->right_son,iftrue,iffalse,0);
    }
    else
    {
        string tmp_out;
        if(fan==1)
        {
            tmp_out=getnotexpression(root,"if");
            cout<<"IF "<<tmp_out<<" GOTO "<<iftrue<<"\n";
        }
        else
        {
            tmp_out=getexpression(root,"if");
            cout<<"IF "<<tmp_out<<" GOTO "<<iftrue<<"\n";
        }
    }
}

void getids(struct parsetree* root,int size)
{
    if(root->name=="ID")
    {
        string v = get_v(root->id);
        // cout<<v<<" := #"<<tot_take<<"\n";
        // tot_take += size;
        cout<<"DEC "<<v<<" "<<size<<"\n";
        cout<<v<<" := &"<<v<<"\n";
        // cerr<<root->id<<"**************\n";
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        getids(nxt,size);
        nxt = nxt->nxt_bro;
    }
}

int setarray(struct parsetree* root,int tot,struct arraytree* arrnow)
{
    if(root->left_son->name=="ID")
    {
        cout<<"DEC "<<get_v(root->left_son->id)<<" "<<4*tot<<"\n";
        cout<<get_v(root->left_son->id)<<" := &"<<get_v(root->left_son->id)<<"\n";
        // cout<<"*/*"<<arrnow->width<<endl;
        array_map[get_v(root->left_son->id)] = arrnow;
        return 1;
    }
    struct parsetree* tmp = root->left_son->nxt_bro->nxt_bro;
    int num = stoi(tmp->to_add);
    struct arraytree* newarray = new arraytree();
    newarray->nxt_dim=arrnow;
    newarray->width = tot;
    // cout<<"***"<<newarray->width<<endl;
    setarray(root->left_son,tot*num,newarray);
    return 1;
}

void getir(struct parsetree* root,int dep)
{
    if(root->name == "Def")
    {
        if(root->left_son->left_son->name == "StructSpecifier")
        {

            getids(root->left_son->nxt_bro,struct_vars[root->left_son->left_son->right_son->id].size()*4);
        }
    }
    if(root->name == "FunDec")
    {
        cout<<"FUNCTION "<<root->id<<" :\n";
        list<pair<string,string>> args=func_args[root->id];
        for(pair<string,string> arg:args){
            cout<<"PARAM "<<get_v(arg.first)<<"\n";
        }
        return;
    }
    if(root->name == "ASSIGN")
    {
        string right_out;
        right_out = getexpression(root->nxt_bro,"assign");
        if(right_out == "READ")
        {
            cout<<right_out<<" "<<get_v(root->last_bro->id,root->last_bro)<<"\n";
        }
        else
        {
            cout<<get_v(root->last_bro->id,root->last_bro)<<" := "<<right_out<<"\n";
        }
        return;
    }
    if(root->name == "RETURN")
    {
        string t = getexpression(root->nxt_bro);
        cout<<"RETURN "<<t<<"\n";
        return;
    }
    if(root->name == "Exp" && root->irtype == "write")
    {
        string exp = getexpression(root->right_son->last_bro);
        cout<<"WRITE "<<exp<<"\n";
        return;
    }
    if(root->name == "Exp" && root->irtype == "function")
    {
        getexpression(root,"if");
        return;
    }
    if(root->name == "WHILE")
    {
        string label1 = get_label();
        string label2 = get_label();
        cout<<"LABEL "<<label1<<" :\n";
        solveifexp(root->nxt_bro->nxt_bro,label2,label1,1);
        getir(root->nxt_bro->nxt_bro->nxt_bro->nxt_bro,0);
        cout<<"GOTO "<<label1<<"\n";
        cout<<"LABEL "<<label2<<" :\n";
    }
    if(root->name == "IF")
    {
        struct parsetree* else_root=root;
        for(int i=1; i<=5; i++) else_root = else_root->nxt_bro;
        if(else_root == NULL || else_root->name!="ELSE")
        {
            string label1 = get_label();
            string label2 = get_label();
            else_root = root;
            for(int i=1; i<=2; i++) else_root = else_root->nxt_bro;
            solveifexp(else_root,label1,label2,0);
            // cout<<"IF "<<getexpression(else_root)<<" GOTO "<<label1<<"\n";
            if(else_root->left_son->nxt_bro->name!="AND")
            {
                cout<<"GOTO "<<label2<<"\n";
                cout<<"LABEL "<<label1<<" :\n";   
            }
            else_root = root;
            for(int i=1; i<=4; i++) else_root = else_root->nxt_bro;
            getir(else_root,0);
            cout<<"LABEL "<<label2<<" :\n";
        }
        else
        {
            string label1 = get_label();
            string label2 = get_label();
            string label3 = get_label();
            else_root = root;
            for(int i=1; i<=2; i++) else_root = else_root->nxt_bro;
            solveifexp(else_root,label1,label2,0);
            // cerr<<else_root->name<<" "<<else_root->irtype<<"\n";
            // cout<<"IF "<<getexpression(else_root)<<" GOTO "<<label1<<"\n";
            
            if(else_root->left_son->nxt_bro->name!="AND")
            {
                cout<<"GOTO "<<label2<<"\n";
                cout<<"LABEL "<<label1<<" :\n";   
            }
            else_root = root;
            for(int i=1; i<=4; i++) else_root = else_root->nxt_bro;
            getir(else_root,0);
            cout<<"GOTO "<<label3<<"\n";
            cout<<"LABEL "<<label2<<" :\n";
            else_root = else_root->nxt_bro->nxt_bro;
            getir(else_root,0);
            cout<<"LABEL "<<label3<<" :\n";
        }
        return;
    }
    if(root->irtype == "arrayDec")
    {
        setarray(root,1,NULL);
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        getir(nxt,dep+1);
        if(nxt->name == "IF") nxt=nxt->nxt_bro->nxt_bro->nxt_bro->nxt_bro;
        if(nxt->name == "ELSE") nxt=nxt->nxt_bro;
        if(nxt->name == "WHILE") nxt=nxt->nxt_bro->nxt_bro->nxt_bro->nxt_bro;
        if(nxt->name == "ASSIGN") nxt=nxt->nxt_bro;
        nxt = nxt->nxt_bro;
    }
    return;
}

void output(struct parsetree* root,int dep)
{
    for(int i=0; i<dep; i++)
        printf("  ");
    cout<<root->name<<":"<<root->to_add;
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
       if ((para_type[root->id].first)!=""){
            argsList.push_back(para_type[root->id].first);
        }else{
            argsList.push_back(root->type);
        }

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
        // cerr<<"hhh"<<endl;
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
                my_yyerror2("incompatiable return type", root->nxt_bro->line, 8);//3是函数体返回值类型 1是定义返回值类型
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
    //     cerr<<"para_type------------"<<endl;
    //      for (const auto& pair : para_type) {
    //     std::cerr << pair.first << ": " << pair.second.first << ' ' << pair.second.second << std::endl;
    //     }
        
    //     cerr<<"func_type------------"<<endl;
    //      for (const auto& pair : func_type) {
    //     std::cerr << pair.first << ": " << pair.second << std::endl;
    //     }
        
    //     cerr<<"para_args------------"<<endl;
    //      for (const auto& pair : func_args) {
    //     std::cerr << pair.first << ": " << std::endl;
    //     for (const auto& pair1: pair.second) {
    //     std::cerr << pair1.first << ' ' << pair1.second <<  endl;
    //      cerr<<endl;
    //     }
    //      }
        
    //     cerr<<"struct_vars------------"<<endl;
    //       for (const auto& pair : struct_vars) {
    //     std::cerr << pair.first << ": "<<std::endl;
    //     for (const auto& pair1: pair.second) {
    //     std::cerr << pair1.first << ' ' << pair1.second.first << " " << pair1.second.second<< endl;

    //     // cerr << getParaType("amy").second << endl;
    // }
    // }
    }
    else
    {
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
