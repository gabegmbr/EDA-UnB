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

int main (){
    pilha *stack = malloc(sizeof(stack));
    stack->N = 5;
    stack->topo = 0;
    stack->dados = (int*)malloc(stack->N * sizeof(int));
    if(stack->dados == NULL){
        printf("memory allocation error.\n");
        exit(0);
    }

    empilha(stack, 1);
    empilha(stack, 3);
    empilha(stack, 6);
    empilha(stack, 49);
    empilha(stack, 69);
    empilha(stack, 71);

    for(int i = 0; i < stack->topo; i++){
        printf("%d ", stack->dados[i]);
    }
}