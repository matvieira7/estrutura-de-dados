#include<stdio.h>

#include<locale.h>

#include<string.h> //Biblioteca para funcionar as funções de string.

main() {

    setlocale(LC_ALL, "Portuguese");

    int valor;

    char palavra[15], inversa[15];

    printf("\nDigite uma palavra: ");

    gets(palavra);

    //strcpy(destino, origem): Copia o conteúdo da string origem para a string destino.

    strcpy(inversa, palavra);

    printf("\nTestando a função strcpy: %s %s", palavra, inversa);

    //Inverte a palavra (reverse). Exemplo: Se o conteúdo da variável inversa for Samuel > Leumas.

    strrev(inversa);

    printf("\nTestando a função strrev: %s %s", palavra, inversa);

    /*

    A função strcmp realiza uma comparação entre a string1 e string2,

    retornando um valor que indica a relação entre elas,

    caso sejam iguais a função strcmp retorna 0.

    */

    valor = strcmp(palavra, inversa);

    printf("\nTestando o retorno da função strcmp: %d", valor);

    if(valor == 0)

        printf("\nA palavra %s é palíndroma\n", palavra);

    else

        printf("\nA palavra %s não é palíndroma\n", palavra);

}
 
