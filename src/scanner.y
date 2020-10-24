%{
	/* fichero scanner.y */
	#include <stdio.h>
	#include <stdbool.h>
	#include "libs/hash_table.h"

	Symbol *hash_table[HT_SIZE];

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


expresion 		:	exp_a 
				|	exp_b
				|	funcion_ll
				;

literal_numerico	:	BI_LIT_ENTERO
					|	BI_LIT_REAL
					;

exp_a_b			:	exp_a_b BI_SUMA exp_a_b
				|	exp_a_b BI_RESTA exp_a_b
				|	exp_a_b BI_MULTIPLICACION exp_a_b
				|	exp_a_b BI_DIVISION exp_a_b
				|	exp_a_b BI_MOD exp_a_b
				|	exp_a_b BI_DIV exp_a_b
				|	BI_PAR_APER exp_a_b BI_PAR_CIER
				|	literal_numerico
				|	BI_RESTA exp_a_b
				|	exp_a_b BI_Y exp_a_b
				|	exp_a_b BI_O exp_a_b
				|	BI_PAR_APER exp_a_b BI_PAR_CIER
				|	BI_NO exp_a_b
				|	expresion oprel expresion
				|	operando
				|	BI_VERDADERO
				{


				$$ = new_exp_a_b(BOOLEAN);
				$$->s = new_symbol("_tmp");
				set_attr(st, type, "_tmp");

				

				}
				|	BI_FALSO
				{

				}
				;

/* The variable nextquad (M.quad) holds the index of the next quadruple to follow. */
M 				: /* empty */ { $$ = next_quad() }


/**
  * EQ:EQUAL
  * NE: NOT EQUAL
  * GE: GREATER THAN
  * GE: GREATER EQUAL
  * LT: LESS THAN
  * LE: LESS EQUAL
  */
oprel			: 	BI_IGUALDAD 	{ $$ = EQ }
				|	BI_DISTINTO 	{ $$ = NE }
				|	BI_MAYOR 		{ $$ = GT }
				|	BI_MAYOR_IGUAL 	{ $$ = GE }
				|	BI_MENOR 		{ $$ = LT }
				|	BI_MENOR_IGUAL 	{ $$ = LE }
				;



/*
	x
	person.name
	arr[5]
	arr[num]
*/

operando		:	BI_IDENTIFICADOR
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


	return 0;
}





















