#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL, "Portuguese");
    
    int id;
    char conceito;
    float n1, n2, n3, n4, media;
    
    printf("Digite o número do aluno: ");
    scanf("%d", &id);
    
    printf("Digite as 4 notas: ");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    
    media = (n1 + n2 + n3 + n4) / 4;
    
    if(media >= 9){
        conceito = 'A';
    }else if(media >= 7.5){
        conceito = 'B';
    }else if(media >= 6){
        conceito = 'C';
    }else if(media >= 4){
        conceito = 'D';
    }else{
        conceito = 'E';
    }
    
    printf("\nAluno: %d", id);
    printf("\nMedia: %.2f", media);
    printf("\nConceito: %c", conceito);
    
    if(conceito == 'A' || conceito == 'B' || conceito == 'C'){
        printf("\nSituacao: APROVADO\n");
    }else{
        printf("\nSituacao: REPROVADO\n");
    }
}
