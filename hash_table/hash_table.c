#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int hash(const char *);

Symbol *new_symbol(char *);

void insert(Symbol *table[], char *name);

int delete(Symbol *hash_table[], char *name);

int delete2(Symbol *hash_table[], char *name);

Symbol *lookup(Symbol *hast_table[], char *name);

int set_attr(Symbol *hash_table[], char *name, char *attr);

char *get_attr(Symbol *hash_table[], char *name);

void print_ht(Symbol *hash_table[]);

void deleteItem(Symbol *table[], const char *key);

int main(int argc, char const *argv[])
{

	Symbol *hash_table[HT_SIZE];

	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;

	//insert(hash_table, "rabiixx");
	insert(hash_table, "root");
	//insert(hash_table, "rabiixx2");

	lookup(hash_table, "rabiixx");
	lookup(hash_table, "rabiixx2");
	lookup(hash_table, "rabiixx7");

	set_attr(hash_table, "rabiixx", "julio");

	for (int i = 0; i < 5; ++i)
	{

		printf("%p: hash_table[%d]: %p\n", &hash_table[i], i, hash_table[i]);

		if ( hash_table[i] )
		{
			Symbol *tmp = hash_table[i];
			while ( tmp != NULL ) {
				printf("\t%p: %s\n", tmp, tmp->name);
				tmp = tmp->next;
			}
		}
	}

	printf("\n\n");

delete2(hash_table, "root");
	deleteItem(hash_table, "root");
	

	printf("\n\n");

	for (int i = 0; i < 5; ++i)
	{

		printf("%p: hash_table[%d]: %p\n", &hash_table[i], i, hash_table[i]);

		if ( hash_table[i] )
		{
			Symbol *tmp = hash_table[i];
			while ( tmp != NULL ) {
				printf("\t%p: %s\n", tmp, tmp->name);
				tmp = tmp->next;
			}
		}
	}


	//print_ht(hash_table);


	return 0;
}

unsigned int hash(const char *str) {

	int sum = 0;

	for (int i = 0; i < strlen(str); ++i)
		sum += (int) *(str + i); 
	
	return (unsigned int) sum % HT_SIZE;
}

// generate hash code
/*unsigned int hashCode(const char *key) {
    unsigned int sum = 0;

    for (int i = 0; key[i]; i++) {
        sum += (unsigned char)key[i] * (i + 1);
    }
    return sum % MAX_HASH;
}*/

Symbol *new_symbol( char *name ) {

	Symbol *s = (Symbol*) calloc(1, sizeof(Symbol));

	s->name = (char*) calloc( strlen( name ), sizeof( char ) );
	strcpy(s->name, name);
	s->next = NULL;

	printf("\nnose: %s\n", *s);

	return s;
}

void insert(Symbol *hash_table[], char *name) {

	const unsigned int index = hash( name );
	//printf("[+] hash(%s) = %d\n", name, index);

	if ( hash_table[ index ] == NULL )
	{
		hash_table[ index ] = new_symbol( name );
		printf("\nhack: %s\n\n", *(hash_table[index]));

	} else {

		Symbol *tmp = hash_table[ index ];

		while ( tmp->next != NULL ) { tmp = tmp->next; }

		tmp->next = new_symbol( name );
	}

}



/** 
  * Checks if a given symbol is on the symbol table.
  *	To avoid false postitves produced by collisions, it also looks 
  *	into index linked list.
  * Linear Search - O(N)
  */
Symbol *lookup(Symbol *hash_table[], char *name) {

	const unsigned int index = hash( name );

	if ( hash_table[index] )
	{

		if ( !strcmp( hash_table[ index ]->name, name ) ) {
			
			//printf("Symbol exist1\n");
			return hash_table[ index ];
		
		} else {

			Symbol *tmp = hash_table[ index ]->next;
			while ( tmp != NULL ) {
				
				if ( !strcmp( tmp->name, name ) ) {
					//printf("Symbol exist2\n");
					return tmp;
				}

				tmp = tmp->next;
			}

			//printf("Symbol doesnt exist1\n");
			return NULL;
		}

	}

	//printf("Symbol doesnt exist2\n");
	return NULL;

}


int set_attr(Symbol *hash_table[], char *name, char *attr) {


	Symbol *s = lookup(hash_table, name);

	if ( s != NULL )
	{
		s->type = (char*) calloc( strlen( attr ), sizeof( char ) );
		strcpy( s->type, attr );

		return 0;
	}

	return -1;

}

char *get_attr(Symbol *hash_table[], char *name) {

	Symbol *s = lookup(hash_table, name);

	return ( s ) ? s->type : NULL; 

}


// function for deleting item from hash table
void deleteItem(Symbol *table[], const char *key) {
    
	printf("\n deleteItem() \n");
	printf("table: %p\n", table);
	
	Symbol **link = &table[hash(key)];

	printf("link: %p\n", link);
	printf("*link: %p\n", *link);
	printf("**link: %p\n", **link);
	printf("&link: %p\n", &link);

    while (*link) {
        Symbol *tmp = *link;
        if (strcmp(tmp->name, key) == 0) {
            *link = tmp->next;  // unlink the list node
            printf("tmp delete: %p", tmp);
			free(tmp);
            break;
        } else {
            link = &(*link)->next;
        }
    }
}

int delete2(Symbol *hash_table[], char *name ) {

	printf("func delete\n");

	const unsigned int index = hash( name );

	Symbol *tmp = hash_table[ index ];
	Symbol *prev = hash_table[ index ];
	
	printf("hash_table[%d]: %p\n", index, hash_table[index]);
	printf("tmp: %p\n", tmp);

	printf("tmp2: %p\n", *tmp);

	if ( !tmp )
		return -1;

	if ( tmp && ( strcmp( (tmp)->name, name ) == 0 ) )
	{
		tmp = (tmp)->next;
		free( tmp );
		return 0;
	}
}




int delete(Symbol *hash_table[], char *name ) {

	printf("func delete\n");

	const unsigned int index = hash( name );

	Symbol **tmp = &hash_table[ index ];
	Symbol **prev = &hash_table[ index ];
	
	printf("hash_table[%d]: %p\n", index, hash_table[index]);
	printf("tmp: %p\n", tmp);

	if ( !tmp )
		return -1;

	if ( *tmp && ( strcmp( (*tmp)->name, name ) == 0 ) )
	{
		*tmp = (*tmp)->next;
		free( *tmp );
		return 0;
	}

	*tmp = (*tmp)->next;
	while ( tmp != NULL && !strcmp( (*tmp)->name, name ) )
	{
		(*prev) = *tmp;
		(*tmp) = (*tmp)->next;
	}

	if ( (*tmp) == NULL ) return -1;

	(*prev)->next = (*tmp)->next;

	free( *tmp );

	printf("delete 2\n");

	return 0;

}


void print_ht(Symbol *hash_table[])
{

	printf("\n***HASH TABLE STATE*** \n");
	for (int i = 0; i < 5; ++i)
	{

		//printf("hash_table[%d]: %p\n", i, hash_table[i]);

		if ( hash_table[i] )
		{
			printf("hash_table[%d] ==>\n", i);
			Symbol *tmp = hash_table[i];
			while ( tmp != NULL ) {
				printf("id: %s\n", tmp->id);
				printf("name: %s\n", tmp->name);
				printf("type: %s\n", tmp->type);
				printf("scope: %s\n\n", tmp->scope);
				tmp = tmp->next;
			}
		}
	}

}
