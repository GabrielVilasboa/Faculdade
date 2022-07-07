#include <stdio.h>
#include <stdlib.h>

void Pointers(){
	//Um ponteiro armazena o endereço de uma variavel
	int num;
	int *ptrNum;
	
	ptrNum = &num;
	*ptrNum = 4;
	printf("O valor de num é: %i \nO endereço de num é: %p", num, ptrNum);
}