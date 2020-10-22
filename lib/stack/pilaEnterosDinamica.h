/*
  FICHERO: pilaEnterosDinamica.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include <stdbool.h>
  
typedef struct Stack{
    char* elem;
    struct celdaP *sig;
} Stack; 

void nuevaPila(tipoPila *);

void apilar(tipoPila* , char *);

void desapilar(tipoPila *);

tipoElementoPila cima(tipoPila);

bool esNulaPila(tipoPila);

