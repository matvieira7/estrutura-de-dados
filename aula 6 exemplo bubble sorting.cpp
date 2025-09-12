#include<stdio.h>
#include<locale.h>

main()
{
	int numeros[100],i,passo,qtde_numeros,temporario;
	
	setlocale(LC_ALL, "Potuguese");
	
	printf("Digite o número de elementos que deseja ordenar: ");
	scanf("%d",&qtde_numeros);
	
	for(i=0;i<qtde_numeros;i++){
		printf("%d. Insira o elemento aqui:",i+1);
		scanf("%d",&numeros[i]); 
	}
	
	for(passo=1;passo<qtde_numeros;passo++){
		for(i=0;i<qtde_numeros-1;i++){
			if(numeros[i]>numeros[i+1]){
				temporario=numeros[i];
				numeros[i]=numeros[i+1];
				numeros[i+1]=temporario;
			}
		}
	}
	
	printf("Em ordem crescente: ");
	for(i=0;i<qtde_numeros;i++)
		printf("%d ",numeros[i]);
}
