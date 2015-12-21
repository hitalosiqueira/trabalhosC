#include <stdio.h>
#include <stdlib.h>

#define PRETO 2
#define CINZA 1
#define BRANCO 0
#define NULO -1
#define MAX 6000

typedef struct NO{
	int v;
	struct NO *prox;
}no;
typedef no* lista;

int cor[MAX], pred[MAX], d[MAX], f[MAX], peso[MAX], tempo, elementos, topSort[MAX];

void iniciaLista(lista *pl);
void insereInicio(lista *pl, int vertice);
void insereFim(lista *pl, int vertice);
void liberaLista(lista *pl);
void imprimeLista(lista *pl);
void removeInicio(lista *pl, int *vertice);
void DFS(lista listaAdj[], int n);
void DFS_AUX(lista listaAdj[], no *aux, int u);

void dependenciaProjetos(int n, int m);

int main() {
	int n, m;

	do{
		scanf("%d %d", &n, &m);
		if((n != 0)){
			dependenciaProjetos(n, m);
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

void DFS(lista listaAdj[], int n){
	int i, pesoAux[n], tempoMax;
	no *aux;

	for(i=0;i<n;i++){
		cor[i] = BRANCO;
		pred[i] = NULO;
		d[i] = NULO;
		f[i] = NULO;
	}
	tempo = 0;

	for(i=0;i<n;i++){
		if(cor[i] == BRANCO){
			DFS_AUX(listaAdj, aux, i);
		}
	}
	for(i=0;i<n;i++){
		pesoAux[i] = peso[i];
	}

	for(i=0;i<n;i++){
		aux = listaAdj[topSort[i]];
		while(aux != NULL){
			if(pesoAux[aux->v] < pesoAux[topSort[i]] + peso[aux->v]){
				pesoAux[aux->v] = pesoAux[topSort[i]] + peso[aux->v];
			}
			aux = aux->prox;
		}
	}

	tempoMax = 0;
	for(i=0;i<n;i++){
		if(tempoMax < pesoAux[i]){
			tempoMax = pesoAux[i];
		}
	}
	printf("%d\n",tempoMax);
}

void DFS_AUX(lista listaAdj[], no *aux, int u){

	cor[u] = CINZA;
	d[u] = tempo;
	tempo++;

	aux = listaAdj[u];

	while(aux != NULL){
		if(cor[aux->v] == BRANCO){
			pred[aux->v] = u;
			DFS_AUX(listaAdj, aux, aux->v);
		}
		aux = aux->prox;
	}
	cor[u] = PRETO;
	f[u] = tempo;

	topSort[elementos] = u;
	elementos--;
	tempo++;
}

void dependenciaProjetos(int n, int m){
	int i, u, v;
	lista listaAdj[n];

	elementos = n - 1;


	for(i=0;i<n;i++){
		iniciaLista(&listaAdj[i]);
	}

	for(i=0;i<n;i++){
	 	scanf("%d", &peso[i]);
	}

	for(i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		insereFim(&listaAdj[u], v);
	}

	DFS(listaAdj, n);

	for(i=0;i<n;i++){
		liberaLista(&listaAdj[i]);
	}

}