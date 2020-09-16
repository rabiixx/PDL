%{
%} 

cifra [0-9]

letra [A-Za-z]
  
regex_literal_entero [+-]?{cifra}+([e|E]?{cifra}+)?

regex_literal_real [+-]?{cifra}+(\.{cifra}+)?([e|E]?{cifra}+)?

regex_literal_booleano verdadero|falso

regex_literal_caracter \"{letra}\"

regex_literal_cadena \'[^\n|^\']+\'

regex_identificador {letra}({letra}|{cifra})*

regex_comentario \{([^}]|[])\}

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