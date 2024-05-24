#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int linha;
    int coluna;
    int alcance;
    struct celula *prox;
} celula;

void enfileira (celula **f, int linha, int coluna, int alcance){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return;
    novo->linha = -1;
    novo->prox = (*f)->prox;
    (*f)->prox = novo;
    (*f)->linha = linha;
    (*f)->coluna = coluna;
    (*f)->alcance = alcance;
    *f = novo;
}

void desenfileira (celula *f){
    if(f->prox == f){
        return;
    }
    celula *remove = f->prox;
    f->prox = remove->prox;
    free(remove);
    return;
}

int main (){
    int linha, coluna;
    celula *torres = malloc(sizeof(celula));
    torres->linha = -1;
    torres->prox = torres;

    scanf("%d %d", &linha, &coluna);
    char *mapa[linha];
    for(int i = 0; i < linha; i++)
        mapa[i] = (char*)malloc(coluna * sizeof(char)); 

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            scanf(" %c", &mapa[i][j]);
            if(mapa[i][j] == 't') enfileira(&torres, i, j, 0);
        }
    }

    torres = torres->prox;

    while(torres->linha != -1){
        int alcance;
        scanf("%d", &alcance);
        torres->alcance = alcance;
        torres = torres->prox;
    }


    int v = 0;
    while(torres->prox->linha != -1){
        //registrar alcance a partir do topo
        int h = 0;
        
        for(int i = torres->prox->linha-(torres->prox->alcance); h <= torres->prox->alcance*2; i++, h++){
            int k = 0;
            for(int j = torres->prox->coluna-(torres->prox->alcance); k <= torres->prox->alcance*2; j++, k++){
                if(i >= 0 && j >= 0 && i < linha && j < coluna && mapa[i][j] != 't' && mapa[i][j] != '.'){
                    mapa[i][j] = '.';
                    v++;
                }
            }
        }        
        desenfileira(torres);
    }

    printf("%d\n", v);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
    
    free(torres);
    for(int i = 0; i < linha; i++){
        free(mapa[i]);
    }
}