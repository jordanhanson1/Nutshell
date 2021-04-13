%{

#include "nutshparser.tab.h"
#include <string.h>
#include "global.h"

char* subAliases(char* name){
    for (int i = 0; i < aliasIndex; i++) {
        if(strcmp(aliasTable.name[i], name) == 0) {
            return aliasTable.word[i];
        }
    }
    return name;
}
bool ifAlias(char* name){
    for (int i = 0; i < aliasIndex; i++) {
        if(strcmp(aliasTable.name[i], name) == 0) {
            return true;
        }
    }
    return false;
}
%}
%array
%option noyywrap
%x string_condition

CHAR            [-|.A-Za-z0-9!\/_-~.:}{$><][-|.A-Za-z0-9!\/_-~.:}{$><]*
ANYCHAR         [|)(*&%$#@!`;,\.a-zA-Z0-9'/*_=~ -][}{)(|*&%$#@!`;,\.a-zA-Z0-9'/*_=~ -][{} ]*
ANYCHAR2         [|)(*&%$#@!`;,\.a-zA-Z0-9'/*_=~ -][}{)(|*&%$#@!`;,\.a-zA-Z0-9'/*_=~ -][}{]*
%%

<string_condition>{ANYCHAR}+     { yylval.string = strdup(yytext); return STRING;}
<string_condition>[\"]          {BEGIN(INITIAL);}

[ ]	                { }
bye                 { return BYE; }
cd		            { return CD;}
alias		        { return ALIAS; }
unalias             {return UNALIAS;}
setenv              { return SETENV;}
unsetenv           { return UNSETENV;}
printenv            {return PRINTENV;}
"\n"		        { return END; }
[\"]                 { BEGIN(string_condition); }
{CHAR}+              {
                        yylval.string = strdup(yytext);
                        return STRING;
                  }
