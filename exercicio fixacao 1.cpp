#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int A[6] = {1, 0, 5, -2, -5, 7};
    int soma, i;

    soma = A[0] + A[1] + A[5];
    printf("Soma de A[0] + A[1] + A[5] = %d\n\n", soma);

    A[4] = 100;

    printf("Valores do vetor A:\n");
    for(i = 0; i < 6; i++){
        printf("A[%d] = %d\n", i, A[i]);
    }

    system("pause");
    return 0;
}