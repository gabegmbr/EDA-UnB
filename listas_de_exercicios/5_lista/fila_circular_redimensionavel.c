#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;


int redimensiona(fila *f){
    int *novo = malloc(sizeof(int)*f->N*2);
    if(novo == NULL) return 0;

    int i;
    int y;
    int tmp = f->u;

    for(i = 0; i <= f->u; i++) novo[i] = f->dados[i]; 
    for(y = 0; y < f->N; y++) novo[y+i] = 0;
    if(f->p != 0) f->p = y+i;
    for(; i < f->N; i++) novo[y+i] = f->dados[i];

    f->N = f->N*2;
    free(f->dados);
    f->dados = novo;
    f->u = tmp;
    return 1;
}

int enfileira (fila *f, int x){
    if((f->u+1) % f->N == f->p){
        if(redimensiona(f) != 1) return 0;
    }
    f->dados[f->u++] = x;
    if(f->u == f->N) f->u = 0;
    return 1;
}

int desenfileira (fila *f, int *y){
    if(f->p == f->u) return 0;
    *y = f->dados[f->p++];
    if(f->p == f->N) f->p = 0;
    return 1;
}

int main () {
    fila *circular = malloc(sizeof(fila));
    circular->N = 5;
    circular->dados = malloc(circular->N*sizeof(int));
    circular->p = circular->u = 1;
    enfileira(circular, 1);
    enfileira(circular, 2);
    enfileira(circular, 3);
    enfileira(circular, 4);
    enfileira(circular, 5);
    int y;
    desenfileira(circular, &y);
    desenfileira(circular, &y);
    desenfileira(circular, &y);
    desenfileira(circular, &y);
    desenfileira(circular, &y);
    desenfileira(circular, &y);
    enfileira(circular, 6);
    enfileira(circular, 7);
    enfileira(circular, 8);
    enfileira(circular, 9);
    enfileira(circular, 10);
    enfileira(circular, 11);
    enfileira(circular, 12);
    enfileira(circular, 13);
    enfileira(circular, 14);
    enfileira(circular, 15);
    desenfileira(circular, &y);

    for (int i = 0; i < circular->N; i++){
        printf("[%d] = %d ", i, circular->dados[i]);
        if(i == circular->p) printf("(inicio)\n");
        else if(i == circular->u) printf("(fim)\n");
        else printf("\n");
    }
    printf("\n %d", circular->dados[circular->p]);
}