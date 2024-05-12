#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    int ID;
    int proxPista;
    struct celula *prox;
} celula;

void *enfileira (celula **f, int id, int dado, int prox_pista){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return NULL;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = dado;
    (*f)->ID = id;
    (*f)->proxPista = prox_pista;
    *f = novo;
}

int desenfileira (celula *f){
    if(f->prox == f){
        return 0;
    }
    celula *remove = f->prox;
    f->prox = remove->prox;
    free(remove);
    return 1;
}
void imprime_rec (celula *le){
    le = le->prox;
    if(le->dado == 0){
        printf("NULL\n");
        return;
    }
    printf("id: %d valor: %d prox: %d\n", le->ID, le->dado, le->proxPista);
    imprime_rec(le);
}

void detetive (celula *le, int next_ID){
    if(next_ID == -1){
        return;
    }
    le = le->prox;
    if(le->ID == next_ID){
        printf("%d\n", le->dado);
        next_ID = le->proxPista;
    }
    detetive(le, next_ID);
}

int main () {
    celula *cabeca = malloc(sizeof(celula));
    cabeca->dado = cabeca->ID = cabeca->proxPista = 0;
    cabeca->prox = cabeca;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int id;
        int dado;
        int prox;

        scanf("%d", &id);
        scanf("%d", &dado);
        scanf("%d", &prox);

        enfileira(&cabeca, id,dado, prox);
    }
    detetive(cabeca, cabeca->prox->ID);
    free(cabeca);
}