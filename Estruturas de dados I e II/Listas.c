#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void testeFilas();
void filaAdd();
void filaRemove();

struct EFila{
	int dados[TAM];
	int first;
	int last;
};

//variaveis goblais
struct EFila fila;

int Listas(){	
	fila.first = 0;
	fila.last = 0;
	testeFilas();
}

void testeFilas(){
		int i;
	
	printf("1 - adiciona dados na fila\n2 - remove dados da fila\n3 - Mostrar fila\n");
	scanf("%i", &i);
	switch(i){
		case 1: filaAdd();
		break;
		case 2: filaRemove();
		break;
		case 3: 
		for(i=0;i != TAM; i++){
			printf("%i\n", fila.dados[i]);
		}
		system("pause");
		system("cls");
		testeFilas();
	}
}
void filaAdd(){
	if(fila.last == TAM){
		printf("A fila está cheia, impossivel adicionar dados");
		system("pause");
		system("cls");
		testeFilas();
	}else{
		printf("qual numero você deseja adicionar?\n");
		scanf("%i", &fila.dados[fila.last]);
		fila.last++;
		system("cls");
		testeFilas();
	}
}
void filaRemove(){
	int i = 0; 
	if(fila.last == 0){
		printf("A fila está vazia, impossivel remover dados");
		system("pause");
		system("cls");
		testeFilas();
	}else{
		for (i = 0; i < fila.last; i++){
			fila.dados[i]=fila.dados[i+1];		
		}
		system("cls");
		testeFilas();
		
	}
}
	
