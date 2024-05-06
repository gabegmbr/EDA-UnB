#include <stdio.h> 
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int resize(fila *f){

}

int enfileira (fila *f, int x){
    if(f->u == f->N){
        f->u = 0;
    }
    if(f->u+1 == f->p){
        
    }
    f->dados[f->u++] = x;
    return 1;
}

int main () {
    fila *queue = malloc(sizeof(fila));
    queue->N = 3;
    queue->u = queue->p = 1;
    queue->dados = calloc(queue->N, sizeof(int));

    enfileira(queue, 10);
    enfileira(queue, 20);
    enfileira(queue, 30);

    for (int i = 0; i < queue->N; i++){
        printf("[%d] = [%d] ", i, queue->dados[i]);
        if(i == queue->p) printf("(inicio da fila) ");
        if(i == queue->u) printf("(final da fila)");
        printf("\n");
    }
}