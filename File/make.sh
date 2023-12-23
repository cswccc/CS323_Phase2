bison -d syntax.y
flex lex.l
g++ syntax.tab.c -o splc
./splc test.c