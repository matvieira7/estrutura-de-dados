#include <stdio.h>
#include <locale.h>
int main() {
   setlocale(LC_ALL, "Portuguese");
   int linha, coluna, matriz[3][3];
   for (linha = 0; linha <= 2; linha++) {
       for (coluna = 0; coluna <= 2; coluna++) {
           printf("Informe o valor da posi��o[%d][%d]: ", linha, coluna);
           scanf("%d", &matriz[linha][coluna]);
       }
   }
   printf("Exibindo todos os valores:\n");
   for (linha = 0; linha <= 2; linha++) {
       for (coluna = 0; coluna <= 2; coluna++) {
           printf("%d ", matriz[linha][coluna]);
       }
       printf("\n");
   }
   printf("\nExibindo apenas os n�meros pares:\n");
   for (linha = 0; linha <= 2; linha++) {
       for (coluna = 0; coluna <= 2; coluna++) {
           if (matriz[linha][coluna] % 2 == 0) {
               printf("%d ", matriz[linha][coluna]);
           }
       }
       printf("\n");
   }
   printf("\nExibindo apenas os n�meros �mpares:\n");
   for (linha = 0; linha <= 2; linha++) {
       for (coluna = 0; coluna <= 2; coluna++) {
           if (matriz[linha][coluna] % 2 == 1) {
               printf("%d ", matriz[linha][coluna]);
           }
       }
       printf("\n");
   }
   return 0;
}
