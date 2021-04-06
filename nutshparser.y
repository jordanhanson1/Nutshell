%{
// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "global.h"
#include <dirent.h>


int yylex(void);
int yyerror(char *s);
int runCD(char* arg);
int runSetAlias(char *name, char *word);
int runNotBuilt1(char* cmnd);
int runNotBuilt2(char* cmnd, char* arg);
%}

%union {char *string;}

%start cmd_line
%token <string> BYE CD UNSETENV ANYSTRING
%token <string> END PIPE PRINTENV UNALIAS INPUT AND
%token <string> STRING SETENV ALIAS OUTPUT BACKSLASH

%%
cmd_line    :
	myCommand END					{return 1;}
	| STRING END					{runNotBuilt1($1); return 1;}
	| STRING STRING END				{runNotBuilt2($1,$2); return 1;}

myCommand :
	BYE END 		                {exit(1); return 1; }
	| CD STRING END        			{runCD($2); return 1;}
	| ALIAS STRING STRING END		{runSetAlias($2, $3); return 1;}

%%

int yyerror(char *s) {
  printf("%s\n",s);
  return 0;
  }

int runCD(char* arg) {
	if (arg[0] != '/') { // arg is relative path
		strcat(varTable.word[0], "/");
		strcat(varTable.word[0], arg);

		if(chdir(varTable.word[0]) == 0) {
			return 1;
		}
		else {
			getcwd(cwd, sizeof(cwd));
			strcpy(varTable.word[0], cwd);
			printf("Directory not found\n");
			return 1;
		}
	}
	else { // arg is absolute path
		if(chdir(arg) == 0){
			strcpy(varTable.word[0], arg);
			return 1;
		}
		else {
			printf("Directory not found\n");
                       	return 1;
		}
	}
}


int runNotBuilt1(char* cmnd){
	char* path="/bin/";
	char* pathWithCMND;
	pathWithCMND = malloc(strlen(path)+strlen(cmnd)); 
	strcpy(pathWithCMND, path); 
	strcat(pathWithCMND, cmnd); 
	printf("%s\n",pathWithCMND);
	if (fork()==0){
		execl(pathWithCMND,pathWithCMND,(char*) NULL);
	}
	else{
		waitpid(-1, NULL, 0);
	}
	return 1;
}

int runNotBuilt2(char* cmnd, char* arg){
	char* path="/bin/";
	char* pathWithCMND;
	pathWithCMND = malloc(strlen(path)+strlen(cmnd)); 
	strcpy(pathWithCMND, path); 
	strcat(pathWithCMND, cmnd); 
	printf("%s\n",pathWithCMND);
	if (fork()==0){
		execl(pathWithCMND,pathWithCMND,arg,(char*) NULL);
	}
	else{
		waitpid(-1, NULL, 0);
	}
	return 1;
}

int runSetAlias(char *name, char *word) {
	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(name, word) == 0){
			printf("Error, expansion of \"%s\" would create a loop.\n", name);
			return 1;
		}
		else if((strcmp(aliasTable.name[i], name) == 0) && (strcmp(aliasTable.word[i], word) == 0)){
			printf("Error, expansion of \"%s\" would create a loop.\n", name);
			return 1;
		}
		else if(strcmp(aliasTable.name[i], name) == 0) {
			strcpy(aliasTable.word[i], word);
			return 1;
		}
	}
	strcpy(aliasTable.name[aliasIndex], name);
	strcpy(aliasTable.word[aliasIndex], word);
	aliasIndex++;

	return 1;
}
