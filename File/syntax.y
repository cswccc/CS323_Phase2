%{
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
    | Specifier FunDec CompSt{$$ = create("ExtDef"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                            if(getFuncType($2->id) != "") my_yyerror2('"' + $2->id + '"' + " is redefined", $$->line, 4);
                            else func_type[$2->id] = $1->type;
                            // cerr<<"函数体返回值"<<$3->type<<endl;
                            // cerr<<"函数定义返回值"<<$1->type<<endl;

                            //comst->stmtlist->stmt->return 检查函数返回值类型
                            //拿到stmtlist
                            checkReturnStmtListIt($3->left_son->nxt_bro,$1->type);


                            } //函数返回值 函数头 函数体 处理func_type

ExtDecList : VarDec{$$ = create("ExtDecList"); add_son($$,$1);}
    | VarDec COMMA ExtDecList{$$ = create("ExtDecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

Specifier : TYPE{$$ = create("Specifier"); add_son($$,$1); $$->type=$1->type;}
    | StructSpecifier{$$ = create("Specifier"); add_son($$,$1); $$->type=$1->type;}

StructSpecifier : STRUCT ID LC DefList RC{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); struct_vars[$2->id]=$4->varsInStruct;
                                        if (struct_vars[$2->id].empty()) {} // 当前结构体类型不存在
                                        $$->type = $$->id;
                                        } //strcut 名字 {vars}
    | STRUCT ID LC DefList error{$$ = create("StructSpecifier"); add_son($$,$1); my_yyerror("Missing right curly '}'",$$->line);}
    | STRUCT ID{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2);
                if (struct_vars[$2->id].empty()) {} // 当前结构体类型不存在
                $$->type = $2->id;
                // cerr << $$->type << endl;
                }

VarDec : ID{$$ = create("VarDec"); add_son($$,$1); if($1->dim == -1) $1->dim = 0; $$->dim = $1->dim; $$->id=$1->id; $$->type = "0";}
    | VarDec LB INT RB{$$ = create("VarDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); 
                        if($1->dim == -1) $1->dim = 0;
                        $$->dim = $1->dim + 1; $$->id = $1->id; $$->type = "0";
                        }
    | VarDec LB INT error{$$ = create("VarDec"); add_son($$,$1); my_yyerror("Missing right brackets ']'",$$->line);}

FunDec : ID LP VarList RP{$$ = create("FunDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); $$->id=$1->id; func_args[$1->id]=$3->argsList;
                        }//有参函数的定义 id向上传个fundec 处理func_args
    | ID LP VarList error{$$ = create("FunDec"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | ID LP RP{$$ = create("FunDec"); add_son($$,$1); add_son($$,$2); add_son($$,$3); $$->id=$1->id; list<pair<string, string>> argsList;func_args[$1->id]=argsList;} //无参函数的定义 id向上传个fundec
    | ID LP error{$$ = create("FunDec"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}

VarList : ParamDec COMMA VarList{$$ = create("VarList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);varListIt($$,$$->argsList);} //参数列表 处理func_args
    | ParamDec{$$ = create("VarList"); add_son($$,$1);varListIt($$,$$->argsList);}

ParamDec : Specifier VarDec{$$ = create("ParamDec"); add_son($$,$1); add_son($$,$2); $$->type=$1->type; $$->id=$2->id;$$->dim = $2->dim;} //参数 类型+名字 把类型传递给paramDec

CompSt : LC DefList StmtList RC{$$ = create("CompSt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); $$->type=$3->type; } //把函数里面的CompSt type换成最后一条stmtlist的类型

CompSt : LC DefList StmtList error{$$ = create("CompSt"); add_son($$,$1); my_yyerror("Missing right curly '}'",$$->line);}

StmtList : Stmt StmtList{$$ = create("StmtList"); add_son($$,$1); add_son($$,$2); 

if ($2==NULL){$$->type=$1->type;}
else{
    $$->type=$2->type;
}
}  //把函数里面的stmtlist type换成最后一条stmt的类型
    | {$$ = NULL;}

Stmt : Exp SEMI{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2);}
    | Assign SEMI{$$ = create("Stmt"); add_son($$, $1); add_son($$, $2);}
    | Exp error{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); my_yyerror("Missing semicolon ';'",$$->line);}
    | Def{$$ = create("Stmt"); add_son($$,$1);}
    | CompSt{$$ = create("Stmt"); add_son($$,$1);
    //考虑返回值在if else语句中
    $$->type=$1->type;
    // cerr<<$1->type<<endl;
    }
    | RETURN Exp SEMI{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); $$->type=$2->type; 
     //返回值的维度不是0就报错
     if($2->dim!=0) {my_yyerror2(" return type wrong", $$->line, 8);
                     my_yyerror2(" indexing on non-array variable", $$->line, 10);}
      } //为了把 return a ;    a是exp  类型给到retrun a  stmt
    | RETURN Exp error{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing semicolon ';'",$$->line);}
    | RETURN error SEMI{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing Expression",$$->line);}
    | IF LP Exp RP Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); $$->type=$5->type;}
    | IF LP Exp error Stmt{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | IF LP Exp RP Stmt ELSE Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); add_son($$,$6); add_son($$,$7);

    }
    | IF LP Exp error Stmt ELSE Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5); add_son($$,$6); add_son($$,$7);my_yyerror("Missing right parentheses ')'",$$->line);}
    | WHILE LP Exp RP Stmt{$$ = create("Stmt"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5);}
    // | WHILE LP Exp error Stmt{$$ = create("Stmt"); add_son($$,$1); my_yyerror("Missing right parentheses222 ')'",$$->line);}

DefList : Def DefList{$$ = create("DefList"); add_son($$,$1); add_son($$,$2); varInStructListIt($$,$$->varsInStruct);}  //是struct 变量匹配
    | {$$ = NULL;}

Def : Specifier DecList SEMI{$$ = create("Def"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                            cerr << $1->type << ' ' << $2->type << endl;
                            // if($1->type != $2->type && $2->type != "0") my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);
                            // else 
                            decListIt($2, $1->type); $$->type=$1->type;
                            }
    | Specifier DecList error{$$ = create("Def"); add_son($$,$1); my_yyerror("Missing semicolon ';'",$$->line);}

DecList : Dec{$$ = create("DecList"); add_son($$,$1); $$->type = $1->type;
            // cerr << $$->type << endl;
            if (getParaType($1->id).first != "") my_yyerror2('"' + $1->id + '"' + " is redefined", $$->line, 3); // 重复定义
            }
    | Dec COMMA DecList{$$ = create("DecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                        if ($1->type == "0") $$->type = $3->type;
                        else if ($3->type == "0") $$->type = $1->type;
                        else if ($1->type != $3->type) my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);
                        else
                            $$->type = $1->type;
                        }

Dec : VarDec{$$ = create("Dec"); add_son($$,$1); $$->id=$1->id; $$->dim = $1->dim; $$->type = "0";}
    | VarDec ASSIGN Exp{$$ = create("Dec"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                        // cerr << $3->dim << ' ' << $3->type << endl;
                        if ($3->dim != $1->dim) my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);
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

Operate2 : AND{$$ = create("AND");$$->line = $1->line;}
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

LVAL : ID {$$ = create("LVAL"); add_son($$, $1);
            // if (getParaType($1->id).first != "")
            // {
                $$->type = getParaType($1->id).first;
                $$->dim = getParaType($1->id).second;
            // }
            }
    | LVAL LB Exp RB {$$ = create("LVAL"); add_son($$, $1); add_son($$, $2); add_son($$, $3);
                    if ($3->type != "int" && $3->dim != 0) my_yyerror2("indexing by non-integer", $$->line, 12);
                    else
                    {
                        $$->type = $1->type;
                        $$->dim = $1->dim - 1;
                    }
                    }
    | LVAL DOT ID {$$ = create("LVAL"); add_son($$, $1); add_son($$, $2); add_son($$, $3);//结构体取参
        if (struct_vars[$1->type][$3->id].first == "")
        {
            if (isNotStruct(getParaType($3->id).first) == 1) my_yyerror2("accessing with non-struct variable", $$->line, 13);
            else my_yyerror2("ccessing an undefined structure member", $$->line, 14);
            $$->dim = 0;
        }
        else
        {
            // cerr << $1->type << ' ' << $3->id << endl;
            $$->type = struct_vars[$1->type][$3->id].first;
            $$->dim = struct_vars[$1->type][$3->id].second;
        }
    }

Assign : LVAL ASSIGN Exp{
        $$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
        if (checkType($1, $3) == 0) my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);/*数据类型不一致*/
        else if ($1->dim < 0 || $3->dim < 0) my_yyerror2("indexing on non-array variable", $$->line, 12);
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
    }
    | Exp ASSIGN Exp{//右值在左侧
        my_yyerror2("rvalue appears on the left-side of assignment", $$->line, 6);
    }

Exp : ID LP Args RP {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); //函数有参调用
                    if(getFuncType($1->id) == "") my_yyerror2('"' + $1->id + '"' + " is invoked without a definition", $$->line, 2); /*该函数当前没定义*/
                    // else
                    // {

                    //需要递归args 去看它是不是匹配函数的参数
                    list<string> argsList; //存args的类型 左到右
                    argsListIt($3,argsList);
                    list<pair<string,string>> func_argsList=func_args[$1->id];
                    //长度判断
                    if(argsList.size()!=func_argsList.size()) {my_yyerror2("invalid argument number, except"+to_string(func_argsList.size())+", got "+to_string(argsList.size()), $$->line, 9);}
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
                            my_yyerror2("invalid argument type at "+to_string(i)+", except "+func_argsPair.second+", got "+argsType, $$->line, 9);
                        }
                    }
                    }

                        $$->dim = 0;
                        $$->type = getFuncType($1->id);
                    // }
                    }

    | ID LP Args error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line); }

    | Exp LB Exp RB {$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); 
                    
                    if ($3->dim != 0 || $3->type != "int") my_yyerror2("indexing by non-integer", $$->line, 12); /*数组坐标只能是整数*/
                    else
                    {
                        $$->dim = $1->dim - 1;
                        $$->type = $1->type;
                    }
                    }

    | Exp Operate2 Exp{
        $$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
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

    | ID LP RP{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);  //函数无参调用 
     $$->dim = 0;
     $$->type = getFuncType($1->id);
     list<pair<string,string>> func_argsList=func_args[$1->id];
    //长度判断
    if(func_argsList.size()!=0) {my_yyerror2("invalid argument number, except "+to_string(func_argsList.size())+", got 0", $$->line, 9);}
     }

    | Exp DOT ID{$$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                if (struct_vars[$1->type][$3->id].first == "")
                {
                    if (isNotStruct(getParaType($3->id).first) == 1) my_yyerror2("accessing with non-struct variable", $$->line, 13);
                    else my_yyerror2("ccessing an undefined structure member", $$->line, 14);
                    $$->dim = 0;
                }//结构体没这个变量
                else
                {
                    $$->type = struct_vars[$1->type][$3->id].first;
                    $$->dim = struct_vars[$1->type][$3->id].second;
                }
                }

    | ID{$$ = create("Exp"); add_son($$,$1);
        if(getParaType($1->id).first == "") my_yyerror2('"' + $1->id + '"' + " is used without a definition", $$->line, 1);
        else
        {
            $$->dim = getParaType($1->id).second;
            $$->type = getParaType($1->id).first;
            $$->id = $1->id;
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
    // ok = false;
}

void my_yyerror2(const string s, int line, int type)
{
    fprintf(stderr, "Error type %d at Line %d: %s\n", type, line, s.c_str());
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
        cout<<"hhh"<<endl;
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

            if(root->nxt_bro->type!=type){
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
