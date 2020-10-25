#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

unsigned int NUMSYM = 0;


/*----------  Function Declaration  ----------*/

void init_symbol_table( Symbol *table[] );

Symbol *new_symbol(char *name);

void add_symbol(Symbol *table[], char *name);

int remove_symbol(Symbol *table[], const char *name);

Symbol *lookup(Symbol *table[], char *name);

int set_attr(Symbol *table[], char *name, char *attr, char *value);

char *get_attr(Symbol *table[], char *name, char *attr);


/*----------  Utils  ----------*/

static unsigned int hash(const char *str);

void print_symbol_table(Symbol *table[]);

/*=====  Symbol Table  ======*/