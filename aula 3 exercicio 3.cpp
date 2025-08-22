#include<stdio.h>
#include <stdlib.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	char resp;
	do{
		printf("\nVocê é solteiro?(responda com S ou N) ");
		scanf(" %c", &resp);
		if(resp == 'S' || resp == 'N'){
			printf("\nResposta válida!\n");
		}else{
			printf("\nResposta inválida!\n");
			system("cls");
		}
	}while(resp != 'S' && resp != 'N');
}
