#include <stdlib.h>
#include <stdio.h>

#include "exp_a_b.h"


Exp_a_b *new_exp_a_b( Expression_type type ) {

	if ( type < BOOLEAN || type > UNDEFINED )
	{
		printf("Expression %d is not a valud expression type");
	}


	Exp_a_b *exp = (Exp_a_b*) calloc(1, sizeof( Exp_a_b ));
	
	if ( !exp )
	{
		perror("Impossible to allocate memory for Exp_a_b");
		exit(-1);
	}

	exp->type = type;
	exp->s = NULL;
	exp->truelist = exp->falselist = NULL;

	return exp;

}

void set_type( Exp_a_b *exp, Expression_type type ) { exp->type = type; }

Expression_type get_type( Exp_a_b* exp) { return exp->type; }

int main(int argc, char const *argv[])
{
	
	Exp_a_b *exp = new_exp_a_b( UNDEFINED );
	printf("type: %d\n", get_type( exp ));

	set_type(exp, BOOLEAN);
	printf("type: %d\n", get_type( exp ));

	set_type(exp, ARITHMETIC);
	printf("type: %d\n", get_type( exp ));


	return 0;
}