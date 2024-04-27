#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

//inicializar listas l1, l2
//ordenar nós

void divide_lista (celula *l, celula *l1, celula *l2){

}

void main () {
    celula c1, c2, c3, c4;
    celula *l;
    celula *l1 = NULL, *l2 = NULL;

    c1.dado = 4;
    c2.dado = 1;
    c3.dado = 10;
    c4.dado = 7;

    l = &c3;
    c3.prox = &c2;
    c2.prox = &c1;
    c1.prox = &c4;
    c4.prox = NULL;

    divide_lista(l, l1, l2);
}