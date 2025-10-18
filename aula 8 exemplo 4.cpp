#include <stdio.h>
#include <locale.h>
/*
Ler_nota() retorna um valor do tipo float e não tem argumentos
*/
float ler_nota() {
   float n;
   printf("Digite a nota: ");
   scanf("%f", &n);
   return n;
}
/*
função media() possui dois argumentos e não tem retorno
*/
void media(float n1, float n2) {
   float media = (n1 + n2) / 2;
   if (media >= 7) {
       printf("Média = %.1f - Aprovado", media);
   } else {
       printf("Média = %.1f - Reprovado", media);
   }
}
int main() {
   setlocale(LC_ALL, "Portuguese");
   float a, b;
   a = ler_nota();
   b = ler_nota();
   media(a, b);
}
