#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int M[2][2];
    int i, j, valor;

    printf("Digite os valores da matriz 2x2 (entre 0 e 10):\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            do{
                printf("Posição [%d][%d]: ", i, j);
                scanf("%d", &valor);
                if(valor < 0 || valor > 10){
                    printf("Valor inválido! Informe um número entre 0 e 10.\n");
                }
            }while(valor < 0 || valor > 10);
            M[i][j] = valor;
        }
    }

    printf("\nMatriz final:\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}