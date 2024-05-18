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
    int n = 0;
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        return 0;
    }

    for(int y = 0; y < n; y++){
        celula *pilha = malloc(sizeof(celula));
        pilha->dado = -1;
        pilha->prox = pilha;

        char *str = malloc(sizeof(char)*500000);
        scanf(" %[^\n]", str);
        int i = 0;
        while(str[i] != '\0'){
            switch (str[i]){
                case '{':
                    empilha(pilha, str[i]);
                    break;

                case '}':
                    if(pilha->prox->dado != -1 && pilha->prox->dado == '{'){
                        desempilha(pilha);
                    } else{
                        empilha(pilha, str[i]);
                    }
                    break;

                case '[':
                    empilha(pilha, str[i]);
                    break;

                case ']':
                    if(pilha->prox->dado != -1 && pilha->prox->dado == '['){
                        desempilha(pilha);
                    } else{
                        empilha(pilha, str[i]);
                    }
                    break;

                case '(':
                    empilha(pilha, str[i]);
                    break;

                case ')':
                    if(pilha->prox->dado != -1 && pilha->prox->dado == '('){
                        desempilha(pilha);
                    } else{
                        empilha(pilha, str[i]);
                    }
                    break;
            }
            i++;
        }
        if(pilha->prox->dado == -1) printf("S\n");
        else printf("N\n");
        free(str);
        free(pilha);
    }
}