#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


llNode *new_linkedList();

Symbol *new_symbol(char *);

void insert(llNode *table[], char *name);

void test(llNode **);

unsigned int hash(char *);

Symbol *lookup(llNode *hast_table[], char *name);

int main(int argc, char const *argv[])
{

	llNode *hash_table[HT_SIZE];

	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;

	insert(hash_table, "rabiixx");
	insert(hash_table, "root");

	lookup(hash_table, "rabiixx");
	lookup(hash_table, "rabiixx2");

	/*for (int i = 0; i < 5; ++i)
	{
		if ( hash_table[i] )
		{
			printf("head: %p\n", hash_table[i]->head);
			printf("tail: %p\n", hash_table[i]->tail);
			printf("head: %d\n", hash_table[i]->count);
		} else {
			printf("hash_table[%d]: %p\n", i, hash_table[i]);
		}
		printf("\n");
	}*/


	printf("\n***HASH TABLE STATE*** \n");
	for (int i = 0; i < ( sizeof( hash_table ) / sizeof( hash_table[0] ) ); ++i)
	{
	
		if ( hash_table[i] )
		{
			printf("HASH TABLE %d\n", i);
			Symbol *tmp = hash_table[i]->head;
			while ( tmp != NULL ) {
				printf("id: %s\n", tmp->id);
				printf("name: %s\n", tmp->name);
				printf("type: %d\n", tmp->type);
				printf("scope: %s\n\n", tmp->scope);
				tmp = tmp->next;
			}
		}
	}

	return 0;
}


unsigned int hash(char *str) {

	int sum = 0;
	for (int i = 0; i < strlen(str); ++i) {
		sum += (int) *(str + i); 
	}
	
	return (unsigned int) sum % HT_SIZE;


}

void insert(llNode *table[], char *name) {

	const unsigned int index = hash(name);
	printf("hash: %d\n", index);

	if ( table[ index ] == NULL )
	{

		printf("[+]first elem\n");

		table[ index ] = new_linkedList();
		table[ index ]->head = table[ index ]->tail = new_symbol(name);
	
	} else {

		printf("[+]second elem\n");

		table[ index ]->tail = table[ index ]->tail->next = new_symbol(name);
		++( table[ index ]->count );
	}

}

llNode *new_linkedList() {

	llNode *node = (llNode*) calloc( 1, sizeof( llNode ) );
	node->head = node->tail = NULL;
	node->count = 1;

	return node;
}


Symbol *new_symbol( char *name ) {

	Symbol *s = (Symbol*)calloc(1, sizeof(Symbol));

	s->name = (char*) calloc( strlen( name ), sizeof( char ) );

	strcpy(s->name, name);
	s->next = NULL;	

	return s;
}


/* Checks if a given symbol is on the symbol table */
Symbol *lookup(llNode *hash_table[], char *name) {

	const unsigned int index = hash( name );

	if ( hash_table[index] )
	{
		printf("Symbol exist\n");
		return hash_table[index]->head;

		Symbol *tmp = hash_table[ index ]->head;
		while ( tmp != NULL ) {
			printf("id: %s\n", tmp->id);
			printf("name: %s\n", tmp->name);
			printf("type: %d\n", tmp->type);
			printf("scope: %s\n\n", tmp->scope);
			tmp = tmp->next;
		}

	} else {
		printf("Symbol doesnt exist\n");
		return NULL;
	}
}


int set_attribute(){

}
