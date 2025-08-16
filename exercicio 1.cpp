#include <stdio.h>;
#include <locale.h>;

main(){
	int presenca;
	float media;
	
	setlocale (LC_ALL, "Portuguese");
	
	printf ("Informe a quantidade de presença: ");
	scanf ("%d", &presenca);
	
	printf("Informe a sua média: ");
	scanf ("%f", &media);
	
	if(media >= 7 and presenca >= 75){
		printf("Aprovado!");
	 }
	else{
		printf("Reprovado!");
	 }
	}
