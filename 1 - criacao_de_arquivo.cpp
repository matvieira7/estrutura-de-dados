#include<stdio.h>
#include<stdlib.h>
main(){
/*
FILE:
É um tipo de dados definido pela biblioteca padrão do C (stdio.h), que representa um 
arquivo no sistema. Internamente, FILE contém informações sobre o estado do arquivo, 
como por exemplo o modo de abertura (leitura ou escrita).
*/
/*	
*arquivo:
Isso é um ponteiro que aponta para uma estrutura do tipo FILE;
Precisamos de um ponteiro para manipular um arquivo do sistema; 
O ponteiro arquivo será usado em funções como fopen() e fclose().
*/
	FILE *arquivo; //declaração do ponteiro arquivo	
	//abre o arquivo com permissão para escrita
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
