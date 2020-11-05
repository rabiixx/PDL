/**
  * [+] Description: ProAlg Language Scanner
  * [+] Authors: Ruben Cherif & Lorenzo Otermin
  * [+] Date: 28/10/2020
  * [+] GitHub: https://github.com/rabiixx/PDL
  * [+] Version: v1.0
  */

%{

	#include "lib/util.h"
	#include "lib/exp_a_b/exp_a_b.h"
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

{regex_literal_entero} { 
	#ifdef _DEBUG
	printf("\e[1;36mScanner --> \e[0mLiteral entero: %d\n", atoi( yytext ) ); return (BI_LIT_ENTERO); 
	#endif
}

{regex_literal_real} {
	#ifdef _DEBUG
	printf("\e[1;36mScanner --> \e[0mLiteral real: %f\n", atof( yytext ) ); return (BI_LIT_REAL); 
	#endif
}

{regex_literal_booleano} {
	#ifdef _DEBUG
	printf("\e[1;36mScanner --> \e[0mBooleano: %s\n", yytext); return (BI_LIT_BOOLEANO);
	#endif
}

{regex_literal_caracter} 	{
	#ifdef _DEBUG
	printf("\e[1;36mScanner --> \e[0mCaracter: %s\n", yytext); return (BI_LIT_CARACTER);
	#endif
}

{regex_literal_cadena} 		{printf("\e[1;36mScanner --> \e[0mString: %s\n", yytext); return (BI_LIT_CADENA);}


{regex_entero} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada entero detectada: %s\n", yytext); return (BI_PR_ENTERO);}

{regex_real} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada real detectada: %s\n", yytext); return (BI_PR_REAL);}

{regex_booleano} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada boolenao detectada: %s\n", yytext); return (BI_PR_BOOLEANO);}

{regex_caracter} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada caracter detectada:%s\n", yytext); return (BI_PR_CARACTER);}

{regex_cadena} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada cadena detectada: %s\n", yytext); return (BI_PR_CADENA);}


{regex_accion} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada accion detectada: %s\n", yytext); return (BI_ACCION);}
{regex_faccion} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada faccion detectada: %s\n", yytext); return (BI_FACCION);}

{regex_algoritmo} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada algoritmo detectada: %s\n", yytext); return (BI_ALGORITMO);}
{regex_falgoritmo} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada falgoritmo detectada: %s\n", yytext); return (BI_FALGORITMO);}

{regex_const} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada const detectada: %s\n", yytext); return (BI_CONST);}
{regex_fconst} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada fconst detectada: %s\n", yytext); return (BI_FCONST);}

{regex_funcion} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada funcion detectada: %s\n", yytext); return (BI_FUNCION);}
{regex_ffuncion} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada ffuncion detectada %s\n", yytext); return (BI_FFUNCION);}

{regex_mientras} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada mientras detectada: %s\n", yytext); return (BI_MIENTRAS);}
{regex_fmientras} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada fmientras detectada: %s\n", yytext); return (BI_FMIENTRAS);}

{regex_para} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada para detectada: %s\n", yytext); return (BI_PARA);}
{regex_fpara} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada fpara detectada: %s\n", yytext); return (BI_FPARA);}

{regex_si} 					{printf("\e[1;36mScanner --> \e[0mPalabra reservada si detectada: %s\n", yytext); return (BI_SI);}
{regex_fsi} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada fsi detectada: %s\n", yytext); return (BI_FSI);}

{regex_tipo} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada tipo detectada: %s\n", yytext); return (BI_TIPO);}
{regex_ftipo} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada ftipo detectada: %s\n", yytext); return (BI_FTIPO);}

{regex_tupla} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada tupla detectada: %s\n", yytext); return (BI_TUPLA);}
{regex_ftupla} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada ftupla detectada: %s\n", yytext); return (BI_FTUPLA);}

{regex_var} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada var detectada: %s\n", yytext); return (BI_VAR);}

{regex_fvar} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada fvar detectada: %s\n", yytext); return (BI_FVAR);}

{regex_punto} 				{printf("\e[1;36mScanner --> \e[0mToken punto: %s\n", yytext); return (BI_PUNTO);}


{regex_continuar} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada continuar detectada: %s\n", yytext); return (BI_CONTINUAR);}

{regex_de} 					{printf("\e[1;36mScanner --> \e[0mPalabra reservada de detectada: %s \n", yytext); return (BI_DE);}

{regex_dev} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada dev detectada: %s\n", yytext); return (BI_DEV);}

{regex_div} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada div detectada: %s\n", yytext); return (BI_DIV);}

{regex_ent} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada ent detectada: %s\n", yytext); return (BI_ENT);}

{regex_e_s} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada e/s detectada: %s\n", yytext); return (BI_E_S);}

{regex_falso} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada falso detectada: %s\n", yytext); return (BI_FALSO);}

{regex_hacer} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada hacer detectada: %s\n", yytext); return (BI_HACER);}

{regex_hasta} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada hasta detectada: %s\n", yytext); return (BI_HASTA);}

{regex_mod} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada mod detectada: %s\n", yytext); return (BI_MOD);}

{regex_no} 					{printf("\e[1;36mScanner --> \e[0mPalabra reservada no detectada: %s\n", yytext); return (BI_NO);}

{regex_o} 					{printf("\e[1;36mScanner --> \e[0mPalabra reservada o detectada: %s\n", yytext); return (BI_O);}

{regex_ref} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada ref detectada: %s\n", yytext); return (BI_REF);}

{regex_sal} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada sal detectada: %s\n", yytext); return (BI_SAL);}

{regex_tabla} 				{printf("\e[1;36mScanner --> \e[0mPalabra reservada tabla detectada: %s\n", yytext); return (BI_TABLA);}

{regex_verdadero} 			{printf("\e[1;36mScanner --> \e[0mPalabra reservada verdadero detectada: %s\n", yytext); return (BI_VERDADERO);}

{regex_y} 					{printf("\e[1;36mScanner --> \e[0mPalabra reservada y detectada: %s\n", yytext); return (BI_Y);}


{regex_asignacion} 			{printf("\e[1;36mScanner --> \e[0m*Token asignacion(:=) detectada: %s\n", yytext); return (BI_ASIGNACION);}

{regex_comp_seq} 			{printf("\e[1;36mScanner --> \e[0m*Token composicion sequencial(;) detectada: %s\n", yytext); return (BI_COMP_SEQ);}

{regex_separador} 			{printf("\e[1;36mScanner --> \e[0m*Token separador(,) detectada: %s\n", yytext); return (BI_SEPARADOR);}
	
{regex_subrango} 			{printf("\e[1;36mScanner --> \e[0m*Token subrango(..) detectada: %s\n", yytext); return (BI_SUBRANGO);}

{regex_def_typevar} 		{printf("\e[1;36mScanner --> \e[0m*Token definicion de tipo de variable (:) detectada: %s\n", yytext); return (BI_DEF_TYPEVAR);}

{regex_entonces} 			{printf("\e[1;36mScanner --> \e[0m*Token entonces (->) detectada: %s\n", yytext); return (BI_ENTONCES);}

{regex_creacion_tipo} 		{printf("\e[1;36mScanner --> \e[0m*Token creacion de tipo (=) detectada: %s\n", yytext); return (BI_CREACION_TIPO);}

{regex_sinosi} 				{printf("\e[1;36mScanner --> \e[0m*Token si no si ([]) detectada: %s\n", yytext); return (BI_SINOSI);}

{regex_ini_array} 			{printf("\e[1;36mScanner --> \e[0m*Token inicio array ([) detectada: %s\n", yytext); return (BI_INI_ARRAY);}

{regex_fin_array} 			{printf("\e[1;36mScanner --> \e[0m*Token fin array (]) detectada: %s\n", yytext); return (BI_FIN_ARRAY);}

{regex_identificador} 		{	printf("\e[1;36mScanner --> \e[0mIdentificador: %s\n", yytext);
								yylval.sval	= malloc( strlen( yytext ) );
								strncpy( yylval.sval, yytext, strlen( yytext ) );
								return (BI_IDENTIFICADOR);
								}


{regex_suma} 				{printf("\e[1;36mScanner --> \e[0mOperador Aritmetico de Suma: %s\n", yytext); return (BI_SUMA);}

{regex_resta} 				{printf("\e[1;36mScanner --> \e[0mOperador Aritmetico de Resta: %s\n", yytext); return (BI_RESTA);}

{regex_multiplicacion} 		{printf("\e[1;36mScanner --> \e[0mOperador Aritmetico de Multiplicacion: %s\n", yytext); return (BI_MULTIPLICACION);}

{regex_division}			{printf("\e[1;36mScanner --> \e[0mOperador Aritmetico de Division: %s\n", yytext); return (BI_DIVISION);}

{regex_igualdad} 			{printf("\e[1;36mScanner --> \e[0mOperador Relacional Igualdad: %s\n", yytext); return (BI_IGUALDAD);}

{regex_distinto} 			{printf("\e[1;36mScanner --> \e[0mOperador Relacional Distinto: %s\n", yytext); return (BI_DISTINTO);}

{regex_mayor} 				{printf("\e[1;36mScanner --> \e[0mOperador Relacional Mayor: %s\n", yytext); return (BI_MAYOR);}

{regex_menor} 				{printf("\e[1;36mScanner --> \e[0mOperador Relacional Menor: %s\n", yytext); return (BI_MENOR);}

{regex_mayor_igual} 		{printf("\e[1;36mScanner --> \e[0mOperador Relacional Mayor o Igual: %s\n", yytext); return (BI_MAYOR_IGUAL);}

{regex_menor_igual} 		{printf("\e[1;36mScanner --> \e[0mOperador Relacional Menor o Igual: %s\n", yytext); return (BI_MENOR_IGUAL);}

{regex_par_aper} 			{printf("\e[1;36mScanner --> \e[0mToken parentesis de apertura: %s\n", yytext); return (BI_PAR_APER);}

{regex_par_cier} 			{printf("\e[1;36mScanner --> \e[0mToken parentesis de cierre: %s\n", yytext); return (BI_PAR_CIER);}



\n|. {}

%%

/*int yywrap(){}
int main(){

	yylex();

	return 0;
}*/