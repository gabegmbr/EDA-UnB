#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;


void divide_lista (celula *l, celula *l1, celula *l2){
    l = l->prox;
    if(l == NULL){
        l1->prox = NULL;
        l2->prox = NULL;
        return;
    }
    if(l->dado%2 == 0){
        l2->prox = l;
        divide_lista(l, l1, l2->prox);
    }
    if(l->dado%2 != 0){
        l1->prox = l;
        divide_lista(l, l1->prox, l2);
    }
}