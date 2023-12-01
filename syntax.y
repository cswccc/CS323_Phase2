%{
    struct parsetree
    {
        char* name;
        struct parsetree* left_son;
        struct parsetree* right_son;
        struct parsetree* nxt_bro;
        int line;
    };
    #define YYSTYPE struct parsetree*
    #define true 1
    #define false 0
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    int tot = 0;
    void my_yyerror(const char* s,int line);
    void yyerror(const char* s);
    struct parsetree* create(const char* to_name);
    struct parsetree* create_add(const char* to_name,const char* to_add);
    void add_son(struct parsetree* parent,struct parsetree* son);
    void output(struct parsetree* root,int dep);
    #include "lex.yy.c"
%}

%token INT
%token FLOAT
%token CHAR
%token ID
%token TYPE
%token STRUCT
%token IF
%token ELSE
%token WHILE
%token RETURN
%token DOT
%token SEMI
%token COMMA
%token ASSIGN
%token LT
%token LE
%token GT
%token GE
%token NE
%token EQ
%token PLUS
%token MINUS
%token MUL
%token DIV
%token AND
%token OR
%token NOT
%token LP
%token RP
%token LB
%token RB
%token LC
%token RC
%token STRING
%token UNDEFINE
%token BITAND
%token BITOR
%token BITXOR


%%
/* high-level definition */
Program : ExtDefList{$$ = create("Program");add_son($$,$1);if(ok) output($$,0);}

ExtDefList : ExtDef ExtDefList{$$ = create("ExtDefList"); add_son($$,$1); add_son($$,$2);}
    | {$$ = NULL;}

ExtDef : Specifier ExtDecList SEMI{$$ = create("ExtDef"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | Specifier SEMI{$$ = create("ExtDef"); add_son($$,$1); add_son($$,$2);}
    | Specifier FunDec CompSt{$$ = create("ExtDef"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

ExtDecList : VarDec{$$ = create("ExtDecList"); add_son($$,$1);}
    | VarDec COMMA ExtDecList{$$ = create("ExtDecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

Specifier : TYPE{$$ = create("Specifier"); add_son($$,$1);}
    | StructSpecifier{$$ = create("Specifier"); add_son($$,$1);}

StructSpecifier : STRUCT ID LC DefList RC{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5);}
    | STRUCT ID LC DefList error{$$ = create("StructSpecifier"); add_son($$,$1); my_yyerror("Missing right curly '}'",$$->line);}
    | STRUCT ID{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2);}

VarDec : ID{$$ = create("VarDec"); add_son($$,$1);}
    | VarDec LB INT RB{$$ = create("VarDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);}
    | VarDec LB INT error{$$ = create("VarDec"); add_son($$,$1); my_yyerror("Missing right brackets ']'",$$->line);}

FunDec : ID LP VarList RP{$$ = create("FunDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);}
    | ID LP VarList error{$$ = create("FunDec"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | ID LP RP{$$ = create("FunDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | ID LP error{$$ = create("FunDec"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}

VarList : ParamDec COMMA VarList{$$ = create("VarList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | ParamDec{$$ = create("VarList"); add_son($$,$1);}

ParamDec : Specifier VarDec{$$ = create("ParamDec"); add_son($$,$1); add_son($$,$2);}

CompSt : LC DefList StmtList RC{$$ = create("CompSt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);}

CompSt : LC DefList StmtList error{$$ = create("CompSt"); add_son($$,$1); my_yyerror("Missing right curly '}'",$$->line);}

StmtList : Stmt StmtList{$$ = create("StmtList"); add_son($$,$1); add_son($$,$2);}
    | {$$ = NULL;}

Stmt : Exp SEMI{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2);}
    | Exp error{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); my_yyerror("Missing semicolon ';'",$$->line);}
    | Def{$$ = create("Stmt"); add_son($$,$1);}
    | CompSt{$$ = create("Stmt"); add_son($$,$1);}
    | RETURN Exp SEMI{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | RETURN Exp error{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing semicolon ';'",$$->line);}
    | RETURN error SEMI{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing Expression",$$->line);}
    | IF LP Exp RP Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5);}
    | IF LP Exp error Stmt{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | IF LP Exp RP Stmt ELSE Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); add_son($$,$6); add_son($$,$7);}
    | IF LP Exp error Stmt ELSE Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); add_son($$,$6); add_son($$,$7);my_yyerror("Missing right parentheses ')'",$$->line);}
    | WHILE LP Exp RP Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5);}
    // | WHILE LP Exp error Stmt{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing right parentheses222 ')'",$$->line);}

DefList : Def DefList{$$ = create("DefList"); add_son($$,$1); add_son($$,$2);}
    | {$$ = NULL;}

Def : Specifier DecList SEMI{$$ = create("Def"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | Specifier DecList error{$$ = create("Def"); add_son($$,$1); my_yyerror("Missing semicolon ';'",$$->line);}

DecList : Dec{$$ = create("DecList"); add_son($$,$1);}
    | Dec COMMA DecList{$$ = create("DecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

Dec : VarDec{$$ = create("Dec"); add_son($$,$1);}
    | VarDec ASSIGN Exp{$$ = create("Dec"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | VarDec ASSIGN error{$$ = create("Dec"); add_son($$,$1);my_yyerror("Missing Expression ",$$->line);}

Operate : ASSIGN{$$ = create("ASSIGN");$$->line = $1->line;}
    | AND{$$ = create("AND");$$->line = $1->line;}
    | OR{$$ = create("OR");$$->line = $1->line;}
    | LT{$$ = create("LT");$$->line = $1->line;}
    | LE{$$ = create("LE");$$->line = $1->line;}
    | GT{$$ = create("GT");$$->line = $1->line;}
    | GE{$$ = create("GE");$$->line = $1->line;}
    | NE{$$ = create("NE");$$->line = $1->line;}
    | EQ{$$ = create("EQ");$$->line = $1->line;}
    | PLUS{$$ = create("PLUS");$$->line = $1->line;}
    | MINUS{$$ = create("MINUS");$$->line = $1->line;}
    | MUL{$$ = create("MUL");$$->line = $1->line;}
    | DIV{$$ = create("DIV");$$->line = $1->line;}
    | BITAND{$$ = create("BITAND");$$->line = $1->line;}
    | BITOR{$$ = create("BITOR");$$->line = $1->line;}
    | BITXOR{$$ = create("BITXOR");$$->line = $1->line;}

Exp : ID LP Args RP {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);}
    | ID LP Args error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line); }
    | Exp LB Exp RB {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);}
    | Exp Operate Exp{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | LP Exp RP {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | MINUS Exp{$$ = create("Exp"); add_son($$,$1); add_son($$,$2);}
    | NOT Exp{$$ = create("Exp"); add_son($$,$1); add_son($$,$2);}
    | ID LP RP{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | Exp DOT ID{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | ID{$$ = create("Exp"); add_son($$,$1);}
    | INT{$$ = create("Exp"); add_son($$,$1);}
    | FLOAT{$$ = create("Exp"); add_son($$,$1);}
    | CHAR{$$ = create("Exp"); add_son($$,$1);}
    | STRING{$$ = create("Exp"); add_son($$,$1);}
    | Exp Operate error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing expression",$$->line);}
    // | Exp error Exp {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing operate",$$->line);}
    | LP Exp error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | ID LP error{$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}

    
Args : Exp COMMA Args{$$ = create("Args"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | Exp{$$ = create("Args"); add_son($$,$1);}

%%
void my_yyerror(const char* s,int line) {
    fprintf(stderr, "Error type B at Line %d: %s\n",line, s);
    ok = false;
}
void yyerror(const char* s) {
    // fprintf(stderr, "Error %s\n",s);
    // ok = false;
}
// struct parsetree* create(char* to_name,int line) {
//     // printf("%s\n",to_name);
//     tot++;
//     tree[tot].line = line;
//     tree[tot].name = (char*)malloc(strlen(to_name)+1);
//     memcpy(tree[tot].name, to_name, strlen(to_name)+1);
//     return &tree[tot];
// }
struct parsetree* create(const char* to_name) {
    struct parsetree* ret = (struct parsetree*) malloc(sizeof(struct parsetree));
    ret->line = lines;
    ret->left_son = ret->right_son = NULL;
    ret->name = (char*)malloc(strlen(to_name)+1);
    memcpy(ret->name, to_name, strlen(to_name)+1);
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

struct parsetree* create_add(const char* to_name,const char* to_add)
{
    struct parsetree* ret = (struct parsetree*) malloc(sizeof(struct parsetree));
    ret->line = lines;
    ret->left_son = ret->right_son = NULL;
    ret->name = (char*)malloc(strlen(to_add)+strlen(to_name)+1);
    memcpy(ret->name, to_name, strlen(to_name));
    memcpy(ret->name+strlen(to_name), to_add, strlen(to_add)+1);
    return ret;
}

void output(struct parsetree* root,int dep)
{
    for(int i=0; i<dep; i++)
        printf("  ");
    printf("%s",root->name);
    if(root->left_son !=NULL) printf(" (%d)",root->line);
    printf("\n");
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        output(nxt,dep+1);
        nxt = nxt->nxt_bro;
    }
}
int main(int argc, char **argv) {
     char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
          return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        freopen("test.c","r",stdin);
        freopen("test.out","w",stdout);
        yyparse();
    }
    else
    {
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
