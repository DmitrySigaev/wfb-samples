/* Infix notation calculator--calc */
/*  алькул€тор дл€ выражени в инфиксной нотации -- calc */

%{
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

%union {
  int db;
  char ch;

}

%token <db>  NUM
%type <db>  exp
%token <ch>  '\n'
/* Grammar follows */
/* ƒалее следует грамматика */
%%
input:    /* empty string */ /* пуста€ строка */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t%d, %c\n", $1, $2); } /* $2 смысла не имеет, как мы видим это только union(либо то либо другое. '\n' не выдает)
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