#include <stdio.h>
#include <stdlib.h>

#define TAM 9

//definindo Nó
typedef struct{
	
	int dado;
	
	int pai;
	int verticeDireita;
	int verticeEsquerda;
	
}no;

void adiciona_parentesco( no arvore[]);
void inicializa_arvore(int ra[], no arvore[]);
void pre_ordem(no arvore[], int indice);
	
int main(){
	int i = 0;
	int ra[] = {2,1,1,4,8,5,4,1,5};
	no arvore[TAM];
	
	printf("O R.A é :\n21148541-5\n");
	
	printf("O ra colocado na Arvore e exibido em preOrdem:\n");
	
	inicializa_arvore(ra, arvore);
	adiciona_parentesco(arvore);
	pre_ordem(arvore, i);
	
}

void inicializa_arvore(int ra[] ,no arvore[]){
	
	for(int i = 0; i < TAM; i++){
		arvore[i].dado = ra[i];
		arvore[i].pai = -1;
		arvore[i].verticeDireita = -1;
		arvore[i].verticeEsquerda = -1;
	}
	
}

void adiciona_parentesco(no arvore[]){
	
	arvore[0].verticeDireita = 3;
	arvore[0].verticeEsquerda = 1;
	arvore[1].verticeDireita = 2;
	arvore[1].pai = 0;
	arvore[2].verticeDireita = 7;
	arvore[2].pai = 1;
	arvore[3].verticeDireita = 4;
	arvore[3].pai = 0;
	arvore[4].verticeEsquerda = 5;
	arvore[4].pai = 3;
	arvore[5].verticeDireita = 8;
	arvore[5].verticeEsquerda = 6;
	arvore[5].pai = 4;
	arvore[6].pai = 5;
	arvore[7].pai = 2;
	arvore[8].pai = 5;
}

void pre_ordem(no arvore[],int indice){
	
	if(indice != -1){
		printf("%d", arvore[indice].dado);
		pre_ordem(arvore, arvore[indice].verticeEsquerda);
		pre_ordem(arvore, arvore[indice].verticeDireita);
	}
}
	
	
