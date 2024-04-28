#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime_rec (celula *le);

void mescla_listas (celula *l1, celula *l2, celula *l3) {
    l1 = l1->prox, l2 = l2->prox;
    for(;;l3 = l3->prox){
        if(l1 != NULL && l2 != NULL){
            if(l1->dado <= l2->dado){l3->prox = l1; l1 = l1->prox;}
            else{l3->prox = l2; l2 = l2->prox;}
        }
        else if(l1 != NULL){l3->prox = l1; l1 = l1->prox;}
        else if(l2 != NULL){l3->prox = l2; l2 = l2->prox;}
        else{return;}
    }
}

void ordena_lista (celula *le);

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
    c2->dado = 3;
    c3->dado = 5;
    c4->dado = 7;

    d1->prox = d2;
    d2->prox = d3;
    d3->prox = d4;
    d4->prox = NULL;

    d1->dado = 2;
    d2->dado = 4;
    d3->dado = 6;
    d4->dado = 8;

    imprime_rec(lista);
    imprime_rec(lista2);
    mescla_listas(lista, lista2, lista3);
    imprime_rec(lista3);
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