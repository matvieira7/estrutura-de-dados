#include <stdio.h>

int main() {
    int linhas, colunas, min, max;
    int i, j, num;
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    printf("Digite o valor minimo permitido: ");
    scanf("%d", &min);
    printf("Digite o valor maximo permitido: ");
    scanf("%d", &max);

    int matriz[linhas][colunas];

    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &num);
            while(num < min || num > max) {
                printf("Valor invalido! Digite entre %d e %d: ", min, max);
                scanf("%d", &num);
            }
            matriz[i][j] = num;

            if(num % 2 == 0) pares++;
            else impares++;
            if(num > 0) positivos++;
            else if(num < 0) negativos++;
        }
    }

    printf("\nQuantidade de pares: %d\n", pares);
    printf("Quantidade de impares: %d\n", impares);
    printf("Quantidade de positivos: %d\n", positivos);
    printf("Quantidade de negativos: %d\n", negativos);

    return 0;
}