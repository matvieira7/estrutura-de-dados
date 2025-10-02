#include <stdio.h>

int main() {
    char resp;

    printf("O animal eh mamifero? (S/N): ");
    scanf(" %c", &resp);

    if(resp == 'S') {
        printf("Eh quadrupede? (S/N): ");
        scanf(" %c", &resp);
        if(resp == 'S') {
            printf("Eh carnivoro? (S/N): ");
            scanf(" %c", &resp);
            if(resp == 'S') printf("Animal: Leao\n");
            else printf("Animal: Cavalo\n");
        } else {
            printf("Eh bipede? (S/N): ");
            scanf(" %c", &resp);
            if(resp == 'S') {
                printf("Eh onivoro? (S/N): ");
                scanf(" %c", &resp);
                if(resp == 'S') printf("Animal: Homem\n");
                else printf("Animal: Macaco\n");
            } else {
                printf("Voa? (S/N): ");
                scanf(" %c", &resp);
                if(resp == 'S') printf("Animal: Morcego\n");
                else printf("Animal: Baleia\n");
            }
        }
    } else {
        printf("Eh ave? (S/N): ");
        scanf(" %c", &resp);
        if(resp == 'S') {
            printf("Nao voa? (S/N): ");
            scanf(" %c", &resp);
            if(resp == 'S') {
                printf("Eh tropical? (S/N): ");
                scanf(" %c", &resp);
                if(resp == 'S') printf("Animal: Avestruz\n");
                else printf("Animal: Pinguim\n");
            } else {
                printf("Eh aquatico? (S/N): ");
                scanf(" %c", &resp);
                if(resp == 'S') printf("Animal: Pato\n");
                else printf("Animal: Aguia\n");
            }
        } else {
            printf("Eh reptil? (S/N): ");
            scanf(" %c", &resp);
            if(resp == 'S') {
                printf("Tem casco? (S/N): ");
                scanf(" %c", &resp);
                if(resp == 'S') printf("Animal: Tartaruga\n");
                else {
                    printf("Eh carnivoro? (S/N): ");
                    scanf(" %c", &resp);
                    if(resp == 'S') printf("Animal: Crocodilo\n");
                    else printf("Animal: Cobra\n");
                }
            }
        }
    }

    return 0;
}