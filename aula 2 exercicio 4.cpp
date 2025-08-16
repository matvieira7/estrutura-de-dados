#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL, "Portuguese");
    
    int codigo, ano_nasc, ano_ingresso, ano_atual;
    int idade, tempo;
    int pode;
    
    printf("Digite o código do empregado: ");
    scanf("%d", &codigo);
    
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano_nasc);
    
    printf("Digite o ano de ingresso na empresa: ");
    scanf("%d", &ano_ingresso);
    
    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);
    
    idade = ano_atual - ano_nasc;
    tempo = ano_atual - ano_ingresso;
    
    if(idade >= 65 or tempo >= 30 or (idade >= 60 and tempo >= 25)){
        pode = 1;
    }else{
        pode = 0;
    }
    
    printf("\nIdade: %d", idade);
    printf("\nTempo de trabalho: %d", tempo);
	printf("\nPode aposentar: %s\n", pode ? "SIM" : "NÃO");
}
