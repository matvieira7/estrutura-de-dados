#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
main(){
	char linha[100];
	FILE *arquivo = fopen("clientes.txt", "r");
    
	if (arquivo == NULL) {
      printf("Erro ao abrir arquivo.\n");
      exit(0);
    }
	
    printf("Dados cadastrados:\n");
    
	/*
    A função fgets lê o arquivo e armazena na variável linha a linha armazenada;
    
    Ao chamar a função, devemos fornecer a string onde os dados lidos devem 
	ser guardados, o tamanho máximo dos dados a serem lidos e o ponteiro para o 
	arquivo onde contém os dados. 
    */
    
   	while (fgets(linha, 100, arquivo)) {
    	printf("%s", linha);
	}
    fclose(arquivo);
}
