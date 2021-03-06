#include "y.tab.c"
#include <stdio.h>
#include <ctype.h>


/* Lexical analyzer returns a double floating point
number on the stack and the token NUM, or the ASCII
character read if not a number.  Skips all blanks
and tabs, returns 0 for EOF. */
int yylex(void)
{
	int c;

	/* skip white space  */
	/* ���������� ����������  */
	while ((c = getchar()) == ' ' || c == '\t')
		;
	/* process numbers   */
	/* ��������� �����       */
	if (c == '.' || isdigit(c))
	{
		ungetc(c, stdin);
		scanf("%d", &yylval.val);
		return NUMBER;
	}
	/* return end-of-file  */
	/* ������� ����� �����  */
	if (c == EOF)
		return 0;
	/* return single chars */
	/* ������� ���� ������ */
	return c;
}

int main(int argc, char **argv) {
	yylval.line = 0;
	yyparse();
}

int yyerror(s)
char * s; /* Called by yyparse on error */
{
	fprintf(stderr, "error: %s\n", s);
	return 0;
}