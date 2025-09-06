#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int i, contador_vogais = 0, contador_consoantes;
	char s[10];
	
	printf("\nInforme uma palavra ou frase: ");
	fflush(stdin);
	gets(s);
	
	for(i = 0; i < strlen(s); i++){
		
		if((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')){
			contador_vogais = contador_vogais + 1;
			printf("%c: [Vogal]. ", s[i]);
		}else{
			printf("%c: [Consoante]. ", s[i]);
		}
	}
	
	contador_consoantes = strlen(s) - contador_vogais;
	
	printf("\nTotal de vogais: %d", contador_vogais);
	printf("\nTotal de consoantes: %d\n", contador_consoantes);
	
	system("pause");
	
	return 0;
}
