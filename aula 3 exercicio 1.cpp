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
		printf("/nDIGITE A OP��O DESEJADA");
		printf("/n 1 - PARA C�LCULO DA RAIZ QUADRADA");
		printf("/n 2 - PARA C�LCULO DE POTENCIALIZA��O");
		printf("/n 3 - PARA C�LCULO DO SENO");
		printf("/n 4 - PARA C�LCULO DO LOGARITMO");
		printf("/n 5 - PARA SOMAR 2 VALORES");
		printf("/n 6 - PARA SUBTRAIR 2 VALORES");
		printf("/n 7 - PARA VER A M�DIA DE 2 VALORES");
		printf("/n 0 - SAIR");
		scanf("%d", &op);
		printf("/n#################################################################");
		switch(op){
			case 1:{
				printf("/n##################### C�LCULO DA RAIZ QUADRADA #################################");
				printf("/nDIGITE O VALOR PARA O C�LCULO DA RAIZ QUADRADA: ");
				scanf("%d", &x);
				z = sqrt(x);
				printf("/nA RAIZ QUADRADA DO VALOR %d �: %.2f/n", x, z);
				system("pause");
				break;
			}
			case 2 : {
				printf("/n################# C�LCULO DE POTENCILIZA��O ###########");
				printf("/nDIGITE O VALOR PARA C�LCULO DA POT�NCIA: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO EXPOENTE: ");
				scanf("%d", &y);
				z = pow(x,y);
				printf("/nA POTENCIA DO VALOR %d COM EXPOENTE %d �: %.2f/n", x, y, z);
				system("pause");
				break;
			}
			case 3 : {
				printf("/n############# C�LCULO DO SENO #############");
				printf("/nDIGITE O ANGULO PARA C�LCULO DE SENO: ");
				scanf("%d", &x);
				z = sin(x);
				printf("/nO ANGULO %d TEM O SENO DE: %.2f/n", x, z);
				system("pause");
				break;
			}
			case 4:{
				printf("/n################# C�LCULO DO LOGARITMO ####################");
				printf("/nDIGITE O VALOR PARA C�LCULO DO LOGARITMO: ");
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
				printf("/nA SOMA ENTRE O VALOR %d E O VALOR %d SER�: %.0f/n", x, y, z);
				system("pause");
				break;
			}
			case 6:{
				printf("/n################# SUBTRA��O DE 2 VALORES ################");
				printf("/nDIGITE O VALOR DO PRIMEIRO NUMERO: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO SEGUNDO NUMERO: ");
				scanf("%d", &y);
				z = x - y;
				printf("/nA SUBTRA��O ENTRE O VALOR %d E O VALOR %d SER�: %.0f/n", x, y, z);
				system("pause");
				break;
			}
			case 7:{
				printf("/n################# M�DIA DE 2 VALORES ################");
				printf("/nDIGITE O VALOR DO PRIMEIRO NUMERO: ");
				scanf("%d", &x);
				printf("/nDIGITE O VALOR DO SEGUNDO NUMERO: ");
				scanf("%d", &y);
				z = (x + y) /2;
				printf("/nA M�DIA DO VALOR %d E O VALOR %d SER�: %.2f/n", x, y, z);
				system("pause");
				break;
			}
			case 0: printf("/n######################### SAIR ####################");break;
			default: printf;("/nDIGITE UMA OP��O V�LIDA/n");system("pause");break;
		}
	}while(op != 0);
}
