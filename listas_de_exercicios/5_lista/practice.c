#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int resize (fila *f){
    f->dados = realloc(f->dados, sizeof(int)*f->N*2);
    if (f->dados == NULL) return 0;
    for(int i = f->N; i < f->N*2; i++){
        f->dados[i] = 0;
    }
    f->N = f->N*2;
    return 1;
}

int enfileira (fila *f, int x) {
    if (f->u == f->N-1){
        if(resize(f) != 1) return 0;
    } 
    f->dados[f->u] = x;
    f->u = (f->u + 1)%f->N;
    return 1;
}

int desenfileira (fila *f, int *y){
    if (f->p == f->u){
        return 0;
    }
    else{
        *y = f->dados[f->p];
        f->p++;
        return 1;
    }
}

int main (){
    fila *queue = malloc(sizeof(fila));
    queue->dados = calloc(5, sizeof(int));
    queue->N = 4;
    queue->p = 0;
    queue->u = 0;

    enfileira(queue, 1);
    enfileira(queue, 2);
    enfileira(queue, 3);
    enfileira(queue, 3);
    enfileira(queue, 3);
    enfileira(queue, 3);

    for (int i = 0; i < queue->N; i++){
        printf("%d ", queue->dados[i]);
    }
}