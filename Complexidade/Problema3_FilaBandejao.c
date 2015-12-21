#include <stdio.h>

void bandejao(int n);
int distancias(int fila[], int n, int k);
void ordena(int v[], int n);
 
int main() {
    int n;
 
     while(scanf("%d", &n) != EOF){
        bandejao(n);
    }
 
    return 0;
}
 
void bandejao(int n){
    int i, fila[n], k, maior;

    scanf("%d", &k);
    fila[0] = 0;
    for(i = 1; i < n; i++){
        scanf("%d", &fila[i]);
    }

    printf("%d\n", distancias(fila, n, k));
 
}
 
int distancias(int fila[], int n, int k) {
    int i, j = 1, cont = 0, aux[n-1];

    for(i = 0; i < n - 1; i++){
        aux[i] = fila[j] - fila[i];
        j++;
    }


    ordena(aux, n-1);

    for(i = k - 1; i < n - 1; i++){
        cont += aux[i];
    }

    return cont;

}

void ordena(int v[], int n){
    int i, j, aux;

    for(i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(v[j] < v[j+1]){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}