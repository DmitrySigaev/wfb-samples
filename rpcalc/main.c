#include "rpcalc.tab.h"
#include <stdio.h>
#include <ctype.h>

int
yylex (void)
{
  int c;

  /* пропустить промежутки  */
  while ((c = getchar ()) == ' ' || c == '\t')
    ;
  /* обработка чисел       */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
      return NUM;
    }
  /* вернуть конец файла  */
  if (c == EOF)
    return 0;
  /* вернуть одну литеру */
  return c;
}

int main(int argc, char **argv) {
	yyparse();
}

int yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	return 0;
}