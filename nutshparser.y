%{

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "global.h"
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <fcntl.h>


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
int unAlias(char* name);
int printAl(void);
int cmndLong2(void);
bool hasFile(char* file);

int addToCommand(char* cm);
int pipefunction(void);

char* Alexpansion(char* word);
char* envExpansion(char* cmnd);

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
	| UNSETENV STRING END   		{runUnsetEnv($2); return 1;}
  	| UNALIAS ALIASCOM END			{unAlias($2); return 1;}

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




int cmndLong2(void){
	char* pa;
	parsePath();


	if (numPipes==0){
	for (int i=0; i<numPaths; i++){
	pa=(char*) malloc(sizeof(pathsVar[i])+sizeof("/")+sizeof(commandStructTable.command[0][0])+1);
	strcpy(pa,pathsVar[i]);
	strcat(pa,"/");
	//printf("%s \n",commandStructTable.command[0][0]);
	strcat(pa,commandStructTable.command[0][0]);
	if (hasFile(pa)==false){
		break;
	}
	}


	int status;
	int pid=fork();
	if (pid==0){
		if (commandStructTable.output[0]==true) { 
        	int fil = creat(commandStructTable.fileOut[0], O_TRUNC);
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.append[0]==true) { 
        	int fil = creat(commandStructTable.fileOut[0], O_APPEND);
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.input[0]==true) { 
        	int fil = open(commandStructTable.fileIn[0], O_RDONLY);
        	dup2(fil, STDIN_FILENO);
        	close(fil);
    	}   
		execv(pa,commandStructTable.command[0]);
		}
	else{
		waitpid(-1, NULL, 0);
	}
	for (int i=0; i<commandStructTable.size[0]; i++){
		commandStructTable.command[0][i]=NULL;
	}
		commandStructTable.size[0]=0;
		commandStructTable.output[0]=false;
		commandStructTable.input[0]=false;
		commandStructTable.fileIn[0]=NULL;
		commandStructTable.fileOut[0]=NULL;

	}


	else{
	pipefunction();
	}

	return 1;
}

int pipefunction(void){
	int count=0;
	int pipeOutside[numPipes][2];
	for (int i=0; i<numPipes;i++){
	if (pipe(pipeOutside[i])<0){
		printf("error in creating pipes");
		return 1;
	}}

	for (int i=0; i<numPipes+1;i++){
		count++;

		if (fork()==0){
			 if (i != numPipes){
				dup2(pipeOutside[i][1],1);
			}
			if (i !=0){
				dup2(pipeOutside[i-1][0],STDIN_FILENO);
			}
			char* pa;
			for (int k=0; k<numPaths; k++){
			pa=(char*) malloc(sizeof(pathsVar[k])+sizeof("/")+sizeof(commandStructTable.command[i][0])+1);
			strcpy(pa,pathsVar[k]);
			strcat(pa,"/");
			//find path
			strcat(pa,commandStructTable.command[i][0]);
			if (hasFile(pa)==false){
				break;
			}
			}
			if (commandStructTable.output[i]==true) { 
        	int fil = creat(commandStructTable.fileOut[i], O_TRUNC);
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    		}   
			if (commandStructTable.append[i]==true) { 
        	int fil = creat(commandStructTable.fileOut[i], O_APPEND);
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    		}   
			if (commandStructTable.input[i]==true) { 
        		int fil = creat(commandStructTable.fileIn[i], 0644);
        		dup2(fil, STDIN_FILENO);
        		close(fil);
    		}   
			execv(pa,commandStructTable.command[i]);
			}
		else{
			if (i != numPipes){
				close(pipeOutside[i][1]);
			}
			if (i==numPipes){
				waitpid(-1,NULL,0);
			}
			}

	}
	

	for (int i=0; i<numPipes+1;i++){
		for (int j=0; j<commandStructTable.size[i];j++){
			commandStructTable.command[i][j]=NULL;
		}
		commandStructTable.size[i]=0;
		commandStructTable.output[i]=false;
		commandStructTable.input[i]=false;
		commandStructTable.fileIn[i]=NULL;
		commandStructTable.fileOut[i]=NULL;
	}
	numPipes=0;
	waitpid(-1, NULL, 0);

	return 0;

}





int parsePath(void)
{
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


bool hasFile(char* file)
{
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

int addToCommand(char* cm)
{
	if (strcmp(cm," ")==0){
		return 1;
	}
	char * temp=Alexpansion(cm);
	char * temp2=envExpansion(temp);
	if (addFileIn==true  && strcmp(temp2,">>")!=0 && strcmp(temp2,">")!=0){
		commandStructTable.fileIn[numPipes]=temp2;
		addFileIn=false;
		//printf("in file :%s \n",temp2);
	}
	else if (addFileOut==true && strcmp(temp2,"<")!=0){
		commandStructTable.fileOut[numPipes]=temp2;
		addFileOut=false;
		//printf("out file :%s \n",temp2);
	}
	else if (strcmp(temp2,">")==0){
		commandStructTable.output[numPipes]=true;
		addFileOut=true;
	}
	else if (strcmp(temp2,">>")==0){
		commandStructTable.append[numPipes]=true;
		addFileOut=true;
	}
	else if (strcmp(temp2,"<")==0){
		commandStructTable.input[numPipes]=true;
		addFileIn=true;
	}
	else if (strcmp(temp2,"|")!=0){
		char* command;
		int start=0;
		for (int i=0; i<strlen(temp2);i++){
			if (temp2[i]==' '){
				char* tempCommand=calloc(i-start,sizeof(char));
				for (int j=start;j<i;j++ ){
					tempCommand[j-start]=temp2[j];
				}
				start=i+1;
				commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=tempCommand;
				commandStructTable.size[numPipes]++;
			}
		}
		if (start==0){
			commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=temp2;
			commandStructTable.size[numPipes]++;}
		else{
				char* tempCommand=calloc(strlen(temp2)-start,sizeof(char));
				for (int j=start;j<strlen(temp2);j++ ){
					tempCommand[j-start]=temp2[j];
				}
				commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=tempCommand;
				commandStructTable.size[numPipes]++;
		}
	}
	else if (strcmp(temp2,"|")==0){
		numPipes++;
		commandStructTable.size[numPipes]=0;
		commandIndex=0;
	}
	else {
		printf("error input %s \n",temp2);

	}
	commandIndex++;
	return 1;
}


char* Alexpansion(char* cmnd) {

		int start=0;
		int end=strlen(cmnd);
		bool starting=false;
		for (int j=0; j<strlen(cmnd); j++){
			if (starting==false && (isalpha(cmnd[j]) || isdigit(cmnd[j])) ){
				start=j;
				starting=true;
			}
			if (starting==true && (isalpha(cmnd[j])==false && isdigit(cmnd[j])==false) ){
				end=j;
				break;
			}
		}
		char* begging=calloc(start,sizeof(char));
		char* ending=calloc(strlen(cmnd)-end+1,sizeof(char));
		for (int i=0; i<strlen(cmnd);i++){
			if (i<start){
				begging[i]=cmnd[i];
			}
			if (i>=end){
				ending[i-end]=cmnd[i];
			}
		}

		char* check=calloc(end-start,sizeof(char));
		for (int i=0; i<(end-start); i++){
			check[i]=cmnd[start+i];
		}
			for (int i = 0; i < aliasIndex; i++) {
				if(strcmp(aliasTable.name[i], check) == 0){
					char* middle= Alexpansion(aliasTable.word[i]);
					char* whole=malloc(sizeof(middle)+sizeof(begging)+sizeof(ending)+1);
					strcpy(whole,begging);
					strcat(whole,middle);
					strcat(whole,ending);
					return whole;
				}
			}
			return cmnd;

}


char* envExpansion(char* cmnd) {
	int iDelete=100;
	int indexC=0;
	bool startString=false;
	bool first=false;
	for (int i=0; i<strlen(cmnd); i++){
		if (cmnd[i]=='$' && startString==false){
			startString=true;
			iDelete=i;
		}
		if (cmnd[i]=='}' && startString==true && first==false){
			first=true;
			indexC=i;
		}
	}

	

	if (startString==true){
		bool startword=false;
		bool endWord=false;
		char* begging=calloc(iDelete,sizeof(char));
		char* word=calloc(indexC-iDelete-2,sizeof(char));
		char* end=calloc(strlen(cmnd)-indexC,sizeof(char));
		for (int i=0;i<iDelete;i++){
			begging[i]=cmnd[i];
		}
		int counter=0;
		for (int i=iDelete+2; i<indexC;i++){
			if (cmnd[i]=='{'){}
			else if (cmnd[i]=='}'){
				indexC=i;
				break;
			}
			else{
				word[counter]=cmnd[i];
				counter++;
			}
		}
		counter=0;
		for (int i=indexC+1; i<strlen(cmnd);i++){
			end[counter]=cmnd[i];
			counter++;
		}

		bool not=true;
		for(int i = 0; i < varIndex; i++) {
			if(strcmp(varTable.var[i], word) == 0) {
				char* temperary=malloc(sizeof(varTable.word[i])+1);
				strcpy(temperary,varTable.word[i]);
				word=Alexpansion(temperary);
				not=false;
			}
		}
		if (not==true){
			return cmnd;
		}		
		char* r=calloc(strlen(begging)+strlen(word)+strlen(end),sizeof(char));
		strcpy(r,begging);
		strcat(r,word);

		strcat(r,end);
		return envExpansion(r);


	}

	return cmnd;

}