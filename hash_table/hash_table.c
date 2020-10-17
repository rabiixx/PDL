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

int set_attribute(llNode *hash_table[], char *name, char *attr);




int main(int argc, char const *argv[])
{

	llNode *hash_table[HT_SIZE];

	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;

	insert(hash_table, "rabiixx");
	insert(hash_table, "root");
	insert(hash_table, "rabiixx2");
	//insert(hash_table, "rabiixx7");

	lookup(hash_table, "rabiixx");
	lookup(hash_table, "rabiixx2");
	lookup(hash_table, "rabiixx7");

	set_attribute(hash_table, "rabiixx", "julio");

	/*for (int i = 0; i < 5; ++i)
	{
		if ( hash_table[i] )
		{
			printf("head: %p\n", hash_table[i]->head);
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
				printf("type: %s\n", tmp->type);
				printf("scope: %s\n\n", tmp->scope);
				tmp = tmp->next;
			}
		}
	}

	return 0;
}


llNode *new_linkedList() {

	llNode *node = (llNode*) calloc( 1, sizeof( llNode ) );
	node->head = NULL;
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


unsigned int hash(char *str) {

	int sum = 0;

	for (int i = 0; i < strlen(str); ++i)
		sum += (int) *(str + i); 
	
	return (unsigned int) sum % HT_SIZE;

}

void insert(llNode *hash_table[], char *name) {

	const unsigned int index = hash( name );
	printf("[+] hash(%s) = %d\n", name, index);

	if ( hash_table[ index ] == NULL )
	{

		hash_table[ index ] = new_linkedList();
		hash_table[ index ]->head = new_symbol( name );
	
	} else {

		Symbol *tmp = hash_table[ index ]->head;

		while ( tmp->next != NULL ) { tmp = tmp->next; }

		tmp->next = new_symbol( name );
		++( hash_table[ index ]->count );

	}

}



/** 
  * Checks if a given symbol is on the symbol table.
  *	To avoid false postitves produced by collisions, it also looks 
  *	into index linked list.
  * Linear Search - O(N)
  */
Symbol *lookup(llNode *hash_table[], char *name) {

	const unsigned int index = hash( name );

	if ( hash_table[index] )
	{

		if ( strcmp( hash_table[ index ]->head->name, name ) == 0 ) {
			
			printf("Symbol exist1\n");
			return hash_table[ index ]->head;
		
		} else {

			Symbol *tmp = hash_table[ index ]->head->next;
			while ( tmp != NULL ) {
				
				if ( strcmp( tmp->name, name ) == 0 ) {
					printf("Symbol exist2\n");
					return tmp;
				}

				tmp = tmp->next;
			}

			printf("Symbol doesnt exist1\n");
			return NULL;
		}

	}

	printf("Symbol doesnt exist2\n");
	return NULL;

}


/**


*/ 

int set_attribute(llNode *hash_table[], char *name, char *attr) {


	Symbol *s = lookup(hash_table, name);

	if ( s != NULL )
	{
		s->type = (char*) calloc( strlen( attr ), sizeof( char ) );
		strcpy( s->type, attr );

		return 0;
	}


	return -1;

}




int delete(llNode *hash_table[], char *name ) {


	const unsigned int index = hash( name );

	Symbol *tmp, *prev = hash_table[ index ]->head;

	if ( tmp != NULL && !strcmp( tmp->name, name ) )
	{

		tmp 

	}

		llNode ll = hash_table[ index ];
	
		if ( ll->count == 1 )
		{
			
			free(s);
			ll->head = ll->tail = NULL;
			free( ll );

		} else {

		

		}

		return 0;
	}


	return -1;

}



