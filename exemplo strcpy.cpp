#include<stdio.h>
#include<locale.h>
#include<string.h>
main(){
   setlocale(LC_ALL, "Portuguese");
   char origem[30] = "teste de copia";
   char destino[30];
   strcpy(destino, origem);
   printf("String de origem: %s\n", origem);
   printf("String copiada: %s\n", destino);
}
