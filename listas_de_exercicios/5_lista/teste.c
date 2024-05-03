#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

void imprime_fila (fila *f) {
    int i;
/*
 ----- -----
|  10 | -30 |
 ----- -----
  p u               
 */
    for (i = 0; i < f->N; i++)
        printf (" -----");
    printf ("\n");
    
    for (i = 0; i < f->N; i++)
        printf ("| %3d ", f->dados[i]);
    printf ("\n");

    for (i = 0; i < f->N; i++)
        printf (" -----");
    printf ("\n");

    if (f->p < f->u) {
        for (i = 0; i < f->p; i++)
            printf ("      ");
        printf ("   p  ");
        for (i = f->p+1; i < f->u; i++)
            printf ("      ");
        printf ("   u\n");
    }
    else if (f->p > f->u) {
        for (i = 0; i < f->u; i++)
            printf ("      ");
        printf ("   u  ");
        for (i = f->u+1; i < f->p; i++)
            printf ("      ");
        printf ("   p\n");
    }
    else {
        for (i = 0; i < f->u; i++)
            printf ("      ");
        printf ("  p u\n");
    }
}

int redimensiona (fila *f) {
    // retorna 0 se der certo, 1 se der errado
    f->dados = realloc (f->dados, 2*f->N*sizeof (int));
    if (f->dados == NULL) return 1;
    if (f->p != 0) {
        if (f->N - f->p < f->u) {
            for (int i = f->N-1; i >= f->p; i--)
                f->dados[i+f->N] = f->dados[i];
            f->p += f->N;
        }
        else {
            for (int i = 0; i < f->u; i++)
                f->dados[i+f->N] = f->dados[i];
            f->u += f->N;
        }
    }
    f->N *= 2;
    return 0;
}

int enfileira (fila *f, int x) {
    if ((f->u+1)%f->N == f->p) // fila cheia
        if (redimensiona (f) != 0) return 1;
    f->dados[f->u] = x;
    f->u = (f->u + 1)%f->N;
    return 0;
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
    enfileira(queue, 4);
    enfileira(queue, 5);
    enfileira(queue, 6);
    enfileira(queue, 7);
    enfileira(queue, 8);

    imprime_fila(queue);
}