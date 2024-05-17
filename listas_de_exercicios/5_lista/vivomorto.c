#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void *enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return NULL;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = x;
    *f = novo;
}

void remove_depois(celula *p){
    if(p->prox == NULL){p->prox = NULL;}
    else{p->prox = p->prox->prox;}
    return;
}

int main (){
    int numeroParticipantes = 1;
    int numeroRodadas = 1;
    int teste = 0;

    while(numeroParticipantes != 0 && numeroRodadas != 0){
        scanf("%d", &numeroParticipantes);
        scanf("%d", &numeroRodadas);

        teste++;

        celula *cabeca = malloc(sizeof(celula));
        cabeca->dado = 0;
        cabeca->prox = cabeca;

        for(int i = 0; i < numeroParticipantes; i++){
            int dado;
            scanf("%d", &dado);
            enfileira(&cabeca, dado);
        }
        
        //rodada se inicia
        for(int i = 0; i <numeroRodadas; i++){
            int participantesVivos;
            int ordem;
            celula *tmp = cabeca;
            scanf("%d", &participantesVivos);
            scanf("%d", &ordem);
            for (int y = 0; y < participantesVivos; y++){
                int movimento;
                scanf("%d", &movimento);
                if(movimento != ordem){
                    remove_depois(tmp);
                }
                else{
                    tmp = tmp->prox;
                }
            }
        }
        if(numeroParticipantes != 0){
            printf("Teste %d\n", teste);
            printf("%d\n", cabeca->prox->dado);
            free(cabeca);
        }
        else{
            free(cabeca);
        }
    }
}