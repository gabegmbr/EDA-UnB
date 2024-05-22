#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int tamanho;
    char lado;
    struct celula *prox;
} celula;

int empilha (celula *p, int t, char l){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return 0;
    }
    else{
        novo->tamanho = t;
        novo->lado = l;
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
    }
}

void desempilha (celula *p){
    celula *tmp = p->prox;
    if(tmp == NULL) return;
    else{
        p->prox = tmp->prox;
        free(tmp);
        return;
    }
}

int main (){
    celula *pilha = malloc(sizeof(celula));
    pilha->lado = '.';
    pilha->prox = pilha;

    int m;

    while(1){
        if(scanf("%d",  &m) != EOF){
            char l;
            scanf(" %c", &l);
            empilha(pilha, m, l);
        } else break;
    }

    int pares = 0;

    while(pilha->prox->lado != '.'){
        celula *pilha_tmp = pilha;
        int flag = 0;
        while(flag == 0 && pilha_tmp->prox->lado != '.'){
            pilha_tmp = pilha_tmp->prox;
            switch (pilha_tmp->prox->lado){
                case 'D':
                if(pilha_tmp->prox->tamanho == pilha->prox->tamanho && pilha->prox->lado == 'E'){
                    pares++;
                    flag++;
                    desempilha(pilha_tmp);
                    desempilha(pilha);
                    break;
                } break;

                case 'E':
                if(pilha_tmp->prox->tamanho == pilha->prox->tamanho && pilha->prox->lado == 'D'){
                    pares++;
                    flag++;
                    desempilha(pilha_tmp);
                    desempilha(pilha);
                    break;
                } break;
            }

        }
        if(flag == 0) pilha = pilha->prox;
    }

    printf("%d \n", pares);
}