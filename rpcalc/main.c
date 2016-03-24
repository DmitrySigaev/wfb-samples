#include "rpcalc.tab.h"
#include <stdio.h>
#include <ctype.h>

int
yylex (void)
{
  int c;

  /* ���������� ����������  */
  while ((c = getchar ()) == ' ' || c == '\t')
    ;
  /* ��������� �����       */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
      return NUM;
    }
  /* ������� ����� �����  */
  if (c == EOF)
    return 0;
  /* ������� ���� ������ */
  return c;
}

int main(int argc, char **argv) {
	yyparse();
}

int yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	return 0;
}