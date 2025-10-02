#include <stdio.h>

int main() {
    int m[4][4], maiores[4], menores[4];
    int i, j;

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for(i = 0; i < 4; i++) {
        maiores[i] = m[i][0];
        for(j = 1; j < 4; j++) {
            if(m[i][j] > maiores[i]) {
                maiores[i] = m[i][j];
            }
        }
    }

    for(j = 0; j < 4; j++) {
        menores[j] = m[0][j];
        for(i = 1; i < 4; i++) {
            if(m[i][j] < menores[j]) {
                menores[j] = m[i][j];
            }
        }
    }

    printf("\nVetor maiores das linhas: ");
    for(i = 0; i < 4; i++) printf("%d ", maiores[i]);

    printf("\nVetor menores das colunas: ");
    for(j = 0; j < 4; j++) printf("%d ", menores[j]);

    return 0;
}