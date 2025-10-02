#include <stdio.h>

int main() {
    char sexo, olhos, cabelos;
    int idade, maiorIdade = 0, contMulheres = 0;

    while(1) {
        printf("Digite a idade (-1 para parar): ");
        scanf("%d", &idade);
        if(idade == -1) break;

        printf("Sexo (M/F/O): ");
        scanf(" %c", &sexo);
        printf("Olhos (A=azuis, V=verdes, C=castanhos): ");
        scanf(" %c", &olhos);
        printf("Cabelos (L=louros, C=castanhos, P=pretos): ");
        scanf(" %c", &cabelos);

        if(idade > maiorIdade) maiorIdade = idade;

        if(sexo == 'F' && idade >= 18 && idade <= 35 && olhos == 'V' && cabelos == 'L') {
            contMulheres++;
        }
    }

    printf("\nMaior idade: %d\n", maiorIdade);
    printf("Qtd mulheres 18-35, olhos verdes, cabelos louros: %d\n", contMulheres);

    return 0;
}