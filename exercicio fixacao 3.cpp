#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int matriz[4][4];
    int i, j;
    int maior, linhaMaior, colunaMaior;

    printf("Digite os valores da matriz 4x4:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("Posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if(i == 0 && j == 0){
                maior = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }else{
                if(matriz[i][j] > maior){
                    maior = matriz[i][j];
                    linhaMaior = i;
                    colunaMaior = j;
                }
            }
        }
    }

    printf("\nO maior valor é %d, localizado na linha %d e coluna %d.\n", maior, linhaMaior, colunaMaior);

    system("pause");
    return 0;
}