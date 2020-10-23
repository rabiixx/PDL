#include <stdlib.h>
#include <stdio.h>
#include "../util.h"

//https://steemit.com/utopian-io/@drifter1/writing-a-simple-compiler-on-my-own-combine-flex-and-bison

typedef struct _quad {
	operators op;			/* Operators enum */
	int op1;
	int op2;
	int res;
	struct _quad *next; 
} Quad;

typedef struct _QuadTable {
	Quad *head;
	Quad *tail;
	unsigned int size;
} QuadTable;


typedef struct _node {
	Quad *q;
	struct _node *next; 
} Node;


typedef struct _linkedList {
	Node *head;
	Node *tail;
	unsigned int size;
} LinkedList;



QuadTable *new_quad_tb();

Quad *new_quad(const int op, const int op1, const unsigned int op2, const unsigned int res);

void gen(QuadTable *qt, Quad *quad);

Node *new_node( Quad *quad );

LinkedList *new_linked_list();

void insert_node( LinkedList *list, Node *node );

LinkedList *makelist( Quad *quad );

LinkedList *merge( LinkedList *l1, LinkedList *l2 );

