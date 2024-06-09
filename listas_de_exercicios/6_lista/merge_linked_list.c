#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = (*f);
    (*f) = novo;
}

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

void imprime_rec (celula *le){
    while(le->prox != NULL){
        le = le->prox;
        printf("%d -> ", le->dado);
    }
    if(le->prox == NULL) printf("NULL\n");
}

int main(){
    celula *head = malloc(sizeof(celula));
    head->prox = NULL;

    enfileira(&head, 15);
    enfileira(&head, 3);
    enfileira(&head, 4);
    enfileira(&head, 5);
    merge_sort(&head);
    imprime_rec (head);
}