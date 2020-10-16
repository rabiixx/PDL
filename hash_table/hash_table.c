#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(llNode **);

unsigned int hash(char *);

int main(int argc, char const *argv[])
{


	char *str = "hola23";
	printf("Hash: %d\n", hash(str) );

	llNode *hash_table[HT_SIZE];

	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;

	insert(&hash_table[0]);
	insert(&hash_table[0]);
	insert(&hash_table[1]);
	insert(&hash_table[2]);
	insert(&hash_table[2]);



	printf("***hash table state*** \n");
	for (int i = 0; i < ( sizeof( hash_table ) / sizeof( hash_table[0] ) ); ++i)
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

	return 0;
}


unsigned int hash(char *str) {

	int sum = 0;
	for (int i = 0; i < strlen(str); ++i) {
		sum += (int) *(str + i); 
	}
	
	return (unsigned int) sum % HT_SIZE;


}

void insert(llNode **table) {

	if ( *table == NULL )
	{

		printf("[+]first elem\n");

		llNode *node = (llNode*) calloc( 1, sizeof( llNode ) );
		node->count = 1;		
		*table = node;

		Symbol *s = (Symbol*)calloc(1, sizeof(Symbol));
	
		s->id = "1";
		s->name = "rabiixx";
		s->type = VAR;
		s->scope = "root";
		s->next = NULL;

		(*table)->head = s;
		(*table)->tail = s;

	} else {

		printf("[+]second elem\n");

		Symbol *s = (Symbol*)malloc(sizeof(Symbol));
	
		s->id = "2";
		s->name = "rabiixx";
		s->type = VAR;
		s->scope = "superroot";
		s->next = NULL;

		++(*table)->count;
		(*table)->head->next = s;
		(*table)->tail = s;

	}

}


Symbol *lookup(llNode *hast_table, char *name) {

}


int set_attribute(){

}

int getA