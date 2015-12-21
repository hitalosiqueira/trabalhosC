#include <stdio.h>
 
void motoboy(int n);
int mochila(int c[], int w[], int n, int W);
 
int main() {
    int n;
 
    do{
        scanf("%d", &n);
        if(n != 0){
            motoboy(n);
        }
    }while(n!=0);
 
    return 0;
}
 
void motoboy(int n){
    int i, c[n + 1], w[n + 1], W;
 
    scanf("%d", &W);
 
    for(i = 1; i <= n; i++){
        scanf("%d %d", &c[i], &w[i]);
    }
 
 
    printf("%d min.\n", mochila(c, w, n, W));
}
 
int mochila(int c[], int w[], int n, int W){
    int d, k, z[n + 1][W + 1];
 
    for(d = 0; d <= W; d++){
        z[0][d] = 0;
    }
 
    for(k = 1; k <= n; k++){
        for(d = 0; d <= W; d++){
            z[k][d] = z[k-1][d];
            if((w[k] <= d) && (c[k] + z[k-1][d-w[k]] > z[k][d])){
                z[k][d] = c[k] + z[k-1][d-w[k]];
            }
        }
    }
 
    return z[n][W];
}