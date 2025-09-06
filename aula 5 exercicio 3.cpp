#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int numeros[5], maior, i;

    for(i = 0; i < 5; i++){
        do{
            printf("Digite o número %d (positivo): ", i+1);
            scanf("%d", &numeros[i]);
            if(numeros[i] <= 0){
                printf("Valor inválido! Digite apenas números positivos.\n");
            }
        }while(numeros[i] <= 0);
    }

    maior = numeros[0];
    for(i = 1; i < 5; i++){
        if(numeros[i] > maior){
            maior = numeros[i];
        }
    }

    printf("\nO maior valor do vetor é: %d\n", maior);

    system("pause");
    return 0;
}