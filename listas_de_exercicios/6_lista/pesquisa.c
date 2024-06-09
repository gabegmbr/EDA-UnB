#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    char *inst;
    struct no *esq, *dir;
} no;


no *criar_no(int x, char *inst){
    no *novo = malloc(sizeof(no));
    novo->inst = inst;
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insere(no *no, int x, char *inst){ //função inserir na árvore. 
    if(x > no->dado){
        if(no->dir == NULL){
            no->dir = criar_no(x, inst);
            return;
        }
            insere(no->dir, x, inst);
    }
    if(x < no->dado){
        if(no->esq == NULL){
            no->esq = criar_no(x, inst);
            return;
        }
        insere(no->esq, x, inst);
    }
}

no *procura (no *raiz, int x){
    no *atual = raiz;
    if(atual == NULL) return NULL;
    if(atual->dado == x) return atual;
    if(atual->dado > x) procura(atual->esq, x);
    else procura(atual->dir, x);
}

int main (){
    int n;
    scanf("%d", &n);
    int id_raiz;
    char inst_raiz[16];
    scanf("%d %s", &id_raiz, inst_raiz);
    no *raiz = criar_no(id_raiz, inst_raiz);

    for(int i = 0; i < n-1; i++){
        int id;
        char *inst = malloc(sizeof(char)*16);
        scanf("%d", &id);
        scanf("%s", inst);
        insere(raiz, id, inst);
    }
    
    int id;
    while(scanf("%d", &id) != EOF){
        no *result = procura(raiz, id);
        if(result != NULL) printf("%s\n", result->inst);
        else printf("undefined\n");
    }
}