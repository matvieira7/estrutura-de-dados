#include <stdio.h>
#include <locale.h>
#define tamanho 5
int main() {
   setlocale(LC_ALL, "Portuguese");
   int x;
   char nomes[tamanho][20];
   float salarios[tamanho], reajuste;
   for (x = 0; x < tamanho; x++) {
       printf("\nNome do funcion�rio %d�: ", x + 1);
       fflush(stdin);
       gets(nomes[x]); 
       printf("Sal�rio: ");
       scanf("%f", &salarios[x]);
   }
   printf("\nDigite o valor do reajuste salarial (em %%): ");
   scanf("%f", &reajuste);
   reajuste = (reajuste / 100) + 1;
   printf("\nCalculando e Listando todos os dados:\n");
   for (x = 0; x < tamanho; x++) {
       salarios[x] = salarios[x] * reajuste;
       printf("\nFuncion�rio: %s R$ %.2f", nomes[x], salarios[x]);
   }
   return 0;
}
