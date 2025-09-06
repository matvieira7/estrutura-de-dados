#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int A[5], B[5], C[5];
    int i, op;

    printf("Escolha a operação:\n");
    printf("1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n");
    scanf("%d", &op);

    printf("\nDigite os elementos do vetor A:\n");
    for(i = 0; i < 5; i++){
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("\nDigite os elementos do vetor B:\n");
    for(i = 0; i < 5; i++){
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    for(i = 0; i < 5; i++){
        if(op == 1){
            C[i] = A[i] + B[i];
        }else if(op == 2){
            C[i] = A[i] - B[i];
        }else if(op == 3){
            C[i] = A[i] * B[i];
        }else if(op == 4){
            if(B[i] != 0){
                C[i] = A[i] / B[i];
            }else{
                C[i] = 0; 
            }
        }
    }

    printf("\nResultado (vetor C):\n");
    for(i = 0; i < 5; i++){
        printf("C[%d] = %d\n", i, C[i]);
    }

    system("pause");
    return 0;
}