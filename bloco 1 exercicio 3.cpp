#include <stdio.h>

int main() {
    float temp[7];
    int i;
    float soma = 0, maior, menor, media;

    for(i = 0; i < 7; i++) {
        printf("Digite a temperatura do dia %d: ", i+1);
        scanf("%f", &temp[i]);
        while(temp[i] < -95 || temp[i] > 65) {
            printf("Temperatura invalida! Digite entre -95 e 65: ");
            scanf("%f", &temp[i]);
        }
        soma += temp[i];
    }

    menor = maior = temp[0];
    for(i = 1; i < 7; i++) {
        if(temp[i] < menor) menor = temp[i];
        if(temp[i] > maior) maior = temp[i];
    }

    media = soma / 7.0;

    printf("\nMenor temperatura: %.1f\n", menor);
    printf("Maior temperatura: %.1f\n", maior);
    printf("Temperatura media: %.1f\n", media);

    return 0;
}
