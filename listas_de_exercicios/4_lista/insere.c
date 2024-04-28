#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    if(le->prox == NULL){
        celula *insert_ini = malloc(sizeof(celula));
        insert_ini->dado = x;
        insert_ini->prox = NULL;
        le->prox = insert_ini;
        return;
    }
    else{
        celula *insert_ini = malloc(sizeof(celula));
        insert_ini->dado = x;
        insert_ini->prox = le->prox;
        le->prox = insert_ini;
        return;
    }
}

void insere_antes (celula *le, int x, int y){
    le = le->prox;
    if(le->prox == NULL){
        celula *inserted_x = malloc(sizeof(celula));
        le->prox = inserted_x;
        inserted_x->dado = x;
        inserted_x->prox = NULL;
        return;
    }
    if(le->prox->dado == y){
        celula *inserted_x = malloc(sizeof(celula));
        inserted_x->dado = x;
        inserted_x->prox = le->prox;
        le->prox = inserted_x;
        return;
    }
    insere_antes(le, x, y);
}