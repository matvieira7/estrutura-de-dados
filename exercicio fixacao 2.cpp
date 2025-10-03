#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int matriz[2][3];
    int i, j;
    int menor100, entre100e400, maior400;
    char opcao;

    do{
        menor100 = 0;
        entre100e400 = 0;
        maior400 = 0;

        printf("Digite os valores da matriz 2x3:\n");
        for(i = 0; i < 2; i++){
            for(j = 0; j < 3; j++){
                printf("Posição [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);

                if(matriz[i][j] < 100){
                    menor100++;
                }
                else if(matriz[i][j] <= 400){
                    entre100e400++;
                }
                else{
                    maior400++;
                }
            }
        }

        printf("\nResultados:\n");
        printf("Menores que 100: %d\n", menor100);
        printf("Entre 100 e 400: %d\n", entre100e400);
        printf("Maiores que 400: %d\n", maior400);

        do{
            printf("\nDeseja informar outros valores [s/n]? ");
            scanf(" %c", &opcao);
            if(opcao != 's' && opcao != 'n'){
                printf("Resposta inválida! Digite apenas 's' ou 'n'.\n");
            }
        }while(opcao != 's' && opcao != 'n');

    }while(opcao == 's');

    system("pause");
    return 0;
}