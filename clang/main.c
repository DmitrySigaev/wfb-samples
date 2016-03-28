#include "lexer.flex.h"
#include "parser.tab.h"
extern int lnumber;


int main(int argc, char **argv) {
	yyparse();
}

int yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	return 0;
}

void countline()
{
	int i;
	for (i = 0; i<yyleng; i++)
	{
		if (*(yytext + i) == '\n') lnumber++;
	}
}
