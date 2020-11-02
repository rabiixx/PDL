#ifndef UTIL_H
#define UTIL_H


/* Quadruples Operators */
typedef enum {
	
	/* Arithmetic Operators */
	QUAD_OP_INTSUM,			/* SUM OF INTEGERS */
	QUAD_OP_REALSUM,		/* SUM OF REALS */
	
	QUAD_OP_INTSUBS,		/* INTEGER SUBSTRACTION */
	QUAD_OP_REALSUBS,		/* REALS SUBSTRACTION */
	
	QUAD_OP_INTMULT,		/* INTEGER MULTIPLICATION  */
	QUAD_OP_REALMULT,		/* REAL MULTIPLICATION */
	
	QUAD_OP_REALDIV,		/* REAL DIVISION */

	QUAD_OP_INTMOD,			/* INTEGER MODULE */
	QUAD_OP_REALMOD,		/* REAL MODULE */

	QUAD_OP_GOTO,
	QUAD_OP_NOGOTO,

	QUAD_OP_INT2REAL,		/* Converts INTEGER to REAL */
	QUAD_OP_REAL2INT,		/* Converts REAL to INTEGER */
	QUAD_OP_BOOL2INT,
	QUAD_OP_BOOL2REAL,
	QUAD_OP_INT2BOOL,
	QUAD_OP_REAL2BOOL,

	QUAD_OP_INTUNIMUS,
	QUAD_OP_REALUNIMUS,

	QUAD_OP_ASSIGN,			/* ASSIGNATION */

	/* Relational Operators */
	QUAD_OP_EQ,				/* EQ:EQUAL */
	QUAD_OP_NE,				/* NE: NOT EQUAL */
	QUAD_OP_GT,				/* GE: GREATER THAN */
	QUAD_OP_GE,				/* GE: GREATER EQUAL */
	QUAD_OP_LT,				/* LT: LESS THAN */
	QUAD_OP_LE,				/* LE: LESS EQUAL */

	/* Boolean */
	QUAD_OP_TRUE,
	QUAD_OP_FALSE,
	
	/* No Operator */
	QUAD_OP_NOOP,
	QUAD_OP_VOID,
} Quad_op_code;


typedef enum {
	BOOLEAN_EXP,
	ARITHMETIC_EXP,
	UNDEFINED_EXP
} Expression_type;

typedef enum {
	DATA_TYPE_STRING,
	DATA_TYPE_INTEGER,
	DATA_TYPE_REAL,
	DATA_TYPE_CHAR,
	DATA_TYPE_BOOLEAN,
	UNKNOWN_DATA_TYPE
} Data_type;

/*typedef enum Quad_AddrType_type{
	QUAD_ADDR_TYPE_EMPTY = 0,

	QUAD_ADDR_TYPE_NAME = 1,
	QUAD_ADDR_TYPE_REG,
	QUAD_ADDR_TYPE_CONSTANT,

	QUAD_ADDR_TYPE_UNKOWN = -1,
} Quad_AddrType_type;*/

#define UNKNOWN_SYMBOL -1

#endif