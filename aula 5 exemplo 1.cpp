/*
Inicializando o vetor com valores
*/

#include<stdio.h>;
#include<locale.h>;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int x;
	int vetor_exemplo[] = {25, 36, 74, 9, 14, 90, -42, 84, 6, 25};
	
	for(x = 0; x < 10; x++){
		printf("\nVetor exemplo[%d] = %d", x, vetor_exemplo[x]); 
	}
	return 0;
} 
