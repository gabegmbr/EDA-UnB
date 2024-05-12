#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira (celula *f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return NULL;
    novo->dado = 0;
    novo->prox = f->prox;
    f->prox = novo;
    f->dado = x;
    return novo;
}

int desenfileira (celula *f, int *y){
    if(f->prox == f){
        return 0;
    }
    celula *remove = f->prox;
    *y = remove->dado;
    f->prox = remove->prox;
    free(remove);
    return 1;
}

celula *criar_no (int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = NULL;
    return novo;
}

void imprime_rec (celula *le){
    le = le->prox;
    if(le->dado == 0){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->dado);
    imprime_rec(le);
}

int main (){
    celula *cartas = malloc(sizeof(celula));
    cartas->dado = 0;
    cartas->prox = cartas;

    int n = 12;

    scanf("%d" , &n);
    
    for (int i = 1; i <= n; i++){
        cartas = enfileira(cartas, i);
    }

    printf("Cartas descartadas: ");
    for (int i = 1; i <= n-1; i++){
        int y;
        desenfileira(cartas, &y);
        if(i == n-1) printf("%d ", y);
        else printf("%d, ", y);
        desenfileira(cartas, &y);
        cartas = enfileira(cartas, y);
    }
    printf("\nCarta restante: %d\n", cartas->prox->dado);
    free(cartas);
    return 0;
}