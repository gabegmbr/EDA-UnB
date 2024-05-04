#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int redimensiona(pilha *p){
    p->dados = realloc(p->dados, p->N*2*sizeof(int));
    if(p->dados == NULL) return 0;
    p->N = p->N*2;
    return 1;
}

int empilha (pilha *p, int x){
    if(p->topo == p->N){ //PILHA CHEIA
        if(redimensiona(p) != 1) return 0;
    }
    p->dados[p->topo++] = x;
    return 1;
}

int desempilha(pilha *p, int *y){
    if(p->topo-1 == -1){ //PILHA VAZIA
        return 0;
    }
    else{
        *y = p->dados[p->topo-1];
        p->dados[p->topo--];
        return 1;
    }
}