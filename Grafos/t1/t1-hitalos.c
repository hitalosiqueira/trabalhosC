#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct NO{
	int v;
	struct NO *prox;
}no;
typedef no* lista;

void iniciaLista(lista *pl);
void insereFim(lista *pl, int vertice);
void liberaLista(lista *pl);
void imprimeLista(lista *pl);

void comMatriz(int n);
void comLista(int n);

int main() {
	int n;

	do{
		scanf("%d", &n);
		if(n != 0){
			comLista(n);
			//comMatriz(n);
		}
	}while(n!=0);
	
	return 0;
}

void comMatriz(int n){
	int i, j, matAdj[MAX][MAX], m = 0;

	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			scanf("%d", &matAdj[i][j]);
			if (matAdj[i][j] == 1){
				m++;
			}
		}
	}

	printf("%d %d\n", n, m);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matAdj[i][j] == 1){
				printf("%d ", j);
			}
		}
		printf("\n");
	}
}

void iniciaLista(lista *pl){
	*pl = NULL;
}

void insereFim(lista *pl, int vertice){
	no *novoNo, *aux;
	
	if(*pl == NULL){
		novoNo = (no*) malloc(sizeof(no));
		novoNo->v = vertice;
		novoNo->prox = NULL;
		
		*pl = novoNo;

	}else{
		aux = *pl;
		insereFim(&(aux->prox), vertice);
	}
}

void liberaLista(lista *pl){
	no *aux;
	
	aux = *pl;
	if(*pl != NULL){
		if(aux->prox != NULL){
			liberaLista(&(aux->prox));
		}
	}
	free(*pl);
	*pl = NULL;
}

void imprimeLista(lista *pl){
	no *aux;
	
	aux = *pl;
	if(aux == NULL){	
		return;
	}else{
		printf("%d ", aux->v);
		imprimeLista(&(aux->prox));
	}
}

void comLista(int n){
	int entrada, i, j, m = 0;
	lista listaAdj[n];

	for(i=0;i<n;i++){
		iniciaLista(&listaAdj[i]);
	}

	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			scanf("%d", &entrada);
			if (entrada == 1){
				insereFim(&listaAdj[i], j);
				m++;
			}
		}
	}

	printf("%d %d\n", n, m);
	for(i=0;i<n;i++){
		imprimeLista(&listaAdj[i]);
		printf("\n");
	}

	for(i=0;i<n;i++){
		liberaLista(&listaAdj[i]);
	}
}

