/* Infix notation calculator--calc */
/* Калькулятор для выражени в инфиксной нотации -- calc */

%{
#define YYSTYPE double
#include <math.h>
#include <stdio.h>
%}

/* BISON Declarations */
/* Operator precedence is determined by the line ordering of the declarations;
 the higher the line number of the declaration (lower on the page or screen), 
 the higher the precedence. Hence, exponentiation has the highest precedence,
 unary minus (NEG) is next, followed by `*' and `/', and so on. */
%token NUM
%left '-' '+'
%left '*' '/'
%left NEG     /* negation--unary minus */ /* обращение -- унарный минус */
%right '^'    /* exponentiation        */ /* возведение в степень       */

/* Grammar follows */
/* Далее следует грамматика */
%%
input:    /* empty string */ /* пустая строка */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t%.10g\n", $1); }
        | error '\n' { yyerrok;                 } /* This addition to the grammar allows for simple error recovery in the event of a parse error. */
;

exp:      NUM                { $$ = $1;         }
        | exp '+' exp        { $$ = $1 + $3;    }
        | exp '-' exp        { $$ = $1 - $3;    }
        | exp '*' exp        { $$ = $1 * $3;    }
        | exp '/' exp        { $$ = $1 / $3;    }
        | '-' exp  %prec NEG { $$ = -$2;        }
        | exp '^' exp        { $$ = pow ($1, $3); }
        | '(' exp ')'        { $$ = $2;         }
;
%%