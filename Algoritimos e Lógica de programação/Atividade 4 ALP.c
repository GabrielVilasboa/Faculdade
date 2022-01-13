#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int main(){
	int x, i, j;
	int cartela[10];
	
	void clear();
	void criar(int ca[10]);
	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
	
	printf("Digite o numero de cartelas\n");
	scanf("%i", &x);
	clear();
	
	j = 0;
	do{
		j++;
		criar(cartela);
		
		for(i = 0; i < 10; i++){
			if(i == 0){
				printf("\nCartela de numero %i:\n%i ", j, cartela[i]);
			}
			else{
				printf("%i ", cartela[i]);
			}	
		}
		printf("\n");
	}while(j < x);
return 0;
}//fim_main	

void clear(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void conferir(int co[10]){
	int i, j;
	for(i = 0; i < 10; i++){
	 for(j= 0; j<10; j++){
			if(j != i){
				if(co[j] == co[i]){
					co[j] = rand()%99;
					conferir(co);
				}
			}
		}
	}
}

void criar(int ca[10]){
	int i;
	void conferir(int co[10]);
	for(i = 0; i < 10; i++) ca[i] = rand()%99;
	conferir(ca);
}
