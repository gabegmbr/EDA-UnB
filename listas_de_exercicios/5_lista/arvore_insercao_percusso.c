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

no *criar_no(int x){
    no *novo = malloc(sizeof(no));
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//funções de empilhamento
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

//funções de impressão de árvore: pre-order, in-order, post-order

void pre_ordem (no *raiz){
    celula *pilha = malloc(sizeof(celula));
    no *tmp = raiz;
    while(tmp != NULL || pilha->prox != NULL){
        if(tmp != NULL){
            printf("%d ", tmp->dado);
            empilha(pilha, tmp);
            tmp = tmp->esq;
        }
        else{
            tmp = pilha->prox->no;
            tmp = tmp->dir;
            desempilha(pilha);
        }
    }
    free(pilha);
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
    free(pilha);
}

void pos_ordem (no *raiz){
    celula *pilha = malloc(sizeof(pilha));
    no *tmp = raiz;
    no *tmp_anterior = NULL;
    while(tmp != NULL || pilha->prox != NULL){
        if (tmp != NULL){
            empilha(pilha, tmp);
            tmp = tmp->esq;
        }
        else{
            tmp = pilha->prox->no;
            if(tmp->dir == NULL || tmp->dir == tmp_anterior){
                printf("%d ", tmp->dado);
                desempilha(pilha);
                tmp_anterior = tmp;
                tmp = NULL;
            }
            else{
                tmp = tmp->dir;
            }
        }
    }
    free(pilha);
}

void insere(no *no, int x){ //função inserir na árvore. 
    if(x > no->dado){
        if(no->dir == NULL){
            no->dir = criar_no(x);
            return;
        }
            insere(no->dir, x);
    }
    if(x < no->dado){
        if(no->esq == NULL){
            no->esq = criar_no(x);
            return;
        }
        insere(no->esq, x);
    }
}



int main () {
    int x;
    scanf("%d ", &x);
    no *raiz = criar_no(x);
    while(scanf("%d", &x) != EOF){
        insere(raiz, x);
    }
    printf("\n");
    pre_ordem(raiz);
    printf(".");
    printf("\n");
    em_ordem(raiz);
    printf(".");
    printf("\n");
    pos_ordem(raiz);
    printf(".");

}