#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    float notas[4], media = 0;
    int i;

    for(i = 0; i < 4; i++){
        printf("Digite a nota %d: ", i+1);
        scanf("%f", &notas[i]);
        media = media + notas[i];
    }

    media = media / 4;

    printf("\nNotas informadas:\n");
    for(i = 0; i < 4; i++){
        printf("Nota %d = %.2f\n", i+1, notas[i]);
    }
    printf("Média = %.2f\n", media);

    system("pause");
    return 0;
}