#include <stdio.h>
#include <stdlib.h>

typedef struct celula {

    int coluna;
    int linha;
    struct celula *prox;

} celula;

void enfileira (celula **f, int y, int x){

    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return;
    novo->coluna = -1;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->linha = x;
    (*f)->coluna = y;
    *f = novo;

}

void desenfileira (celula *f, int *y, int *x){

    if(f->prox == f){
        return;
    }
    celula *remove = f->prox;
    *y = remove->coluna;
    *x = remove->linha;
    f->prox = remove->prox;
    free(remove);
    return;

}

int main (){

    while(1){

        char coluna;
        int linha;
        if(scanf(" %c", &coluna) == EOF) break; //condição de parada do while
        scanf("%d", &linha);

        int matriz[8][8];

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++)
                matriz[i][j] = 0;
        }

        matriz[(coluna-97)][linha-1] = 1; 

        celula *fila = malloc(sizeof(fila));
        fila->coluna = -1;
        fila->prox = fila;
        enfileira(&fila, coluna-97, linha-1);

        char colunaf;
        int linhaf;
        scanf(" %c%d", &colunaf, &linhaf);
        while(fila->prox->coluna != -1){
            int y, x;

            desenfileira(fila, &y, &x);

            //se pode ir para cima à esquerda -1 coluna +2 linha
            if(y-1 >= 0 && x+2 < 8 && matriz[y-1][x+2] == 0){
                matriz[y-1][x+2] = matriz[y][x]+1;
                enfileira(&fila, y-1, x+2);
            }

            //se pode ir para cima à direita +1 coluna +2 linha

            if(y+1 < 8 && x+2 < 8 && matriz[y+1][x+2] == 0){
                matriz[y+1][x+2] = matriz[y][x]+1;
                enfileira(&fila, y+1, x+2);
            }

            //se pode ir para lado esquerdo para cima -2 coluna +1 linha
            if(y-2 >= 0 && x+1 < 8 && matriz[y-2][x+1] == 0){
                matriz[y-2][x+1] = matriz[y][x]+1;
                enfileira(&fila, y-2, x+1);
            }

            //se pode ir para lado direito para cima +2 coluna +1 linha

            if(y+2 < 8 && x+1 < 8 && matriz[y+2][x+1] == 0){
                matriz[y+2][x+1] = matriz[y][x]+1;
                enfileira(&fila, y+2, x+1);
            }

            //se pode ir para lado esquerdo para baixo -2 coluna -1 linha

            if(y-2 >= 0 && x-1 >= 0 && matriz[y-2][x-1] == 0){
                matriz[y-2][x-1] = matriz[y][x]+1;
                enfileira(&fila, y-2, x-1);
            }

            //se pode ir para lado direito para baixo +2 coluna -1 linha

            if(y+2 < 8 && x-1 >= 0 && matriz[y+2][x-1] == 0){
                matriz[y+2][x-1] = matriz[y][x]+1;
                enfileira(&fila, y+2, x-1);
            }

            //se pode ir para baixo à esquerda -1 coluna -2 linha

            if(y-1 >= 0 && x-2 >= 0 && matriz[y-1][x-2] == 0){
                matriz[y-1][x-2] = matriz[y][x]+1;
                enfileira(&fila, y-1, x-2);
            }

            //se pode ir para baixo à direita +1 coluna -2 linha

            if(y+1 < 8 && x-2 >= 0 && matriz[y+1][x-2] == 0){
                matriz[y+1][x-2] = matriz[y][x]+1;
                enfileira(&fila, y+1, x-2);
            }
        }

        printf("To get from %c%d to %c%d takes %d knight moves.\n", coluna, linha, colunaf, linhaf, matriz[colunaf-97][linhaf-1]-1);

        free(fila);

    }
}