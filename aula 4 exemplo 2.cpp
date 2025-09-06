#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char nome[10];
	
	printf("Informe seu nome completo: ");
	
	scanf("%s", &nome); //So armazena o que foi digitado antes do espaço "uma palavra"
	
	fflush(stdin);
	
	printf("O nome completo é: %s. \n", nome);
	
	system("pause");
}
