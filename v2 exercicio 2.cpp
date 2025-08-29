#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
    int cont;
    float n1, n2, n3, n4, media;
    char nome[40], resp;
    setlocale(LC_ALL, "Portuguese");

    resp = 's';
    while (resp != 'n') {
        printf("\nInforme seu nome: ");
        fflush(stdin);
        gets(nome);

        do {
            printf("\nInforme a 1° nota (0 a 10): ");
            if (scanf("%f", &n1) != 1 || n1 < 0 || n1 > 10) {
                printf("Nota inválida! Digite um valor numérico entre 0 e 10.\n");
                fflush(stdin); // limpa buffer se o input for inválido
                n1 = -1;       // força repetir o loop
            }
        } while (n1 < 0 || n1 > 10);

        do {
            printf("\nInforme a 2° nota (0 a 10): ");
            if (scanf("%f", &n2) != 1 || n2 < 0 || n2 > 10) {
                printf("Nota inválida! Digite um valor numérico entre 0 e 10.\n");
                fflush(stdin);
                n2 = -1;
            }
        } while (n2 < 0 || n2 > 10);

        do {
            printf("\nInforme a 3° nota (0 a 10): ");
            if (scanf("%f", &n3) != 1 || n3 < 0 || n3 > 10) {
                printf("Nota inválida! Digite um valor numérico entre 0 e 10.\n");
                fflush(stdin);
                n3 = -1;
            }
        } while (n3 < 0 || n3 > 10);

        do {
            printf("\nInforme a 4° nota (0 a 10): ");
            if (scanf("%f", &n4) != 1 || n4 < 0 || n4 > 10) {
                printf("Nota inválida! Digite um valor numérico entre 0 e 10.\n");
                fflush(stdin);
                n4 = -1;
            }
        } while (n4 < 0 || n4 > 10);

        media = (n1+n2+n3+n4) / 4;
        printf("\n%s, sua média é: %.1f.\n", nome, media);

        do {
            printf("\nDeseja calcular a média de outro aluno? [s/n]: ");
            fflush(stdin);
            scanf("%c", &resp);

            if (resp != 's' && resp != 'n') {
                printf("\nDigite uma resposta válida [s] ou [n].\n");
            }
        } while (resp != 's' && resp != 'n');
    }

    system("pause");
}
