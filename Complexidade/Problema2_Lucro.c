#include <stdio.h>

int somaMaximaVetor(int vet[], int tam);
void lucro(int n);
 
int main () {
    int n;
 
    while(scanf("%d", &n) != EOF){
        lucro(n);
    }
 
    return 0;
}

void lucro(int n){
    int receita[n], i, custo, aux;
    scanf("%d", &custo);

    for(i=0;i<n;i++){
        scanf("%d", &aux);
        receita[i] = aux - custo;
    }

    printf("%d\n", somaMaximaVetor(receita, n));   

}

int somaMaximaVetor(int vet[], int tam){
     
    int max = 0, maxAux = 0, i;
    for(i = 0;i < tam; i++) {

        maxAux += vet[i];
        if(maxAux < 0){
            maxAux = 0;
        }else{ 
            if (max < maxAux){
                max = maxAux;
            }
        }
    }
    return max;
}