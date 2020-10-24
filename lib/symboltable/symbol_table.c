#include "symbol_table.h"

Symbol *new_hash_table( const unsigned int SIZE ) {

	Symbol *table[ 2 ][ SIZE ];
	
	for (int i = 0; i < SIZE; ++i) {
		table[0][i] = NULL;
		table[1][i] = 0;
	}

	return table;
}


Symbol *new_symbol( char *name ) {

	Symbol *s = (Symbol*) calloc(1, sizeof(Symbol));

	s->name = (char*) calloc( strlen( name ), sizeof( char ) );
	strcpy(s->name, name);
	
	s->next = NULL;

	return s;
}

void insertSymbol(Symbol table[2][], char *name) {


	static int numSymbols = 

	const unsigned int index = hash( name );
	
	if ( table[ 0 ][ index ] == NULL )
	{
		table[ 0 ][ index ] = new_symbol( name );

	} else {

		Symbol *tmp = hash_table[ 0 ][ index ];

		while ( tmp->next != NULL ) { tmp = tmp->next; }

		tmp->next = new_symbol( name );
	}
	
	++table[ 1 ][ index ];
	table[ 0 ][ index ]->id = table[ 1 ][ index ];

}


/**
 * Deletes a given symbol from symbol table
 * @param tabel: symbol table
 * @param name: symbol name
 * @return -1: if symbol doesnt exist 
 * @return 0: if symbol has been removed successfully 
 */
int deleteSymbol(Symbol *table[2][], const char *name) {
	
	Symbol **link = &table[ 0 ][ hash( name ) ];

    while (*link) 
    {
        Symbol *tmp = *link;
        if ( !strcmp(tmp->name, name) )
        {
            *link = tmp->next;
			free(tmp);
            ++table[ 1 ][ hash( name ) ];
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

static unsigned int hash(const char *str) {

	int sum = 0;

	for (int i = 0; i < strlen(str); ++i)
		sum += (int) *(str + i); 
	
	return (unsigned int) sum % HT_SIZE;
}

static int get_num_symbol( Symbol *table[] ) {

	int sum = 0;
	for (int i = 0; i < sizeof( table ) / sizeof( table[0]); ++i)
		sum += table[i];

	return sum;

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

/*int main(int argc, char const *argv[])
{

	

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
}*/