#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int linha, coluna, matriz[3][2] = {25, 36, 9, 13, 6, 25};
	
	for(linha = 0; linha <= 2; linha++){
		for(coluna = 0; coluna <=1; coluna++){
			printf("Matriz[%d][%d] = %d ", linha, coluna, matriz[linha][coluna]);
		}
		printf("\n");
	}
}
