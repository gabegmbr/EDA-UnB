#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int empilha (pilha *p, int x);

int main (){
    pilha *stack = malloc(sizeof(stack));
    stack->N = 5;
    stack->dados = (int*)malloc(stack->N * sizeof(int));
    if(stack->dados == NULL){
        printf("memory allocation error.\n");
        exit(0);
    }
}