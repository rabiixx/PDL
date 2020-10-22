#include "quadruples.h"

QuadTable *new_quad_tb() {

	QuadTable *qt = (QuadTable*) calloc(1, sizeof( QuadTable ));

	if ( qt == NULL )
	{
		perror("Impossible to assign memory to quad table");
		exit(-1);
	}

	qt->size = 0;

	return qt;

}


Quad *new_quad(const int op, const int op1, const unsigned int op2, const unsigned int res) {


	Quad q = (Quad*) calloc(1, sizeof( Quad ));

	q->op =




}


int main(int argc, char const *argv[])
{
	

	QuadTable *qt = new_quad_tb();

	return 0;
}



