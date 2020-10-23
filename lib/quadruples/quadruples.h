#include <stdlib.h>
#include <stdio.h>
#include "../util.h"

//https://steemit.com/utopian-io/@drifter1/writing-a-simple-compiler-on-my-own-combine-flex-and-bison

typedef struct quadruple {
	operators op;			/* Operators enum */
	int op1;
	int op2;
	int res;
	struct quead *queadnext; 
} Quad;

typedef struct _QuadTable {
	struct quead *head;
	struct quead *tail;
	unsigned int size;
} QuadTable;


typedef struct _node {
	Quad *q;
	struct Node *next; 
} Node;


typedef struct _linkedList {
	Node *head;
	Node *tail;
	unsigned int size;
} LinkedList;



QuadTable *new_quad_tb();

Quad *new_quad(const int op, const int op1, const unsigned int op2, const unsigned int res);

Node *new_node( Quad *quad );

LinkedList *new_linked_list();

LinkedList *makelist( Quad *quad );