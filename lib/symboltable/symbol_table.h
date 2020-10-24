#include <stdio.h>
#include <stdlib.h>

/*====================================
=            Symbol Table            =
====================================*/

/* MACROS */
#define HT_SIZE 5

/* Data Types */
#define STR 9
#define INT 6
#define FLOAT 7
#define CHAR 8

/* Indexes */
#define VAR 0
#define FUNCT 1
#define ACT 2
#define CTE 3

/* Data Structures */

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
	char *type;
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

type



/*----------  Function Declaration  ----------*/

Symbol *new_hash_table( const unsigned int SIZE );

Symbol *new_symbol(char *name);

void insertSymbol(Symbol table[2][], char *name);

int deleteSymbol(Symbol *table[2][], const char *name);

Symbol *lookup(Symbol *table[], char *name);

int set_attr(Symbol *table[], char *name, char *attr, char *value);

char *get_attr(Symbol *table[], char *name, char *attr);


/*----------  Utils  ----------*/

static unsigned int hash(const char *);

void printHt(Symbol *table[]);

static int get_num_symbol( Symbol *table[] );



/*=====  Symbol Table  ======*/