#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	
	Symbol *hash_table[HT_SIZE];



	for (int i = 0; i < sizeof(hash_table)/sizeof(hash_table[0]); ++i)
	{
		
		//Symbol *s = (Symbol*)malloc(sizeof(Symbol));

		Symbol s;

		s.id = (char*)malloc(sizeof(char) * 10);
		s.name = (char*)malloc(sizeof(char) * 20);
		s.id = (char*)malloc(sizeof(char) * 10);
		

		s.id = "1";
		s.name = "rabiixx";
		s.type = VAR;
		s.scope = "rabixx_legend";
		s.next = NULL;
	
		hash_table[i] = &s;

	}


	for (int i = 0; i < sizeof(hash_table)/sizeof(hash_table[0]); ++i)
	{
		printf("Iteracion: %d\n", i);
		printf("ID: %s\n", hash_table[i]->id);
		printf("NAME: %s\n", hash_table[i]->name);
		printf("TYPE: %d\n", hash_table[i]->type);
		printf("SCOPE: %s\n\n", hash_table[i]->scope);
	}

	printf("Hash table size %d\n", sizeof(hash_table)/sizeof(hash_table[0]));
	printf("SIZEOF table elem: %d\n", sizeof(hash_table[0]));
	printf("Sizeof symbol: %d\n", sizeof(Symbol));


	char *id;
	char id2;
	struct Symbol *next;
	printf("jhsbdjhs2: %d\n", sizeof(*hash_table[0]) );
	printf("jhsbdjhs2: %d\n", sizeof(hash_table[0]->id));
	printf("jhsbdjhs2: %d\n", sizeof(hash_table[0]->name));
	printf("jhsbdjhs2: %d\n", sizeof(hash_table[0]->type));
	printf("jhsbdjhs2: %d\n", sizeof(hash_table[0]->scope));
	printf("jhsbdjhs2: %d\n", sizeof(hash_table[0]->value));
	printf("jhsbdjhs2: %d\n", sizeof(hash_table[0]->next));


	return 0;
}