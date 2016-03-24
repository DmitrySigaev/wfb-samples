/*  алькул€тор обратной польской нотации. */
/* Reverse polish notation calculator */

%{
#define YYSTYPE double
#include <math.h>
#include <stdio.h>
%}

%token NUM

%% /* ƒалее следуют правила грамматики и действи€ */
/* Grammar rules and actions follow */

input:    /* пусто */    /* empty */
        | input line     /* A complete input is either an empty string, or a complete input followed by an input line. */
;

line:     '\n'
        | exp '\n'  { printf ("\t%.10g\n", $1); }
;

exp:      NUM             { $$ = $1;         }
        | exp exp '+'     { $$ = $1 + $2;    }
        | exp exp '-'     { $$ = $1 - $2;    }
        | exp exp '*'     { $$ = $1 * $2;    }
        | exp exp '/'     { $$ = $1 / $2;    }
      /* возведение в степень */ /* Exponentiation */
        | exp exp '^'     { $$ = pow ($1, $2); }
      /* унарный минус        */ /* Unary minus    */
        | exp 'n'         { $$ = -$1;        }
;
%%
