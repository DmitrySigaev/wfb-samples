%{
#include "parser.tab.h"
%}

%option noyywrap
%option nodefault

%%
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
"("         { return LEFT_PAREN; }
")"         { return RIGHT_PAREN; }
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
0x[a-f0-9]+ { yylval = strtol(yytext, NULL, 16); return NUMBER; }
\n          { return NEWLINE; }
[ \t]
.           { return UNKNOWN; };
%%
