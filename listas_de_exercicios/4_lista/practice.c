#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime_rec (celula *le);

void remove_depois(celula *p){
    if(p->prox == NULL){p->prox = NULL;}
    else{p->prox = p->prox->prox;}
    return;
}

void main () {
    celula *lista = malloc(sizeof(celula));
    celula *lista2 = malloc(sizeof(celula));
    celula *lista3 = malloc(sizeof(celula));

    celula *c1 = malloc(sizeof(celula));
    celula *c2 = malloc(sizeof(celula));
    celula *c3 = malloc(sizeof(celula));
    celula *c4 = malloc(sizeof(celula));

    celula *d1 = malloc(sizeof(celula));
    celula *d2 = malloc(sizeof(celula));
    celula *d3 = malloc(sizeof(celula));
    celula *d4 = malloc(sizeof(celula));

    lista->prox = c1;
    lista2->prox = d1;
    lista3->prox = NULL;

    c1->prox = c2;
    c2->prox = c3;
    c3->prox = c4;
    c4->prox = NULL;

    c1->dado = 1;
    c2->dado = 2;
    c3->dado = 3;
    c4->dado = 4;

    d1->prox = d2;
    d2->prox = d3;
    d3->prox = d4;
    d4->prox = NULL;

    d1->dado = 2;
    d2->dado = 4;
    d3->dado = 6;
    d4->dado = 8;

    imprime_rec(lista);
    remove_depois(c1);
    imprime_rec(lista);
}

void imprime_rec (celula *le){
    le = le->prox;
    if(le == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->dado);
    imprime_rec(le);
}