#ifndef EXP_A_B
#define EXP_A_B

#include "../symboltable/symbol_table.h"
#include "../quadruples/quadruples.h"

typedef struct _exp_a_b {
	Expression_type type;
	Symbol *s;
	LinkedList *truelist;
	LinkedList *falselist;
} Exp_a_b;


typedef struct _inst {
	LinkedList *nextlist;
	int size;
} Inst;


Exp_a_b *new_exp_a_b( Expression_type type );

void set_exp_type( Exp_a_b *exp, Expression_type type );

Expression_type get_exp_type( Exp_a_b *exp );

#endif