#if !defined (__CALC_H__) 
#define __CALC_H__
/* Тип функций.                                      */
typedef double (*func_t) (double);

/* Тип данных для связей в цепочке символов.         */
struct symrec
{
  char *name;  /* имя символа                        */
  int type;    /* тип символа: либо VAR, либо FNCT   */
  union
  {
    double var;                  /* значение VAR     */
    func_t fnctptr;              /* значение FNCT    */
  } value;
  struct symrec *next;    /* поле связи              */
};

typedef struct symrec symrec_t;

/* Таблица символов: цепочка `struct symrec'.        */
extern symrec_t *sym_table;

symrec_t *putsym (const char *, func_t);
symrec_t *getsym (const char *);

#endif /*defined (__CALC_H__) */