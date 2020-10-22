#include <stdio.h>
#include <stdlib.h>


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
	char *id;
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


unsigned int hash(const char *);

Symbol *new_symbol(char *);

void insertSymbol(Symbol *table[], char *name);

int deleteSymbol(Symbol *hash_table[], const char *name);

Symbol *lookup(Symbol *hast_table[], char *name);

int set_attr(Symbol *hash_table[], char *name, char *attr);

char *get_attr(Symbol *hash_table[], char *name);

void printHt(Symbol *hash_table[]);

void delete(Symbol *table[], const char *key);