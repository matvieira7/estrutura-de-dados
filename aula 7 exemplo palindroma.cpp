#include<stdio.h>

#include<locale.h>

#include<string.h> //Biblioteca para funcionar as fun��es de string.

main() {

    setlocale(LC_ALL, "Portuguese");

    int valor;

    char palavra[15], inversa[15];

    printf("\nDigite uma palavra: ");

    gets(palavra);

    //strcpy(destino, origem): Copia o conte�do da string origem para a string destino.

    strcpy(inversa, palavra);

    printf("\nTestando a fun��o strcpy: %s %s", palavra, inversa);

    //Inverte a palavra (reverse). Exemplo: Se o conte�do da vari�vel inversa for Samuel > Leumas.

    strrev(inversa);

    printf("\nTestando a fun��o strrev: %s %s", palavra, inversa);

    /*

    A fun��o strcmp realiza uma compara��o entre a string1 e string2,

    retornando um valor que indica a rela��o entre elas,

    caso sejam iguais a fun��o strcmp retorna 0.

    */

    valor = strcmp(palavra, inversa);

    printf("\nTestando o retorno da fun��o strcmp: %d", valor);

    if(valor == 0)

        printf("\nA palavra %s � pal�ndroma\n", palavra);

    else

        printf("\nA palavra %s n�o � pal�ndroma\n", palavra);

}
 
