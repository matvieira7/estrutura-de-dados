#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char nome[40];
	
	printf("Informe seu nome completo: ");
	
	gets(nome); //Armazena tudo que foi digitado.
	
	fflush(stdin); //limpa o buffer do teclado.
	
	printf("O nome completo é: %s. \n", nome);
	
	system("pause");
}
