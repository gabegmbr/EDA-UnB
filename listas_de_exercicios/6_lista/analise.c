/*

receber string;
analisar string char por char até '\0';
análise consiste em:
    enfileirar caractere numa lista encadeada
    que contém: int dados e char letra;
    registrar cada ocorrência do caractere 
    no int dados até encontrar um caractere
    diferente;
depois de terminar a análise, ordenar, de maneira
decrescente, a lista encadeada
após ordenação, printar char e dados da lista;


*/

#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    char c;
    int dado;
    int i;
    struct celula *prox;
} celula;

void split(celula *head, celula **a, celula **b){
    celula *fast;
    celula *slow;
    slow = head; //percorre até a metade da lista
    fast = head->prox; //percorre até o final da lista

    while(fast != NULL){
        fast = fast->prox;
        if(fast != NULL){
            slow = slow->prox;
            fast = fast->prox;
        }
    }
    *a = head;
    *b = slow->prox;
    slow->prox = NULL;
}

celula *sort (celula *a, celula *b){
    celula *result = NULL;
    if (a == NULL){
        return b;
    } else if (b == NULL){
        return a;
    }

    if(a->dado <= b->dado){
        result = a;
        result->prox = sort(a->prox, b);
    } else{
        result = b;
        result->prox = sort(a, b->prox);
    }
    return result;
}

void merge_sort(celula **cabeca_Ref){
    celula *cabeca = *cabeca_Ref;
    celula *a;
    celula *b;

    if(cabeca == NULL || cabeca->prox == NULL){
        return;
    }

    split(cabeca, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *cabeca_Ref = sort(a, b);
}

void imprime_rec (celula *le){ //imprimir em ordem decrescente
    if(le == NULL) return;
    imprime_rec(le->prox);
    printf("%d %c %d\n", le->dado, le->c, le->i);
}

void enfileira (celula **f, char c, int x, int i){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->c = c;
    novo->i = i;
    novo->prox = (*f);
    (*f) = novo;
}


int main(){
    char string[1000000];
    int i = 0;
    while(scanf(" %c", &string[i]) != EOF) i++;

    celula *lista = malloc(sizeof(celula));
    lista = NULL;

    i = 0;
    while(string[i] != '\0'){
        char caracter = string[i];
        int ini = i;
        int ocorrencias = 0;
        while(string[i] == caracter){
            ocorrencias++;
            i++;
        }
        enfileira(&lista, caracter, ocorrencias, ini);
    }
    merge_sort(&lista);
    imprime_rec(lista);
}



