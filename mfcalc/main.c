#include "mfcalc.tab.h"
#include "calc.h"
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void init_table(void);

int main(void)
{
	init_table();
	return yyparse();
}

void yyerror(const char *s)  /* Вызывается yyparse в случае ошибки */
{
	printf("%s\n", s);
}

struct init
{
	char *fname;
	double(*fnct)(double);
};

struct init arith_fncts[] =
{
	"sin",  sin,
	"cos",  cos,
	"atan", atan,
	"ln",   log,
	"exp",  exp,
	"sqrt", sqrt,
	0, 0
};

/* Таблица символов: цепочка `struct symrec'.  */
symrec_t *sym_table = (symrec_t *)0;

/* Поместить арифметические функции в таблицу. */
void init_table(void)
{
	int i;
	symrec_t *ptr;
	for (i = 0; arith_fncts[i].fname != 0; i++)
	{
		ptr = putsym(arith_fncts[i].fname, FNCT);
		ptr->value.fnctptr = arith_fncts[i].fnct;
	}
}

symrec_t * putsym(char *sym_name, int sym_type)
{
	symrec_t *ptr;
	ptr = (symrec_t *)malloc(sizeof(symrec_t));
	ptr->name = (char *)malloc(strlen(sym_name) + 1);
	strcpy(ptr->name, sym_name);
	ptr->type = sym_type;
	ptr->value.var = 0; /* set value to 0 even if fctn.  */
	ptr->next = (struct symrec *)sym_table;
	sym_table = ptr;
	return ptr;
}

symrec_t * getsym(const char *sym_name)
{
	symrec_t *ptr;
	for (ptr = sym_table; ptr != (symrec_t *)0;
	ptr = (symrec_t *)ptr->next)
		if (strcmp(ptr->name, sym_name) == 0)
			return ptr;
	return 0;
}

/*Lexical analyzer returns a double floating point
number on the stack and the token NUM, or the ASCII
character read if not a number.Skips all blanks
and tabs, returns 0 for EOF. */
int yylex(void)
{
	int c;

	/* Игнорировать промежутки, получить первый непробельный символ.  */
	while ((c = getchar()) == ' ' || c == '\t');

	if (c == EOF)
		return 0;

	/* С литеры начинается число => разобрать число.                  */
	if (c == '.' || isdigit(c))
	{
		ungetc(c, stdin);
		scanf("%lf", &yylval.val);
		return NUM;
	}

	/* С литеры начинается идентификатор => читать имя.              */
	if (isalpha(c))
	{
		symrec_t *s;
		static char *symbuf = 0;
		static int length = 0;
		int i;

		/* Первоначально сделать буфер достаточно большим
		для имени символа из 40 литер.  */
		if (length == 0)
			length = 40, symbuf = (char *)malloc(length + 1);

		i = 0;
		do
		{
			/* Если буфер полон, расширить его.          */
			if (i == length)
			{
				length *= 2;
				symbuf = (char *)realloc(symbuf, length + 1);
			}
			/* Добавить эту литеру в буфер.              */
			symbuf[i++] = c;
			/* Получить следующую литеру.                */
			c = getchar();
		} while (c != EOF && isalnum(c));

		ungetc(c, stdin);
		symbuf[i] = '\0';

		s = getsym(symbuf);
		if (s == 0)
			s = putsym(symbuf, VAR);
		yylval.tptr = s;
		return s->type;
	}

	/* Любая другая литера сама по себе является лексемой.        */
	return c;
}

