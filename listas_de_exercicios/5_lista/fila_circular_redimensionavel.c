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

    
    if(f->p > ((f->N/2) + (f->N % 2))){
        for(i = 0; i <= f->u; i++) novo[i] = f->dados[i];
        for(y = 0; y < f->N; y++) novo[y+i] = 0;
        f->p = y+i;
        for(; i < f->N; i++) novo[y+i] = f->dados[i];
    } else {
        for(i = f->p; i <= f->N; i++) novo[i] = f->dados[i]; 
        i--;
        for(y = 0; y < f->p; y++, i++) novo[i] = f->dados[y];
        f->u = i-1;
    }

    f->N = f->N*2;
    free(f->dados);
    f->dados = novo;
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

