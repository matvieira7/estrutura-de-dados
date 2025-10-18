#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivo;
	char CPF[14], nome[50], telefone[15], resp;
	int i;
	
	 do{
	/*
	a = Abre o arquivo para escrita no final do arquivo. Não apaga o 
	conteúdo pré-existente. (O "a" vem do inglês append: acrescentar)
	*/
	arquivo = fopen("clientes.txt", "a");
	
	//verifica se houve erro ao abrir o arquivo
	if(arquivo == NULL){
		printf("Houve um erro ao abrir o arquivo.\n");
	}else{
	  system("cls");
	  printf("Cadastro de Clientes\n");
	
	  printf("\nCPF - Modelo: 332.569.963-51: ");
	  fflush(stdin);
	  gets(CPF);
	
      printf("\nNome Completo: ");
	  fflush(stdin);
	  gets(nome);
	
	  printf("\nTelefone - Modelo: (19)99245-8503: ");
	  fflush(stdin);
	  gets(telefone);
	
	  /*Grava o CPF através do fprintf*/	  
	  fprintf(arquivo, "%s\t", CPF);// \t - Coloca tab no arquivo
	
	  /*Grava o telefone através do fprintf*/	  
	  fprintf(arquivo, "%s\t", telefone);// \t - Coloca tab no arquivo
	
	  /*Grava o nome através do fprintf*/	  
	  fprintf(arquivo, "%s\n", nome);
	  
	  /*Laço para validar a resposta do usuário, permitindo apenas 's' ou 'n'*/
	  do{
	    printf("\nDeseja cadastrar outro cliente: ");
	    fflush(stdin);
	    scanf("%c", &resp);
	  }while(resp != 's' && resp != 'S' && resp != 'n' && resp != 'N');
		
	  fclose(arquivo);
	  
  	}/*Essa chave fecha a chave do else*/
  	
	}while(resp == 's');
}
