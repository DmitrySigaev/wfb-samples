#include "lexer.1.h"
#include "parser.tab.h"

int main(int argc, char **argv) {
	yyparse();
}

int yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	return 0;
}