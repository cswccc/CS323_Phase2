CC=g++
FLEX=flex
BISON=bison
splc:
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	$(CC) syntax.tab.c -o splc
clean:
.PHONY: splc