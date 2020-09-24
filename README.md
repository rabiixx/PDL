# PDL
Procesadores del Lenguaje


## Compilation

* Default Compilation
```bash
	make
```

* Clean files
```bash
	make clean
``` 

## Usage
./scanner < programaX.alg


## Explicacion

Los literales enteros y reales son tratados como enteros y double en C.
Si el literal entero o real viene dado en notacion E (2e3 / 2.3e5) se transforma a notacion normal.

Al leer 2e4 el escaner mostrara (literal_entero, 20.000).
Si al transformar el valor dado en notacion E a notacion normal se produce un desbordamiento (Overflow)
el programa lanzara un aviso.


## Dependencies
Para asegurar el correcto funcionamiento debe tener instaldas las siguientes librerias estandares de C:
* <limits.h>: La libreria contiene MACROS (INT_MAX) que son utilizadas para evitar desbordamientos en numero enteros.
* <float.h>: La libreria contiene MACROS (DBL_MAX) que son utilizadas para evitar desbordamientos en numero reales.
* <string.h>: Contien funciones muy utiles para la manipualcion de cadenas de caracteres.
* <math.h>: Se utiliza para facilitar operaciones matematicas.