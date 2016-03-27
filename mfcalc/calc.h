#if !defined (__CALC_H__) 
#define __CALC_H__
/* ��� �������.                                      */
typedef double (*func_t) (double);

/* ��� ������ ��� ������ � ������� ��������.         */
struct symrec
{
  char *name;  /* ��� �������                        */
  int type;    /* ��� �������: ���� VAR, ���� FNCT   */
  union
  {
    double var;                  /* �������� VAR     */
    func_t fnctptr;              /* �������� FNCT    */
  } value;
  struct symrec *next;    /* ���� �����              */
};

typedef struct symrec symrec_t;

/* ������� ��������: ������� `struct symrec'.        */
extern symrec_t *sym_table;

symrec_t *putsym (const char *, func_t);
symrec_t *getsym (const char *);

#endif /*defined (__CALC_H__) */