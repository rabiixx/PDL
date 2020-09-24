/**
  * [+] ProAlg Language Scanner
  * [+] Authors: Ruben Cherif & Lorenzo Otermin
  * [+] Date: 
  * [+] GitHub: https://github.com/rabiixx/PDL
  * [+] Version
  */

%{

	#include <math.h>
	#include <limits.h>
	#include <float.h>

	/* Checks for Pow operation Overflow beetween intergers */ 
	long int checkPowOverflowInt( int a, int b);

	/* Checks for Pow operation Overflow between floats */ 
	double checkPowOverflowFloat( double a, double b);
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

regex_literal_caracter \"{letra}\"

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
	

	/* Comentarios */

regex_comentario "{"[^}\n]"}"


	/* Identificadores */

regex_identificador {letra}({letra}|{cifra})*


	/* Operadores Aritmeticos */

regex_suma \+
regex_resta -
regex_multiplicacion \*


	/* Operadores Relacionales */

regex_igualdad ==
regex_distinto <>
regex_mayor >
regex_menor <
regex_mayor_igual >=
regex_menor_igual <=

%%


{regex_literal_entero} {

	//printf("yytext memory address: %p\n", &yytext);
	//printf("Sizeof yytext: %d\n", sizeof(yytext));
	//printf("Strlen yytext: %zu\n", strlen(yytext));
	

	//printf("%s - Literal entero\n", yytext);
	
	char *p;
	
	char *str = (char*) malloc( sizeof( yytext ) );
	strcpy(str, yytext);

	if ( ( p = strchr( str, 'e' ) ) || ( p = strchr( str, 'E' ) ) ) {

		*p = 0;
		p++;
		
		long int exp;
		if (  ( exp = checkPowOverflowInt( 10, atoi( p ) ) ) == -1 )
		{
			printf("Literal integer exponent Overflow: %s\n", yytext);
		} else {
			printf("Lietral entero: %ld\n", ( atoi( str ) * exp ) );	
		}

	} else {
	
	 	printf("Literal entero: %d\n", atoi( yytext ) );

	}
}

{regex_literal_real} {

	char *p;
	
	char *str = (char*) malloc( sizeof( yytext ) );
	strcpy(str, yytext);

	if ( ( p = strchr( str, 'e' ) ) || ( p = strchr( str, 'E' ) ) ) {

		*p = 0;
		p++;
		
		double exp;
		if (  ( exp = checkPowOverflowFloat( 10, atof( p ) ) ) == -1 )
		{
			printf("Literal real exponent Overflow: %s\n", yytext);
		} else {
			printf("Lietral real: %.2f\n", ( atof( str ) * exp ) );	
		}

	} else {
	
	 	printf("Literal real: %f\n", atof( yytext ) );

	}

}

{regex_literal_booleano} {printf("%s - Booleano\n", yytext);}

{regex_literal_caracter} {printf("%s - Caracter\n", yytext);}

{regex_literal_cadena} {printf("%s - String\n", yytext);}


{regex_accion} {printf("%s - Palabra reservada accion detectdada \n", yytext);}

{regex_algoritmo} {printf("%s - Palabra reservada algoritmo detectdada \n", yytext);}

{regex_booleano} {printf("%s - Palabra reservada boolenao detectdada \n", yytext);}

{regex_cadena} {printf("%s - Palabra reservada cadena detectdada \n", yytext);}

{regex_caracter} {printf("%s - Palabra reservada caracter detectdada \n", yytext);}

{regex_const} {printf("%s - Palabra reservada const detectdada \n", yytext);}

{regex_continuar} {printf("%s - Palabra reservada continuar detectdada \n", yytext);}

{regex_de} {printf("%s - Palabra reservada de detectdada \n", yytext);}

{regex_dev} {printf("%s - Palabra reservada dev detectdada \n", yytext);}

{regex_div} {printf("%s - Palabra reservada div detectdada \n", yytext);}

{regex_ent} {printf("%s - Palabra reservada ent detectdada \n", yytext);}

{regex_entero} {printf("%s - Palabra reservada entero detectdada \n", yytext);}

{regex_e_s} {printf("%s - Palabra reservada e/s detectdada \n", yytext);}

{regex_faccion} {printf("%s - Palabra reservada faccion detectdada \n", yytext);}

{regex_falgoritmo} {printf("%s - Palabra reservada falgoritmo detectdada \n", yytext);}

{regex_falso} {printf("%s - Palabra reservada falso detectdada \n", yytext);}

{regex_fconst} {printf("%s - Palabra reservada fconst detectdada \n", yytext);}

{regex_ffuncion} {printf("%s - Palabra reservada ffuncion detectdada \n", yytext);}

{regex_fmientras} {printf("%s - Palabra reservada fmientras detectdada \n", yytext);}

{regex_fpara} {printf("%s - Palabra reservada fpara detectdada \n", yytext);}

{regex_fsi} {printf("%s - Palabra reservada fsi detectdada \n", yytext);}

{regex_ftipo} {printf("%s - Palabra reservada ftipo detectdada \n", yytext);}

{regex_ftupla} {printf("%s - Palabra reservada ftupla detectdada \n", yytext);}

{regex_funcion} {printf("%s - Palabra reservada funcion detectdada \n", yytext);}

{regex_fvar} {printf("%s - Palabra reservada fvar detectdada \n", yytext);}

{regex_hacer} {printf("%s - Palabra reservada hacer detectdada \n", yytext);}

{regex_hasta} {printf("%s - Palabra reservada hasta detectdada \n", yytext);}

{regex_mientras} {printf("%s - Palabra reservada mientras detectdada \n", yytext);}

{regex_mod} {printf("%s - Palabra reservada mod detectdada \n", yytext);}

{regex_no} {printf("%s - Palabra reservada no detectdada \n", yytext);}

{regex_o} {printf("%s - Palabra reservada o detectdada \n", yytext);}

{regex_para} {printf("%s - Palabra reservada para detectdada \n", yytext);}

{regex_real} {printf("%s - Palabra reservada real detectdada \n", yytext);}

{regex_ref} {printf("%s - Palabra reservada ref detectdada \n", yytext);}

{regex_sal} {printf("%s - Palabra reservada sal detectdada \n", yytext);}

{regex_si} {printf("%s - Palabra reservada si detectdada \n", yytext);}

{regex_tabla} {printf("%s - Palabra reservada tabla detectdada \n", yytext);}

{regex_tipo} {printf("%s - Palabra reservada tipo detectdada \n", yytext);}

{regex_tupla} {printf("%s - Palabra reservada tupla detectdada \n", yytext);}

{regex_var} {printf("%s - Palabra reservada var detectdada \n", yytext);}

{regex_verdadero} {printf("%s - Palabra reservada verdadero detectdada \n", yytext);}

{regex_y} {printf("%s - Palabra reservada y detectdada \n", yytext);}



{regex_asignacion} {printf("%s - *Token asignacion(:=) detectdada \n", yytext);}

{regex_comp_seq} {printf("%s - *Token composicion sequencial(;) detectdada \n", yytext);}

{regex_separador} {printf("%s - *Token separador(,) detectdada \n", yytext);}
	
{regex_subrango} {printf("%s - *Token subrango(..) detectdada \n", yytext);}

{regex_def_typevar} {printf("%s - *Token definicion de tipo de variable (:) detectdada \n", yytext);}

{regex_entonces} {printf("%s - *Token entonces (->) detectdada \n", yytext);}

{regex_creacion_tipo} {printf("%s - *Token creacion de tipo (=) detectdada \n", yytext);}

{regex_sinosi} {printf("%s - *Token si no si ([]) detectdada \n", yytext);}

{regex_ini_array} {printf("%s - *Token inicio array ([) detectdada \n", yytext);}

{regex_fin_array} {printf("%s - *Token fin array (]) detectdada \n", yytext);}

{regex_identificador} {printf("%s - Identificador\n", yytext);}


{regex_suma} {printf("Operador Aritmetico de Suma: %s\n", yytext);}

{regex_resta} {printf("Operador Aritmetico de Resta: %s\n", yytext);}

{regex_multiplicacion} {printf("Operador Aritmetico de Multiplicacion: %s\n", yytext);}


{regex_igualdad} {printf("Operador Relacional Igualdad: %s\n", yytext);}

{regex_distinto} {printf("Operador Relacional Distinto: %s\n", yytext);}

{regex_mayor} {printf("Operador Relacional Mayor: %s\n", yytext);}

{regex_menor} {printf("Operador Relacional Menor: %s\n", yytext);}

{regex_mayor_igual} {printf("Operador Relacional Mayor o Igual: %s\n", yytext);}

{regex_menor_igual} {printf("Operador Relacional Menor o Igual: %s\n", yytext);}


\n|. {}

%%

long int checkPowOverflowInt( int a, int b) {

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
}

int yywrap(){}
int main(){

	yylex();

	return 0;
}