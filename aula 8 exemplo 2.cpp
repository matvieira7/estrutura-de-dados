#include <stdio.h>
#include <locale.h>
/*
função digitar(), não retorna nada (void) e não tem argumentos
*/
void digitar() {
   printf("Digite um número: ");
}
/*
função soma(), não retorna nada e tem dois argumentos
*/
void soma(int n1, int n2) {
   int total;
   total = n1 + n2;
   printf("Soma = %d\n", total);
}
int main() {
   setlocale(LC_ALL, "Portuguese");
   int a, b;
   digitar(); // chamando a função digitar()
   scanf("%d", &a);
   digitar(); // chamando a função digitar()
   scanf("%d", &b);
   soma(a, b); // chamando a função soma() e passando os argumentos a e b
}
