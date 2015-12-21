#include <stdio.h>
#define SIM 1;
#define NAO 0;

void ordena(int n, int vetor[]);
int buscaSoma(int vetorA[], int elementoB, int vetorC[], int inicioA, int fimC, int fim, int x);
void pescaria(int n, int x);


int main() {
	int n, x;

	do{
		scanf("%d %d", &n, &x);
		if((n != 0)){
			pescaria(n, x);
		}
	}while((n!=0));
	return 0;
}

void pescaria(int n, int x){
	int vetorA[n], vetorB[n], vetorC[n], i;

	for (i=0;i<n;i++){
		scanf("%d", &vetorA[i]);
	}

	for (i=0;i<n;i++){
		scanf("%d", &vetorB[i]);
	}

	for (i=0;i<n;i++){
		scanf("%d", &vetorC[i]);
	}

	ordena(n,vetorA);
	ordena(n,vetorC);

	for(i=0;i<n;i++){
		if(buscaSoma(vetorA, vetorB[i], vetorC, 0, n-1, n-1, x)){
			printf("SIM\n");
			return;
		}
	}
	printf("NÃO\n");
}

void ordena(int n, int vetor[]){
	int i, j, aux;

	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(vetor[j] > vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

int buscaSoma(int vetorA[], int elementoB, int vetorC[], int inicioA, int fimC, int fim, int x){
	if(inicioA == fim || fimC == 0){
		return NAO;
	}else{
		if(vetorA[inicioA] + elementoB + vetorC[fimC] == x){
			return SIM;
		}else{
			if(vetorA[inicioA] + elementoB + vetorC[fimC] < x){
				return buscaSoma(vetorA, elementoB, vetorC, inicioA + 1, fimC, fim, x);
			}else{
				return buscaSoma(vetorA, elementoB, vetorC, inicioA, fimC - 1, fim, x);
			}
		}
	}
}