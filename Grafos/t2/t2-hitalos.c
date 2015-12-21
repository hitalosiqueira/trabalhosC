#include <stdio.h>
#include <stdlib.h>

#define PRETO 2
#define CINZA 1
#define BRANCO 0
#define NULO -1

typedef struct NO{
	int v;
	struct NO *prox;
}no;
typedef no* lista;

void iniciaLista(lista *pl);
void insereInicio(lista *pl, int vertice);
void insereFim(lista *pl, int vertice);
void liberaLista(lista *pl);
void imprimeLista(lista *pl);
void removeInicio(lista *pl, int *vertice);
int buscaLargura(lista listaAdj[], int n);

void erdosNumber(int n, int m);

int main() {
	int n, m;

	do{
		scanf("%d %d", &n, &m);
		if((n != 0)){
			erdosNumber(n, m);
		}
	}while((n!=0));
	return 0;
}

void iniciaLista(lista *pl){
	*pl = NULL;
}

void insereInicio(lista *pl, int vertice){
	no *novoNo;
	novoNo = (no*) malloc(sizeof(no));

	novoNo->v = vertice;
	novoNo->prox = *pl;

	*pl = novoNo;
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

void removeInicio(lista *pl, int *vertice){
	no *aux;

	aux = *pl;
	if(aux == NULL){	
		return;
	}else{
		*pl = aux->prox;
		*vertice = aux->v;
		free(aux);
	}
}

int buscaLargura(lista listaAdj[], int n){
	lista q;
	int vertice, max, i, dist[n], cor[n], pred[n];
	no *aux;

	for(i=0;i<n;i++){
		dist[i] = n + 1;
		cor[i] = BRANCO;
		pred[i] = n + 1;
	}

	dist[0] = 0;
	cor[0] = CINZA;
	pred[0] = NULO;

	iniciaLista(&q);
	insereFim(&q, 0);

	while(q != NULL){
		removeInicio(&q, &vertice);
		aux = listaAdj[vertice];

		while(aux != NULL){
			if(cor[aux->v] == BRANCO){
				cor[aux->v] = CINZA;
				dist[aux->v] = dist[vertice] + 1;
				pred[aux->v] = vertice;
				insereFim(&q, aux->v);
			}
			
			cor[vertice] = PRETO;
			aux = aux->prox;
		}	
	}

	max = 0;
	for(i = 0; i < n; i++){
		if(max < dist[i]){ 
			max = dist[i];
		}
	}
	return max;
}

void erdosNumber(int n, int m){
	int A, B, i, max;
	lista listaAdj[n];

	for(i=0;i<n;i++){
		iniciaLista(&listaAdj[i]);
	}

	for(i = 0; i < m; i++){
		scanf("%d %d", &A, &B);

		insereInicio(&listaAdj[A], B);
		insereInicio(&listaAdj[B], A);
	}

	max = buscaLargura(listaAdj, n);
	
	if(max == n + 1){
		printf("infinito\n");
	}else{
		printf("%d\n", max);
	}

	for(i=0;i<n;i++){
		liberaLista(&listaAdj[i]);
	}

}