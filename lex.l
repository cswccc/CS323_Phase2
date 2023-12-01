%{
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #include "syntax.tab.h"
    #define YYSTYPE struct parsetree*
    void line();
    int check(char* num);
    // global variables
    // int identifiers = 0;
    // 注意顺序比如 1.>= =    >=要写在前面  2.关键字写在id的前面 3.错误放在最后
    // 4. 0X165 16进制需要放在单个整数的前面 5.错误的16进制数放在错误id前面
    //转义字符和字符串
    //数组
    int ok = true;
    int lines = 1;
%}
%option noyywrap
DOT  "."
SEMI ";"
COMMA  ","
ASSIGN  "="
LT  "<"
LE  "<="
GT  ">"
GE  ">="
NE "!="
EQ "=="
PLUS "+"
MINUS "-"
MUL "*"
DIV  "/"
AND  "&&"
OR  "||"
BITAND "&"
BITOR "|"
BITXOR "^"
NOT  "!"
LP "("
RP  ")"
LB  "["
RB "]"
LC  "{"
RC  "}"
/*SPCHAR \\(a|b|f|n|r|t|v|\\|'|\"|?|0)*/
SPCHAR \\(a|b|f|n|r|t|v|\\|'|\"|\?|0)
CHAR "'"({SPCHAR}|([^\\]))"'"
STRING \"({SPCHAR}|([^(\\|\"]))*\"

letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
INT [1-9]{digit}+|{digit}
INT_HEX 0[xX][a-fA-F1-9][a-fA-F0-9]*
ID {letter_}({digit}|{letter_})*
Type (char)|(int)|(float)|(string)

wrongId {digit}({digit}|{letter_})*
INT_HEX_ERROR (0[xX][a-fA-F0-9]*[g-zG-Z]+[a-zA-Z0-9]*)|(0[xX][0]+[a-fA-F0-9]+)
CHAR_HEX_ERROR ("'"\\[xX][a-fA-F0-9]*[g-zG-Z]+[a-zA-Z0-9]*"'")|("'"\\[xX][a-fA-F0-9][a-fA-F0-9][a-fA-F0-9]+"'")|("'"\\[xX]0[a-fA-F0-9]"'")
CHAR_HEX ("'"\\[xX][a-fA-F1-9]([a-fA-F0-9]){0,1}"'")|("'"\\[xX]0"'")
INT_ERROR 0+{digit}+
/*未定义字符*/
UndefindERROR .

/* 关键字 */
STRUCT struct
RETURN return
IF if
ELSE else
WHILE while

%%
{CHAR} {/*line();*/       /*printf("CHAR %s\n",yytext);*/    yylval = create_add("CHAR: ",yytext);  return CHAR;}
{CHAR_HEX} {/*line();*/       /*printf("CHAR %s\n",yytext);*/    yylval = create_add("CHAR: ",yytext);  return CHAR;}
{STRUCT} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("STRUCT");     return STRUCT;}
{RETURN} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("RETURN");     return RETURN;}
{IF}  {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("IF");     return IF;}
{ELSE} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("ELSE");     return ELSE;}
{WHILE} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("WHILE");     return WHILE;}

{AND} {/*line();*/       /*printf("AND %s\n",yytext);   */ yylval = create("AND");     return AND;}
{OR} {/*line();*/       /*printf("OR %s\n",yytext);   */ yylval = create("OR");     return OR;}
{BITAND} {yylval = create("BITAND");     return BITAND;}
{BITOR} {yylval = create("BITOR");     return BITOR;}
{BITXOR} {yylval = create("BITXOR");     return BITXOR;}
{LP} {/*line();*/       /*printf("LP %s\n",yytext);   */ yylval = create("LP");     return LP;}
{RP} {/*line();*/       /*printf("RP %s\n",yytext);   */ yylval = create("RP");     return RP;}
{LC} {/*line();*/       /*printf("LC %s\n",yytext);   */ yylval = create("LC");     return LC;}
{RC} {/*line();*/       /*printf("RC %s\n",yytext);   */ yylval = create("RC");     return RC;}
{LB} {/*line();*/       /*printf("LB %s\n",yytext);   */ yylval = create("LB");     return LB;}
{RB} {/*line();*/       /*printf("RB %s\n",yytext);   */ yylval = create("RB");     return RB;}
"//".*\n {/*line();*/       /*printf("%s",yytext);*/   lines++;}

{EQ}    {/*line();*/       /*printf("EQ %s\n",yytext);   */ yylval = create("RQ");     return EQ;}
{NE}    {/*line();*/       /*printf("NE %s\n",yytext);   */ yylval = create("NE");     return NE;}
{LE}     {/*line();*/       /*printf("LE %s\n",yytext);   */ yylval = create("LE");     return LE;}
{GE}     {/*line();*/       /*printf("GE %s\n",yytext);   */ yylval = create("GE");     return GE;}
{ASSIGN}    {/*line();*/       /*printf("ASSIGN %s\n",yytext);   */ yylval = create("ASSIGN");     return ASSIGN;}
{LT}    {/*line();*/       /*printf("LT %s\n",yytext);   */ yylval = create("LT");     return LT;}
{GT}    {/*line();*/       /*printf("GT %s\n",yytext);   */ yylval = create("GT");     return GT;}
{PLUS}   {/*line();*/       /*printf("PLUS %s\n",yytext);   */ yylval = create("PLUS");     return PLUS;}
{MINUS}   {/*line();*/       /*printf("MINUS %s\n",yytext);   */ yylval = create("MINUS");     return MINUS;}
{MUL}   {/*line();*/       /*printf("MUL %s\n",yytext);   */ yylval = create("MUL");     return MUL;}
{DIV}    {/*line();*/       /*printf("DIV %s\n",yytext);   */ yylval = create("DIV");     return DIV;}

{DOT} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("DOT");     return DOT;}
{SEMI} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("SEMI");     return SEMI;}
{COMMA} {/*line();*/       /*printf("%s\n",yytext);   */ yylval = create("COMMA");     return COMMA;}

{Type} {/*line();*/       /*printf("Type %s\n",yytext);   */ yylval = create_add("TYPE: ",yytext); yylval->type=yytext;  return TYPE;}
{ID} {/*line();*/       /*printf("Id %s\n",yytext);   */ yylval = create_add("ID: ",yytext);  yylval->id=yytext; return ID;}
(([1-9]{digit}*)|0+)\.{digit}+ {/*line();*/       /*printf("Float %s\n",yytext);   */ yylval = create_add("FLOAT: ",yytext);   return FLOAT;}
{INT_HEX} {/*line();*/       /*printf("Hex %s\n",yytext);   */ yylval = create_add("INT: ",yytext);   return INT;}
{INT} {/*line();*/       /*printf("INT10 %s\n",yytext);   */ yylval = create_add("INT: ",yytext); if(!check(yytext)){fprintf(stderr,"too large int %s at line %d\n",yytext,lines);}  return INT;}
{NOT} {/*line();*/       /*printf("NOT %s\n",yytext);   */ yylval = create("NOT");     return NOT;}
{STRING} {/*line();*/       /*printf("string %s\n",yytext);   */ yylval = create_add("STRING: ",yytext);   return STRING;}
\n {lines++;}
[\t\r ]+ {}
{INT_ERROR} {ok=false;fprintf(stderr,"Error type A at Line %d: unknown lexeme %s\n",lines,yytext);return INT;}
{CHAR_HEX_ERROR} {ok=false;fprintf(stderr,"Error type A at Line %d: unknown lexeme %s\n",lines,yytext);return INT;}
{INT_HEX_ERROR} {ok=false;fprintf(stderr,"Error type A at Line %d: unknown lexeme %s\n",lines,yytext);return INT;}
{wrongId} {ok=false;fprintf(stderr,"Error type A at Line %d: unknown lexeme %s\n",lines,yytext);return ID;}
{UndefindERROR} {ok=false;fprintf(stderr,"Error type A at Line %d: unknown lexeme %s\n",lines,yytext);}
%%

int check(char* num)
{
    long long real = 0;
    for(int i=0; num[i]!='\0'; i++)
    {
        real=real*10+i;
        if(real>=2147483648)
        {
            return false;
        }
    }
    return true;
}


void line(){
    printf("lines:%d ",lines);
}

// int main(int argc, char **argv){
//     char *file_path;
//     if(argc < 2){
//         fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
//           return EXIT_FAIL;
//     } else if(argc == 2){
//         file_path = argv[1];
//         if(!(yyin = fopen(file_path, "r"))){
//             perror(argv[1]);
//               return EXIT_FAIL;
//         }
//         yylex();
//           return EXIT_OK;
//     } else{
//         fputs("Too many arguments! Expected: 2.\n", stderr);
//           return EXIT_FAIL;
//     }
// }