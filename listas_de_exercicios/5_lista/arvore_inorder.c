#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct celula {
    struct no *no ;
    struct celula *prox;
} celula;

int empilha (celula *p, no *n){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return 0;
    }
    else{
        novo->no = n;
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
    }
}

int desempilha (celula *p){
    celula *tmp = p->prox;
    if(tmp == NULL) return 0;
    else{
        p->prox = tmp->prox;
        free(tmp);
        return 1;
    }
}

void em_ordem (no *raiz){
    celula *pilha = malloc(sizeof(pilha));
    no *tmp = raiz;
    while(tmp != NULL || pilha->prox != NULL){
        if(tmp != NULL){
            empilha(pilha, tmp);
            if(tmp->esq == NULL){
                tmp = NULL;
            }
            else tmp = tmp->esq;
        }
        else{
            tmp = pilha->prox->no;
            desempilha(pilha);
            printf("%d ", tmp->dado);
            tmp = tmp->dir;
        }
    }
}