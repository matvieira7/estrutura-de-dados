#include<stdio.h>
#include<locale.h>
#include<string.h>
main(){
   setlocale(LC_ALL, "Portuguese");
   char palavra[30] = "fatec";
   printf("Original: %s\n", palavra);
   printf("Invertida: %s\n", strrev(palavra));
}
