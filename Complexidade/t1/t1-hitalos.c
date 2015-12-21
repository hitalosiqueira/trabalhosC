#include <stdio.h>
#define MAX 1000000

//protótipo da função que calcula a soma
int somaMaximaVetor(int vet[], int tam);

//função principal
int main () {
	int vet[MAX], tam, i, sair = 0;

	do{
		//leitura da quantidade de elementos
		scanf("%d",&tam);
		if(tam == 0){
			sair = 1;
		}else{
			//leitura do vetor
			for(i = 0;i < tam; i++){
				scanf("%d ",&vet[i]);
			}
			//print do retorno da chamada de função
			printf("%d\n", somaMaximaVetor(vet,tam));
		}
	}while (sair != 1);
}

//função que calcula a soma maxima consecutiva em um vetor
int somaMaximaVetor(int vet[], int tam){
	
	//declara-se duas variaveis que serão usadas para calcular a soma maxima
	int max = 0, maxAux = 0, i;
	for(i = 0;i < tam; i++) {
		//a variavel de maximo auxiliar vai sendo agregada do valor de cada posição no vetor
		maxAux += vet[i];
		//se caso no momento que fizer a soma, for obtido um numero negativo
		if(maxAux < 0){
			//zera-se novamente a variavel auxiliar
			maxAux = 0;
		}else{ 
			//se nao, compara-se o valor dela, com o maximo que se tem atualmente
			//se o maximo ate o momento for menor, atribui-se o valor da variavel auxiliar
			//essa verificação, garante que a maior soma será de fato a que será retornada pela função
			if (max < maxAux){
				max = maxAux;
			}
		}
	}
	//retorno do valor da soma
	return max;
}
