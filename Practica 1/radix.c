#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int edad;
int resPcr;

int main(int argc, char const *argv[])
{
	

	printf("Indique la edad\n");
	scanf("%d", &edad);

	printf("Indique resultado de la PCR\n
			1 - Positivo
			2 - Negativo");
	
	scanf("%d", &resPcr)
	--resPcr;

	if ( resPcr )
	{
		printf("Muy chavalin\n");	
	} else {
		printf("Among Us\n");
	}

	return 0;
}




/* fin fichero cmd ctrl-e*/