#include <stdio.h>
#include <stdlib.h>

void DinamicAlocation(){

	int *ptr;
	
	ptr = (int *)malloc(sizeof(int));
	*ptr = 4;
	
	printf("O valor de ptr é: %i \nO endereço de ptr é: %p\n", *ptr, ptr);
	
	free(ptr);	
}
