#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

unsigned int NUM_SYM = 0;

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

/* Return system time. Gonna be used for tmp variables naming */
char *gen_tmp_name() {

	char *name = (char*) malloc( sizeof(char) * 20 );
	strcpy(name, "_tmp_");
	
	time_t rawtime;
	struct tm *timeinfo;
    char buffer[80];

	time( &rawtime );
	timeinfo = localtime( &rawtime );

	strftime(buffer, 80, "%X", timeinfo);

	char *p;
	while ( p = strchr(buffer, ':' ) ) {
		*p = '_';
	}

	strcat(name, buffer);

	return name;
}


Symbol *new_symbol( char *name ) {


	printf("new_symbol(%s)\n", name);

	Symbol *s = (Symbol*) calloc(1, sizeof(Symbol));

	s->name = (char*) calloc( strlen( name ), sizeof( char ) );

	
	if ( strcmp( name, "_tmp") == 0 )
		strcpy( s->name, gen_tmp_name() );
	else
		strcpy(s->name, name);

	s->next = NULL;

	return s;
}

int add_symbol(Symbol *table[], Symbol *symbol) {
	printf("0. NUM_SYS: %d\n", NUM_SYM);

	if (  lookup( table, symbol->name) ){ return -1; }
	else {
	
		const unsigned int index = hash( symbol->name );
		
		if ( table[ index ] == NULL )
		{
			table[ index ] = symbol;
			table[ index ]->id = NUM_SYM;
			printf("ADD SYMBOL: %d\n", NUM_SYM);
		}
		else
		{

			Symbol *tmp = table[ index ];

			while ( tmp->next != NULL ) { tmp = tmp->next; }

			tmp->next = symbol;
			tmp->next->id = NUM_SYM;
			printf("ADD SYMBOL: %d\n", NUM_SYM);
		}

		printf("1. NUM_SYS: %d\n", NUM_SYM);
		NUM_SYM++;
		printf("2. NUM_SYS: %d\n", NUM_SYM);
	}

	return 0;
	
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
            --NUM_SYM;
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

int set_symbol_type(Symbol *table[], char *name, Data_type type) {

	if ( type < DATA_TYPE_STRING || type > DATA_TYPE_BOOLEAN )
	{
		return UNKNOWN_DATA_TYPE;
	}

	Symbol *s = lookup( table, name );

	if ( s ) { s->type = type; }

	return UNKNOWN_SYMBOL;
}

Data_type get_symbol_type(Symbol *table[], char *name) {

	Symbol *s = lookup( table, name );

	( s ) ? s->type : UNKNOWN_SYMBOL;
}

void print_st_title( char *title ) {
	for (int i = 0; i < 49	; ++i){
		printf("=");
	}
	printf("\n");


	printf("%1c%18c\e[4;31m\e[1;31m%12s\e[0m%17c%1c\n", '|', ' ', title, ' ', '|');

	for (int i = 0; i < 49	; ++i){
		printf("=");
	}
	printf("\n");
}

void print_st_header( char *header[] ) {

	printf("\e[1;32m%12s\e[0m", header[0]);
	printf("\e[1;33m%12s\e[0m", header[1]);
	printf("\e[1;34m%12s\e[0m\n", header[2]);

	for (int i = 0; i < 49; ++i){
		printf("=");
	}

	printf("\n");
}

void print_st_row( Symbol *s ) {

	printf("%1c\e[42m%9d%2s\e[0m", '|', s->id, "");
	printf("%1c\e[43m%9s%2s\e[0m", '|', s->name, "");
	printf("%1c\e[44m%9d%2s\e[0m\n", '|', s->type, "");

}

void print_symbol_table( Symbol *table[] ) {

	char *title = "Symbol Table";
	char * header[3] = 	{
							"id",
							"name",
							"type"
						};


	print_st_title( title );
	print_st_header( header );

	for (int i = 0; i < HT_SIZE; ++i) {

		Symbol *aux = table[i];
		while ( aux ) {
			print_st_row( aux );
			aux = aux->next;
		}
	}
}