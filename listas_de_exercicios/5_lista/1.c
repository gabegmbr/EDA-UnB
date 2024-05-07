#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem (no *raiz){
    
}

int main () {

    no *sub0 = malloc(sizeof(no));
    no *sub2 = malloc(sizeof(no));

    sub0->dado = 0;
    sub0->esq = sub0->dir = NULL;

    sub2->dado = 2;
    sub2->esq = sub2->dir = NULL;

    no *sub1 = malloc(sizeof(no));
    sub1->dado = 1;
    sub1->esq = sub0;
    sub1->dir = sub2;

    no *sub4 = malloc(sizeof(no));
    sub4->dado = 4;
    sub4->esq = sub4->dir = NULL;

    no *sub3 = malloc(sizeof(no));
    sub3->dado = 3;
    sub3->esq = sub1;
    sub3->dir = sub4;

    //declaração da subárvore 3 (eu vou me matar)

    no *sub7 = malloc(sizeof(no));
    sub7->dado = 7;
    sub7->esq = sub7->dir = NULL;

    no *sub6 = malloc(sizeof(no));
    sub6->dado = 6;
    sub6->esq = NULL;
    sub6->dir = sub7;

    no *sub9 = malloc(sizeof(no));
    sub9->dado = 9;
    sub9->esq = sub9->dir = NULL;

    no *sub8 = malloc(sizeof(no));
    sub8->dado = 8;
    sub8->esq = sub6;
    sub8->dir = sub9;


    //declaração da subárvore 8
    no *raiz = malloc(sizeof(no));
    raiz->dado = 5;
    raiz->esq = sub3;
    raiz->dir = sub8;

    em_ordem(raiz);
}