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

	if ( qt == NULL )
	{
		perror("Impossible to assign memory to quad");
		exit(-1);
	}

	/* Check if given op is valid (check enum range) */
	q->op = op;
	q->op1 = op1;
	q->op2 = op2;
	q->res = res;
	q->next = NULL;

	return q;

}


/**
  * Inserts a given quadruple into quadruples table.
  *
  *
  */
void gen(QuadTable *qt, Quad *quad) {

	if ( qt )
	{
		qt->head = qt->tail = quad;
		
	} else {
		qt->tail->next = quad;
		qt->tail = quad;
	}

	++(qt->size);

}

Node *new_node( Quad *quad ) {

	Node *node = (Node*) calloc(1, sizeof( Node ));
	
	node->q = quad;
	node->next = NULL;

	return node;
}

LinkedList *new_linked_list() {

	LinkedList *linkedList = (LinkedList*) calloc(1, sizeof( LinkedList ));
	
	linkedList->head = linkedList->tail = NULL;
	linkedList->size = 0;

	return linkedList;

}

LinkedList *makelist( Quad *quad ) {

	LinkedList *ll = new_linked_list();
	Node *node = new_node( quad );

	ll->head = ll->tail = node;

	return ll;

}

int main(int argc, char const *argv[])
{
	

	QuadTable *qt = new_quad_tb();

	return 0;
}



LinkedList *merge( LinkedList *l1, LinkedList *l2 ) {

	if ( !l1 && !l2)
	{
		return NULL;
	} 
	else if ( !l1 )
	{
		return l2;
	} 
	else if ( !l2 )
	{
		return l1;
	} 
	else 
	{
		
		LinkedList *l3 = new_linked_list();
		Node *tmp = (Node*) calloc(1, sizeof( Node ));
		
		tmp = l1->head;



		while ( tmp ) {

		

		}


	}






}