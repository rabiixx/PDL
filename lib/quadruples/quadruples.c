#include <stdlib.h>
#include <stdio.h>

#include "quadruples.h"

QuadTable *new_quad_table() {

	QuadTable *qt = (QuadTable*) calloc(1, sizeof( QuadTable ));

	if ( qt == NULL )
	{
		perror("Error: Impossible to assign memory to quad table");
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

	if ( !(qt->head) )
	{
		qt->head = qt->tail = quad;	
	}
	else
	{
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

void backpatch(LinkedList *list, int q) {

	Node *tmp = list->head;

	while ( tmp ) {
		tmp->q->res = q;
		tmp = tmp->next;
	}

}


void free_quad_table(Quad **head) {

	if ( *head )
	{
		free_quad_table( & ((*head)->next) );
		free( *head );
	}

	//*head = NULL;
}

/* Function to delete the entire linked list */
void deleteList(Quad** q) 
{ 

	Quad* current = *q; 
	Quad* next; 

	while (current != NULL) 
	{ 
		next = current->next; 
		free(current); 
		current = next; 
	} 
	
	*q = NULL; 
}

/* Function to delete the entire linked list */
void deleteList2(QuadTable *qt) 
{ 

	Quad* current = qt->head; 
	Quad* next; 

	while (current != NULL) 
	{ 
		next = current->next; 
		free(current); 
		current = next; 
	} 
	
	qt->head = NULL;
}

int next_quad() {

	return 0;
}