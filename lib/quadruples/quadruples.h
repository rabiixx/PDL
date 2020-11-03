#ifndef QUADRUPLES_H
#define QUADRUPLES_H

#include "../util.h"

//https://steemit.com/utopian-io/@drifter1/writing-a-simple-compiler-on-my-own-combine-flex-and-bison

typedef struct _quad {
	Quad_op_code op;			/* Operators enum */
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



QuadTable *new_quad_table();

Quad *new_quad(const int op, const int op1, const unsigned int op2, const unsigned int res);

void gen(QuadTable *qt, Quad *quad);

Node *new_node( Quad *quad );

LinkedList *new_linked_list();

void insert_node( LinkedList *list, Node *node );

LinkedList *makelist( Quad *quad );

LinkedList *merge( LinkedList *l1, LinkedList *l2 );

void backpatch(LinkedList *list, int q);

void free_quad_table(Quad **head);

void free_quad_table2(Quad *head);


void free_quads_qt(Quad *q);

void deleteList(Quad **q);

void deleteList2(QuadTable *q);

int next_quad();

void print_title( char *title );
void print_header( char *header[] );
void print_row( Quad *q );
void print_quadruples( QuadTable *qt );

#endif