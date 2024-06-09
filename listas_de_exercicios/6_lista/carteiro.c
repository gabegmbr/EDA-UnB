#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return;
    novo->dado = -1;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = x;
    *f = novo;
}

void desenfileira (celula *f){
    if(f->prox == f){
        return;
    }
    celula *remove = f->prox;
    f->prox = remove->prox;
    free(remove);
    return;
}

int main (){
    int n, m;
    scanf("%d %d", &n, &m);
    int *rua = malloc(n*sizeof(int));
    celula *fila = malloc(sizeof(celula));
    fila->prox = fila;

    for(int i = 0; i < n; i++) 
        scanf("%d", &rua[i]);

    for(int i = 0; i < m; i++){
        int r;
        scanf("%d", &r);
        enfileira(&fila, r);
    }

    int casa = 0;
    int steps = 0;
    while(fila->prox->dado != -1){
        int j = 0;
        int i;
        for(i = casa; i < n && rua[i] != fila->prox->dado; i++, j++);
        if(rua[i] == fila->prox->dado){
            casa = i;
            desenfileira(fila);
            steps+=j;
        } else{
            j = 0;
            for(i = casa; i > 0 && rua[i] != fila->prox->dado; i--, j++);
            casa = i;
            desenfileira(fila);
            steps+=j;
        }
    }
    printf("%d", steps);

}