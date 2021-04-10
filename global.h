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

char cwd[PATH_MAX];

struct evTable varTable;

struct aTable aliasTable;

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
