%{
%} 

cifra [0-9]

letra [A-Za-z]
  
regex_literal_entero [+-]?{cifra}+([e|E]?{cifra}+)?

regex_literal_real [+-]?{cifra}+(\.{cifra}+)?([e|E]?{cifra}+)?

regex_literal_booleano verdadero|falso

regex_literal_caracter \"{letra}\"

regex_literal_cadena \'[^\n|^\']+\'

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
regex_e/s (?i:"e/s")
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


regex_asignacion :=
regex_comp_seq ;
regex_separador ,
regex_subrango ..
regex_def_typevar :
regex_entonces -> 
regex_sinosi []
regex_creacion_tipo =
regex_ini_array [
regex_fin_array ]

regex_comentario "{"[^}\n]"}"














regex_identificador {letra}({letra}|{cifra})*


%%

{regex_literal_entero} {
	printf("%s - Numero entero\n", yytext);
}

{regex_literal_real} {
	printf("%s - Numero real\n", yytext);
}

{regex_literal_booleano} {
	printf("%s - Booleano\n", yytext);
}

{regex_literal_caracter} {
	printf("%s - Caracter\n", yytext);
}

{regex_literal_cadena} {
	printf("%s - String\n", yytext);
}


{regex_accion} {
	printf("%s - sfdsf\n", yytext);
}

{regex_identificador} {
	printf("%s - Identificador\n", yytext);
}


{regex_literal_entero} {
	printf("%s - Numero entero\n", yytext);
}

{regex_literal_real} {
	printf("%s - Numero real\n", yytext);
}

{regex_literal_booleano} {
	printf("%s - Booleano\n", yytext);
}

{regex_literal_caracter} {
	printf("%s - Caracter\n", yytext);
}

{regex_literal_cadena} {
	printf("%s - String\n", yytext);
}


{regex_accion} {
	printf("%s - sfdsf\n", yytext);
}

{regex_identificador} {
	printf("%s - Identificador\n", yytext);
}


{regex_literal_entero} {
	printf("%s - Numero entero\n", yytext);
}

{regex_literal_real} {
	printf("%s - Numero real\n", yytext);
}

{regex_literal_booleano} {
	printf("%s - Booleano\n", yytext);
}

{regex_literal_caracter} {
	printf("%s - Caracter\n", yytext);
}

{regex_literal_cadena} {
	printf("%s - String\n", yytext);
}


{regex_accion} {
	printf("%s - sfdsf\n", yytext);
}

{regex_identificador} {
	printf("%s - Identificador\n", yytext);
}


{regex_literal_entero} {
	printf("%s - Numero entero\n", yytext);
}

{regex_literal_real} {
	printf("%s - Numero real\n", yytext);
}

{regex_literal_booleano} {
	printf("%s - Booleano\n", yytext);
}

{regex_literal_caracter} {
	printf("%s - Caracter\n", yytext);
}

{regex_literal_cadena} {
	printf("%s - String\n", yytext);
}


{regex_accion} {
	printf("%s - sfdsf\n", yytext);
}

{regex_identificador} {
	printf("%s - Identificador\n", yytext);
}

\n|. {} 

%%
  
int yywrap(){} 
int main(){ 
  
  
	yylex(); 
  
	return 0; 
} 


// https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/
// https://github.com/sanved77/flexbison/blob/master/Makefile