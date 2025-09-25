#include<stdio.h>
#include<locale.h>
#include<string.h>
main(){
   setlocale(LC_ALL, "Portuguese");
   char senha[20] = "12345";
   char tentativa[20];
   printf("Digite a senha: ");
   fflush(stdin);
   gets(tentativa);
   if(strcmp(senha, tentativa) == 0){
       printf("Senha correta!\n");
   } else {
       printf("Senha incorreta!\n");
   }
}
