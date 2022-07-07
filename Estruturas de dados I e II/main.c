#include <stdio.h>
#include <stdlib.h>

#define PONTO '.'
#define TAM 15

void inicializaCampo(char matrizCampo[TAM][TAM], int* x, int* y);
void imprimeMatrizCampo(char matrizCampo[TAM][TAM]);
void LevanteEAndas(char matrizCampo[TAM][TAM], int *x, int *y);


int main() {
	
	int x;
	int y;
	
	
	char matrizCampo[TAM][TAM];
	
	inicializaCampo(matrizCampo, &x, &y);
	LevanteEAndas(matrizCampo, &x, &y);
	
}

void inicializaCampo(char matrizCampo[TAM][TAM], int* x, int* y){
	int i, j;
	
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
		matrizCampo[i][j] = ' ';
		}
	}
	
	*x = 0;
	*y = 0;
	
	matrizCampo[*x][*y] = PONTO;
	
	imprimeMatrizCampo(matrizCampo);
	
}

void imprimeMatrizCampo(char matrizCampo[TAM][TAM]){
	
	int i, j;
	
	system("cls");
	
	for(i = 0; i < TAM; i++){
		printf("\n");
		for(j = 0; j < TAM; j++){
			printf("%c", matrizCampo[i][j]);
			
			
		}
	}	
}

void LevanteEAndas(char matrizCampo[TAM][TAM], int *x, int *y){
		
	char op;
	
	scanf("%c", &op);
	fflush(stdin);
	
	switch (op){
		
		case 'd':
			
			if(matrizCampo[*x+1][*y] == ' '){
				matrizCampo[*x+1][*y] = PONTO;
				matrizCampo[*x][*y] = ' ';
				*x++;
				imprimeMatrizCampo(matrizCampo);
				LevanteEAndas(matrizCampo, &x, &y);
			}
			imprimeMatrizCampo(matrizCampo);
			LevanteEAndas(matrizCampo, &x, &y);
			break;
		case 'e':
			
			if(matrizCampo[*x-1][*y] == ' '){
				matrizCampo[*x-1][*y] = PONTO;
				matrizCampo[*x][*y] = ' ';
				*x--;
				imprimeMatrizCampo(matrizCampo);
				LevanteEAndas(matrizCampo, &x, &y);
			}
			imprimeMatrizCampo(matrizCampo);
			LevanteEAndas(matrizCampo, &x, &y);
			break;
			
		case 'w':
			
			if(matrizCampo[*x][*y+1] == ' '){
				matrizCampo[*x][*y+1] = PONTO;
				matrizCampo[*x][*y] = ' ';
				*y++;
				imprimeMatrizCampo(matrizCampo);
				LevanteEAndas(matrizCampo, &x, &y);
			}
			imprimeMatrizCampo(matrizCampo);
			LevanteEAndas(matrizCampo, &x, &y);
			break;
		case 's':
			
			if(matrizCampo[*x][*y-1] == ' '){
				matrizCampo[*x][*y-1] = PONTO;
				matrizCampo[*x][*y] = ' ';
				*y--;
				imprimeMatrizCampo(matrizCampo);	
				LevanteEAndas(matrizCampo, &x, &y);
			}
			imprimeMatrizCampo(matrizCampo);
			LevanteEAndas(matrizCampo, &x, &y);
			break;
			
		default:
			imprimeMatrizCampo(matrizCampo);
			LevanteEAndas(matrizCampo, &x, &y);
		break;
	}
}



