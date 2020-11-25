algoritmo intercambio;
	ent a, b: entero;
	sal a, b: entero;
{Prec: a= A AND b = B}
	const
                c = 1;
                d = 2;
        fconst
	var
                aux, aux2: entero;
                j : real;
        fvar

	aux:= a;
	a:= b;
	b:= aux;
{Post: b=A AND a = B}
falgoritmo
