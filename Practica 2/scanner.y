%{
	/* fichero scanner.y */
	#include <stdio.h>
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


%left  BI_SUMA BI_RESTA
%left  BI_MULT BI_DIVISION BI_MOD BI_DIV
%left  BI_MENOR BI_MAYOR BI_MENOR_IGUAL BI_MAYOR_IGUAL BI_IGUALDAD BI_DISTINTO



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

tipo_base 		: 	regex_entero
				|	regex_real
				|	regex_booleano
				|	regex_caracter
				|	regex_cadena
				;

literal			:	regex_literal_entero
				|	regex_literal_real
				|	regex_literal_booleano
				|	regex_literal_caracter
				|	regex_literal_cadena
				;

lista_d_cte		:	regex_identificador regex_creacion_tipo regex_literal regex_comp_seq lista_d_cte 
				|	/* cadena vacia */
				;


lista_d_var		:	lista_id regex_def_typevar regex_identificador regex_comp_seq lista_d_var
				| 	lista_id regex_def_typevar d_tipo regex_comp_seq lista_d_var
				|	/* cadena vacia */
				;

lista_id 		:	regex_identificador regex_separador lista_id
				|	regex_identificador
				;

decl_ent_sal	:	decl_ent
				|	decl_ent decl_sal
				|	decl_sal
				;

decl_ent 		:	regex_ent lista_d_var
				;

decl_sal 		:	regex_sal lista_d_var
				;

/* Expresiones */

expresion 		:	exp_a 
				|	exp_b
				|	funcion_ll
				;

literal_numerico	:	regex_literal_entero
					|	regex_literal_real
					;

exp_a			:	exp_a regex_suma exp_a
				|	exp_a regex_resta exp_a
				|	exp_a regex_multiplicacion
				|	exp_a regex_division exp_a
				|	exp_a regex_mod exp_a
				|	exp_a regex_div exa_a
				|	regex_par_aper exp_a regex_par_cier
				|	operando 
				|	literal_numerico 
				|	regex_resta exp_a
				;

oprel			: 	regex_igualdad
				|	regex_distinto
				|	regex_mayor
				|	regex_menor
				|	regex_mayor_igual
				|	regex_menor_igual
				;

exp_b 			:	exp_b regex_y exp_b
				|	exp_b regex_o exp_b
				|	regex_no exp_b
				|	operando
				|	regex_verdadero
				|	regex_falso
				|	expresion oprel expresion
				|	regex_par_aper exp_b regex_par_cier
				;

operando		:	regex_identificador
				|	operando regex_punto operando
				|	operando regex_ini_array expresion regex_fin_array
				|	operando regex_ref
				;

/* Instrucciones */
instrucciones 	:	instruccion regex_comp_seq instrucciones
				|	instruccion
				;

instruccion 	:	regex_continuar
				|	asignacion
				|	alternativa
				| 	iteracion
				|	accion_ll
				;

asignacion 		:	operando regex_asignacion expresion
				;

alternativa		:	regex_si expresion regex_entonces instrucciones lista_opciones regex_fsi
				;

lista_opciones 	:	regex_ini_array regex_fin_array expresion regex_entonces instrucciones lista_opciones
				|	/* cadena vacia */
				;

iteracion 		:	it_cota_fija
				|	it_cota_exp
				;

it_cota_exp		:	regex_mientras expresion regex_hacer instrucciones regex_fmientras
				;

it_cota_fija	:	regex_para regex_identificador regex_asignacion expresion 
					regex_hasta expresion regrex_hacer instrucciones regex_fpara
				;

/* Acciones y Funciones */
accion_d 		:	regex_accion a_cabecera bloque regex_faccion
				;

funcion_d		:	regex_funcion f_cabecera bloque regex_dev expresion regex_ffuncion
				;

a_cabecera		:	regex_identificador regex_par_aper d_par_form
				;

f_cabecera		:	regex_identificador regex_par_aper lista_d_var regex_par_cier regex_comp_seq
				;

d_par_form		:	d_p_form regex_comp_seq d_par_form
				|	/* cadena vacia */
				;

d_p_form 		:	regex_ent lista_id regex_def_typevar d_tipo 
				|	regex_sal lista_id regex_def_typevar d_tipo
				| 	regex_e_s lista_id regex_def_typevar d_tipo
				;

accion_ll		:	regex_identificador regex_par_aper l_ll regex_par_cier
				;

funcion_ll		:	regex_identificador regex_par_aper l_ll regex_par_cier
				;

l_ll			:	expresion regex_separador l_ll
				|	expresion
				;











%%























