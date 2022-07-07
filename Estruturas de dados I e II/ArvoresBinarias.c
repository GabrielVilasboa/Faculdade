#include <stdio.h>
#include <stdlib.h>

//definindo Nó

typedef struct arvore{
	
	int dado;
	int visitado;
	
	struct arvore* verticeDireita;
	struct arvore* verticeEsquerda;
	
}no;



int adicionarDado(no *raiz, int valor);
void buscarDado(no *raiz);
void menu(no *raiz, int valor);

int arvoreUm(){
	
	int valor;
	no *raiz;
	
	raiz = (no*)malloc(sizeof(no));
	
	raiz->dado = 0;
	raiz->visitado = 0;

	menu(raiz, valor);
}


int adicionarDado(no *raiz, int valor){
	
	no* novo;
	printf("Entrou na função\n");
	
	if(raiz->dado == 0){
		raiz->dado = valor;
		printf("valor igual a 0, já foi adicionado : )\n");
		system("pause");
	}else{
		if(valor >= raiz->dado){
			novo = (no*)malloc(sizeof (no));
			raiz = novo->verticeDireita;
			raiz->dado = 0;
			printf("valor maior do que a raiz, vamos pra direita raiz->dado = %d\n", raiz->dado);
			adicionarDado(raiz, valor);
		}else{
			novo = (no*)malloc(sizeof (no));
			raiz = novo->verticeEsquerda;
			raiz->dado = 0;
			printf("valor menor do que a raiz, vamos pra esquerda raiz->dado = %d\n", raiz->dado);
			adicionarDado(raiz, valor);
		}	
	}
}

void menua(no *raiz, int valor){
	
	int op;
	
	system("cls");
	printf("Escolha uma opção:\n");
	printf("1 - criar novo dado\n");
	scanf("%d", &op);
	
	switch(op){
		case 1 : 
			printf("Digite o valor que será salvo\n");
			scanf("%d", &valor);
			adicionarDado(raiz, valor);
			menu(raiz, valor);
		break;
		
	}
	
}