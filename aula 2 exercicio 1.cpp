#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int l1, l2, l3;
	
	printf("Informe o 1� lado: ");
	scanf("%d", &l1);
	
	printf("Informe o 2� lado: ");
	scanf("%d", &l2);
	
	printf("Informe o 3� lado: ");
	scanf("%d", &l3);
	
	if((l1 > l2 + l3 ) or (l2 > l1 + l3 ) or (l3 > l1 + l2)){
		printf("Os lados informados n�o formam um tri�ngulo!\n");
	}else{
		if((l1 == l2) and (l1 == l3)){
			printf("Tri�ngulo equil�tero!\n");
		}else{
			if((l1 != l2) and (l1 != l3) and (l2 != l3)){
				printf("Tri�ngulo escaleno!\n");
			}else{
				printf("Tri�ngulo is�sceles!\n");
			}
		}
	}
}
