#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
  
typedef struct _stack{
    char* elem;
    struct _stack *sig;
} Stack; 

void nuevaPila(Stack **);

void apilar(Stack** , char *);

void desapilar(Stack **);

char *cima(Stack *);

bool esNulaPila(Stack *);

#endif