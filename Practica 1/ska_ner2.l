// Un ejemplo del uso de la clase analizador en C++ de flex.

%{
int mylineno = 0;
%}
/*


ws      [ \t]+

letra   [A-Za-z]

/* Cualquier numero entre 0 y 9 */
cifra     [0-9]

regex_identificador    {letra}({letra}|{cifra}|[_.\-/$])*

regex_literal_entero [+-]?{cifra}+([e|E]?{cifra}+)?
regex_literal_real [+-]?{cifra}+(\.{cifra}+)?([e|E]?{cifra}+)?
regex_literal_booleano verdadero|falso
regex_literal_caracter "{letra}"
regex_literal_cadena \'[^\n|^\']+\'

/** 
  *  Un numero con simbolo o no, 
  *  Numero decimal o no
  *  Exponente o no
  *  Exponenete con simbolo o no 
  */

num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?

/**  
  * num1 pero no es necesario la parte 
  *  entera en caso de ser un numero decimal entre 
  */
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?

sl \n

%%

{ws}    /* evita los espacios en blanco y tabuladores */

"/*"    {
        int c;

        while((c = yyinput()) != 0)
            {
            if(c == '\n')
                ++mylineno;

            else if(c == '*')
                {
                if((c = yyinput()) == '/')
                    break;
                else
                    unput(c);
                }
            }
        }

{number}  cout << "número " << YYText() << '\n';

{sl}        mylineno++;

{name}    cout << "nombre " << YYText() << '\n';

{string}  cout << "cadena " << YYText() << '\n';

%%

int main( int /* argc */, char** /* argv */ )
    {
    FlexLexer* lexer = new yyFlexLexer;
    while(lexer->yylex() != 0)
        ;
    return 0;
    }