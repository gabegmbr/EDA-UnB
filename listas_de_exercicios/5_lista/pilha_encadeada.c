#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha (celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return 0;
    }
    else{
        novo->dado = x;
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
    }
}

int desempilha (celula *p, int *y){
    celula *tmp = p->prox;
    if(tmp == NULL) return 0;
    else{
        *y = tmp->dado;
        p->prox = tmp->prox;
        free(tmp);
        return 1;
    }
}