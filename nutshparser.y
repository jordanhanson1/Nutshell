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
#include <wordexp.h>


#include <stdbool.h>
int parsePath(void);
int yylex(void);
int yyerror(char *s);
int runCD(char* dir);
int runSetAlias(char *name, char *word);
int runLS(void);
int runEcho(char *s);
int runPrintEnv(void);
int runSetEnv(char *name, char *value);
int runUnsetEnv(char *var);
int unAlias(char* al);
int printAl(void);
int cmndLong2(void);
char* hasFile(char* file);

int addToCommand(char* cm);
int pipefunction(void);
int  wildcardFunc();
bool aliasLoopDetect(char* name, char* word);
char* Alexpansion(char* word);
char* envExpansion(char* cmnd);
char* envExpansionForUnset(char* cmnd);

%}

%union {char* string;}

%type<string> nonBuilt
%start cmd_line
%token <string> BYE CD UNSETENV ANYSTRING ALIASCOM LEFTCURLY
%token <string> END PIPE UNALIAS INPUT AND RIGHTCURLY
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
	| SETENV STRING STRING END		{runSetEnv($2, $3); return 1;}
	| UNSETENV STRING END   		{runUnsetEnv($2); return 1;}
  	| UNALIAS STRING END			{unAlias($2); return 1;}

 nonBuilt : 
 	STRING											{addToCommand($1);}
	| nonBuilt STRING								{addToCommand($2);}
	

%%

int yyerror(char *s) {
  printf("%s\n",s);
  return 0;
  }

int runCD(char* dir) {
	char* temp= Alexpansion(dir);
	char* arg=envExpansion(temp);
	wordexp_t patt;
    char **words;
	bool wild=false;
	char getrid;
	for (int i=0; i<strlen(dir); i++){
		if (dir[i]=='*'|| dir[i]=='?'){
			wild = true;
			getrid=dir[i];
		}
	}
	if (wild == true){
    if (wordexp(dir, &patt, 0) != 0){
		printf("error in expanding wildcard");
	}
    words = patt.we_wordv;
	if (patt.we_wordc==0){
		char * t=malloc(sizeof(dir)+1);
		strcpy(t,dir);
		char *src, *dst;
    	for (src = dst = t; *src != '\0'; src++) {
        	*dst = *src;
        	if (*dst != getrid) dst++;
    	}
    	*dst = '\0';
		arg=t;
	}
	else{
		arg = words[0];
	}
	}



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

bool aliasLoopDetect(char* name, char* word){
	bool here=false;
	int index=0;
	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(name, word) == 0){
			return true;
		}
		else if((strcmp(aliasTable.name[i], name) == 0) && (strcmp(aliasTable.word[i], word) == 0)){
			return true;
		}
	}
	
	return false;

}



int runSetAlias(char *name, char *word) {
	
	if (aliasLoopDetect(name,word)==false){
	strcpy(aliasTable.name[aliasIndex], name);
	strcpy(aliasTable.word[aliasIndex], word);
	aliasIndex++;}
	else{
		printf("Error, expansion of \"%s\" would create a loop.\n", name);
	}

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

int runUnsetEnv(char *var) {
	char* variable= Alexpansion(var);
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
		else if (strcmp(varTable.var[1], variable) == 0)
			printf("cannot unset this variable\n");
		else if (strcmp(varTable.var[2], variable) == 0)
			printf("cannot unset this variable\n");
		else if (strcmp(varTable.var[3], variable) == 0)
			printf("cannot unset this variable\n");
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

int unAlias(char* al){
	char * word=envExpansionForUnset(al);
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
	bool foundPath=true;

	if (numPipes==0){
	if (commandStructTable.printenv[0]==false && commandStructTable.printalias[0]==false){
	if (commandStructTable.path[0]==true){
		foundPath=false;
		pa =hasFile(commandStructTable.command[0][0]);
		if (strcmp(pa,"none")!=0){
			foundPath=true;
		}
	}
	else{
		pa=malloc(sizeof(commandStructTable.command[0][0])+1);
		strcpy(pa,commandStructTable.command[0][0]);
		foundPath=true;
	}}
	if (foundPath==false){
		printf("could not find the executable in the path \n");
		return 1;
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
        	int fil = open(commandStructTable.fileOut[0], 'a');
        	dup2(fil, STDOUT_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.input[0]==true) { 
        	int fil = open(commandStructTable.fileIn[0], O_RDONLY);
        	dup2(fil, STDIN_FILENO);
        	close(fil);
    	}   
		if (commandStructTable.fileEr[0]==true){
			int fil = creat(commandStructTable.fileError[0], O_TRUNC);
			dup2(fil, STDERR_FILENO);
			close(fil);
		}
		else if (commandStructTable.errorOut[0]==true){
			dup2(STDOUT_FILENO, STDERR_FILENO);
		}



		if (commandStructTable.printalias[0]==true && commandStructTable.size[0]>0 && strcmp(commandStructTable.command[0][0],">")!=0&&strcmp(commandStructTable.command[0][0],">>")!=0){
			runSetAlias(commandStructTable.command[0][0],commandStructTable.command[0][1]);
		}
		else if (commandStructTable.printalias[0]==true){
			printAl();
		}
		else if (commandStructTable.printenv[0]==true){
			runPrintEnv();
		}
		else {
			execv(pa,commandStructTable.command[0]);
		}
		}
	else{
		if (background==false){
		waitpid(-1, NULL, 0);}
	}
	for (int i=0; i<commandStructTable.size[0]; i++){
		commandStructTable.command[0][i]=NULL;
	}
		commandStructTable.size[0]=0;
		commandStructTable.output[0]=false;
		commandStructTable.input[0]=false;
		commandStructTable.fileIn[0]=NULL;
		commandStructTable.fileOut[0]=NULL;
		commandStructTable.fileError[0]=false;
		commandStructTable.errorOut[0]=false;
		commandStructTable.fileError[0]=NULL;
		commandStructTable.printenv[0]=false;
		commandStructTable.printalias[0]=false;
		commandStructTable.path[0]=false;

	}


	else{
	pipefunction();
	}
	background=false;
	numPipes=0;
	return 1;
}

int pipefunction(void){
	bool foundPath=true;
	int count=0;
	int pipeOutside[numPipes][2];
	for (int i=0; i<numPipes;i++){
	if (pipe(pipeOutside[i])<0){
		printf("error in creating pipes");
		return 1;
	}}

	for (int i=0; i<numPipes+1;i++){
		count++;

		char* pa;
		if (commandStructTable.printenv[i]==false && commandStructTable.printalias[i]==false){
		if (commandStructTable.path[i]==true){
			pa =hasFile(commandStructTable.command[i][0]);
			if (strcmp(pa,"none")!=0){
				foundPath=true;
			}
		}
		else{
			pa=malloc(sizeof(commandStructTable.command[i][0])+1);
			strcpy(pa,commandStructTable.command[i][0]);
			
			foundPath=true;
		}}

		if (foundPath==false){
			printf("could not find executable in the path");
			return 1;
		}

		if (fork()==0){
			 if (i != numPipes){
				dup2(pipeOutside[i][1],STDOUT_FILENO);
			}
			if (i !=0){
				dup2(pipeOutside[i-1][0],STDIN_FILENO);
			}

			if (commandStructTable.output[i]==true) { 
        		int fil = creat(commandStructTable.fileOut[i], O_TRUNC);
        		dup2(fil, STDOUT_FILENO);
        		close(fil);
    		}   
			if (commandStructTable.append[i]==true) { 
        		int fil = open(commandStructTable.fileOut[i], 'a');
        		dup2(fil, STDOUT_FILENO);
        		close(fil);
    		}   
			if (commandStructTable.input[i]==true) { 
        		int fil = open(commandStructTable.fileIn[i], O_RDONLY);
        		dup2(fil, STDIN_FILENO);
        		close(fil);
    		}   
			if (commandStructTable.fileEr[i]==true){
				int fil = creat(commandStructTable.fileError[i], O_TRUNC);
				dup2(fil, STDERR_FILENO);
				close(fil);
			}
			else if (commandStructTable.errorOut[i]==true){
				dup2(STDOUT_FILENO, STDERR_FILENO);
			}

			if (commandStructTable.printalias[i]==true){
				printAl();
			}
			else if (commandStructTable.printenv[i]==true){
				runPrintEnv();
			}
			else{
				execv(pa,commandStructTable.command[i]);
			}
		}
	else{
			if (i != numPipes){
				close(pipeOutside[i][1]);
			}
			if (i==numPipes && background==false){
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
		commandStructTable.fileError[i]=false;
		commandStructTable.errorOut[i]=false;
		commandStructTable.fileError[i]=NULL;
		commandStructTable.printenv[i]=false;
		commandStructTable.printalias[i]=false;
		commandStructTable.path[i]=false;
	}
	numPipes=0;
	if (background==false){
	waitpid(-1, NULL, 0);}
	background=false;

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


char* hasFile(char* file)
{
	struct stat   buffer;
	bool found=false;
	for (int i=0; i<numPaths; i++){
		char* temp=malloc(sizeof(pathsVar[i])+sizeof(file)+sizeof("/")+1);
		strcpy(temp,pathsVar[i]);
		strcat(temp,"/");
		strcat(temp,file);
		if (stat (temp, &buffer) == 0){
			found=true;
			return temp;
		}
	}  
  return "none";

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
	else if (strcmp(temp2, "2>&1")==0){
		commandStructTable.errorOut[numPipes]=true;
	}
	else if (temp2[0]=='2' && temp2[1]=='>'){
		commandStructTable.errorOut[numPipes]=true;
		char* fil= calloc(strlen(temp2)-2,sizeof(char));
		for (int i=2; i<strlen(temp2);i++){
			fil[i-2]=temp2[i];
		}
		commandStructTable.fileEr[numPipes]=true;
		commandStructTable.fileError[numPipes]=fil;
	}
	else if (strcmp(temp2,"&")==0){
		background=true;
	}
	else if (strcmp(temp2,"printenv")==0){
		commandStructTable.printenv[numPipes]=true;
		commandStructTable.path[numPipes]=false;
	}
	else if (strcmp(temp2,"alias")==0){
		commandStructTable.printalias[numPipes]=true;
		commandStructTable.path[numPipes]=false;
	}
	else if (strcmp(temp2,"|")!=0){
		if (commandStructTable.size[numPipes]==0){
			addFileIn=false;
			addFileOut=false;
			if (temp2[0]=='/' || temp2[0]=='.' || commandStructTable.printalias[numPipes]==true || commandStructTable.printenv[numPipes]==true){
				commandStructTable.path[numPipes]=false;}
			else {
				commandStructTable.path[numPipes]=true;
			}
		}
		char* command;
		int start=0;
		for (int i=0; i<strlen(temp2);i++){
			if (temp2[i]=='*'|| temp2[i]=='?'){
				return wildcardFunc(temp2);
			}
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

char* envExpansionForUnset(char* cmnd){
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
				word=malloc(sizeof(varTable.word[i])+1);
				strcpy(word,varTable.word[i]);
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


int wildcardFunc(char* cm){
    wordexp_t patt;
    char **words;
	char getrid;
	for (int i=0; i<strlen(cm); i++){
		if (cm[i]=='*'|| cm[i]=='?'){
			getrid=cm[i];
		}
	}

    if (wordexp(cm, &patt, 0) != 0){
		printf("error in expanding wildcard");
	}
    words = patt.we_wordv;
	if (patt.we_wordc==0){
		char * t=malloc(sizeof(cm)+1);
		strcpy(t,cm);
		char *src, *dst;
    	for (src = dst = t; *src != '\0'; src++) {
        	*dst = *src;
        	if (*dst != getrid) dst++;
    	}
    	*dst = '\0';
		printf("%s \n",t);
		commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=t;
		commandStructTable.size[numPipes]++;
		return 1;
	}
    for (int i = 0; i < patt.we_wordc; i++){
		commandStructTable.command[numPipes][commandStructTable.size[numPipes]]=words[i];
		commandStructTable.size[numPipes]++;
	}
	return 1;
}