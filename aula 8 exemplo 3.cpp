#include <stdio.h>
#include <locale.h>
void digitar() {
   printf("Digite um número: ");
}
int soma(int n1, int n2) {
   return n1 + n2;
}
int main() {
   setlocale(LC_ALL, "Portuguese");
   int a, b, total;
   digitar();
   scanf("%d", &a);
   digitar();
   scanf("%d", &b);
   total = soma(a, b);
   printf("Soma: %d", total);
}
