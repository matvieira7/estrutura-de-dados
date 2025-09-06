#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int i, contador_vogais = 0;
	char s[10];
	
	printf("\nInforme uma palavra ou frase: ");
	fflush(stdin);
	gets(s);
	
	for(i = 0; i < strlen(s); i++){
		
		if((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')){
			contador_vogais = contador_vogais + 1;
			printf("%c ", s[i]);
		}
	}
	
	printf("\nTotal de vogais: %d\n", contador_vogais);
	
	system("pause");
	
	return 0;
}
