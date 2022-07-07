#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void testePilhas();
void pilhaAdd();
void pilhaRemove();

struct EPilha{
	
	int dados[TAM];
	int first;
	int last;
	
};

struct EPilha pilha;

void Pilhas(){
	pilha.first = 0;
	pilha.last = 0;
	testePilhas();
}

void testePilhas(){
	
	int i;
	
	printf("1 - adiciona dados na pilha\n2 - remove dados da pilha\n3 - Mostrar pilha\n");
	scanf("%i", &i);
	switch(i){
		case 1: pilhaAdd();
		break;
		case 2: pilhaRemove();
		break;
		case 3: 
		for(i=0;i != TAM; i++){
			printf("%i\n", pilha.dados[i]);
		}
		system("pause");
		system("cls");
		testePilhas();
	}	
}

void pilhaAdd(){
	if (pilha.last == TAM){
		printf("Está pilha está cheia");
		system("pause");
		system("cls");
		testePilhas();
	} else {
		printf("adicione um numero na pilha\n");
		scanf("%i", &pilha.dados[pilha.last]);
		pilha.last++;
		system("cls");
		testePilhas();
	}
}

void pilhaRemove(){
	if (pilha.last == pilha.first){
		printf("a pilha está vazia");
		system("pause");
		system("cls");
		testePilhas();
	}else{
		pilha.dados[pilha.last-1] = 0;
		pilha.last--;
		system("cls");
		testePilhas();
	}
}