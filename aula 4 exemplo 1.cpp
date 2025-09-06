#include<stdio.h>
#include<locale.h>

main() 
{
	setlocale(LC_ALL, "Portuguese");
	
	char letra;
	
	printf("Informe uma letra: ");
	
	scanf("%c", &letra);
	
	fflush(stdin); //Limpa o buffer do teclado(espaço).
	
	printf("A letra informada é: %c.", letra);
}
