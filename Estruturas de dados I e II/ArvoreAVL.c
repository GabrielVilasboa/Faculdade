#include <stdio.h>
#include <stdlib.h>

//definindo Nó

typedef struct arvore{
	
	int dado;
	int visitado;
	int altura;
	
	struct arvore* pai;
	struct arvore* verticeDireita;
	struct arvore* verticeEsquerda;
	
}no;

void menu(no* raiz);
void adicionarNo(no* raiz, int valor);
void imprimirArvore(no* raiz);

int main(){
	
	no* raiz;
	
	raiz = (no*)malloc(sizeof(no));
	
	raiz->pai = NULL;
	raiz->verticeDireita = NULL;
	raiz->verticeEsquerda = NULL;
	raiz->dado = 0;
	raiz->altura = 0;
	
	
	menu(raiz);
	
	return 0;
}

void menu(no* raiz){
	
	int op;
	int valor;
	
	printf("o que você deseja fazer?\n");
	printf("1 - Adicionar um novo dado a arvore\n");
	printf("2 - Imprimir a arvore\n\n");
	
	scanf("%i", &op);
	
	switch(op){
		case 1:
			system("cls");
			printf("Qual valor ira ser adicionado?");
			scanf("%i", &valor);
			adicionarNo(raiz,valor);
			menu(raiz);
			break;
		case 2: 
			system("cls");
			imprimirArvore(raiz);
			menu(raiz);
			break;
	}
}

void adicionarNo(no* raiz, int valor){
	
	no* novo;
	
	if(raiz->dado == 0){
		raiz->dado = valor;
	}else{
		//lado direito maior que raiz
		if (valor >= raiz->dado){
			if(raiz->verticeDireita != NULL){
				raiz = raiz->verticeDireita;
				adicionarNo(raiz,valor);
				raiz = raiz->pai;
			}else{		
			novo = (no*)malloc(sizeof(no));
			novo->pai = raiz;
			novo->verticeDireita = NULL;
			novo->verticeEsquerda = NULL;
			novo->dado = valor;	
			
			raiz->verticeDireita = novo;
	
			}
		}else{
			//lado esquerdo menor que raiz
			if(valor < raiz->dado){
				if(raiz->verticeEsquerda != NULL){
					raiz = raiz->verticeEsquerda;
					adicionarNo(raiz,valor);
					raiz = raiz->pai;
				}else{
	
					novo = (no*)malloc(sizeof(no));
					novo->pai = raiz;
					novo->verticeDireita = NULL;
					novo->verticeEsquerda = NULL;
					novo->dado = valor;	
			
					raiz->verticeEsquerda = novo;
					
				}
			}
		}
		
	}
	
}

void imprimirArvore(no* raiz){
	
	if(raiz){
		printf("%d \t", raiz->dado);
		imprimirArvore(raiz->verticeEsquerda);
		imprimirArvore(raiz->verticeDireita);
		
		
	}
	
}



	
