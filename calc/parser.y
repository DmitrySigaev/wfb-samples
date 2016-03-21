%{
#include <stdio.h>
#include "lexer.h"
%}

%token NUMBER
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token LEFT_PAREN
%token RIGHT_PAREN
%token NEWLINE
%token UNKNOWN

%%
commands: command
        | commands command

command: NEWLINE
       | expr NEWLINE { printf("= %d\n", $1); }

expr: term
    | expr PLUS term { $$ = $1 + $3; }
    | expr MINUS term { $$ = $1 - $3; }

term: factor
    | term TIMES factor { $$ = $1 * $3; }
    | term DIVIDE factor { $$ = $1 / $3; }

factor: NUMBER
      | LEFT_PAREN expr RIGHT_PAREN { $$ = $2; }
%%