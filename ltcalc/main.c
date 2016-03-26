#include "ltcalc.tab.h"
#include <stdio.h>
#include <ctype.h>


/* Lexical analyzer returns a double floating point
number on the stack and the token NUM, or the ASCII
character read if not a number.  Skips all blanks
and tabs, returns 0 for EOF. */
int yylex(void)
{
	int c;

	/* ���������� ���������� */
	while ((c = getchar()) == ' ' || c == '\t')
		++yylloc.last_column;

	/* ��� */
	yylloc.first_line = yylloc.last_line;
	yylloc.first_column = yylloc.last_column;

	/* ��������� ����� */
	if (isdigit(c))
	{
		yylval = c - '0';
		++yylloc.last_column;
		while (isdigit(c = getchar()))
		{
			++yylloc.last_column;
			yylval = yylval * 10 + c - '0';
		}
		ungetc(c, stdin);
		return NUM;
	}

	/* ������� ����� ����� */
	if (c == EOF)
		return 0;

	/* ������� ���� ������ � �������� ��������� */
	if (c == '\n')
	{
		++yylloc.last_line;
		yylloc.last_column = 0;
	}
	else
		++yylloc.last_column;
	return c;
}

int main(int argc, char **argv) {
	yyparse();
}

int yyerror(s)
char * s; /* Called by yyparse on error */
{
	yylloc.first_line = yylloc.last_line = 1;
	yylloc.first_column = yylloc.last_column = 0;
	fprintf(stderr, "error: %s\n", s);
	return 0;
}