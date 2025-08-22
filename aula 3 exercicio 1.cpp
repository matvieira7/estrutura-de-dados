#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<locale.h>

main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int op, x, y;
	float z;
	
	do{
		system("cls");
		printf("/n###################################################################################");
		printf("/nDIGITE A OPÇÃO DESEJADA");
		printf("/n 1 - PARA CÁLCULO DA RAIZ QUADRADA");
		printf("/n 2 - PARA CÁLCULO DE POTENCIALIZAÇÃO");
		printf("/n 3 - PARA CÁLCULO DO SENO");
		printf("/n 4 - PARA CÁLCULO DO LOGARITMO");
		printf("/n 5 - PARA SOMAR 2 VALORES");
		printf("/n 6 - PARA SUBTRAIR 2 VALORES");
		printf("/n 7 - PARA VER A MÉDIA DE 2 VALORES");
		printf("/n 0 - SAIR");
		scanf("%d", &op);
		printf("/n#################################################################");
		switch(op){
			case 1:{
				printf("/n##################### CÁLCULO DA RAIZ QUADRADA #################################");
				printf("/nDIGITE O VALOR PARA O CÁLCULO DA RAIZ QUADRADA: ");
				scanf("%d", &x);
				z = sqrt(x);
				printf("/nA RAIZ QUADRADA DO VALOR %d É: %.2f/n", x, z);
				system("pause");
				break;
			}
			case 2 : {
				printf("/n################# CÁLCULO DE POTENCILIZAÇÃO ###########");
				printf("/nDIGITE O VALOR PARA CÁLCULO DA POTÊNCIA: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO EXPOENTE: ");
				scanf("%d", &y);
				z = pow(x,y);
				printf("/nA POTENCIA DO VALOR %d COM EXPOENTE %d É: %.2f/n", x, y, z);
				system("pause");
				break;
			}
			case 3 : {
				printf("/n############# CÁLCULO DO SENO #############");
				printf("/nDIGITE O ANGULO PARA CÁLCULO DE SENO: ");
				scanf("%d", &x);
				z = sin(x);
				printf("/nO ANGULO %d TEM O SENO DE: %.2f/n", x, z);
				system("pause");
				break;
			}
			case 4:{
				printf("/n################# CÁLCULO DO LOGARITMO ####################");
				printf("/nDIGITE O VALOR PARA CÁLCULO DO LOGARITMO: ");
				scanf("%d", &x);
				z = log(x);
				printf("/nO VALOR DO %d TEM O LOGARITMO: %.2f/n", x, z);
				system("pause");
				break;
			}
			case 5:{
				printf("/n################# SOMA DE 2 VALORES ################");
				printf("/nDIGITE O VALOR DO PRIMEIRO NUMERO: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO SEGUNDO NUMERO: ");
				scanf("%d", &y);
				z = x + y;
				printf("/nA SOMA ENTRE O VALOR %d E O VALOR %d SERÁ: %.0f/n", x, y, z);
				system("pause");
				break;
			}
			case 6:{
				printf("/n################# SUBTRAÇÃO DE 2 VALORES ################");
				printf("/nDIGITE O VALOR DO PRIMEIRO NUMERO: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO SEGUNDO NUMERO: ");
				scanf("%d", &y);
				z = x - y;
				printf("/nA SUBTRAÇÃO ENTRE O VALOR %d E O VALOR %d SERÁ: %.0f/n", x, y, z);
				system("pause");
				break;
			}
			case 7:{
				printf("/n################# MÉDIA DE 2 VALORES ################");
				printf("/nDIGITE O VALOR DO PRIMEIRO NUMERO: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO SEGUNDO NUMERO: ");
				scanf("%d", &y);
				z = (x + y) /2;
				printf("/nA MÉDIA DO VALOR %d E O VALOR %d SERÁ: %.2f/n", x, y, z);
				system("pause");
				break;
			}
			case 0: printf("/n######################### SAIR ####################");break;
			default: printf;("/nDIGITE UMA OPÇÃO VÁLIDA/n");system("pause");break;
		}
	}while(op != 0);
}
