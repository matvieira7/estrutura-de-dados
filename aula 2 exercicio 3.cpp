#include<stdio.h>
#include<locale.h>

main(){
    setlocale(LC_ALL, "Portuguese");
    
    char tipo;
    float litros, preco, total;
    
    printf("Digite o tipo de combustível (A para álcool e G para gasolina): ");
    scanf(" %c", &tipo);
    
    printf("Digite a quantidade de litros: ");
    scanf("%f", &litros);
    
    if(tipo == 'A'){
        preco = 3.49;
        if(litros <= 20){
            total = litros * preco * 0.97;
        }else{
            total = litros * preco * 0.95;
        }
    }else if(tipo == 'G'){
        preco = 5.49;
        if(litros <= 20){
            total = litros * preco * 0.96;
        }else{
            total = litros * preco * 0.94;
        }
    }else{
        printf("Tipo inválido!\n");
        return 0;
    }
    
    printf("Valor a pagar: R$ %.2f\n", total);
}
