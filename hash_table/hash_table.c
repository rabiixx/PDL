#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int hash(const char *);

/**
 * Creates a new Symbol
 */
Symbol *new_symbol(char *);


/**
 * Inserts a given Symbol in the hash table.
 * If symbol exists it wont be inserted.
 * If a collision occurs the new symbol is appended.
 */
void insertSymbol(Symbol *table[], char *name);


/**
 * 
 * 
 * 
 */
int deleteSymbol(Symbol *hash_table[], const char *name);

int delete(Symbol *hash_table[], char *name);

Symbol *lookup(Symbol *hast_table[], char *name);

int set_attr(Symbol *hash_table[], char *name, char *attr);

char *get_attr(Symbol *hash_table[], char *name);

void printHt(Symbol *hash_table[]);

void deleteItem(Symbol *table[], const char *key);

int main(int argc, char const *argv[])
{

	Symbol *hash_table[HT_SIZE];

	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;

	insertSymbol(hash_table, "rabiixx");	// 4
	insertSymbol(hash_table, "rabiixx2");	// 4
	insertSymbol(hash_table, "rabiixx13");	// 4
	insertSymbol(hash_table, "root");		// 2
	insertSymbol(hash_table, "rabiixx11");	// 2

	lookup(hash_table, "rabiixx");
	lookup(hash_table, "rabiixx2");
	lookup(hash_table, "rabiixx7");

	printHt(hash_table);

	printf("\n\n");

	//deleteSymbol(hash_table, "rabiixx");
	//deleteSymbol(hash_table, "rabiixx13");
	deleteSymbol(hash_table, "rabiixx13");
	
	printf("\n\n");
//	set_attr(hash_table, "rabiixx", "julio");

	printHt(hash_table);


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

	return s;
}

void insertSymbol(Symbol *hash_table[], char *name) {

	const unsigned int index = hash( name );

	/* Symbol alredy exist */
	if ( lookup(hash_table, name) )
	{
		printf("[+] Symbol alredy exists!");
		return;
	}
	
	if ( hash_table[ index ] == NULL )
	{
		hash_table[ index ] = new_symbol( name );

	} else {

		Symbol *tmp = hash_table[ index ];

		while ( tmp->next != NULL ) { tmp = tmp->next; }

		tmp->next = new_symbol( name );
	}

}

// Deletes a given symbol from hash table
int deleteSymbol(Symbol *table[], const char *name) {
	
	Symbol **link = &table[hash(name)];

    while (*link) {
        Symbol *tmp = *link;
        if ( !strcmp(tmp->name, name) ) {
            *link = tmp->next;
			free(tmp);
            break;
        } else {
            link = &(*link)->next;
        }
    }
}



/** 
  * Checks if a given symbol is on the symbol table.
  *	To avoid false postitves produced by collisions, it also looks 
  *	into corresponding linked list.
  * Linear Search - O(N)
  * Returns a pointer to the symbol, if the symbol exist.
  * Return NULL if the given symvbol doesnt exist. 
  */
Symbol *lookup(Symbol *hash_table[], char *name) {

	const unsigned int index = hash( name );

	if ( hash_table[index] )
	{

		if ( !strcmp( hash_table[ index ]->name, name ) ) {

			return hash_table[ index ];
		
		} else {

			Symbol *tmp = hash_table[ index ]->next;
			
			while ( tmp != NULL ) {	
				if ( !strcmp( tmp->name, name ) ) {
					return tmp;
				}
				tmp = tmp->next;
			}
			
			return NULL;
		}
	}

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

int set_attr(Symbol *hash_table[], char *name, char *attr, char *value) {

	Symbol *s = lookup(hash_table, name);

	if ( s != NULL )
	{

		if ( strcmp("type", attr) == 0 )
		{
			s->type = (char*) calloc( strlen( value ), sizeof( char ) );
			strcpy( s->type, value );
		} else if ( strcmp("scope", attr) == 0) {
			s->type = (char*) calloc( strlen( value ), sizeof( char ) );
			strcpy( s->type, value );
		} else {
			printf("Attribute %s doesnt exist.\n", attr);
			return -1;
		}

		return 0;
	}

	return -1;

}

void printHt(Symbol *hash_table[])
{

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

}

char *get_attr(Symbol *hash_table[], char *name) {

	Symbol *s = lookup(hash_table, name);

	return ( s ) ? s->type : NULL; 

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