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
				{printf("desc_algoritmo")}
				;

cabecera_alg	:	decl_globales decl_a_f decl_ent_sal BI_COMENTARIO
				{printf("cabecera_alg")}
				;

bloque_alg		:	bloque BI_COMENTARIO
				{printf("bloque_alg")}
				;

decl_globales	:	declaracion_tipo decl_globales
				{printf("decl_globales")}
				| 	declaracion_cte decl_globales
				{printf("decl_globales")}
				|	/* cadena vacia */
				;

decl_a_f		:	accion_d decl_a_f
				{printf("decl_accion")}
				|	funcion_d decl_a_f
				{printf("decl_funcion")}
				|	/* cadena vacia */
				;

bloque 			: declaraciones instrucciones
				{printf("bloque")}
				;

declaraciones	:	declaracion_tipo declaraciones
				{printf("declaraciones")}
				| 	declaracion_cte declaraciones
				{printf("declaraciones")}
				|	declaracion_var declaraciones
				{printf("declaraciones")}
				|	/* cadena vacia */
				;

/* Declaraciones */

/* Ejemplos de declracion_tipo 

tipo

	x = 


ftipo;
*/
declaracion_tipo	:	BI_TIPO lista_d_tipo BI_FTIPO BI_COMP_SEQ
					{printf("declaracion_tipo")}
					;
/* 
const
	
fconst;
*/

declaracion_cte		:	BI_CONST lista_d_cte BI_FCONST BI_COMP_SEQ
					{printf("declaracion_cte")}
					;

declaracion_var		:	BI_VAR lista_d_var BI_FVAR BI_COMP_SEQ
					{printf("declaraciones_var")}
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
				{printf("d_tipo")}
				|	BI_IDENTIFICADOR 				/* base case */
				{printf("d_tipo")}
				|	BI_REF d_tipo 								/* recursive by d_tipo */
				|	expresion_t BI_SUBRANGO expresion_t			/* recursive by expresion_t */
				| 	BI_TUPLA lista_campos BI_FTUPLA				/* recursive by lista_campos */
				{
					/* Que devolver ??? tupla*/
				}
				|	BI_TABLA BI_INI_ARRAY expresion_t BI_SUBRANGO expresion_t BI_FIN_ARRAY BI_DE d_tipo 	/* recursive by expresion_t and d_tipo */
				;

expresion_t		: 	expresion
				{printf("expresion_t")}
				|	BI_LIT_CARACTER
				{printf("expresion_t")}
				;
/* x = tupla
			y : entero;
	   ftupla
*/

lista_campos	:	BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos
				{


				}
				|	/* cadena vacia */
				;

tipo_base 		: 	BI_PR_ENTERO
				{
					printf("tipo_base entero")
				}
				|	BI_PR_REAL
				{printf("tipo_base real")}
				|	BI_PR_BOOLEANO
				{printf("tipo_base booleano")}
				|	BI_PR_CARACTER
				{printf("tipo_base caracter")}	
				|	BI_PR_CADENA
				{printf("tipo_base cadena")}
				;


/**
  * This grammar rule is used by lista_d_cte that defines the stucture
  * of a constant definition. In this case we need tu return the literal type.
  * Returned literal type will be used in the parent grammar rule to set 
  * identifier type in symbol table
  */

literal			:	BI_LIT_ENTERO 
				{printf("literal entero")}
				|	BI_LIT_REAL
				{printf("literal real")}
				|	BI_LIT_BOOLEANO
				{printf("literal booleano")}
				|	BI_LIT_CARACTER
				{printf("literal caracter")}
				|	BI_LIT_CADENA
				{printf("literal cadena")}
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
					
				}
				|	/* cadena vacia */
				;

/** 
  *	x, y, z : suma; 
  *	x, y, z : d_tipo;
  */
lista_d_var		:	lista_id BI_DEF_TYPEVAR BI_IDENTIFICADOR BI_COMP_SEQ lista_d_var 
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
				|	BI_IDENTIFICADOR
				;

decl_ent_sal	:	decl_ent
				{printf("decl_ent_sal")}
				|	decl_ent decl_sal
				{printf("decl_ent_sal")}
				|	decl_sal
				{printf("decl_ent_sal")}
				;

/* 
	ent
		x, y : entero
*/ 
decl_ent 		:	BI_ENT lista_d_var
				{printf("decl_ent")}
				;

decl_sal 		:	BI_SAL lista_d_var
				{printf("decl_sal")}
				;

/* Expresiones */


expresion 		:	exp_a_b
				{printf("expresion")}
				|	funcion_ll
				{printf("expresion")}
				;

literal_numerico	:	BI_LIT_ENTERO
					{printf("literal_entero")}
					|	BI_LIT_REAL
					{printf("literal_real")}
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
				|	BI_NO exp_a_b
				|	expresion oprel expresion
				|	operando
				|	BI_VERDADERO
				|	BI_FALSO
				;
				;

/**
  * EQ:EQUAL
  * NE: NOT EQUAL
  * GE: GREATER THAN
  * GE: GREATER EQUAL
  * LT: LESS THAN
  * LE: LESS EQUAL
  */
oprel			: 	BI_IGUALDAD 	{printf("igualdad")}
				|	BI_DISTINTO 	{printf("distino")}
				|	BI_MAYOR 		{printf("mayor")}
				|	BI_MAYOR_IGUAL 	{printf("mayor_igual")}
				|	BI_MENOR 		{printf("menor")}
				|	BI_MENOR_IGUAL 	{printf("menor_igual")}
				;



/*
	x
	person.name
	arr[5]
	arr[num]
*/

operando		:	BI_IDENTIFICADOR
				{printf("operando")}
				|	operando BI_PUNTO operando
				{printf("operando")}
				|	operando BI_INI_ARRAY expresion BI_FIN_ARRAY
				{printf("operando")}
				|	operando BI_REF
				{printf("operando")}
				;



/* Instrucciones */
instrucciones 	:	instruccion BI_COMP_SEQ instrucciones
				{printf("instrucciones")}
				|	instruccion
				{printf("instrucciones")}
				;

instruccion 	:	BI_CONTINUAR
				{printf("continuar")}
				|	asignacion
				{printf("instruccion")}
				|	alternativa
				{printf("instruccion")}
				| 	iteracion
				{printf("instruccion")}
				|	accion_ll
				{printf("instruccion")}
				;

asignacion 		:	operando BI_ASIGNACION expresion
				{printf("asignacion")}
				;

alternativa		:	BI_SI expresion BI_ENTONCES instrucciones lista_opciones BI_FSI
				{printf("alternativa")}
				;

lista_opciones 	:	BI_SINOSI expresion BI_ENTONCES instrucciones lista_opciones
				|	/* cadena vacia */
				;

iteracion 		:	it_cota_fija
				{printf("iteracion")}
				|	it_cota_exp
				{printf("iteracion")}
				;

it_cota_exp		:	BI_MIENTRAS expresion BI_HACER instrucciones BI_FMIENTRAS
				{printf("it_cota_exp")}
				;

it_cota_fija	:	BI_PARA BI_IDENTIFICADOR BI_ASIGNACION expresion 
					BI_HASTA expresion BI_HACER instrucciones BI_FPARA
				{printf("it_cota_fija")}
				;

/* Acciones y Funciones */
accion_d 		:	BI_ACCION a_cabecera bloque BI_FACCION
				{printf("accion_d")}
				;

funcion_d		:	BI_FUNCION f_cabecera bloque BI_DEV expresion BI_FFUNCION
				{printf("funcion_d")}
				;

a_cabecera		:	BI_IDENTIFICADOR BI_PAR_APER d_par_form
				{printf("a_cabecera")}
				;

f_cabecera		:	BI_IDENTIFICADOR BI_PAR_APER lista_d_var BI_PAR_CIER BI_COMP_SEQ
				{printf("f_cabecera")}
				;

d_par_form		:	d_p_form BI_COMP_SEQ d_par_form
				{printf("d_par_form")}
				|	/* cadena vacia */
				;

d_p_form 		:	BI_ENT lista_id BI_DEF_TYPEVAR d_tipo 
				|	BI_SAL lista_id BI_DEF_TYPEVAR d_tipo
				| 	BI_E_S lista_id BI_DEF_TYPEVAR d_tipo
				;

accion_ll		:	BI_IDENTIFICADOR BI_PAR_APER l_ll BI_PAR_CIER
				{printf("accion_ll")}
				;

funcion_ll		:	BI_IDENTIFICADOR BI_PAR_APER l_ll BI_PAR_CIER
				{printf("funcion_ll")}
				;

l_ll			:	expresion BI_SEPARADOR l_ll
				{printf("l_ll")}
				|	expresion
				{printf("l_ll")}
				;



%%


int main(int argc, char const *argv[])
{
	
	for (int i = 0; i < sizeof(hash_table) / sizeof(hash_table[0]); ++i)
		hash_table[i] = NULL;


	return 0;
}





















