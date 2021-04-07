# Simple Makefile

CC=/usr/bin/cc

all:  bison-config flex-config nutshell

bison-config:
	win_bison -d nutshparser.y

flex-config:
	win_flex nutshscanner.l

nutshell: 
	$(CC) nutshell.c nutshparser.tab.c lex.yy.c -o nutshell.o
#gcc nutshell.c nutshparser.tab.c lex.yy.c -o nutshell

clean:
	rm nutshparser.tab.c nutshparser.tab.h lex.yy.c