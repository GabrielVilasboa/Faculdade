//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//constante
#define GASOLINA_PRECO 6.596

//Variáveis
int destino, origem, vertices = 0;
int destinoA[] = {2,3,4,5,2,5,5};
int origemA[] = {1,1,2,2,3,3,4};
int custo, *custos = NULL; 
int ra[]= {2,1,1,4,8,5,4};


//Prototipação
void dijkstra(int vertices,int origem,int destino,int *custos);
void menu_mostrar(void);
void grafo_procurar(void);
void grafo_criar(void);

//Função principal
int main(int argc, char **argv) {
 	int opt = -1;
 	
 	grafo_criar();
 	grafo_procurar();
 	
 	printf("\nAlgoritmo de Dijkstra finalizado...\n\n");
 	system("pause");
	return 0;
}
//Implementação do algoritmo de Dijkstra
void dijkstra(int vertices,int origem,int destino,int *custos){
	
 	int i, v, cont = 0;
 	int *ant, *tmp; 
 	int *z; /* vertices para os quais se conhece o caminho minimo */
 	double min;
 	double dist[vertices]; /* vetor com os custos dos caminhos */
 	
 	//aloca as linhas da matriz 
 	ant = (int*) calloc (vertices, sizeof(int *));
 	if (ant == NULL) {
 		system("color fc"); 
 		printf ("** Erro: Memoria Insuficiente **");
 		exit(-1);
 	}
 	tmp = (int*) calloc (vertices, sizeof(int *));
 	if (tmp == NULL) {system("color fc"); 
 		printf ("** Erro: Memoria Insuficiente **");
 		exit(-1);
 	} 
 	z = (int *) calloc (vertices, sizeof(int *));
 	if (z == NULL) {
 		system("color fc");
 		printf ("** Erro: Memoria Insuficiente **");
 		exit(-1);
 	}
 	for (i = 0; i < vertices; i++) {
 		if (custos[(origem - 1) * vertices + i] !=- 1) {
 			ant[i] = origem - 1;
 			dist[i] = custos[(origem-1)*vertices+i];
 		}else {
			 ant[i]= -1;
 			dist[i] = HUGE_VAL;
		} 
 		z[i]=0;
 	}	
	 z[origem-1] = 1;
 	dist[origem-1] = 0;
 /* Laco principal */
 	do {
 /* Encontrando o vertice que deve entrar em z */
 		min = HUGE_VAL;
 		for (i=0;i<vertices;i++){
 			if (!z[i]){
 				if (dist[i]>=0 && dist[i]<min) {
 					min=dist[i];v=i;
 				} 
 			}
 		}
 		
 /* Calculando as distancias dos novos vizinhos de z */
 		if (min != HUGE_VAL && v != destino - 1) {
			z[v] = 1;
 			for (i = 0; i < vertices; i++){
 				if (!z[i]) {
 					if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
 						dist[i] = dist[v] + custos[v*vertices+i];
 						ant[i] =v; 
					}
				}
 			}
 		}
 	} while (v != destino - 1 && min != HUGE_VAL);
 	// apresenta na tela todos os destinos com os seus respectivos pesos.
 	printf("\tDe %d para %d: \t", origem, destino);
	 if (min == HUGE_VAL) {
 		printf("Nao Existe\n");
 		printf("\tCusto: \t- \n");
	}else {
 		i = destino;
		i = ant[i-1];
		while (i != -1) {
		 	tmp[cont] = i+1;
		 	cont++;
		 	i = ant[i];
		} 
 		for (i = cont; i > 0 ; i--) {
			printf("%d -> ", tmp[i-1]);
		}
		printf("%d", destino);
		//printa o valor do RA * o preço da gasolina
		printf("\n\tCusto: %.2f\n",dist[destino-1]*GASOLINA_PRECO);
	}
}

void grafo_criar(void){
	int i = 0;
 	vertices = 5;
 	if (!custos) {
 		free(custos);
 	}
 	custos = (int *) malloc(sizeof(int)*vertices*vertices);
 	//Se o compilador falhou em alocar espaço na memória
 	if (custos == NULL) {
 		system("color fc"); 
 		printf ("** Erro: Memoria Insuficiente **");
 		exit(-1);
 } //Preenchendo a matriz com -1
 	for (int j = 0; j <= vertices * vertices; j++){
 		custos[j] = -1; 
 	}
 	do {
 		origem = origemA[i];
		if (origem) {
		 	destino = destinoA[i];
		 	custo = ra[i];
 			custos[(origem-1) * vertices + destino-1] = custo;
 		}
 		i++;
 	} while (origem);
}
void grafo_procurar(void){
	int i, j;
	system("cls");
 	printf("Lista dos Menores Caminhos no Grafo Dado: \n");
	for (i = 1; i <= vertices; i++) {
 		for (j = 1; j <= vertices; j++) {
 			dijkstra(vertices, i,j, custos);
		} 
	 printf("\n");
 	}
 	system("pause");
}



