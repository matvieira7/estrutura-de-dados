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

        printf("\nInforme a 1° nota: ");
        scanf("%f", &n1);

        printf("\nInforme a 2° nota: ");
        scanf("%f", &n2);

        printf("\nInforme a 3° nota: ");
        scanf("%f", &n3);

        printf("\nInforme a 4° nota: ");
        scanf("%f", &n4);

        media = (n1+n2+n3+n4) / 4;
        printf("\n%s, sua média é: %.1f.\n", nome, media);

        do {
            printf("\nDeseja calcular a média de outro aluno? [s/n]: ");
            fflush(stdin);
            scanf("%c", &resp);

            if(resp != 's' && resp != 'n'){
                printf("\nDigite uma resposta válida [s] ou [n].\n");
            }
        } while(resp != 's' && resp != 'n');
    }

    system("pause");
}
