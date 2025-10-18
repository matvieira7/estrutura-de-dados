#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int idadeEmDias(int anos, int meses, int dias) {
    return anos * 365 + meses * 30 + dias;
}

float pesoIdeal(float alt, char sexo) {
    if (alt <= 0) return -2;
    if (sexo == 'M' || sexo == 'm') return 72.7 * alt - 58;
    if (sexo == 'F' || sexo == 'f') return 62.1 * alt - 44.7;
    return -1;
}

float mediaNotas(float n1, float n2, char tipo) {
    if (tipo == 'A' || tipo == 'a') return (n1 + n2) / 2;
    if (tipo == 'P' || tipo == 'p') return (n1 * 3 + n2 * 7) / 10;
    return -1;
}

void pesquisaHabitantes() {
    int filhos, totalFilhos = 0, cont = 0, contSalarioAte1412 = 0;
    float salario, totalSalario = 0, maiorSalario = 0;
    char resp;
    do {
        printf("Digite o salário: ");
        scanf("%f", &salario);
        printf("Digite o número de filhos: ");
        scanf("%d", &filhos);
        totalSalario += salario;
        totalFilhos += filhos;
        if (salario > maiorSalario) maiorSalario = salario;
        if (salario <= 1412.00) contSalarioAte1412++;
        cont++;
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &resp);
    } while (resp == 'S' || resp == 's');
    printf("Média de salário: %.2f\n", totalSalario / cont);
    printf("Média de filhos: %.2f\n", (float)totalFilhos / cont);
    printf("Maior salário: %.2f\n", maiorSalario);
    printf("Percentual com salário até 1412: %.2f%%\n", (float)contSalarioAte1412 / cont * 100);
}

long fatorial(int n) {
    long fat = 1;
    for (int i = 1; i <= n; i++) fat *= i;
    return fat;
}

void inverterVetor() {
    int v[10], temp;
    printf("Digite 10 números: ");
    for (int i = 0; i < 10; i++) scanf("%d", &v[i]);
    for (int i = 0; i < 5; i++) {
        temp = v[i];
        v[i] = v[i + 5];
        v[i + 5] = temp;
    }
    printf("Vetor invertido: ");
    for (int i = 0; i < 10; i++) printf("%d ", v[i]);
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;
    do {
        printf("\n1 – Idade em dias\n2 – Peso ideal\n3 – Média aritmética ou ponderada\n4 – Pesquisa de habitantes\n5 – Fatorial\n6 – Invertendo valores no vetor\n0 – Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                int anos, meses, dias, total;
                printf("Digite anos, meses e dias: ");
                scanf("%d %d %d", &anos, &meses, &dias);
                total = idadeEmDias(anos, meses, dias);
                printf("Idade em dias: %d\n", total);
                break;
            }
            case 2: {
                float alt, peso;
                char sexo;
                printf("Digite altura: ");
                scanf("%f", &alt);
                printf("Digite sexo (M/F): ");
                scanf(" %c", &sexo);
                peso = pesoIdeal(alt, sexo);
                if (peso == -1) printf("Sexo inválido!\n");
                else if (peso == -2) printf("Altura inválida!\n");
                else printf("Peso ideal: %.2f kg\n", peso);
                break;
            }
            case 3: {
                float n1, n2, media;
                char tipo;
                printf("Digite nota1, nota2 e tipo de média (A/P): ");
                scanf("%f %f %c", &n1, &n2, &tipo);
                media = mediaNotas(n1, n2, tipo);
                if (media == -1) printf("Tipo de média inválido!\n");
                else printf("Média: %.2f\n", media);
                break;
            }
            case 4:
                pesquisaHabitantes();
                break;
            case 5: {
                int n;
                long fat;
                printf("Digite um número inteiro positivo: ");
                scanf("%d", &n);
                if (n < 0) printf("Número inválido!\n");
                else {
                    fat = fatorial(n);
                    printf("Fatorial de %d é %ld\n", n, fat);
                }
                break;
            }
            case 6:
                inverterVetor();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    return 0;
}