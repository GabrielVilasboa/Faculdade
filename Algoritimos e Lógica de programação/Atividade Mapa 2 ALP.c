#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char rInvalida();
void
 quest(char pergunta[200], int pont, int *pacientePont);

struct registro{
	char nome[100];
	char cpf[20];
	char sexo;
	short idade;
	int pontos;
};


int main() {
	//declara��o de variaveis 
	struct registro paciente;
	int c, tam, controleIdade = 1;
	FILE *arq;
	
	setlocale(LC_ALL, "Portuguese");
	
	//Registro

	printf("\tProgama de triagem\n");
	//Nome
	printf("Digite seu nome completo:\n");
	gets(paciente.nome);
	fflush(stdin);
	//CPF
	printf("Digite o seu cpf:\n");
	scanf("%s", &paciente.cpf);
	fflush(stdin);
	//idade
	while(controleIdade == 1){
		printf("Digite sua idade:\n");
		scanf("%i", &paciente.idade);
		fflush(stdin);
		if(paciente.idade < 0){
			printf("idade invalida, tente novamente \n");
		}else controleIdade = 0;
	}
	//Sexo
	printf("Digite seu sexo\nM-Masculino\nF-feminino\n");
	do{
		scanf("%c", &paciente.sexo);
		fflush(stdin);
		if(paciente.sexo != 'm' && paciente.sexo != 'M' && paciente.sexo != 'F' && paciente.sexo != 'f'){
		printf("Sexo invalido. tente novamente:\t");
		}
	}while(paciente.sexo != 'm' && paciente.sexo != 'M' && paciente.sexo != 'F' && paciente.sexo != 'f');
		
	//questionario
	
	system("cls");
	printf("\tQuestionario de sintomas.\n");
	
	quest("Tem febre? S para sim e N para n�o.", 5, &paciente.pontos);
	quest("Tem dor de cabe�a? S para sim e N para n�o.", 1, &paciente.pontos);
	quest("Tem secre��o nasal ou espirros? S para sim e N para n�o.", 1, &paciente.pontos);
	quest("Tem dor/irrita��o na garganta? S para sim e N para n�o.", 1, &paciente.pontos);
	quest("Tem tosse seca? S para sim e N para n�o.", 3 , &paciente.pontos);
	quest("Tem dificuldade respirat�ria? S para sim e N para n�o.", 10, &paciente.pontos);
	quest("Tem dores no corpo? S para sim e N para n�o.", 1, &paciente.pontos);
	quest("Tem diarr�ia? S para sim e N para n�o.", 1, &paciente.pontos);
	quest("Esteve em contato, nos �ltimos 14 dias, com um caso diagnosticado com COVID-19? S para sim e N para n�o.", 10, &paciente.pontos);
	quest("Esteve em locais com grande aglomera��o? S para sim e N para n�o", 3, &paciente.pontos);

	if(paciente.pontos <= 9){
		printf("\nSe dirija a Ala de Risco Baixo.\n");
	}
	else{
		if(paciente.pontos <= 19){
			printf("\nSe dirija a Ala de Risco M�dio.\n");
		}
		else printf("\nSe dirija a Ala de Risco Alto\n");
	}
	
	//Salvando arquivo
	arq = fopen("Paciente.txt", "a");
	fprintf(arq, " Nome: %s \n Cpf: %s \n Idade: %i \n Pontua��o %i", paciente.nome, paciente.cpf, paciente.idade, paciente.pontos);
	fprintf(arq, "\n_________________________________________________\n");
	
	return 0;
}

char rInvalida(){
	char x;
	printf("\n");
	scanf("%c", &x);
	fflush(stdin);
	if(x != 's' && x != 'S' && x != 'n' && x!='N'){
		printf("resposta invalida, tente novamente.");
		x = rInvalida();
		return x;

	}
	else return x;
}
//fun��o para facilitar os questionario
void quest(char pergunta[200], int pont, int *pacientePont){
	char x;
	printf("%s", pergunta);
	x = rInvalida();
	if (x == 's' || x == 'S'){
		*pacientePont = *pacientePont + pont;
	}
}
