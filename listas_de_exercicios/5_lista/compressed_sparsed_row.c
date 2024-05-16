#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int linha;
    int coluna;
    int dado;
    struct celula *prox;
} celula;

void *enfileira (celula **f, int n, int m, int d){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return NULL;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->linha = n;
    (*f)->coluna = m;
    (*f)->dado = d;
    *f = novo;
}

int main (){
    celula *matriz = malloc(sizeof(celula));
    matriz->dado = -1;
    matriz->prox = matriz;

    int n, m;
    scanf("%d%d", &m, &n);
    
    int linha, coluna, valor;
    while(linha != -1 && coluna != -1 && valor != -1){
        scanf("%d%d%d", &linha, &coluna, &valor);
        enfileira(&matriz, linha, coluna, valor);
    }

    int *vetor = malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    int *resultado = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) resultado[i] = 0;

    while(matriz->prox->dado != -1){
        matriz = matriz->prox;
        resultado[matriz->linha]+= vetor[matriz->coluna]*matriz->dado; 
    }

    for(int i = 0; i < m; i++) printf("%d\n", resultado[i]);
}