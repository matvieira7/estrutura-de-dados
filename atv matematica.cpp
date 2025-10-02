#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main(){
	
	setlocale(LC_ALL, "Portuguese");
	
int a[10], b[10], uniaotemp[20], uniao[20], interseccao[10];
int a_b[20], b_a[20], difsim[20];
int i, j, icont = 0, ucont = 0, temp;
int a_b_cont = 0, b_a_cont = 0, difsim_cont = 0;
	
	printf("Preenchendo o vetor A...\n");
	for (i=0; i<10; i++){
		printf("%d. Insira um elemento único: ", i+1);
		scanf("%d", &a[i]);
		for (j=0; j<i; j++){
			if (a[i] == a[j]){
				printf("\n Não insira números repetidos.");
				i=i-1;
			}
		}	
	}
//colocando o A em ordem decrescente
	for (i=1; i<10; i++) {
		for(j=0; j<9; j++){
			if (a[j] < a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	printf("Preenchendo o vetor B...\n");
	for (i=0; i<10; i++){
		printf("%d. Insira um elemento único: ", i+1);
		scanf("%d", &b[i]);
		for (j=0; j<i; j++){
			if (b[i] == b[j]){
				printf("\n Não insira números repetidos.");
				i=i-1;
			}
		}	
	}
//colocando o B em ordem decrescente
	for (i=1; i<10; i++) {
		for(j=0; j<9; j++){
			if (b[j] < b[j+1]){
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
	printf("\nVetor A (ordem decrescente):");
	for (i=0; i<10; i++){
		printf("  %d  ", a[i]);
	}
	
	printf("\nVetor B (ordem decrescente):");
	for (i=0; i<10; i++){
		printf("  %d  ", b[i]);
	}
	
/////////////////////////////////////	
	for (i=0; i<10; i++){
		uniaotemp[i] = a[i];
	}
	for (i=0; i<10; i++){
		uniaotemp[i+10] = b[i];
	}
	
//colocando o uniao em ordem crescente
	for (i=1; i<20; i++) {
		for(j=0; j<19; j++){
			if (uniaotemp[j] > uniaotemp[j+1]){
				temp = uniaotemp[j];
				uniaotemp[j] = uniaotemp[j+1];
				uniaotemp[j+1] = temp;
			}
		}
	}
	
//tirando os valores duplicados
	for (i = 0; i < 20; i++) {
    	if (uniaotemp[i] != uniaotemp[i-1]) {
        	uniao[ucont] = uniaotemp[i];
        	ucont++;
    	}
	}
	
	printf("\nUnião (ordem crescente): ");
	for (i=0; i<ucont; i++){
		printf("  %d  ",uniao[i]);
	}
////////////////////////////////////	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if (a[i] == b[j]){
				interseccao[icont] = a[i];
				icont++;
			}
		}
	}
//colocando o intersecção em ordem crescente
	for (i=1; i<icont; i++) {
    	for (j=0; j<icont-1; j++) {
        	if (interseccao[j] > interseccao[j+1]) {
            	temp = interseccao[j];
            	interseccao[j] = interseccao[j+1];
            	interseccao[j+1] = temp;
       		}
    	}
	}
	printf("\nIntersecção (ordem crescente): ");
	for (i=0; i<icont; i++){
		printf("  %d  ",interseccao[i]);

	}
//////////////////////////////////// A - B
	for (i=0; i<10; i++){
		int existe = 0;
		for (j=0; j<10; j++){
			if (a[i] == b[j]){
				existe = 1;
				break;
			}
		}
		if (!existe){
			a_b[a_b_cont++] = a[i];
		}
	}
	printf("\nA - B: ");
	for (i=0; i<a_b_cont; i++){
		printf("  %d  ", a_b[i]);
	}
	
	//////////////////////////////////// B - A
	for (i=0; i<10; i++){
		int existe = 0;
		for (j=0; j<10; j++){
			if (b[i] == a[j]){
				existe = 1;
				break;
			}
		}
		if (!existe){
			b_a[b_a_cont++] = b[i];
		}
	}
	printf("\nB - A: ");
	for (i=0; i<b_a_cont; i++){
		printf("  %d  ", b_a[i]);
	}
	
	//////////////////////////////////// DIFERENÇA SIMÉTRICA
	for (i=0; i<a_b_cont; i++){
		difsim[difsim_cont++] = a_b[i];
	}
	for (i=0; i<b_a_cont; i++){
		difsim[difsim_cont++] = b_a[i];
	}
	
	//colocando difsim em ordem crescente
	for (i=1; i<difsim_cont; i++) {
    	for (j=0; j<difsim_cont-1; j++) {
        	if (difsim[j] > difsim[j+1]) {
            	temp = difsim[j];
            	difsim[j] = difsim[j+1];
            	difsim[j+1] = temp;
       		}
    	}
	}
	printf("\nDiferença Simétrica (ordem crescente): ");
	for (i=0; i<difsim_cont; i++){
		printf("  %d  ", difsim[i]);
	}
}