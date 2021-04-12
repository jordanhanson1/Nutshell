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
   char* command[128][100];
   int size[128];
   bool output[128];
   bool input[128];
   bool background[128];
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
