#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int linhas, colunas;
    int i, j;

    printf("Informe o número de linhas da matriz A: ");
    scanf("%d", &linhas);
    printf("Informe o número de colunas da matriz A: ");
    scanf("%d", &colunas);

    int A[linhas][colunas];
    int B[linhas][colunas];

    printf("\nDigite os valores da matriz A:\n");
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("Posição [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            B[i][j] = A[i][j] * A[i][j]; // A²
        }
    }

    printf("\nMatriz B = A²:\n");
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}