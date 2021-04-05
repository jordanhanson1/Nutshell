%{
#include <stdio.h>
#include <string.h>

int yylex(); // Defined in lex.yy.c

int yyparse(); // Need this definition so that yyerror can call it

void yyerror(char* e) {
	printf("Error: %s\n", e);
}
%}


%token <string> BYE CD UNSETENV ANYSTRING
%token <string> END PIPE PRINTENV UNALIAS INPUT AND
%token <string> STRING SETENV ALIAS OUTPUT BACKSLASH
