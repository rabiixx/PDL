%{
%}


regex_subrange \.\.
regex_space (" ")*
%%


{regex_subrange} {
	printf("%s Entonces detected\n", yytext);
}


{regex_space} {
	printf("* Space detected\n");
}
%%

int yywrap(){}
int main(){

	yylex();

	return 0;
}