#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int dado;
	struct lista* prox;
}no;

void inserir(int x,  no *p){
	no *novo;
	novo = malloc(sizeof(no));
	novo->dado = x;
	novo->prox = p->prox;
	p->prox = novo;
}

void excluir(no *p){
	no *lixo;
	lixo = p->prox;
	p->prox = lixo->prox;
	free(lixo);
}

void imprimir(no *le){
	no *p;
	for(p = le; p != NULL; p = p->prox){
		printf("%d\n", p->dado);
	}
}

int ListasDinamicas(){
	
	int valor = 6;
	int i;
	no *le;
	le = malloc(sizeof(no));
	le->prox = NULL;
	
	for(i = 0;i <= 20; i++){
		inserir(valor*i, le);
	}
	
	imprimir(le);
	system("pause");
	system("cls");
	excluir(le);
	imprimir(le);
	
}