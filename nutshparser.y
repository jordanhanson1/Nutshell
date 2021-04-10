%{

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "global.h"
#include <dirent.h>
#include <signal.h>



#include <stdbool.h>
int parsePath(void);
int yylex(void);
int yyerror(char *s);
int runCD(char* arg);
int runSetAlias(char *name, char *word);
int runLS(void);
int runEcho(char *s);
int runPrintEnv();
int runSetEnv(char *name, char *value);
int runUnsetEnv(char *variable);
int runNotBuilt1(char* cmnd);
int runNotBuilt2(char* cmnd, char* arg);
int unAlias(char* name);
int printAl(void);
int cmndLong2(void);
bool hasFile(char* file);
int aliasCmnd(char* name);

int addToCommand(char* cm);

%}

%union {char* string;}

%type<string> nonBuilt
%start cmd_line
%token <string> BYE CD UNSETENV ANYSTRING ALIASCOM LEFTCURLY
%token <string> END PIPE PRINTENV UNALIAS INPUT AND RIGHTCURLY
%token <string> STRING SETENV ALIAS OUTPUT BACKSLASH

%%
cmd_line    :
	myCommand END 						{return 1;}
	| nonBuilt END							{cmndLong2(); return 1;}

	
myCommand :
	BYE END 		                {exit(1); return 1; }
	| built_in END        	        {return 1;}
  
 built_in :
  	| CD STRING END        			{runCD($2); return 1;}
	| ALIAS END						{printAl(); return 1;}
	| ALIAS STRING STRING END		{runSetAlias($2, $3); return 1;}
	| PRINTENV						{runPrintEnv();}
	| SETENV STRING STRING END		{runSetEnv($2, $3); return 1;}
	| UNSETENV STRING END   			{runUnsetEnv($2); return 1;}
  	| UNALIAS ALIASCOM END			{unAlias($2); return 1;}
	| ALIASCOM END					{aliasCmnd($1); return 1;}

 nonBuilt : 
 	STRING											{addToCommand($1);}
	| nonBuilt STRING								{addToCommand($2);}
	

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


int runPrintEnv() {
	for(int i = 0; i < varIndex; i++)
		printf("%s = %s\n", varTable.var[i], varTable.word[i]);
	return 1;
}

int runSetEnv(char *variable, char *word) {
	if(strcmp(varTable.var[0], variable) == 0)
		printf("cannot set this variable\n");
	if(strcmp(varTable.var[1], variable) == 0)
		printf("cannot set this variable\n");
	if(strcmp(varTable.var[2], variable) == 0)
		printf("cannot set this variable\n");
	if(strcmp(varTable.var[3], variable) == 0) {
		if(strcmp(varTable.word[3], "") != 0)
			strcat(varTable.word[3], ":");
		strcat(varTable.word[3], word);
	}
	
	else {
		setenv(variable, word, 1);
		strcpy(varTable.var[varIndex], variable);
		strcpy(varTable.word[varIndex], word);
		varIndex++;
	}
}

int runUnsetEnv(char *variable) {
	bool present = false;
	int currIndex = 0;
	for(int i = 0; i < varIndex; i++) {
		if(strcmp(varTable.var[i], variable) == 0) {
			present = true;
			currIndex = i;
			break;
		}
	}
	if(present) {
		if(strcmp(varTable.var[0], variable) == 0)
			printf("cannot unset this variable\n");
		if(strcmp(varTable.var[1], variable) == 0)
			printf("cannot unset this variable\n");
		if(strcmp(varTable.var[2], variable) == 0)
			printf("cannot unset this variable\n");
		if(strcmp(varTable.var[3], variable) == 0)
			strcpy(varTable.word[3], "");
		if(strcmp(varTable.var[4], variable) == 0) {
			strcpy(varTable.word[4], "");
		}
		else {
			strcpy(varTable.var[currIndex], "");
			strcpy(varTable.word[currIndex], "");
			varIndex--;
		}
		return 1;
	}
	else {
		printf("environment variable does not exist\n");
		return -1;
	}

}

int unAlias(char* word){

	for (int i=0; i<aliasIndex; i++){
		if (strcmp(aliasTable.name[i],word)==0){
			strcpy(aliasTable.name[i], "");
			strcpy(aliasTable.word[i], "");
			if (aliasIndex>1){
			for (int k=i+1; k<aliasIndex; k++){
				strcpy(aliasTable.name[k-1], aliasTable.name[k]);
				strcpy(aliasTable.word[k-1], aliasTable.word[k]);
			}
			}
			aliasIndex--;
			break;
		}

	}
	return 1;


}


int printAl(void){
	for (int i=0; i<aliasIndex; i++){
		printf("%s=%s \n",aliasTable.name[i], aliasTable.word[i]);
	}

	return 1;

}

int aliasCmnd(char* name){
	for (int i=0; i<aliasIndex; i++){
		if (strcmp(name,aliasTable.name[i])==0){
			return 1;
		}

	}
	printf("could not find name %s \n", name);
	return 1;
}


int cmndLong2(void){
	char* pa;
	char* arrChar[commandIndex+1];

	for (int i=0; i<commandIndex; i++){
		arrChar[i]=commandTable[i];
		if (strcmp(commandTable[i],"|")==0){
			comI[numCommands]=i;
			numPipes++;
			numCommands++;
		}
	}
	//arrChar[commandIndex]=NULL;
	parsePath();
	if (numPipes==0){
	for (int i=0; i<numPaths; i++){
	pa=(char*) malloc(sizeof(pathsVar[i])+sizeof("/")+sizeof(arrChar[0])+1);
	strcpy(pa,pathsVar[i]);
	strcat(pa,"/");
	strcat(pa,arrChar[0]);
	if (hasFile(pa)==true){
		break;
	}
	}

	if (hasFile(pa)==true){
		printf("no file found in paths");
		return 1;
	}

	int status;
	int pid=fork();
	if (pid==0){
		execv(pa,arrChar);
		}
	else{
		waitpid(-1, NULL, 0);
	}
	for (int i=0; i<commandIndex; i++){
		commandTable[i]="";
	}
	commandIndex=0;
	}
	else{
	for (int pip=0; pip<numPipes; pip++){	
	for (int i=0; i<numPaths; i++){
	pa=(char*) malloc(sizeof(pathsVar[i])+sizeof("/")+sizeof(arrChar[0])+1);
	strcpy(pa,pathsVar[i]);
	strcat(pa,"/");
	strcat(pa,arrChar[0]);
	if (hasFile(pa)==true){
		break;
	}
	}

	if (hasFile(pa)==true){
		printf("no file found in paths");
		return 1;
	}

	int status;
	int pid=fork();
	if (pid==0){
		execv(pa,arrChar);
		}
	else{
		waitpid(-1, NULL, 0);
	}
	for (int i=0; i<commandIndex; i++){
		commandTable[i]="";
	}
	commandIndex=0;
	}
	}

	return 1;
}



int parsePath(void){
	char * cmnd = malloc(strlen(varTable.word[3]) + 1); 
	strcpy(cmnd, varTable.word[3]);

	int count=1;
	for (int i=0; i<strlen(cmnd); i++){
		if (cmnd[i]==':'){
			numPaths++;
			count++;
		}
	}
	numPaths=count;
	int size=count+1;
	count=0;
	char* ptr= strtok(cmnd, ":");
	while (ptr!=NULL){
		pathsVar[count]=ptr;
		count++;
		ptr= strtok(NULL, ":");
	}
	for (int i=0; i<numPaths;i++){
		pathsVar[i];
	}	
	return 1;
}


bool hasFile(char* file){
	if (file[0]!='.'){
	char* temp = (char*) malloc(sizeof(file)+sizeof(".")+1);
	strcpy(temp,".");
	strcat(temp, file);
	return (access( temp, F_OK ) == 0 );
	}

	else{
		return (access( file, F_OK ) == 0 );
	}

}

int addToCommand(char* cm){
	commandTable[commandIndex]=cm;
	commandIndex++;
	return 1;
}

