#include<stdio.h>
#include <stdlib.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	float n1;
	do{
		printf("/nInforme um número entre [0..10]: ");
		scanf("%f", &n1);
		if((n1<0) || (n1>10)){
			printf("/nNúmero inválido!/n");
			system("cls");
		}else{
			printf("/nNúmero válido!/n");
		}
	}while((n1<0) || (n1>10);
}
