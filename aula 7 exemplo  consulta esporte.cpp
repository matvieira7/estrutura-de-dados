#include<stdio.h>
#include<locale.h>
#include<string.h>
main(){
   setlocale(LC_ALL, "Portuguese");
   int i, achou = 0;
   char esportes[5][15] = {"futebol", "volei", "basquete", "tenis", "ciclismo"};
   char busca[50];
   printf("Digite um esporte para pesquisa: ");
   fflush(stdin);
   gets(busca);
   for(i = 0; i < 5; i++){
       if(strcmp(busca, esportes[i]) == 0){
           printf("Encontrado: %s", esportes[i]);
           achou = 1;
       }
   }
   if(achou == 0){
       printf("%s não encontrado!", busca);
   }
}
