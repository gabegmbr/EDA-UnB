#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int redimensiona(pilha *p){

}

int empilha (pilha *p, int x){
    if(p->topo == p->N){
        return 0;
    }
    p->dados[p->topo++] = x;
}

int desempilha(pilha *p){
    if(p->topo-1 == -1){
        p->dados[p->topo]
    }else{
        p->dados[p->topo--];
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
    empilha(stack, 2);

    for(int i = 0; i < stack->topo; i++){
        printf("%d ", stack->dados[i]);
    }
}