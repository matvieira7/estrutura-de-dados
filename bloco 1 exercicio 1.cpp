#include <stdio.h>
#include <math.h>

int main() {
    int vetor[8];
    int i, decimal = 0;

    printf("Digite 8 digitos binarios (0 ou 1):\n");
    for(i = 0; i < 8; i++) {
        scanf("%d", &vetor[i]);
        while(vetor[i] != 0 && vetor[i] != 1) {
            printf("Valor invalido, digite 0 ou 1: ");
            scanf("%d", &vetor[i]);
        }
    }

    for(i = 0; i < 8; i++) {
        decimal += vetor[7-i] * pow(2, i);
    }

    printf("Valor decimal: %d\n", decimal);

    return 0;
}