#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define strSize 256

typedef struct celula {
    char *text;
    struct celula *prox;
} celula;

int empilha (celula *p, char *text){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return 0;
    }
    else{
        novo->text = text;
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
    }
}

void *desempilha (celula *p){
    celula *tmp = p->prox;
    if(tmp == NULL) return NULL;
    else{
        p->prox = tmp->prox;
        free(tmp);
    }
}

int main () {
    celula *historico = malloc(sizeof(celula));
    historico->text = NULL;
    char *mode = malloc(101);

    while(scanf("%s", mode) != EOF){
        if(strcmp(mode, "desfazer") == 0){
            if(historico->prox != NULL){
                printf("%s", historico->prox->text);
                desempilha(historico);
            } else{
                printf("NULL\n");
            }
        }
        else if(strcmp(mode, "inserir") == 0){
            char *STR = malloc(strSize);
            fgets(STR, 255, stdin);
            empilha(historico, STR);
        }
    }
    free(mode);
    free(historico);
}