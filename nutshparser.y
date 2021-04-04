%{
#include <stdio.h>

int yylex(); // Defined in lex.yy.c

int yyparse(); // Need this definition so that yyerror can call it

void yyerror(char* e) {
	printf("Error: %s\n", e);
}
%}


%token LS
%token DOT
%token DDOT
%token 