#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main ( void )
{

	time_t rawtime;
	struct tm *timeinfo;

	time( &rawtime );
	timeinfo = localtime( &rawtime );


	char buffer[80];
   	strftime(buffer, 80, "%X", timeinfo);
   	printf("Formatted time : %s\n", buffer );

	char *p;
	while ( p = strchr(buffer, ':' ) ) {
		*p = '_';
	}


	char name[20] = "_tmp_";

	strcat(name, buffer);

	printf("name: %s\n", name);





	return 0;
}
