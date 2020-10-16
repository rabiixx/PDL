#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	

	char arr[] = "string";

	printf("%s\n", arr);
	printf("sizeof arr: \t %d\n", sizeof(arr));
	printf("typeof\t %d\n", arr[0]);
	printf("typeof\t %d\n", *arr);

	printf("MA arr:\t %p\n", &arr);
	printf("MA 0:\t %p\n", &arr[0]);
	printf("MA 1:\t %p\n", &arr[1]);
	printf("MA 2:\t %p\n", &arr[2]);
	printf("MA 3:\t %p\n", &arr[3]);
	printf("MA 4:\t %p\n", &arr[4]);


	char *x = "hola";
	//x = arr;
	arr = x;
	printf("%s\n", x);
	printf("sizeof arr: \t %d\n", sizeof(x));
	printf("typeof\t %d\n", x[3]);
	printf("typeof\t %d\n", *x);

	



	return 0;
}