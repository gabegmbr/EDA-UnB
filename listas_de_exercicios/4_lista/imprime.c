#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le) {
    for(celula *tmp = le->prox; tmp != NULL; tmp = tmp->prox){
        printf("%d -> ", tmp->dado);
    }
    printf("NULL\n");
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