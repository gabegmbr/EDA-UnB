#include <stdio.h>
#include <stdlib.h>

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

int desempilha (celula *p, int *y){
    celula *tmp = p->prox;
    if(tmp == NULL) return 0;
    else{
        *y = tmp->dado;
        p->prox = tmp->prox;
        free(tmp);
        return 1;
    }
}

void enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return;
    novo->dado = -1;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = x;
    *f = novo;
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

int main () {
    int i = 1;

    while(1){
        scanf("%d", &i);
        if(i == 0) break;

        celula *main_street = malloc(sizeof(celula));
        main_street->dado = -1;
        main_street->prox = main_street;
        int n = -1;
        
        int y = 0;
        while(y < i){
            scanf("%d", &n);
            if(n == 0) break;
            empilha(main_street, n);
            y++;
        }

        celula *side_street = malloc(sizeof(celula));
        side_street->dado = -1;
        side_street->prox = side_street;

        //desempilhar quando numero posterior for maior
        main_street = main_street->prox;
        while(main_street->dado != -1){
            if(main_street->dado < main_street->prox->dado){
                int y;
                desempilha(main_street, &y);
                enfileira(&side_street, y);
            } else main_street = main_street->prox;
        }

        while(side_street->prox->dado != -1){
            int flag = 0;
            if(main_street->prox->dado == -1){
                celula *tmp = side_street->prox;
                while(tmp->prox->dado != -1){
                    if(tmp->prox->dado == side_street->prox->dado-1){
                        flag = 1;
                        break;
                    } else tmp = tmp->prox;
                }
            }
            if (flag == 1) break;
            if(main_street->prox->dado == side_street->prox->dado-1){
                int y;
                desenfileira(side_street, &y);
                empilha(main_street, y);
            } else main_street = main_street->prox;
        }

        if(side_street->prox->dado == -1) printf("yes\n");
        else printf("no\n");
        free(main_street);
        free(side_street);
    }
}