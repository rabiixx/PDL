/**
  * [+] Description: ProAlg Language Scanner
  * [+] Authors: Ruben Cherif & Lorenzo Otermin
  * [+] Date: 28/10/2020
  * [+] GitHub: https://github.com/rabiixx/PDL
  * [+] Version: v1.0
  */

%{

	#include "parser.tab.h"

%}




	/* Special Characters */
regex_special_char (\n|\t|)


	/* Alfabeto */

cifra [0-9]

letra [A-Za-z]


	/* Literales */

regex_literal_entero [+-]?{cifra}+([e|E]?{cifra}+)?

regex_literal_real [+-]?{cifra}+(\.{cifra}+)?([e|E]?{cifra}+)?

regex_literal_booleano regex_falso|regex_verdadero

regex_literal_caracter \".\"

regex_literal_cadena \'[^\n|^\']+\'


	/* Palabras Reservadas */

regex_accion (?i:"accion")
regex_algoritmo (?i:"algoritmo")
regex_booleano (?i:"booleano")
regex_cadena (?i:"cadena")
regex_caracter (?i:"caracter")
regex_const (?i:"const")
regex_continuar (?i:"continuar")
regex_de (?i:"de")
regex_dev (?i:"dev")
regex_div (?i:"div")
regex_ent (?i:"ent")
regex_entero (?i:"entero")
regex_e_s (?i:"e/s")
regex_faccion (?i:"faccion")
regex_falgoritmo (?i:"falgoritmo")
regex_falso (?i:"falso")
regex_fconst (?i:"fconst")
regex_ffuncion (?i:"ffuncion")
regex_fmientras (?i:"fmientras")
regex_fpara (?i:"fpara")
regex_fsi (?i:"fsi")
regex_ftipo (?i:"ftipo")
regex_ftupla (?i:"ftupla")
regex_funcion (?i:"funcion")
regex_fvar (?i:"fvar")
regex_hacer (?i:"hacer")
regex_hasta (?i:"hasta")
regex_mientras (?i:"mientras")
regex_mod (?i:"mod")
regex_no (?i:"no")
regex_o (?i:"o")
regex_para (?i:"para")
regex_real (?i:"real")
regex_ref (?i:"ref")
regex_sal (?i:"sal")
regex_si (?i:"si")
regex_tabla (?i:"tabla")
regex_tipo (?i:"tipo")
regex_tupla (?i:"tupla")
regex_var (?i:"var")
regex_verdadero (?i:"verdadero")
regex_y (?i:"y")


	/* Otros Tokens */

regex_asignacion :=
regex_comp_seq ;
regex_separador ,
regex_subrango \.\.
regex_def_typevar :
regex_creacion_tipo =
regex_entonces (->)
regex_sinosi \[\]
regex_ini_array \[
regex_fin_array \]
regex_punto \.
regex_par_aper \(
regex_par_cier \)
	

	/* Comentarios */
regex_comentario \{([^}]|(\/\}))*\}

	/* Identificadores */

regex_identificador {letra}({letra}|{cifra})*


	/* Operadores Aritmeticos */

regex_suma \+
regex_resta -
regex_multiplicacion \*
regex_division \/


	/* Operadores Relacionales */

regex_igualdad ==
regex_distinto <>
regex_mayor >
regex_menor <
regex_mayor_igual >=
regex_menor_igual <=

%%

{regex_comentario} 			{printf("%s - Comentario detectado\n", yytext); return (BI_COMENTARIO); }

{regex_literal_entero} 		{ printf("Literal entero: %d\n", atoi( yytext ) ); return (BI_LIT_ENTERO); }

{regex_literal_real} 		{ printf("Literal real: %f\n", atof( yytext ) ); return (BI_LIT_REAL); }

{regex_literal_booleano} 	{printf("%s - Booleano\n", yytext); return (BI_LIT_BOOLEANO);}

{regex_literal_caracter} 	{printf("%s - Caracter\n", yytext); return (BI_LIT_CARACTER);}

{regex_literal_cadena} 		{printf("%s - String\n", yytext); return (BI_LIT_CADENA);}


{regex_entero} 				{printf("%s - Palabra reservada entero detectada \n", yytext); return (BI_PR_ENTERO);}

{regex_real} 				{printf("%s - Palabra reservada real detectada \n", yytext); return (BI_PR_REAL);}

{regex_booleano} 			{printf("%s - Palabra reservada boolenao detectada \n", yytext); return (BI_PR_BOOLEANO);}

{regex_caracter} 			{printf("%s - Palabra reservada caracter detectada \n", yytext); return (BI_PR_CARACTER);}

{regex_cadena} 				{printf("%s - Palabra reservada cadena detectada \n", yytext); return (BI_PR_CADENA);}


{regex_accion} 				{printf("%s - Palabra reservada accion detectada \n", yytext); return (BI_ACCION);}
{regex_faccion} 			{printf("%s - Palabra reservada faccion detectada \n", yytext); return (BI_FACCION);}

{regex_algoritmo} 			{printf("%s - Palabra reservada algoritmo detectada \n", yytext); return (BI_ALGORITMO);}
{regex_falgoritmo} 			{printf("%s - Palabra reservada falgoritmo detectada \n", yytext); return (BI_FALGORITMO);}

{regex_const} 				{printf("%s - Palabra reservada const detectada \n", yytext); return (BI_CONST);}
{regex_fconst} 				{printf("%s - Palabra reservada fconst detectada \n", yytext); return (BI_FCONST);}

{regex_funcion} 			{printf("%s - Palabra reservada funcion detectada \n", yytext); return (BI_FUNCION);}
{regex_ffuncion} 			{printf("%s - Palabra reservada ffuncion detectada \n", yytext); return (BI_FFUNCION);}

{regex_mientras} 			{printf("%s - Palabra reservada mientras detectada \n", yytext); return (BI_MIENTRAS);}
{regex_fmientras} 			{printf("%s - Palabra reservada fmientras detectada \n", yytext); return (BI_FMIENTRAS);}

{regex_para} 				{printf("%s - Palabra reservada para detectada \n", yytext); return (BI_PARA);}
{regex_fpara} 				{printf("%s - Palabra reservada fpara detectada \n", yytext); return (BI_FPARA);}

{regex_si} 					{printf("%s - Palabra reservada si detectada \n", yytext); return (BI_SI);}
{regex_fsi} 				{printf("%s - Palabra reservada fsi detectada \n", yytext); return (BI_FSI);}

{regex_tipo} 				{printf("%s - Palabra reservada tipo detectada \n", yytext); return (BI_TIPO);}
{regex_ftipo} 				{printf("%s - Palabra reservada ftipo detectada \n", yytext); return (BI_FTIPO);}

{regex_tupla} 				{printf("%s - Palabra reservada tupla detectada \n", yytext); return (BI_TUPLA);}
{regex_ftupla} 				{printf("%s - Palabra reservada ftupla detectada \n", yytext); return (BI_FTUPLA);}

{regex_var} 				{printf("%s - Palabra reservada var detectada \n", yytext); return (BI_VAR);}

{regex_fvar} 				{printf("%s - Palabra reservada fvar detectada \n", yytext); return (BI_FVAR);}

{regex_punto} 				{printf("%s - Token punto \n", yytext); return (BI_PUNTO);}


{regex_continuar} 			{printf("%s - Palabra reservada continuar detectada \n", yytext); return (BI_CONTINUAR);}

{regex_de} 					{printf("%s - Palabra reservada de detectada \n", yytext); return (BI_DE);}

{regex_dev} 				{printf("%s - Palabra reservada dev detectada \n", yytext); return (BI_DEV);}

{regex_div} 				{printf("%s - Palabra reservada div detectada \n", yytext); return (BI_DIV);}

{regex_ent} 				{printf("%s - Palabra reservada ent detectada \n", yytext); return (BI_ENT);}

{regex_e_s} 				{printf("%s - Palabra reservada e/s detectada \n", yytext); return (BI_E_S);}

{regex_falso} 				{printf("%s - Palabra reservada falso detectada \n", yytext); return (BI_FALSO);}

{regex_hacer} 				{printf("%s - Palabra reservada hacer detectada \n", yytext); return (BI_HACER);}

{regex_hasta} 				{printf("%s - Palabra reservada hasta detectada \n", yytext); return (BI_HASTA);}

{regex_mod} 				{printf("%s - Palabra reservada mod detectada \n", yytext); return (BI_MOD);}

{regex_no} 					{printf("%s - Palabra reservada no detectada \n", yytext); return (BI_NO);}

{regex_o} 					{printf("%s - Palabra reservada o detectada \n", yytext); return (BI_O);}

{regex_ref} 				{printf("%s - Palabra reservada ref detectada \n", yytext); return (BI_REF);}

{regex_sal} 				{printf("%s - Palabra reservada sal detectada \n", yytext); return (BI_SAL);}

{regex_tabla} 				{printf("%s - Palabra reservada tabla detectada \n", yytext); return (BI_TABLA);}

{regex_verdadero} 			{printf("%s - Palabra reservada verdadero detectada \n", yytext); return (BI_VERDADERO);}

{regex_y} 					{printf("%s - Palabra reservada y detectada \n", yytext); return (BI_Y);}


{regex_asignacion} 			{printf("%s - *Token asignacion(:=) detectada \n", yytext); return (BI_ASIGNACION);}

{regex_comp_seq} 			{printf("%s - *Token composicion sequencial(;) detectada \n", yytext); return (BI_COMP_SEQ);}

{regex_separador} 			{printf("%s - *Token separador(,) detectada \n", yytext); return (BI_SEPARADOR);}
	
{regex_subrango} 			{printf("%s - *Token subrango(..) detectada \n", yytext); return (BI_SUBRANGO);}

{regex_def_typevar} 		{printf("%s - *Token definicion de tipo de variable (:) detectada \n", yytext); return (BI_DEF_TYPEVAR);}

{regex_entonces} 			{printf("%s - *Token entonces (->) detectada \n", yytext); return (BI_ENTONCES);}

{regex_creacion_tipo} 		{printf("%s - *Token creacion de tipo (=) detectada \n", yytext); return (BI_CREACION_TIPO);}

{regex_sinosi} 				{printf("%s - *Token si no si ([]) detectada \n", yytext); return (BI_SINOSI);}

{regex_ini_array} 			{printf("%s - *Token inicio array ([) detectada \n", yytext); return (BI_INI_ARRAY);}

{regex_fin_array} 			{printf("%s - *Token fin array (]) detectada \n", yytext); return (BI_FIN_ARRAY);}

{regex_identificador} 		{printf("%s - Identificador\n", yytext); return (BI_IDENTIFICADOR);}


{regex_suma} 				{printf("Operador Aritmetico de Suma: %s\n", yytext); return (BI_SUMA);}

{regex_resta} 				{printf("Operador Aritmetico de Resta: %s\n", yytext); return (BI_RESTA);}

{regex_multiplicacion} 		{printf("Operador Aritmetico de Multiplicacion: %s\n", yytext); return (BI_MULTIPLICACION);}

{regex_division}			{printf("Operador Aritmetico de Division: %s\n", yytext); return (BI_DIVISION);}

{regex_igualdad} 			{printf("Operador Relacional Igualdad: %s\n", yytext); return (BI_IGUALDAD);}

{regex_distinto} 			{printf("Operador Relacional Distinto: %s\n", yytext); return (BI_DISTINTO);}

{regex_mayor} 				{printf("Operador Relacional Mayor: %s\n", yytext); return (BI_MAYOR);}

{regex_menor} 				{printf("Operador Relacional Menor: %s\n", yytext); return (BI_MENOR);}

{regex_mayor_igual} 		{printf("Operador Relacional Mayor o Igual: %s\n", yytext); return (BI_MAYOR_IGUAL);}

{regex_menor_igual} 		{printf("Operador Relacional Menor o Igual: %s\n", yytext); return (BI_MENOR_IGUAL);}

{regex_par_aper} 			{printf("Token parentesis de apertura: %s\n", yytext); return (BI_PAR_APER);}

{regex_par_cier} 			{printf("Token parentesis de cierre: %s\n", yytext); return (BI_PAR_CIER);}



\n|. {}

%%

/*long int checkPowOverflowInt( int a, int b) {

	for (int i = 0; i < b; ++i)
	    if ( (i * log(a)) >= log(LONG_MAX))
			return -1;

	return (long int) pow(a, b);
}

double checkPowOverflowFloat( double a, double b) {

	for (int i = 0; i < b; ++i)
	    if ( ( i * log( a ) ) >= log( DBL_MAX ) )
			return -1;

	return (double) pow(a, b);
}*/

/*int yywrap(){}
int main(){

	yylex();

	return 0;
}*/