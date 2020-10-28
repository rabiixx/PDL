#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

static unsigned int hash(const char *str) {

	int sum = 0;

	for (int i = 0; i < strlen(str); ++i)
		sum += (int) *(str + i); 
	
	return (unsigned int) sum % HT_SIZE;
}

void init_symbol_table( Symbol *table[] ) {

	for (int i = 0; i < HT_SIZE; ++i)
		table[ i ] = NULL;

}


Symbol *new_symbol( char *name ) {

	Symbol *s = (Symbol*) calloc(1, sizeof(Symbol));

	s->name = (char*) calloc( strlen( name ), sizeof( char ) );
	strcpy(s->name, name);
	
	s->next = NULL;

	return s;
}

void add_symbol(Symbol *table[], char *name) {


	const unsigned int index = hash( name );
	
	if ( table[ index ] == NULL )
	{
		table[ index ] = new_symbol( name );
		table[ index ]->id = NUMSYM++;

	} else {

		Symbol *tmp = table[ index ];

		while ( tmp->next != NULL ) { tmp = tmp->next; }

		tmp->next = new_symbol( name );
		tmp->next->id = NUMSYM++;
	}
	
}


/**
 * Deletes a given symbol from symbol table
 * @param tabel: symbol table
 * @param name: symbol name
 * @return -1: if symbol doesnt exist 
 * @return 0: if symbol has been removed successfully 
 */
int remove_symbol(Symbol *table[], const char *name) {
	
	Symbol **link = &table[ hash( name ) ];

    while (*link) 
    {
        Symbol *tmp = *link;
        if ( !strcmp(tmp->name, name) )
        {
            *link = tmp->next;
			free(tmp);
            --NUMSYM;
            return 0;
        }
        else
        {
            link = &(*link)->next;
        }
    }

    return -1;
}



/** 
  * Checks if a given symbol is on the symbol table.
  *	To avoid false postitves produced by collisions, it also looks 
  *	into corresponding linked list.
  * Linear Search - O(N)
  * Returns a pointer to the symbol, if the symbol exist.
  * Return NULL if the given symvbol doesnt exist. 
  */
Symbol *lookup(Symbol *table[], char *name) {

	const unsigned int index = hash( name );

	if ( table[ index ] )
	{

		if ( !strcmp( table[ index ]->name, name ) ) {

			return table[ index ];
		
		} else {

			Symbol *tmp = table[ index ]->next;
			
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


int set_attr(Symbol *table[], char *name, char *attr, char *value) {

	Symbol *s = lookup(table, name);

	if ( s )
	{

		if ( strcmp("type", attr) == 0 )
		{
			s->type = (char*) calloc( strlen( value ), sizeof( char ) );
			strcpy( s->type, value );
		}
		else if ( strcmp("scope", attr) == 0 )
		{
			s->scope = (char*) calloc( strlen( value ), sizeof( char ) );
			strcpy( s->type, value );
		}
		else
		{
			printf("Attribute %s doesnt exist.\n", attr);
			return -1;
		}

		return 0;
	}

	return -1;

}

char *get_attr(Symbol *table[], char *name, char *attr) {

	Symbol *s = lookup(table, name);

	if ( s ) {

		if ( strcmp(attr, "type") == 0 )
		{
			return s->type;
		}
		else if ( strcmp(attr, "scope") == 0 )
		{
			return s->scope;
		}
	}

	return NULL;

}

Data_type get_type(Symbol *table[], char *name) {

	Symbol *s = lookup( table, name );

	( s ) ? s->type : UNKNOWN_SYMBOL;
}

int set_type(Symbol *table[], char *name, Data_type type) {

	if ( type < DATA_TYPE_STRING || type > DATA_TYPE_BOOLEAN )
	{
		return UNKNOWN_DATA_TYPE;
	}

	Symbol *s = lookup( table, name );

	if ( s ) { s->type = type; }

	return UNKNOWN_SYMBOL;
}

void print_symbol_table(Symbol *table[])
{

	for (int i = 0; i < HT_SIZE; ++i)
	{

		printf("%p: symbol_table[%d]: %p\n", &table[i], i, table[i]);
		if ( table[i] )
		{
			Symbol *tmp = table[i];
			while ( tmp != NULL ) {
				printf("\t%p: %s\n", tmp, tmp->name);
				tmp = tmp->next;
			}
		}
	}

}

int main(int argc, char const *argv[])
{

	Symbol *table[ 5 ];

	init_symbol_table( table );

	add_symbol(table, "rabiixx");	// 4
	add_symbol(table, "rabiixx2");	// 4
	add_symbol(table, "rabiixx13");	// 4
	add_symbol(table, "root");		// 2
	add_symbol(table, "rabiixx16");	// 2
	add_symbol(table, "rabiixx11");	// 2
	add_symbol(table, "rabiixx14");	// 0


	print_symbol_table(table);
	
	if ( lookup(table, "rabiixx") )
	{
		printf("symbol exist \n");
	} else {
		printf("symbol not exist \n");
	}


	if ( lookup(table, "rabiixx2") )
	{
		printf("symbol exist \n");
	} else {
		printf("symbol not exist \n");
	}

	if ( lookup(table, "rabiixx19") )
	{
		printf("symbol exist \n");
	} else {
		printf("symbol not exist \n");
	}


	printf("\n\n");

	remove_symbol(table, "rabiixx");
	
	printf("\n\n");
	print_symbol_table(table);


	return 0;
}