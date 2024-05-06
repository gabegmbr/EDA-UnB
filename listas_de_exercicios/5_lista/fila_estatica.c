#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int redimensiona(fila *f){
    int *novo_array = malloc(f->N*2*sizeof(int)); //inicia novo vetor com o dobro de posições do tamanho anterior da fila.
    if (novo_array == NULL) return 0; //se vetor for nulo, a alocação de memória foi mal sucedida
    
    int p_tmp = f->p; //guardar valor de p para evitar sobreposição de endereço (isso pode ocorrer? fonte: não foi preciso)
    int i; //variável para iterações

    for(i = 0; i < f->u; i++) novo_array[i] = f->dados[i];
    f->u = i; //atualizar posição do último elemento da fila
    for(i = f->u; i < f->N*2; i++) novo_array[i] = 0; //inicializar novas posições do novo vetor

    free(f->dados); //limpa memória ocupada pelo velho vetor
    f->dados = novo_array; //fila agora aponta para o novo vetor
    f->p = p_tmp; //atualizar valor de p;
    f->N = f->N*2; //atualizar o número de posições da fila. multiplica-se por dois para evitar redimensionamentos frequentes, afinal, a complexidade da função é linear.
    return 1; //retorna 1 se operação foi bem sucedida.
}

int enfileira (fila *f, int x){
    if(f->u == f->N){ //verifica se novo elemento na posição u irá ultrapassar fim da fila
        if(redimensiona(f) != 1) return 0; //duplica tamanho do vetor da fila. se a função retornar um valor diferente de 1, a operação foi mal sucedida.
    }
    f->dados[f->u++] = x; //enfileira novo dado na posição u e incrementa a variável por +1.
    return 1; //retorna 1 se operação foi bem sucedida.
}

int desenfileira (fila *f, int *y){
    if(f->p+1 > f->N){
        return 0;
    }
    *y = f->dados[f->p];
    f->p++;
}