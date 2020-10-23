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


	Quad *quad = (Quad*) calloc(1, sizeof( Quad ));

	if ( quad == NULL )
	{
		perror("Impossible to assign memory to quad");
		exit(-1);
	}

	/* Check if given op is valid (check enum range) */
	quad->op = op;
	quad->op1 = op1;
	quad->op2 = op2;
	quad->res = res;
	quad->next = NULL;

	return quad;

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

void insert_node( LinkedList *list, Node *node ) {


	if ( !(list->head) )
	{
	 	list->head = list->tail = node; 
	}
	else
	{
		printf("sadas\n");

		list->tail->next = node;
		list->tail = node;
	}

	++(list->size);

}

LinkedList *makelist( Quad *quad ) {

	LinkedList *ll = new_linked_list();
	Node *node = new_node( quad );

	ll->head = ll->tail = node;

	return ll;

}


/**
  * Merges two given lists into new one (non-destructive)
  *
  */

LinkedList *merge( LinkedList *l1, LinkedList *l2 ) {
	
	if ( !l1 && !l2 )
	{
		return NULL;
	}
	else 
	{
		
		LinkedList *list = new_linked_list();
		Node *tmp;

		tmp = l1->head;

		while ( tmp ) {
			Node *node = new_node( tmp->q );
			insert_node(list, node);
		}

		tmp = l2->head;

		while ( tmp ) {
			Node *node = new_node( tmp->q );
			insert_node(list, node);
		}

		return list;
	}
}




int main(int argc, char const *argv[])
{
	
	QuadTable *qt = new_quad_tb();
	
	Quad *quad1 = new_quad(99, 1, 2 , 3);

	printf("quad1: \n");
	printf("\top: %d\n", quad1->op);
	printf("\top1: %d\n", quad1->op1);
	printf("\top2: %d\n", quad1->op2);
	printf("\tres: %d\n", quad1->res);


	Quad *quad2 = (Quad*) calloc(1, sizeof( Quad ) );
	*quad2 = *quad1;

	printf("MA quad1: %p\n", quad1);
	printf("MA quad2: %p\n", quad2);

	printf("quad2: \n");
	printf("\top: %d\n", quad2->op);
	printf("\top1: %d\n", quad2->op1);
	printf("\top2: %d\n", quad2->op2);
	printf("\tres: %d\n", quad2->res);

	quad2->op = 100;

	printf("quad1: \n");
	printf("\top: %d\n", quad1->op);
	printf("\top1: %d\n", quad1->op1);
	printf("\top2: %d\n", quad1->op2);
	printf("\tres: %d\n", quad1->res);

	printf("quad2: \n");
	printf("\top: %d\n", quad2->op);
	printf("\top1: %d\n", quad2->op1);
	printf("\top2: %d\n", quad2->op2);
	printf("\tres: %d\n", quad2->res);


	LinkedList *list = new_linked_list();
	
	Node *node1 = new_node(quad1);
	Node *node2 = new_node(quad2);

	insert_node(list, node1);
	insert_node(list, node2);
	

	Node *tmp = list->head; 

	int i = 0;
	while ( tmp ) {

		printf("list[%d]: \n", i);

		printf("\top: %d\n", tmp->q->op);
		printf("\top1: %d\n", tmp->q->op1);
		printf("\top2: %d\n", tmp->q->op2);
		printf("\tres: %d\n", tmp->q->res);

		tmp = tmp->next;
		++i;
	}


	return 0;
}



