%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <errno.h>

	#include "lib/symboltable/symbol_table.h"
	#include "lib/quadruples/quadruples.h"
	#include "lib/exp_a_b/exp_a_b.h"
	#include "lib/stack/stack.h"


	extern int yylex();
	extern FILE *yyin;
	extern yylineno;

	void yyerror (char const *);

	Symbol *hash_table[HT_SIZE];
	QuadTable *qt = new_quad_table();

	Stack stack;

%}

%token BI_COMENTARIO
%token BI_LIT_ENTERO
%token BI_LIT_REAL
%token BI_LIT_BOOLEANO
%token BI_LIT_CARACTER
%token BI_LIT_CADENA

%token BI_PR_ENTERO
%token BI_PR_REAL
%token BI_PR_BOOLEANO
%token BI_PR_CARACTER
%token BI_PR_CADENA

%token BI_ACCION
%token BI_FACCION

%token BI_ALGORITMO
%token BI_FALGORITMO

%token BI_CONST
%token BI_FCONST

%token BI_FUNCION
%token BI_FFUNCION

%token BI_MIENTRAS
%token BI_FMIENTRAS

%token BI_PARA
%token BI_FPARA

%token BI_SI
%token BI_FSI

%token BI_TIPO
%token BI_FTIPO

%token BI_TUPLA
%token BI_FTUPLA

%token BI_VAR
%token BI_FVAR

%token BI_CONTINUAR
%token BI_DE
%token BI_DEV
%token BI_DIV
%token BI_ENT
%token BI_E_S
%token BI_FALSO
%token BI_HACER
%token BI_HASTA
%token BI_REF
%token BI_SAL
%token BI_TABLA
%token BI_VERDADERO
%left  BI_Y BI_O
%left BI_NO

%right BI_ASIGNACION
%token BI_COMP_SEQ
%token BI_SEPARADOR
%token BI_SUBRANGO
%token BI_DEF_TYPEVAR
%token BI_ENTONCES
%token BI_CREACION_TIPO
%token BI_SINOSI
%token BI_INI_ARRAY
%token BI_FIN_ARRAY
%token BI_IDENTIFICADOR
%token BI_PUNTO

%token BI_PAR_APER
%token BI_PAR_CIER


%left  BI_SUMA BI_RESTA
%left  BI_MULTIPLICACION BI_DIVISION BI_MOD BI_DIV
%left  BI_MENOR BI_MAYOR BI_MENOR_IGUAL BI_MAYOR_IGUAL BI_IGUALDAD BI_DISTINTO

%%

desc_algoritmo	: 	BI_ALGORITMO BI_IDENTIFICADOR BI_COMP_SEQ cabecera_alg bloque_alg BI_FALGORITMO
				;

cabecera_alg	:	decl_globales decl_a_f decl_ent_sal BI_COMENTARIO
				;

bloque_alg		:	bloque BI_COMENTARIO
				;

decl_globales	:	declaracion_tipo decl_globales
				| 	declaracion_cte decl_globales
				|	/* cadena vacia */
				;

decl_a_f		:	accion_d decl_a_f
				|	funcion_d decl_a_f
				|	/* cadena vacia */
				;

bloque 			: declaraciones instrucciones
				;

declaraciones	:	declaracion_tipo declaraciones
				| 	declaracion_cte declaraciones
				|	declaracion_var declaraciones
				|	/* cadena vacia */
				;

/* Declaraciones */

/* Ejemplos de declracion_tipo 

tipo

	x = 


ftipo;
*/
declaracion_tipo	:	BI_TIPO lista_d_tipo BI_FTIPO BI_COMP_SEQ
					;
/* 
const
	
fconst;
*/

declaracion_cte		:	BI_CONST lista_d_cte BI_FCONST BI_COMP_SEQ
					;

declaracion_var		:	BI_VAR lista_d_var BI_FVAR BI_COMP_SEQ
					;

/* Declaraciones de tipos */


/* 

	x = 

*/
lista_d_tipo	:	BI_IDENTIFICADOR BI_CREACION_TIPO d_tipo BI_COMP_SEQ lista_d_tipo
				{


				}
				| 	/* cadena vacia */
				;

/** Ejemplo d_tipo

G4: tupla
		x : tabla[1 o 0..3] de entero;
		x : y;
		x : 1..N;
		x : ref y;
		x : entero;
		x = tupla
	ftupla
	
State analiysis

	GR1: x = entero;
	GR2: x = y;
	GR3.1: x = ref entero ( gramatica incorrecta )
	GR3.2: x = ref y;
	GR3.3: x = ref ref ref ...
	tabla[1+2..5-3] de 
*/


d_tipo 			:	tipo_base 						/* base case */
				{
					/****duda: es integer? */
				}
				|	BI_IDENTIFICADOR 				/* base case */
				{

					char *type = get_attr(st, $1, "type");

					if ( !type ) {
						printf("Identifier %s doesnt exist", $1);
					} else {
						// strcpy();
						$$ = type;
					}


				}
				|	BI_REF d_tipo 								/* recursive by d_tipo */
				|	expresion_t BI_SUBRANGO expresion_t			/* recursive by expresion_t */
				| 	BI_TUPLA lista_campos BI_FTUPLA				/* recursive by lista_campos */
				{
					/* Que devolver ??? tupla*/
				}
				|	BI_TABLA BI_INI_ARRAY expresion_t BI_SUBRANGO expresion_t BI_FIN_ARRAY BI_DE d_tipo 	/* recursive by expresion_t and d_tipo */
				;

expresion_t		: 	expresion
				|	BI_LIT_CARACTER
				;
/* x = tupla
			y : entero;
	   ftupla
*/

lista_campos	:	BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos
				{

					insertSymbol(st, $1);
					set_attr(st, $1, "type", $3);

				}
				|	/* cadena vacia */
				;

tipo_base 		: 	BI_PR_ENTERO
				{
					$$ = INTEGER;
				}
				|	BI_PR_REAL
				{
					$$ = FLOAT;
				}
				|	BI_PR_BOOLEANO
				{
					$$ = BOOLEAN;
				}
				|	BI_PR_CARACTER
				{
					$$ = CHARACTER;
				}
				|	BI_PR_CADENA
				{
					$$ = STRING;
				}
				;


/**
  * This grammar rule is used by lista_d_cte that defines the stucture
  * of a constant definition. In this case we need tu return the literal type.
  * Returned literal type will be used in the parent grammar rule to set 
  * identifier type in symbol table
  */

literal			:	BI_LIT_ENTERO 
				{

					printf("LITERAL_ENTERO");

					$$ = INTEGER;
				}
				|	BI_LIT_REAL
				{
					$$ = FLOAT;
				}
				|	BI_LIT_BOOLEANO{
					$$ = BOOLEAN;
				}
				|	BI_LIT_CARACTER{

					$$ = CHARACTER;
				}
				|	BI_LIT_CADENA{
					$$ = STRING;
				}
				;


/** 
  *	CONST
  * 	x = 3.1;
  * 	y = asdas;
  * FCONST

decla_cte: BI_CTE lista_d_cte B

  x = 2;
  */
lista_d_cte		:	BI_IDENTIFICADOR BI_CREACION_TIPO literal BI_COMP_SEQ lista_d_cte
				{


					/** 
					  * We insert the identifier into the symbol table and we define its scope and type.
					  * in this case scope will be, const. The type is returned by literal grammar rule 
					  */
					insertSymbol(st, $1);
					set_attr(st, $1, "scope", "cte");
					set_attr(st, $1, "type", $3)
				}
				|	/* cadena vacia */
				;

/** 
  *	x, y, z : suma; 
  *	x, y, z : d_tipo;
  */
lista_d_var		:	lista_id BI_DEF_TYPEVAR BI_IDENTIFICADOR BI_COMP_SEQ lista_d_var {

				/* Debug */
				if ( lookup(st, $3) ) {

					char *type;

					if ( ( type = get_attr(st, %3) ) ) {
						
						/* 
						 * Now we need to assign type to all identifiers reduced by lista_id grammar rule.
						 * Those identifiers have been added to symbol table and they have been added to 
						 * stack. For each identifier, we set the type and we remove it from the stack.
						 */

						while ( !esNulaPila( stack ) ) {

							char *id = cima( stack );

							if ( set_attr(st, id, type) == -1 ) {
								printf("Identifier %s is not in the symbol table", id);
							}

							desapilar( stack );

						}

					} else {
						printf("Symbol %s type is not defined\n", $3);
					}


				} else {
					printf("The symbol %s doesnt seem to be decalred\n", $3);
				}


				/* 
				 * get_attr() function includes lookup, so its not necessary 
				 * to make a lookup before get_attr(). In this case is done for
				 * debugginf reesons 
				 */
				if ( get_attr(st, %3) ) {

				} else {
					printf("Symbol %s type is not defined\n", $3);
				}


}
				| 	lista_id BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_d_var
				|	/* cadena vacia */
				;
/**
  * Bison antes de realizar un reduccion comprueba cual es el proximo valor.
  * En caso de que dicho valor pueda utilizarse para una reduccion mayor, 
  * no aplica la reduccion y lo añade a la pile del Parser.
  * Ejemplo:
  * Supongamo la siguiente expresion: "x, y" <==> BI_ID BI_COMA BI_ID
  * Bison leera un identificador y podria aplicar la siguiente reduccion: lista_id = BI_ID
  * En caso de que la aplicara la expresion quedaria tal que asi: lista_id , y <==> lista_id BI_COMA BI_ID
  * Como podemos ver, no existe ninguna regla de la gramatica por la cual la expresion pueda ser reducida y por
  * lo tanto sa liado bastante. Por ello, antes de realizar reducciones Bison realizar ciertas comprobaciones 
  * con el fin de evitar este tipo de situaciones.
  *
  * En este caso la reduccion se aplicaria de la siguiente manera. Soponiendo la sigueinte expresion: x, y, z
  * BI_ID BI_SEP lista_id ==> BI_ID BI_SEP BI_ID BI_SEP ==> BI_ID BI_SEP BI_ID BI_SEP BI_ID
  * Bison añadira lo siguiente a su pila(izq=primero): \n z , y , x 
  * A partir de ese punto lo sigueinte que lea sera otro identificador y un salto de linea. Por tanto, realizara
  * una reduccion por la segunda regla sobre z, quedando la pila tal que asi: pila(izq=primero): lista_id , y , x 
  * Ahora aplicara una reduccion por la primera regla: lista_id = y, lista_id (BI_ID BI_SEP lista_id) quedando la pila
  * tal que asi: lista_id , x.
  * Finalmente volvera a aplicar la misma reduccion: lista_id = x, lista_id (BI_ID BI_SEP lista_id) quedando la pila
  * finalemente asi: lista_id.
  * Al aplicar la reduccion, se añade el identificador a la tabla de simbolos. Posteriormente habra que especificar 
  * el tipo de identificador (entero,, char ...)
  */



lista_id 		:	BI_IDENTIFICADOR BI_SEPARADOR lista_id 
				{

					if ( !lookup(st, $1) ) {

						insertSymbol(st, $1);
						
						/* 
						 * We add identifiers to stack, to be able to set their type
						 * when we know it 
						 */
						apilar(stack, $1);


					} else {
						printf("Identifier alredy exists")
					}
				}
				|	BI_IDENTIFICADOR
				{

					if ( !lookup(st, $1) ) {
						
						insertSymbol(st, $1);
						apilar(stack, $1);

					} else {
						printf("Identifier alredy exists")
					}
				}
				;

decl_ent_sal	:	decl_ent
				|	decl_ent decl_sal
				|	decl_sal
				;

/* 
	ent
		x, y : entero
*/ 
decl_ent 		:	BI_ENT lista_d_var
				;

decl_sal 		:	BI_SAL lista_d_var
				;

/* Expresiones */


expresion 		:	exp_a_b
				|	funcion_ll
				;

exp_a_b			:	exp_a_b BI_SUMA exp_a_b
				{

					$$ = new_exp_a_b(ARITHMETIC_EXP);
					$$->s = new_symbol("_tmp");
					add_symbol(st, $$->s);

					if ( ( $1->s->type == INTEGER ) && ( $3->s->type == INTEGER ) )
					{
						$$->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUM, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);

					}
					else if ( ( $1->s->type == REAL ) && ( $3->s->type == REAL ) )
					{
						$$->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALSUM, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
					}
					else if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUM, $$->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $3->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUM, $$->s->id, $1->s->id, $$->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $1->s->type == DATA_TYPE_BOOLEAN ))
					{

					}

				}
				|	exp_a_b BI_RESTA exp_a_b
				{
					$$ = new_exp_a_b(ARITHMETIC_EXP);
					$$->s = new_symbol("_tmp");
					add_symbol(st, $$->s);

					if ( ( $1->s->type == INTEGER ) && ( $3->s->type == INTEGER ) )
					{
						$$->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTSUBS, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);

					}
					else if ( ( $1->s->type == REAL ) && ( $3->s->type == REAL ) )
					{
						$$->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALSUBS, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
					}
					else if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUBS, $$->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $3->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALSUBS, $$->s->id, $1->s->id, $$->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $1->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
				|	exp_a_b BI_MULTIPLICACION exp_a_b
				{
					$$ = new_exp_a_b(ARITHMETIC_EXP);
					$$->s = new_symbol("_tmp");
					add_symbol(st, $$->s);

					if ( ( $1->s->type == INTEGER ) && ( $3->s->type == INTEGER ) )
					{
						$$->s->type = DATA_TYPE_INTEGER;
						Quad *quad = new_quad(QUAD_OP_INTMULT, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);

					}
					else if ( ( $1->s->type == REAL ) && ( $3->s->type == REAL ) )
					{
						$$->s->type = DATA_TYPE_REAL;
						Quad *quad = new_quad(QUAD_OP_REALMULT, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
					}
					else if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMULT, $$->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $3->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMULT, $$->s->id, $1->s->id, $$->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $1->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
				|	exp_a_b BI_DIVISION exp_a_b
				{

				/**
				 * In case the argumnets are integers we need to convert them to 
				 * real before realizing the division. If both arguments are of
				 * integer type, we need another tmp variable to store the result
				 * of the conversions. 
				 *
				 */

					$$ = new_exp_a_b(ARITHMETIC_EXP);
					$$->s = new_symbol("_tmp");
					add_symbol(st, $$->s);


					if ( ( $1->s->type == INTEGER ) && ( $3->s->type == INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( tmp_symbol );
						
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, $1->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( ( $1->s->type == REAL ) && ( $3->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALDIV, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, $$->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $3->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, $$->s->id, $1->s->id, $$->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $1->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
				|	exp_a_b BI_MOD exp_a_b
				{

					$$ = new_exp_a_b(ARITHMETIC_EXP);
					$$->s = new_symbol("_tmp");
					add_symbol(st, $$->s);

					if ( ( $1->s->type == INTEGER ) && ( $3->s->type == INTEGER ) )
					{
						Quad *quad = new_quad(QUAD_OP_INTMOD, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
						$$->s->type = DATA_TYPE_INTEGER;
					}
					else if ( ( $1->s->type == REAL ) && ( $3->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_MODREAL, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMOD, $$->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( $3->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALMOD, $$->s->id, $1->s->id, $$->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);

						$$->s->type = DATA_TYPE_REAL;
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $1->s->type == DATA_TYPE_BOOLEAN ))
					{

					}
				}
				|	exp_a_b BI_DIV exp_a_b
				{

					/* div is division in which the fractional part (remainder) is discarded */

					$$ = new_exp_a_b(ARITHMETIC_EXP);
					$$->s = new_symbol("_tmp");
					add_symbol(st, $$->s);


					if ( ( $1->s->type == INTEGER ) && ( $3->s->type == INTEGER ) )
					{
						Symbol *tmp_symbol = new_symbol("_tmp");
						add_symbol( tmp_symbol );

						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, tmp_symbol->id);
						Quad *quad3 = new_quad(QUAD_OP_REALDIV, $1->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
						gen(qt, quad3);
					}
					else if ( ( $1->s->type == REAL ) && ( $3->s->type == REAL ) )
					{
						Quad *quad = new_quad(QUAD_OP_REALDIV, $1->s->id, $3->s->id, $$->s->id);
						gen(qt, quad);
					}
					else if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $1->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, $$->s->id, $3->s->id, $$->s->id);

						gen(qt, quad1);
						gen(qt, quad2);
					}
					else if ( $3->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad1 = new_quad(QUAD_OP_INT2REAL, $3->s->id, QUAD_OP_VOID, $$->s->id);
						Quad *quad2 = new_quad(QUAD_OP_REALDIV, $$->s->id, $1->s->id, $$->s->id);
						
						gen(qt, quad1);
						gen(qt, quad2);
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $1->s->type == DATA_TYPE_BOOLEAN ))
					{

					}

					/* Convert result to INTEGER */
					Quad *q = new_quad(QUAD_OP_REAL2INT, $$->s->id, QUAD_OP_VOID, $$->s->id);
					gen(qt, q);
					
					$$->s->type = DATA_TYPE_INTEGER;
				}
				|	BI_LIT_ENTERO
				{

					$$ = new_exp_a_b( ARITHMETIC_EXP );
					$$->s = new_symbol( "_tmp" );
					$$->S->type = DATA_TYPE_INTEGER;
					add_symbol(st, $$->s);

				}
				| 	BI_LIT_REAL
				{
					$$ = new_exp_a_b( ARITHMETIC_EXP );
					$$->s = new_symbol( "_tmp" );
					$$->S->type = DATA_TYPE_REAL;
					add_symbol(st, $$->s);
				}
				|	BI_RESTA exp_a_b
				{
					/**
					 * Productio: E --> -E1
					 * Semantic Rule:
					 * 	{
					 * 		T := newTemp();
					 *		modificarTipoTS(T, E1.type);
					 *		E.place = T;
					 * 		si ( E1.type = entero ) --> gen(E.place := -ent E1.place);
					 *		[] ( E1.type = real ) --> gen(E.place := -real E1.place)
					 *		fsi
					 *	}
					 */
					$$ = new_exp_a_b( ARITHMETIC_EXP );
					$$->s = new_symbol( "_tmp");
					$$->s->type = $1->s->type;

					if ( $1->s->type == DATA_TYPE_INTEGER )
					{
						Quad *quad = new_quad(QUAD_OP_INTUNIMUS, $2->s->id, QUAD_OP_VOID, $$->s->id)
					}
					else if ( $1->s->type == DATA_TYPE_REAL )
					{
						Quad *quad = new_quad(QUAD_OP_REALUNIMUS, $2->s->id, QUAD_OP_VOID, $$->s->id)
					}

				}
				|	operando
				{

				}
				|	exp_a_b BI_O M exp_a_b
				{

					/**
					 * Production 1: E --> E1 OR M E2
					 * 	{
					 * 		backpatch(E1.falselist, M.quad);
					 *		E.truelist := merge(E1.truelist, E2.truelist)
					 *		E.falselist := E2.falselist
					 *	}
					 */

					$$ = new_exp_a_b(BOOLEAN);
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
					add_symbol( st, $$->s );
					
					backpatch($1->falselist, $3);
					$$->truelist = merge($1->truelist, $4->truelist);
					$$->falselist = $4->falselist;

				}
				|	exp_a_b BI_Y M exp_a_b
				{
					/**
					 * Production 2: E --> E1 AND M E2
					 * 	{
					 * 		backpatch(E1.truelist, M.quad);
					 *		E.truelist := E2.truelist
					 *		E.falselist := merge(E1.falselist, E2.falselist)
					 *	}
					 */

					$$ = new_exp_a_b(BOOLEAN);
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
					add_symbol( st, $$->s );
					
					backpatch($1->truelist, $3);
					$$->truelist = $4->truelist;
					$$->falselist = merge($1->falselist, $4->falselist);

				}
				|	BI_NO exp_a_b
				{

					/**
					 * Production 3: E --> not E1
					 * {
					 * 		E.truelist = E1.falselist
					 *		E.falselist = E1.truelist
					 * }
					 */
					
					$$ = new_exp_a_b(BOOLEAN);
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
					add_symbol( st, $$->s );

					$$->truelist = $2->falselist;
					$$->falselist = $2->truelist;

				}
				|	BI_PAR_APER exp_a_b BI_PAR_CIER
				{

					/**
					 * Production 4: E --> (E1)
					 * 	{
					 *		E.truelist := E1.truelist
					 *		E.falselist := E1.falselist
					 * 	}
					 */
					
					$$ = new_exp_a_b(BOOLEAN);
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
					add_symbol( st, $$->s );

					$$->truelist = $2->truelist;
					$$->falselist = $2->falselist;

				}
				|	expresion oprel expresion
				{

					/**
					 * Production 5: E --> id1 relop id2
					 * { 	
					 *		E.truelist := makelist( nextaddr )
					 * 		E.falselist := makelist( nextaddr + 1)
					 *		emit( 'if' id1.place relop.op id2.place 'goto_')
					 *		emit( 'goto_' )
					 * }
					 */

					$$ = new_exp_a_b(BOOLEAN);

					 /* We create new tmp variable and add to symbol table*/
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
					add_symbol( st, $$->s );

					/* We generate new quadruples */ 
					Quad *quad1 = new_quad($2, $1->s->is, $2->s->id, QUAD_OP_NOGOTO);
					Quad *quad2 = new_quad(QUAD_OP_GOTO, $$->s->id, QUAD_OP_FALSE, QUAD_OP_NOGOTO);

					gen( qt, quad1 );
					gen( qt, quad2 );

					$$->truelist = makelist( quad1 );
					$$->falselist = makelist( quad2 );

				}
				|	BI_VERDADERO
				{
					/** 
					  * Production 6: E --> true
					  * { E.truelist := makelist(nextaddr) } 
					  * 
					  */
					$$ = new_exp_a_b(BOOLEAN);
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, $$->s);

					Quad *quad = new_quad(GOTO, $$->s->id, OP_QUAD_TRUE, NOTGOTO);
					gen(qt, quad);
					$$->truelist = makelist( quad );


				}
				|	BI_FALSO
				{
					/** 
					  * Production 7: E --> false
					  * { E.falselist := makelist(nextaddr) } 
					  * 
					  */
					$$ = new_exp_a_b(BOOLEAN);
					$$->s = new_symbol("_tmp");
					$$->s->type = BOOLEAN;
      				/*$$->s->value.bool = $1;*/
      				add_symbol(st, $$->s);

					Quad *quad = new_quad(GOTO, $$->s->id, OP_QUAD_FALSE, NOTGOTO);
					gen(qt, quad);
					$$->falselist = makelist( quad );

				}
				;


/**
 * 	The variable nextquad (M.quad) holds the index of the next quadruple to follow.
 * 	Production 8: E --> epsilon
 * 	{
 *		M.quad := nextaddr
 *	}
 */
M 				: /* empty */ { $$ = next_quad() }



oprel			: 	BI_IGUALDAD 	{ $$ = QUAD_OP_EQ }
				|	BI_DISTINTO 	{ $$ = QUAD_OP_NE }
				|	BI_MAYOR 		{ $$ = QUAD_OP_GT }
				|	BI_MAYOR_IGUAL 	{ $$ = QUAD_OP_GE }
				|	BI_MENOR 		{ $$ = QUAD_OP_LT }
				|	BI_MENOR_IGUAL 	{ $$ = QUAD_OP_LE }
				;



/*
	x
	person.name
	arr[5]
	arr[num]
*/

operando		:	BI_IDENTIFICADOR
				{
					/**
					 * Prodcution 6: E --> id
					 * Semantic Rule:
					 * 	{
					 * 		E.place := id.val
					 *		E.type := consultar_tipo_TS( id.val );
					 *	}
					 */
					
					Symbol *symbol = lookup( st, $1 );
					if ( symbol )
					{
						$$ = new_exp_a_b( UNDEFINED_EXP );					
						$$->s = symbol;

					}
					else
					{
						fprintf(stderr, "Error: Symbol %s doesnt exist in symbom table", $1);
					}


					
				}
				|	operando BI_PUNTO operando
				|	operando BI_INI_ARRAY expresion BI_FIN_ARRAY
				|	operando BI_REF
				;



/* Instrucciones */
instrucciones 	:	instruccion BI_COMP_SEQ instrucciones
				|	instruccion
				;

instruccion 	:	BI_CONTINUAR
				|	asignacion
				|	alternativa
				| 	iteracion
				|	accion_ll
				;

asignacion 		:	operando BI_ASIGNACION expresion
				{


					/**
					 *
					 * 
					 *
					 */

					if ( $1->s->type == $3->s->type )
					{
						Quad *quad = new_quad( QUAD_OP_ASSIGN, $1->s->id, $3->s->id, QUAD_OP_VOID, $$->s->id );
						gen( qt, quad );
					}
					else if ( ( $1->s->type == DATA_TYPE_INTEGER ) && ( $3->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( REAL2INT, $3->s->id, QUAD_OP_VOID, $1->s->id );
						gen( qt, quad );
					}
					else if ( ( $1->s->type == DATA_TYPE_REAL ) && ( $3->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2REAL, $3->s->id, QUAD_OP_VOID, $1->s->id );
						gen( qt, quad );	
					}
					else if ( ( $1->s->type == DATA_TYPE_INTEGER ) && ( $3->s->type == DATA_TYPE_BOOLEAN ) )
					{
						Quad *quad = new_quad( BOOL2INT, $3->s->id, QUAD_OP_VOID, $1->s->id );
						gen( qt, quad );	
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $3->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2BOOL, $3->s->id, QUAD_OP_VOID, $1->s->id );
						gen( qt, quad );
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $3->s->type == DATA_TYPE_REAL ) )
					{
						Quad *quad = new_quad( INT2BOOL, $3->s->id, QUAD_OP_VOID, $1->s->id );
						gen( qt, quad );	
					}
					else if ( ( $1->s->type == DATA_TYPE_BOOLEAN ) && ( $3->s->type == DATA_TYPE_INTEGER ) )
					{
						Quad *quad = new_quad( INT2BOOL, $3->s->id, QUAD_OP_VOID, $1->s->id );
						gen( qt, quad );
					}
					


				}
				;

alternativa		:	BI_SI expresion BI_ENTONCES instrucciones lista_opciones BI_FSI
				;

lista_opciones 	:	BI_SINOSI expresion BI_ENTONCES instrucciones lista_opciones
				|	/* cadena vacia */
				;

iteracion 		:	it_cota_fija
				|	it_cota_exp
				;

it_cota_exp		:	BI_MIENTRAS expresion BI_HACER instrucciones BI_FMIENTRAS
				;

it_cota_fija	:	BI_PARA BI_IDENTIFICADOR BI_ASIGNACION expresion 
					BI_HASTA expresion BI_HACER instrucciones BI_FPARA
				;

/* Acciones y Funciones */
accion_d 		:	BI_ACCION a_cabecera bloque BI_FACCION
				;

funcion_d		:	BI_FUNCION f_cabecera bloque BI_DEV expresion BI_FFUNCION
				;

a_cabecera		:	BI_IDENTIFICADOR BI_PAR_APER d_par_form
				;

f_cabecera		:	BI_IDENTIFICADOR BI_PAR_APER lista_d_var BI_PAR_CIER BI_COMP_SEQ
				;

d_par_form		:	d_p_form BI_COMP_SEQ d_par_form
				|	/* cadena vacia */
				;

d_p_form 		:	BI_ENT lista_id BI_DEF_TYPEVAR d_tipo 
				|	BI_SAL lista_id BI_DEF_TYPEVAR d_tipo
				| 	BI_E_S lista_id BI_DEF_TYPEVAR d_tipo
				;

accion_ll		:	BI_IDENTIFICADOR BI_PAR_APER l_ll BI_PAR_CIER
				;

funcion_ll		:	BI_IDENTIFICADOR BI_PAR_APER l_ll BI_PAR_CIER
				;

l_ll			:	expresion BI_SEPARADOR l_ll
				|	expresion
				;



%%


int main(int argc, char const *argv[])
{
	
	init_symbol_table( st );

	if ( argc == 2 && ( strcmp( argv[1], "--help" ) == 0 || strcmp( argv[1], "--help" ) == 0 ) )
	{
		printf("Usage: compiler <input-file>\n");
		printf("Supported input file extensions: .txt and .alg\n");
		return EXIT_SUCCESS;
	}
	else if ( argc == 2 )
	{
		
		char *ext = strrchr( argv[1], '.' );
		++ext;

		/* No extension */
		if ( !ext ) {
			printf("Usage: compiler <input-file>\n");
			printf("Supported input file extensions: .txt and .alg\n");
			return EXIT_SUCCESS;
		}

		if ( ( strcmp( ext, "txt" ) == 0 ) || ( strcmp( ext, "alg") ) )
		{
			FILE *file = fopen( argv[1], "r");
			
			if ( !file )
			{
				fprintf("Error: %s\n",	strerror( errno ) );
				return EXIT_FAILURE;
			}

			yyin = file;			
		} else {
			printf("Error: Not supported input file extension.\n\n");
			printf("Usage: compiler <input-file>\n");
			printf("Supported input file extensions: .txt and .alg\n");
			return EXIT_SUCCESS;

		}
	}

	return EXIT_SUCCESS;
}

















/*
|	BI_PAR_APER exp_a_b BI_PAR_CIER
				{
					**
					 * Production 5: E --> ( E1 )
					 * Semantic Rule:
					 * 	{
					 *		E.place := E1.place 
					 *		E.type = E1.type
					 *	}
					 *

					if ( !( $2->type == BOOLEAN_EXP ) && !( $2->type == ARITHMETIC_EXP ) )	
					{
				 		fprintf(stderr, "Error: Not valid expresion type\n");
				 	} else {
						$$ = $2;
				 	}

				}
*/