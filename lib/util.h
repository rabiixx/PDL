typedef enum {
	INTSUM,			/* SUM OF INTEGERS */
	REALSUM,		/* SUM OF REALS */
	INTSUBS,		/* INTEGER SUBSTRACTION */
	REALSUBS,		/* REALS SUBSTRACTION */
	INTMULT,		/* INTEGER MULTIPLICATION  */
	REALMULT,		/* REAL MULTIPLICATION */
	DIVENT,			/* INTEGER DIVISION */
	DIVREAL,		/* REAL DIVISION */
} operators;


typedef enum {
	BOOLEAN,
	ARITHMETIC,
	UNDEFINED
} Expression_type;