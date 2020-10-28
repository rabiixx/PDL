#ifndef STACK_H
#define STACK_H

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