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

no *criar_no(int x){
    no *novo = malloc(sizeof(no));
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
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
    int n, m;
    printf("%ld", sizeof(int));
    scanf("%d %d", &n, &m);

    no *head = malloc(sizeof(no));
    head->esq = head->dir = NULL;
    scanf("%d", &head->dado);

    for(int i = 1; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        insere(head, tmp);
    }

    for(int i = 0; i < m; i++){
        int compare;
        int j = 0;
        no *tmp = head;
        scanf("%d", &compare);
        while(tmp != NULL){
            if(compare > tmp->dado){
                if(tmp->dir == NULL) break; 
                tmp = tmp->dir;
                j++;
            }
            if(compare <= tmp->dado){
                if(tmp->esq == NULL) break;
                tmp = tmp->esq;
                j++;
            }
        }
        if(tmp->dado < compare) j++;
        printf("%d\n", j);
    }
}