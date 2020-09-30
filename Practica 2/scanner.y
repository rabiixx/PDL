%{
	/* fichero scanner.y */
	#include <stdio.h>
%}

%%

	
desc_algoritmo	: 	regex_algoritmo regex_identificador regex_comp_seq cabecera_alg bloque_alg regex_falgoritmo
				;

cabecera_alg	:	decl_globales decl_a_f decl_ent_sal regex_comentario
				;

bloque_alg		:	bloque regex_comentario
				;

decl_globales	:	declaracion_tipo decl_globales
				| 	declaracion_const decl_globales
				|	/* cadena vacia */
				;

decl_a_f		:	accion_d decl_a_f
				|	funcion_d decl_a_f
				|	/* cadena vacia */
				;

bloque 			: declaraciones instrucciones
				;

declaraciones	:	declaracion_tipo declaraciones
				| 	declaracion_const declaraciones
				|	declaracion_var declaraciones
				|	/* cadena vacia */
				;

/* Declaraciones */
declaracion_tipo	:	regex_tipo lista_d_tipo regex_ftipo regex_comp_seq
					;

declaracion_cte		:	regex_const lista_d_cte regex_fconst regex_comp_seq
					;

declaracion_var		:	regex_var lista_d_var regex_fvar regex_comp_seq
					;

/* Declaraciones de tipos */
lista_d_tipo	:	regex_identificador regex_creacion_tipo d_tipo regex_comp_seq lista_d_tipo
				| 	/* cadena vacia */
				;

d_tipo 			: 	regex_tupla lista_campos regex_ftupla
				|	regex_tabla regex_ini_array expresion_t regex_ini_array expresion_t regex_fin_array regex_de d_tipo
				;

expresion_t		: 	expresion
				|	regex_literal_caracter
				;

lista_d_tipo	:	regex_identificador regex_def_typevar d_tipo regex_comp_seq lista_campos
				|	/* cadena vacia */
				;

tipo_base		:	regex_literal_entero
				|	regex_literal_real
				|	regex_literal_booleano
				|	regex_literal_caracter
				|	regex_literal_cadena


%%