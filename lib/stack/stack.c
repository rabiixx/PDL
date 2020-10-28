/*
  FICHERO: pilaEnterosDinamica.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void nuevaPila(Stack **p){
	*p=NULL;
}

void errorPila(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
}

void apilar(Stack **p, char* elemento){
	celdaPila *nuevo;
	nuevo=(celdaPila*)malloc(sizeof(celdaPila));
	nuevo->elem=elemento;
	nuevo->sig = *p;
	*p = nuevo;
}

void desapilar(Stack **p){
	if (esNulaPila(*p))
		errorPila("No se puede desapilar en una pila vacia.");
	else{
		celdaPila *aux;
		aux=*p;
		*p=(*p)->sig;
		free(aux);
	}
}

char *cima(Stack *p){
	if (esNulaPila(p))
		errorPila("No se puede obtener la cima en una pila vacia.");
	else
		return p->elem;
}

bool esNulaPila(Stack *p){
	return p==NULL;
}

