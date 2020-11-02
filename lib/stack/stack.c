#include "stack.h"

void nuevaPila(Stack **p){
	*p = NULL;
}

void errorPila(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
}

void apilar(Stack **p, char* elemento){
	Stack *nuevo;
	nuevo = (Stack*) malloc( sizeof( Stack ) );
	nuevo->elem = elemento;
	nuevo->sig = *p;
	*p = nuevo;
}

void desapilar(Stack **p){

	if ( esNulaPila( *p ) )
	{
		errorPila("No se puede desapilar en una pila vacia.");
	}
	else
	{
		Stack *aux;
		aux = *p;
		*p = (*p)->sig;
		
		free( aux );
	}
}

char *cima(Stack *p){
	
	if ( esNulaPila( p ) )
		errorPila("No se puede obtener la cima en una pila vacia.");
	else
		return p->elem;

}

bool esNulaPila(Stack *p){
	return p == NULL;
}

