#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
int vereadores(int votoV){
	int num;
	switch(votoV) {
		case 111:
			system("cls");
			printf("Voc� votou no Vereador Jo�o do Frete.\n");
			return 1;
			break;
		case 222:
			system("cls");
			printf("Voc� votou no Vereador Maria da Pamonha. \n");
			return 2;
			break;
		case 333:
			system("cls");
			printf("Voc� votou no Vereador Z� da Farmacia. \n");
			return 3;
			break;
		case 444:
			system("cls");
			printf("Voc� votou Nulo. \n");	
			return 4;
			break;
		default:
			system("cls");
			printf("voto invalido \n");		
			system("pause");
			system("cls");
			printf("digite o numero do vereador em qual deseja votar. \n");
			scanf("%d", &num);
			fflush(stdin);
			system("cls");
			vereadores(num);
			break;
	}
}
int prefeito(int votoP){
	int numP;
	switch(votoP){
		case 11:
			system("cls");
			printf("Voc� votou no Prefeito Dr. Zureta. \n");
			return 1;
			break;
		case 22:
			system("cls");
			printf("Voc� votou no prefeito Sr. Gomes. \n");
			return 2;
			break;
		case 44:
			printf("voc� votou nulo. \n");
			return 4;
			break;
		default:
			system("cls");
			printf("voto invalido \n");		
			system("pause");
			system("cls");
			printf("digite o numero do prefeito em qual deseja votar. \n");
			scanf("%d", &numP);
			fflush(stdin);
			system("cls");
			prefeito(numP);	
			break;
	}		
	
}
int main(){
	int votoVe, numv, numPe, votoPe, menu, Jfrete, Mpam, Zfarm, vnulo;
	int Dzureta, Sgomes, pnulo, i;
	Jfrete=0;
	Mpam=0;
	Zfarm=0;
	vnulo;
	Dzureta=0;
	Sgomes=0;
	pnulo=0;
	while(i!=3){
		setlocale(LC_ALL, "Portuguese");
		printf("Progama Eleitoral \n");
		printf("1-votar\n2-Apura��o\n3-sair \n");
		scanf("%d", &menu);
		fflush(stdin);
		switch(menu){
			case 1:
				system("cls");
				printf("Vota��o para Vereador \n");
				printf("digite o numero do vereador em qual deseja votar. \n");
				scanf("%d", &numv);
				fflush(stdin);
				votoVe=vereadores(numv);
				system("pause");
				system("cls");
				switch(votoVe){
					case 1:
						Jfrete++;
						break;
					case 2:
						Mpam++;
						break;
					case 3:
						Zfarm++;
						break;
					default:
						vnulo++;
						break;	
				}
				printf("Vota��o para Prefeito.\n");
				printf("digite o numero do prefeito em qual deseja votar. \n");
				scanf("%d", &numPe);
				fflush(stdin);
				votoPe=prefeito(numPe);
				system("pause");
				system("cls");
				switch(votoPe){
				case 1:
					Dzureta++;
					break;
				case 2:
					Sgomes++;
					break;
				default:
					pnulo++;
					break;
	     	}
				break;
	   		case 2:
				system("cls");
				printf("Apura��o de votos. \nVereadores:\n");
				printf(" Jo�o do frete - %d Votos\n Maria da pamonha - %d Votos\n", Jfrete, Mpam, Zfarm);
				printf(" Z� da farmacia - %d Votos/n Nulo - %d Votos\n\n",Zfarm, vnulo);
				printf("Prefeitos:\n");
				printf(" Dr.Zureta - %d Votos\n Sr.Gomes - %d Votos\n Nulo - %d Votos\n",Dzureta,Sgomes,pnulo);
				system("pause");
				system("cls");
				break;
			case 3:
				i=3;
				break;	
			default:
				system("cls");
				printf("N�mero invalido\n");
				system("pause");
				system("cls");
				break;
		}
	}	
} 

	
	
	
