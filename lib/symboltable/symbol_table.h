#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <time.h>
#include "../util.h"

/*====================================
=            Symbol Table            =
====================================*/

/* MACROS */
#define HT_SIZE 5


/*----------  Data Structures  ----------*/


/* Variables */
typedef struct Variable {
	char *type;			/* Variable type */
} Variable;

typedef struct Constant {
	char *type;
} Constant;

typedef struct Function {
	char *name;
	char *devType;
} Function;

typedef struct Action {
	char *name;
	char *devType;
} Action;


typedef struct Label {
	char *name;
	char *devType;
} Label;

typedef struct Symbol {
	int id;
	char *name;
	Data_type type;			/* Data types enum */
	char *scope;
	struct Symbol *next;
	union {
		struct Variable var;
		struct Function func;
		struct Action act;
		struct Constant cte;
		struct Label lab;
	} value;
} Symbol;

/*----------  Function Declaration  ----------*/

void init_symbol_table( Symbol *table[] );

Symbol *new_symbol(char *name);

int add_symbol(Symbol *table[], Symbol *Symbol);

int remove_symbol(Symbol *table[], const char *name);

Symbol *lookup(Symbol *table[], char *name);

Data_type get_symbol_type(Symbol *table[], char *name);

int set_symbol_type(Symbol *table[], char *name, Data_type type); 

/*----------  Utils  ----------*/

static unsigned int hash(const char *str);


/* Show Symbol Table */
void print_st_title( char *title );

void print_st_header( char *header[] );

void print_st_row( Symbol *s );

void print_symbol_table( Symbol *table[] );


/*=====  Symbol Table  ======*/


#endif