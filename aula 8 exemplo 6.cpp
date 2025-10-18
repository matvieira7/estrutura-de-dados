#include <stdio.h>
#include <locale.h>
float entrada_dados() {
   float numero;
   printf("Informe um número: ");
   scanf("%f", &numero);
   return numero;
}
float soma(float n1, float n2) {
   float resultado;
   resultado = n1 + n2;
   return resultado;
}
float subtracao(float n1, float n2) {
   float resultado;
   resultado = n1 - n2;
   return resultado;
}
float multiplicacao(float n1, float n2) {
   float resultado;
   resultado = n1 * n2;
   return resultado;
}
float divisao(float n1, float n2) {
   float resultado;
   resultado = n1 / n2;
   return resultado;
}
void exibir_resultado(float valor) {
   printf("\n%.1f\n", valor);
}
int main() {
   setlocale(LC_ALL, "Portuguese");
   float A, B;
   A = entrada_dados();
   B = entrada_dados();
   exibir_resultado(soma(A, B));
   exibir_resultado(subtracao(A, B));
   exibir_resultado(multiplicacao(A, B));
   exibir_resultado(divisao(A, B));
}
