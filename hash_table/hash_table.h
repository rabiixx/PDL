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

typedef struct Variable {
	char *type;
	char *scope;
} Variable;

typedef struct Function {
	char *name;
	char *devType;
} Function;

typedef struct Action {
	char *name;
	char *devType;
} Action;

typedef struct Constant {
	char *name;
	char *devType;
} Constant;

typedef struct Label {
	char *name;
	char *devType;
} Label;

typedef struct Symbol {
	char *id;
	char *name;
	int type;
	char *scope;
	union {
		struct Variable var;
		struct Function func;
		struct Action act;
		struct Constant cte;
		struct Label lab;
		int hola;
	} value;
	struct Symbol *next;
} Symbol;
