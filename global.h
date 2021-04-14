#include <stdbool.h>
#include <limits.h>

struct evTable
{
   char var[128][100];
   char word[128][100];
};

struct aTable
{
   char name[128][100];
   char word[128][100];
};

struct cTable
{
   char *command[128][100];
   int size[128];
   bool output[128];
   bool errorOut[128];
   bool fileEr[128];
   char *fileError[128];
   char *fileIn[128];
   char *fileOut[128];
   bool input[128];
   bool path[128];
   bool append[128];
   bool printenv[128];
   bool printalias[128];
};

char cwd[PATH_MAX];

struct evTable varTable;

struct aTable aliasTable;

struct cTable commandStructTable;

char *commandTable[128];
int commandIndex;

int aliasIndex, varIndex;

char *subAliases(char *name);

char *commandlong;
int numPipes;
int numPaths;
char *pathsVar[100];

int numCommands;
int comI[100];
bool addFileIn;
bool addFileOut;
bool background;
