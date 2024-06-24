#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha (celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return 0;
    }
    else{
        novo->dado = x;
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
    }
}

int main () {
    int c, t;
    scanf("%d %d", &c, &t);
    celula *circulos = malloc(sizeof(celula));
    circulos->dado = -1;
    circulos->prox = circulos;
    for(int i = 0; i < c; i++){
        int raio;
        scanf("%d", &raio);
        empilha(circulos, raio);
    }

    int pontos = 0;

    for(int i = 0; i < t; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x = abs(x); 
        y = abs(y);

        float distancia = sqrt(x*x+y*y);

        int ponto = 0;
        celula *tmp = circulos;
        while(tmp->prox->dado != -1){
            if(distancia <= tmp->prox->dado){
                ponto++;
            } else break;
            tmp = tmp->prox;
        }
        pontos+= ponto;
    }

    printf("%d", pontos);
    free(circulos);
}