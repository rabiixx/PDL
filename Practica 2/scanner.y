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

	
desc_algoritmo	: 	BI_ALGORITMO BI_IDENTIFICADOR BI_COMP_SEQ cabecera_alg bloque_alg BI_FALGORITMO
				;

cabecera_alg	:	decl_globales decl_a_f decl_ent_sal BI_COMENTARIO
				;

bloque_alg		:	bloque BI_COMENTARIO
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
declaracion_tipo	:	BI_TIPO lista_d_tipo BI_FTIPO BI_COMP_SEQ
					;

declaracion_cte		:	BI_CONST lista_d_cte BI_FCONST BI_COMP_SEQ
					;

declaracion_var		:	BI_VAR lista_d_var BI_FVAR BI_COMP_SEQ
					;

/* Declaraciones de tipos */
lista_d_tipo	:	BI_IDENTIFICADOR BI_CREACION_TIPO d_tipo BI_COMP_SEQ lista_d_tipo
				| 	/* cadena vacia */
				;

d_tipo 			: 	BI_TUPLA lista_campos BI_FTUPLA
				|	BI_TABLA BI_INI_ARRAY expresion_t BI_INI_ARRAY expresion_t BI_FIN_ARRAY BI_DE d_tipo
				;

expresion_t		: 	expresion
				|	BI_LITERAL_CARACTER
				;

lista_d_tipo	:	BI_IDENTIFICADOR BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_campos
				|	/* cadena vacia */
				;

tipo_base 		: 	BI_ENTERO
				|	BI_REAL
				|	BI_BOOLEANO
				|	BI_CARACTER
				|	BI_CADENA
				;

literal			:	BI_LITERAL_ENTERO
				|	BI_LITERAL_REAL
				|	BI_LITERAL_BOOLEANO
				|	BI_LITERAL_CARACTER
				|	BI_LITERAL_CADENA
				;

lista_d_cte		:	BI_IDENTIFICADOR BI_CREACION_TIPO BI_LITERAL BI_COMP_SEQ lista_d_cte 
				|	/* cadena vacia */
				;


lista_d_var		:	lista_id BI_DEF_TYPEVAR BI_IDENTIFICADOR BI_COMP_SEQ lista_d_var
				| 	lista_id BI_DEF_TYPEVAR d_tipo BI_COMP_SEQ lista_d_var
				|	/* cadena vacia */
				;

lista_id 		:	BI_IDENTIFICADOR BI_SEPARADOR lista_id
				|	BI_IDENTIFICADOR
				;

decl_ent_sal	:	decl_ent
				|	decl_ent decl_sal
				|	decl_sal
				;

decl_ent 		:	BI_ENT lista_d_var
				;

decl_sal 		:	BI_SAL lista_d_var
				;

/* Expresiones */

expresion 		:	exp_a 
				|	exp_b
				|	funcion_ll
				;

literal_numerico	:	BI_LITERAL_ENTERO
					|	BI_LITERAL_REAL
					;

exp_a			:	exp_a BI_SUMA exp_a
				|	exp_a BI_RESTA exp_a
				|	exp_a BI_MULTIPLICACION
				|	exp_a BI_DIVISION exp_a
				|	exp_a BI_MOD exp_a
				|	exp_a BI_DIV exp_a
				|	BI_PAR_APER exp_a BI_PAR_CIER
				|	operando 
				|	literal_numerico 
				|	BI_RESTA exp_a
				;

oprel			: 	BI_IGUALDAD
				|	BI_DISTINTO
				|	BI_MAYOR
				|	BI_MENOR
				|	BI_MAYOR_IGUAL
				|	BI_MENOR_IGUAL
				;

exp_b 			:	exp_b BI_Y exp_b
				|	exp_b BI_O exp_b
				|	BI_NO exp_b
				|	operando
				|	BI_VERDADERO
				|	BI_FALSO
				|	expresion oprel expresion
				|	BI_PAR_APER exp_b BI_PAR_CIER
				;

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

lista_opciones 	:	BI_INI_ARRAY BI_FIN_ARRAY expresion BI_ENTONCES instrucciones lista_opciones
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























