#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int numeros[5], soma = 0, i;

    for(i = 0; i < 5; i++){
        printf("Digite o número %d: ", i+1);
        scanf("%d", &numeros[i]);
        soma = soma + numeros[i];
    }

    printf("\nA soma dos elementos do vetor = %d\n", soma);

    system("pause");
    return 0;
}