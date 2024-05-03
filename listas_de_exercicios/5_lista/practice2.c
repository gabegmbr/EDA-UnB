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
void imprime_rec (celula *le){
    le = le->prox;
    if(le == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->dado);
    imprime_rec(le);
}

int main () {
    celula *pilha = malloc(sizeof(celula));
    pilha->prox = NULL;
    empilha(pilha, 10);
    empilha(pilha, 1235240);
    empilha(pilha, 30);
    imprime_rec(pilha);
}