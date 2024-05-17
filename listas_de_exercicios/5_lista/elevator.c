#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void *enfileira (celula **f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return NULL;
    novo->dado = -666;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->dado = x;
    *f = novo;
}

int desenfileira (celula *f){
    int y;
    if(f->prox == f){
        return 0;
    }
    celula *remove = f->prox;
    y = remove->dado;
    f->prox = remove->prox;
    free(remove);
    return y;
}

int main (){
    int floors = 10;
    int start = 1;
    int desiredFloor = 10;
    int up = 2;
    int down = 1;

    scanf("%d %d %d %d %d", &floors, &start, &desiredFloor, &up, &down);

    int *floorsArray = malloc(sizeof(int)*(floors+1));

    celula *queue = malloc(sizeof(queue));
    queue->dado = -666;
    queue->prox = queue;

    for(int i = 0; i <= floors; i++) floorsArray[i] = -1;

    floorsArray[start] = 0;
    enfileira(&queue, start);

    while (queue->prox->dado != -666){
        int currentFloor = desenfileira(queue);

        if(currentFloor+up <= floors && floorsArray[currentFloor+up] == -1){
            floorsArray[currentFloor+up] = floorsArray[currentFloor]+1;
            enfileira(&queue, currentFloor+up);
        }
        if(currentFloor-down > 0 && floorsArray[currentFloor-down] == -1){
            floorsArray[currentFloor-down] = floorsArray[currentFloor]+1;
            enfileira(&queue, currentFloor-down);
        }
    }
    if(floorsArray[desiredFloor] == -1) printf("use the stairs\n");
    else printf("%d", floorsArray[desiredFloor]);
    free(queue);
}