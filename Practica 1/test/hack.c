

{regex_entonces} {printf("%s - *Token entonces (->) detectdada \n", yytext);}

{regex_ini_array} {printf("%s - *Token inicio array ([) detectdada \n", yytext);}

{regex_fin_array} {printf("%s - *Token fin array (]) detectdada \n", yytext);}


{regex_asignacion} {printf("%s - *Token asignacion(:=) detectdada \n", yytext);}


{regex_comp_seq} {printf("%s - *Token composicion sequencial(;) detectdada \n", yytext);}

{regex_separador} {printf("%s - *Token separador(,) detectdada \n", yytext);}

{regex_subrango} {printf("%s - *Token subrango(..) detectdada \n", yytext);}

{regex_def_typevar} {printf("%s - *Token definicion de tipo de variable (:) detectdada \n", yytext);}

{regex_sinosi} {printf("%s - *Token si no si ([]) detectdada \n", yytext);}

{regex_creacion_tipo} {printf("%s - *Token creacion de tipo (=) detectdada \n", yytext);}

{regex_identificador} {printf("%s - Identificador\n", yytext);}