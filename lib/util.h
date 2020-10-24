/* Quadruples Operators */
typedef enum {
	
	/* Arithmetic Operators */
	QUAD_OP_INTSUM,			/* SUM OF INTEGERS */
	QUAD_OP_REALSUM,		/* SUM OF REALS */
	QUAD_OP_INTSUBS,		/* INTEGER SUBSTRACTION */
	QUAD_OP_REALSUBS,		/* REALS SUBSTRACTION */
	QUAD_OP_INTMULT,		/* INTEGER MULTIPLICATION  */
	QUAD_OP_REALMULT,		/* REAL MULTIPLICATION */
	QUAD_OP_DIVENT,			/* INTEGER DIVISION */
	QUAD_OP_DIVREAL,		/* REAL DIVISION */
	QUAD_OP_GOTO,
	QUAD_OP_NOGOTO,

	/* Relational Operators */
	QUAD_OP_EQ,				/* EQ:EQUAL */
	QUAD_OP_NE,				/* NE: NOT EQUAL */
	QUAD_OP_GE,				/* GE: GREATER THAN */
	QUAD_OP_GE,				/* GE: GREATER EQUAL */
	QUAD_OP_LT,				/* LT: LESS THAN */
	QUAD_OP_LE,				/* LE: LESS EQUAL */

	/* Boolean */
	QUAD_OP_TRUE,
	QUAD_OP_FALSE,
	
	/* No Operator */
	QUAD_OP_NOOP,
} Quad_operators;


typedef enum {
	BOOLEANEXP,
	ARITHMETICEXP,
	UNDEFINEDEXP
} Expression_type;

typedef enum {
	STRING,
	INTEGER,
	REAL,
	CHAR,
	BOOLEAN
} Data_type;

typedef enum Quad_AddrType_type{
	QUAD_ADDR_TYPE_EMPTY = 0,

	QUAD_ADDR_TYPE_NAME = 1,
	QUAD_ADDR_TYPE_REG,
	QUAD_ADDR_TYPE_CONSTANT,

	QUAD_ADDR_TYPE_UNKOWN = -1,
} Quad_AddrType_type;