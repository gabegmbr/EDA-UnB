#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void remove_depois(celula *p){
    if(p->prox == NULL){p->prox = NULL;}
    else{p->prox = p->prox->prox;}
    return;
}

void remove_elemento (celula *le, int x){
    le = le->prox;
    if(le == NULL){return;}
    if(le->prox != NULL && le->prox->dado == x){le->prox = le->prox->prox; return;}
    remove_elemento (le, x);
}

void remove_todos_elementos (celula *le, int x){
    le = le->prox;
    if(le == NULL){return;}
    if(le->prox != NULL && le->prox->dado == x){le->prox = le->prox->prox;}
    remove_todos_elementos (le, x);
}