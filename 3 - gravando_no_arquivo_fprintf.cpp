#include<stdio.h>
#include<stdlib.h>

main(){
	FILE *arquivo; //declaração do ponteiro arquivo
	char frase[100];
		
	arquivo = fopen("teste.txt", "a");
	
	//verifica se houve erro ao abrir o arquivo
	if(arquivo == NULL){
		printf("Houve um erro ao abrir o arquivo.\n");
	}
	
	printf("Entre com a frase a ser gravada no arquivo: ");
	fflush(stdin);
	gets(frase);
	
	/*Grava a frase usando o fprintf*/
	fprintf(arquivo, "%s", frase);
	
	fprintf(arquivo, "\n");
	
	fclose(arquivo);
}

