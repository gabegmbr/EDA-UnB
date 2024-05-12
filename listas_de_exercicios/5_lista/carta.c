#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void *enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return NULL;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = x;
    *f = novo;
}

int desenfileira (celula *f, int *y){
    if(f->prox == f){
        return 0;
    }
    celula *remove = f->prox;
    *y = remove->dado;
    f->prox = remove->prox;
    free(remove);
    return 1;
}

void move_fim(celula **f){
    enfileira(f, (*f)->prox->dado);
    desenfileira((*f), 0);
}

int main () {
    celula *cartas = malloc(sizeof(celula));
    cartas->prox = NULL;
    celula *descartadas = malloc(sizeof(celula));
    descartadas->prox = NULL;
    int n = 6;
    
    for (int i = 2; i <= 6; i++){
        enfileira(&cartas, i);
    }   

    while(cartas != NULL){
        int x;
        desenfileira(cartas, &x);
        enfileira(&descartadas, x);
        move_fim(&cartas);
    }
}