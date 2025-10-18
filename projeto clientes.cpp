#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivo, *temp;
	char CPF[14], nome[50], telefone[15];
	char cpfBusca[14];
	char linha[200];
	int opcao, encontrado;
	char resp;
	
	do{
		system("cls");
		printf("=== Sistema de Clientes ===\n");
		printf("1 - Cadastrar cliente\n");
		printf("2 - Mostrar todos os clientes\n");
		printf("3 - Atualizar dados de um cliente\n");
		printf("4 - Excluir cliente\n");
		printf("5 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		getchar();

		
		switch(opcao){
			
			// 1 - Cadastrar cliente
			case 1:
				do{
					arquivo = fopen("clientes.txt", "a");
					
					if(arquivo == NULL){
						printf("Erro ao abrir o arquivo.\n");
						exit(0);
					}
					
					system("cls");
					printf("=== Cadastro de Cliente ===\n");
					
					printf("\nCPF (Modelo: 332.569.963-51): ");
					fflush(stdin);
					gets(CPF);
					
					printf("Nome Completo: ");
					fflush(stdin);
					gets(nome);
					
					printf("Telefone (Modelo: (19)99245-8503): ");
					fflush(stdin);
					gets(telefone);
					
					fprintf(arquivo, "%s\t%s\t%s\n", CPF, telefone, nome);
					fclose(arquivo);
										
					do{
					    printf("\nDeseja cadastrar outro cliente (s/n)? ");
					    fflush(stdin);
					    resp = getchar();
					}while(resp != 's' && resp != 'S' && resp != 'n' && resp != 'N');

					
				}while(resp == 's' || resp == 'S');
			break;
			
			
			// 2 - Mostrar todos os clientes
			case 2:
				system("cls");
				printf("=== Lista de Clientes ===\n\n");
				
				arquivo = fopen("clientes.txt", "r");
				if(arquivo == NULL){
					printf("Nenhum cliente cadastrado.\n");
				}else{
					while(fgets(linha, 200, arquivo)){
						printf("%s", linha);
					}
					fclose(arquivo);
				}
			printf("\nPressione ENTER para voltar ao menu...");
			fflush(stdin);
			getchar();

			break;
			
			
			// 3 - Atualizar dados de um cliente
			case 3:
				system("cls");
				printf("=== Atualizar Cliente ===\n");
				
				printf("\nInforme o CPF do cliente que deseja alterar: ");
				fflush(stdin);
				gets(cpfBusca);
				
				arquivo = fopen("clientes.txt", "r");
				temp = fopen("temp.txt", "w");
				
				if(arquivo == NULL){
					printf("Nenhum cliente cadastrado.\n");
				}else{
					encontrado = 0;
					while(fscanf(arquivo, "%13s %14s %[^\n]", CPF, telefone, nome) != EOF){
						if(strcmp(CPF, cpfBusca) == 0){
							encontrado = 1;
							printf("\nCliente encontrado: %s - %s - %s\n", CPF, telefone, nome);
							
							printf("\nNovo nome: ");
							fflush(stdin);
							gets(nome);
							
							printf("Novo telefone: ");
							fflush(stdin);
							gets(telefone);
							
							fprintf(temp, "%s\t%s\t%s\n", CPF, telefone, nome);
							printf("\nDados atualizados com sucesso!\n");
						}else{
							fprintf(temp, "%s\t%s\t%s\n", CPF, telefone, nome);
						}
					}
					fclose(arquivo);
					fclose(temp);
					
					remove("clientes.txt");
					rename("temp.txt", "clientes.txt");
					
					if(!encontrado){
						printf("\nCPF não encontrado.\n");
					}
				}
			printf("\nPressione ENTER para voltar ao menu...");
			fflush(stdin);
			getchar();
			break;
			
			
			// 4 - Excluir cliente
			case 4:
				system("cls");
				printf("=== Excluir Cliente ===\n");
				
				printf("\nInforme o CPF do cliente que deseja excluir: ");
				fflush(stdin);
				gets(cpfBusca);
				
				arquivo = fopen("clientes.txt", "r");
				temp = fopen("temp.txt", "w");
				
				if(arquivo == NULL){
					printf("Nenhum cliente cadastrado.\n");
				}else{
					encontrado = 0;
				while(fscanf(arquivo, "%13s %14s %[^\n]", CPF, telefone, nome) != EOF){
						if(strcmp(CPF, cpfBusca) == 0){
							encontrado = 1;
							printf("\nCliente removido: %s - %s - %s\n", CPF, telefone, nome);
						}else{
							fprintf(temp, "%s\t%s\t%s\n", CPF, telefone, nome);
						}
					}
					fclose(arquivo);
					fclose(temp);
					
					remove("clientes.txt");
					rename("temp.txt", "clientes.txt");
					
					if(!encontrado){
						printf("\nCPF não encontrado.\n");
					}else{
						printf("\nExclusão concluída com sucesso!\n");
					}
				}
			printf("\nPressione ENTER para voltar ao menu...");
			fflush(stdin);
			getchar();
			break;
			
			
			// 5 - Sair
			case 5:
				system("cls");
				printf("Encerrando o sistema...\n");
			break;
			
			
			default:
				printf("Opção inválida!\n");
				system("pause");
		}
		
	}while(opcao != 5);
}