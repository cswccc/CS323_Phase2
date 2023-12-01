%{
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
        unordered_map<string, string> varsInStruct;
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
    unordered_map<string,unordered_map<string,string>> struct_vars;

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
   void varInStructListIt(struct parsetree* root,unordered_map<string, string>& varsInStruct);
    void decListItForStruct(struct parsetree* root,string type,unordered_map<string, string>& varsInStruct);
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
    | Specifier FunDec CompSt{$$ = create("ExtDef"); add_son($$,$1); add_son($$,$2); add_son($$,$3); func_type[$2->id]=$1->type;} //函数返回值 函数头 函数体 处理func_type

ExtDecList : VarDec{$$ = create("ExtDecList"); add_son($$,$1);}
    | VarDec COMMA ExtDecList{$$ = create("ExtDecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

Specifier : TYPE{$$ = create("Specifier"); add_son($$,$1); $$->type=$1->type;}
    | StructSpecifier{$$ = create("Specifier"); add_son($$,$1);}

StructSpecifier : STRUCT ID LC DefList RC{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); struct_vars[$2->id]=$4->varsInStruct;} //strcut 名字 {vars}
    | STRUCT ID LC DefList error{$$ = create("StructSpecifier"); add_son($$,$1); my_yyerror("Missing right curly '}'",$$->line);}
    | STRUCT ID{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2);}

VarDec : ID{$$ = create("VarDec"); add_son($$,$1); if($1->dim == -1) $1->dim = 0; $$->dim = $1->dim; $$->id=$1->id; $$->type = "0";}
    | VarDec LB INT RB{$$ = create("VarDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); 
                        if($1->dim == -1) $1->dim = 0;
                        $$->dim = $1->dim + 1; $$->id = $1->id; $$->type = "0";
                        }
    | VarDec LB INT error{$$ = create("VarDec"); add_son($$,$1); my_yyerror("Missing right brackets ']'",$$->line);}

FunDec : ID LP VarList RP{$$ = create("FunDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); $$->id=$1->id; func_args[$1->id]=$3->argsList;}//有参函数的定义 id向上传个fundec 处理func_args
    | ID LP VarList error{$$ = create("FunDec"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | ID LP RP{$$ = create("FunDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); $$->id=$1->id; list<string> argsList;func_args[$1->id]=argsList;} //无参函数的定义 id向上传个fundec
    | ID LP error{$$ = create("FunDec"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}

VarList : ParamDec COMMA VarList{$$ = create("VarList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);varListIt($$,$$->argsList);} //参数列表 处理func_args
    | ParamDec{$$ = create("VarList"); add_son($$,$1);}

ParamDec : Specifier VarDec{$$ = create("ParamDec"); add_son($$,$1); add_son($$,$2); $$->type=$1->type;} //参数 类型+名字 把类型传递给paramDec

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

DefList : Def DefList{$$ = create("DefList"); add_son($$,$1); add_son($$,$2); varInStructListIt($$,$$->varsInStruct);}  //是struct 变量匹配
    | {$$ = NULL;}

Def : Specifier DecList SEMI{$$ = create("Def"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                            // cerr << $1->type << ' ' << $2->type << endl;
                            if($1->type != $2->type && $2->type != "0") my_yyerror("para diff type", $$->line);
                            else decListIt($2, $1->type); $$->type=$1->type;
                            }
    | Specifier DecList error{$$ = create("Def"); add_son($$,$1); my_yyerror("Missing semicolon ';'",$$->line);}

DecList : Dec{$$ = create("DecList"); add_son($$,$1); $$->type = $1->type;}
    | Dec COMMA DecList{$$ = create("DecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                        if ($1->type == "0") $$->type = $3->type;
                        else if ($3->type == "0") $$->type = $1->type;
                        else if ($1->type != $3->type) my_yyerror("para diff type", $$->line);
                        else
                            $$->type = $1->type;
                        }

Dec : VarDec{$$ = create("Dec"); add_son($$,$1); $$->id=$1->id; $$->dim = $1->dim; $$->type = "0";}
    | VarDec ASSIGN Exp{$$ = create("Dec"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                        // cerr << $3->dim << ' ' << $3->type << endl;
                        if ($3->dim != $1->dim) my_yyerror("Miss match type",$$->line);
                        else
                        {
                            $$->type = $3->type;
                            $1->type = $3->type;//此时变量还未获取type
                            $$->id=$1->id; $$->dim = $1->dim;
                        }
                        }
    | VarDec ASSIGN error{$$ = create("Dec"); add_son($$,$1);my_yyerror("Missing Expression ",$$->line); $$->id=$1->id;}

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

Exp : ID LP Args RP {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);
                    if(getFuncType($1->id) == "") my_yyerror("No def for func",$$->line); /*该函数当前没定义*/
                    else
                    {
                        $$->dim = 0;
                        $$->type = getFuncType($1->id);
                    }
                    }

    | ID LP Args error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line); }

    | Exp LB Exp RB {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); 
                    
                    if ($3->dim != 0 || $3->type != "int") my_yyerror("Wrong index",$$->line); /*数组坐标只能是整数*/
                    else
                    {
                        $$->dim = $1->dim - 1;
                        $$->type = $1->type;
                    }
                    }

    | Exp Operate Exp{
        $$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror("diff type", $$->line);/*数据类型不一致*/
        else {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }

    | LP Exp RP {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                $$->dim = $2->dim; $$->type = $2->type;
                }

    | MINUS Exp{$$ = create("Exp"); add_son($$,$1); add_son($$,$2);
                $$->dim = $2->dim; $$->type = $2->type;
                }

    | NOT Exp{$$ = create("Exp"); add_son($$,$1); add_son($$,$2);}

    | ID LP RP{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

    | Exp DOT ID{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

    | ID{$$ = create("Exp"); add_son($$,$1);
        if(getParaType($1->id).first == "") my_yyerror("ID no def", $$->line);
        else
        {
            $$->dim = getParaType($1->id).second;
            $$->type = getParaType($1->id).first;
        }
        }

    | INT{$$ = create("Exp"); add_son($$,$1);
        $$->dim = 0; $$->type = "int";
        $1->dim = 0; $1->type = "int";
        }

    | FLOAT{$$ = create("Exp"); add_son($$,$1);
            $$->dim = 0; $$->type = "float";
            $1->dim = 0; $1->type = "float";
            }

    | CHAR{$$ = create("Exp"); add_son($$,$1);
            $$->dim = 0; $$->type = "char";
            $1->dim = 0; $1->type = "char";
    }

    | STRING{$$ = create("Exp"); add_son($$,$1);
            $$->dim = 0; $$->type = "string";
            $1->dim = 0; $1->type = "string";
    }
    | Exp Operate error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing expression",$$->line);}
    // | Exp error Exp {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing operate",$$->line);}
    | LP Exp error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | ID LP error{$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}

    
Args : Exp COMMA Args{$$ = create("Args"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | Exp{$$ = create("Args"); add_son($$,$1);}

%%
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
void decListItForStruct(struct parsetree* root,string type,unordered_map<string, string>& varsInStruct)
{
    if(root->name == "COMMA") return;
    if(root->name == "Dec")
    {

        varsInStruct[root->id]=type;
        return;
    }
    struct parsetree* nxt = root->left_son;
    while(nxt!=NULL)
    {
        decListItForStruct(nxt,type,varsInStruct);
        nxt = nxt->nxt_bro;
    }
}

void varInStructListIt(struct parsetree* root,unordered_map<string, string>& varsInStruct)
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
         for (string argsType : pair.second) {
        std::cout << argsType << " "<<endl;
         }
         cout<<endl;
        }
        
        cout<<"struct_vars------------"<<endl;
          for (const auto& pair : struct_vars) {
        std::cout << pair.first << ": "<<std::endl;
        for (const auto& pair1: pair.second) {
        std::cout << pair1.first<<pair1.second << " "<<endl;
    }
    }
    }
    else
    {
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
