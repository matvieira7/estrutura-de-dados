#include <stdio.h>
#include <locale.h>
/*
fun��o digitar(), n�o retorna nada (void) e n�o tem argumentos
*/
void digitar() {
   printf("Digite um n�mero: ");
}
/*
fun��o soma(), n�o retorna nada e tem dois argumentos
*/
void soma(int n1, int n2) {
   int total;
   total = n1 + n2;
   printf("Soma = %d\n", total);
}
int main() {
   setlocale(LC_ALL, "Portuguese");
   int a, b;
   digitar(); // chamando a fun��o digitar()
   scanf("%d", &a);
   digitar(); // chamando a fun��o digitar()
   scanf("%d", &b);
   soma(a, b); // chamando a fun��o soma() e passando os argumentos a e b
}
