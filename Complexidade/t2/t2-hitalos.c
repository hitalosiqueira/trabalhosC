#include <stdio.h>

int mat[5000][5000];

void tribruxo(int n);

int main() {
	int n;

	do{
		scanf("%d", &n);
		if(n != 0){
			tribruxo(n);
		}
	}while(n!=0);

	return 0;
}

void tribruxo(int n){
	int i, j, max;

	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			scanf("%d",&mat[i][j]);
		}
	}

	for(i=1;i<n;i++){
		for(j=0;j<=i;j++){
			if(j == 0){
				mat[i][j] += mat[i-1][j];
			}else{
				if(j<i){
					if(mat[i-1][j] >= mat[i-1][j-1]){   
						mat[i][j] += mat[i-1][j];
					}else{
						mat[i][j] += mat[i-1][j-1];
					}
				}else{
					mat[i][j] += mat[i-1][j-1];
				}
			}
		}
	}

	max = 0;
	for (j=0;j<n;j++){
		if (mat[n-1][j] > max)
			max = mat[n-1][j];
	}

	printf("%d\n", max);

}