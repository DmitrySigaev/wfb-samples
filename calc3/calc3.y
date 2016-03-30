%{
#include <stdio.h>
%}

/* yacc declarations */
%token '(' ')'
%left '+'
%left '*'
%union {
 int val;
 int line;
} 

%token <val>  NUMBER 
%type  <val> exp factor term
/* %type  <line> cal
%token <line> '\n' */
/* %start cal */


%%
commands:    /* empty string */ /* пустая строка - цикл для непрерывного ввода с  терминала */
        | commands cal
;

cal: exp  '\n'               { printf("The result is %d\n", $1); }
   | '\n'
 ; 

exp: exp '+' factor      { $$ = $1 + $3; /* %type  <val> exp factor */ /*yyac notation $$.val = $1.val + $3.val .val means type int*/}
   | factor              { $$ = $1; }
 ; 

factor: factor '*' term  { $$ = $1 * $3; }
      | term             { $$ = $1; }
 ; 

term: NUMBER             { $$ = $1; }
    | '(' exp ')'        { $$ = $2; }
 ; 
%%