#include<stdio.h>
#include<stdlib.h>
main(){
/*
FILE:
� um tipo de dados definido pela biblioteca padr�o do C (stdio.h), que representa um 
arquivo no sistema. Internamente, FILE cont�m informa��es sobre o estado do arquivo, 
como por exemplo o modo de abertura (leitura ou escrita).
*/
/*	
*arquivo:
Isso � um ponteiro que aponta para uma estrutura do tipo FILE;
Precisamos de um ponteiro para manipular um arquivo do sistema; 
O ponteiro arquivo ser� usado em fun��es como fopen() e fclose().
*/
	FILE *arquivo; //declara��o do ponteiro arquivo	
	//abre o arquivo com permiss�o para escrita
	arquivo = fopen("teste.txt","w");
	//verifica se houve erro ao abrir o arquivo
	if(arquivo == NULL){
		printf("Houve um erro ao abrir o arquivo.\n");
	}else{
		printf("Arquivo teste.txt criado com sucesso!\n");
	}
	//fecha o arquivo
	fclose(arquivo);
}
