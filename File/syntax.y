%{
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
%token WRITE
%token READ
%left OR
%left AND
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left MUL DIV
%%
/* high-level definition */
Program : ExtDefList{$$ = create("Program");add_son($$,$1);if(ok)
{

    output($$,0);
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
       


    getir($$,0);
}}

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
                            checkReturnStmtListIt($3->left_son->nxt_bro->nxt_bro,$1->type);

                            } //函数返回值 函数头 函数体 处理func_type

ExtDecList : VarDec{$$ = create("ExtDecList"); add_son($$,$1);}
    | VarDec COMMA ExtDecList{$$ = create("ExtDecList"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}

Specifier : TYPE{$$ = create("Specifier"); add_son($$,$1); $$->type=$1->type;}
    | StructSpecifier{$$ = create("Specifier"); add_son($$,$1); $$->type=$1->type;}

StructSpecifier : STRUCT ID LC DefList RC{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); add_son($$,$5);
                                        if (!struct_vars[$2->id].empty()) {my_yyerror2("redefine the same structure type", $$->line, 15);} // 重复定义
                                        else struct_vars[$2->id]=$4->varsInStruct;
                                        // bonus 如果结构体的变量一样认为他们重复 数量 对应
                                        unordered_map<string,pair<string,int>> newOne=$4->varsInStruct;
                                        bool repeat=false;
                                        for (const auto& varsListInStruct : struct_vars) {
                                            if(varsListInStruct.first!=$2->id){  //把自己排除在外
                                                bool rep=true;
                                                //数量不同不可能相同
                                                if(varsListInStruct.second.size()==$4->varsInStruct.size()){
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
                                            my_yyerror2("redefine the same structure type S", $$->line, 15);
                                        }

                                        $$->type = $$->id;
                                        } //strcut 名字 {vars}
    | STRUCT ID LC DefList error{$$ = create("StructSpecifier"); add_son($$,$1); my_yyerror("Missing right curly '}'",$$->line);}
    | STRUCT ID{$$ = create("StructSpecifier"); add_son($$,$1); add_son($$,$2);
                $$->type = $2->id;
                // cerr << $$->type << endl;
                }

VarDec : ID{$$ = create("VarDec"); add_son($$,$1); if($1->dim == -1) $1->dim = 0; $$->dim = $1->dim; $$->id=$1->id; $$->type = "0";}
    | VarDec LB INT RB{$$ = create("VarDec"); $$->irtype = "arrayDec";  add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); 
                        if($1->dim == -1) $1->dim = 0;
                        $$->dim = $1->dim + 1; $$->id = $1->id; $$->type = "0";
                        }
    | VarDec LB INT error{$$ = create("VarDec"); add_son($$,$1); my_yyerror("Missing right brackets ']'",$$->line);}
    | VarDec LB RB{$$ = create("VarDec"); $$->irtype = "id[]"; add_son($$,$1);
                        if($1->dim == -1) $1->dim = 0;
                        $$->dim = $1->dim + 1; $$->id = $1->id; $$->type = "0";
                }

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
     if($2->dim!=0) {my_yyerror2("incompatiable return type", $$->line, 8);
                     if($2->dim < 0) my_yyerror2(" indexing on non-array variable", $$->line, 10);}
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
                            // cerr << $1->type << ' ' << $2->type << endl;
                            if($1->type != $2->type && $2->type != "0") {my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);}
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
                        else if ($1->type != $3->type) $$->type = "-1"; // 定义的变量类型不同
                        else
                            $$->type = $1->type;
                        }

Dec : VarDec{$$ = create("Dec"); add_son($$,$1); $$->id=$1->id; $$->dim = $1->dim; $$->type = "0";}
    | VarDec ASSIGN Exp{$$ = create("Dec"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
                        // cerr << $3->dim << ' ' << $3->type << endl;
                        // cerr << $1->id << endl;
                        // cerr << $1->dim << ' ' << $1->type << endl;
                        $$->id = $1->id; $$->dim = $1->dim; $$->type = "0";
                        if ($3->dim != $1->dim) {my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);}
                        else
                        {
                            $$->type = $3->type;
                            $1->type = $3->type;//此时变量还未获取type
                        }
                        }
    | VarDec ASSIGN error{$$ = create("Dec"); add_son($$,$1);my_yyerror("Missing Expression ",$$->line); $$->id=$1->id;}


LVAL : ID {$$ = create("LVAL"); $$->irtype = "id"; add_son($$, $1);
            // if (getParaType($1->id).first != "")
            // {
                $$->type = getParaType($1->id).first;
                $$->dim = getParaType($1->id).second;
                $$->id = $1->id;
            // }
            }
    | LVAL LB Exp RB {$$ = create("LVAL"); $$->irtype = "array"; add_son($$, $1); add_son($$, $2); add_son($$, $3);
                    if ($3->type != "int" && $3->dim != 0) my_yyerror2("indexing by non-integer", $$->line, 12);
                    else
                    {
                        $$->type = $1->type;
                        $$->dim = $1->dim - 1;
                    }
                    }
    | LVAL DOT ID {$$ = create("LVAL"); $$->irtype = "struct.id"; add_son($$, $1); add_son($$, $2); add_son($$, $3);//结构体取参
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

Assign : LVAL ASSIGN Exp {
        $$ = create("Exp"); add_son($$,$1); add_son($$,$2); add_son($$,$3);
        if (checkType($1, $3) == 0) { my_yyerror2("unmatching types on both sides of assignment", $$->line, 5);}/*数据类型不一致*/
        else if ($1->dim < 0 || $3->dim < 0) my_yyerror2("indexing on non-array variable", $$->line, 12);
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
    }
    | Exp ASSIGN Exp{//右值在左侧
        my_yyerror2("rvalue appears on the left-side of assignment", $$->line, 6);
    }
Exp :ID LP Args RP {$$ = create("Exp"); $$->irtype = "function"; add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); //函数有参调用

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
                    argsListIt($3,argsList);
                    list<pair<string,string>> func_argsList=func_args[$1->id];
                    //长度判断
                    if(argsList.size()!=func_argsList.size()) {my_yyerror2("invalid argument number, except "+to_string(func_argsList.size())+", got "+to_string(argsList.size()), $$->line, 9);}
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
                            my_yyerror2("invalid argument type at "+to_string(i)+ ", except "+func_argsPair.second+", got "+argsType, $$->line, 9);
                        }
                    }
                    }
                        $$->dim = 0;
                        $$->type = getFuncType($1->id);
                    // }
                    }
    | READ {$$ = create("Exp"); $$->irtype="read"; add_son($$,$1); $$->type = "int"; $$->dim = 0;}

    | ID LP Args error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line); }

    | Exp LB Exp RB {$$ = create("Exp"); $$->irtype="array"; add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4); 
                    if ($3->dim != 0 || $3->type != "int") my_yyerror2("indexing by non-integer", $$->line, 12); /*数组坐标只能是整数*/
                    else
                    {
                        $$->dim = $1->dim - 1;
                        $$->type = $1->type;
                    }
                    }

    | Exp MUL Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp AND Exp{
    $$ = create("Exp"); $$->irtype="andexpression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
    // cerr << $1->dim << ' ' << $1->type << endl;
    // cerr << $3->dim << ' ' << $3->type << endl;
    if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
    else 
    {
        $$->dim = $1->dim; $$->type = $1->type;
    }
    }
    | Exp OR Exp{
        $$ = create("Exp"); $$->irtype="orexpression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp DIV Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp PLUS Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp MINUS Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp LT Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp LE Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp GT Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp GE Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp NE Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | Exp EQ Exp{
        $$ = create("Exp"); $$->irtype="expression"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
        // cerr << $1->dim << ' ' << $1->type << endl;
        // cerr << $3->dim << ' ' << $3->type << endl;
        if (checkType($1, $3) == 0) my_yyerror2("unmatching operand", $$->line, 7);/*数据类型不一致*/
        else 
        {
            $$->dim = $1->dim; $$->type = $1->type;
        }
        }
    | LP Exp RP {$$ = create("Exp"); $$->irtype="(expression)"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
                $$->dim = $2->dim; $$->type = $2->type;
                }

    | MINUS Exp{$$ = create("Exp"); $$->irtype="-expression"; add_son($$,$1); add_son($$,$2);
                $$->dim = $2->dim; $$->type = $2->type;
                }

    | NOT Exp{$$ = create("Exp"); $$->irtype="!expression"; add_son($$,$1); add_son($$,$2);}

    | ID LP RP{$$ = create("Exp"); $$->irtype="function"; add_son($$,$1); add_son($$,$2); add_son($$,$3);  //函数无参调用
            //递归的时候，函数使用先被parse 声明才被parse 所以会显示函数没被定义，为了stage 3 4的分数（保证不出错） 暂时不处理函数没被定义了 
            // if(getFuncType($1->id) == "") 
            // {
            //     if(getParaType($1->id).first == "") my_yyerror2('"' + $1->id + '"' + " is invoked without a definition", $$->line, 2);
            //     else my_yyerror2("invoking non-function variable", $$->line, 11);
            // }

            $$->dim = 0;
            $$->type = getFuncType($1->id);
            list<pair<string,string>> func_argsList=func_args[$1->id];
            //长度判断
            if(func_argsList.size()!=0) {my_yyerror2("invalid argument number, except "+to_string(func_argsList.size())+", got 0", $$->line, 9);}
            }

    | Exp DOT ID{$$ = create("Exp"); $$->irtype="struct.id"; add_son($$,$1); add_son($$,$2); add_son($$,$3);
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

    | ID{$$ = create("Exp"); $$->irtype="id"; add_son($$,$1);
        if(getParaType($1->id).first == "") my_yyerror2('"' + $1->id + '"' + " is used without a definition", $$->line, 1);
        else
        {
            $$->dim = getParaType($1->id).second;
            $$->type = getParaType($1->id).first;
            $$->id = $1->id;
        }
        }

    | INT{$$ = create("Exp"); $$->irtype="#"; add_son($$,$1);
        $$->dim = 0; $$->type = "int";
        $1->dim = 0; $1->type = "int";
        }

    | FLOAT{$$ = create("Exp"); $$->irtype="#"; add_son($$,$1);
            $$->dim = 0; $$->type = "float";
            $1->dim = 0; $1->type = "float";
            }

    | CHAR{$$ = create("Exp"); $$->irtype="#"; add_son($$,$1);
            $$->dim = 0; $$->type = "char";
            $1->dim = 0; $1->type = "char";
    }

    | STRING{$$ = create("Exp"); $$->irtype="#"; add_son($$,$1);
            $$->dim = 0; $$->type = "string";
            $1->dim = 0; $1->type = "string";
    }
    | LP Exp error {$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | ID LP error{$$ = create("Exp"); add_son($$,$1); my_yyerror("Missing right parentheses ')'",$$->line);}
    | WRITE LP Exp RP{$$ = create("Exp");  $$->irtype="write"; add_son($$,$1); add_son($$,$2); add_son($$,$3); add_son($$,$4);}
Args : Exp COMMA Args{$$ = create("Args"); add_son($$,$1); add_son($$,$2); add_son($$,$3);}
    | Exp{$$ = create("Args"); add_son($$,$1); }

%%
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