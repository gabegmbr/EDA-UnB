#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime_rec (celula *le);

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

void main () {
    celula *lista = malloc(sizeof(celula));
    celula *lista_par = malloc(sizeof(celula));
    celula *lista_impar = malloc(sizeof(celula));
    celula *c1 = malloc(sizeof(celula));
    celula *c2 = malloc(sizeof(celula));
    celula *c3 = malloc(sizeof(celula));
    celula *c4 = malloc(sizeof(celula));

    lista->prox = c1;

    c1->prox = c2;
    c2->prox = c3;
    c3->prox = c4;
    c4->prox = NULL;

    c1->dado = 1;
    c2->dado = 2;
    c3->dado = 4;
    c4->dado = 3;

    imprime_rec(lista);
    divide_lista(lista, lista_impar, lista_par);
    imprime_rec(lista_impar);
    imprime_rec(lista_par);
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