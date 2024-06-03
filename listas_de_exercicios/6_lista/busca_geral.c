#include <stdio.h>
#include <stdlib.h>
void merge(int *v, int *c, int ini, int meio, int fim){
    int tamanho = fim+1 - ini;
    int tmp[tamanho];

    int i = ini;
    int j = meio+1;
    int k = 0;

    while(i <= meio && j <= fim){
        if(v[c[i]] <= v[c[j]]){
            tmp[k] = c[i];
            k++;
            i++;
        } else {
            tmp[k] = c[j];
            k++;
            j++;
        }
    }
    while(i <= meio) tmp[k++] = c[i++];
    while(j <= fim) tmp[k++] = c[j++];
    k = 0;
    i = ini;
    for(; i <= fim; i++, k++){
        c[i] = tmp[k];
    }
}

void merge_sort(int *v, int *c, int ini, int fim){
    if(ini >= fim) return;
    
    int meio = (fim+ini)/2;
    merge_sort(v, c, ini, meio);
    merge_sort(v, c, meio+1, fim);
    merge(v, c, ini, meio, fim);
}

int binary_search(int *v, int *c, int n, int num){
    int inicio = 0;
    int fim = n-1;
    int meio;
    while(inicio <= fim){
        meio = inicio + (fim - inicio) / 2;
        if(v[c[meio]] == num) return c[meio];
        if(num > v[c[meio]]) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int *vetor = malloc(sizeof(int)*n);
    int *chaves = malloc(sizeof(int)*n);
    int r = -1;
    for(int i = 0; i < n; i++, r++){
        scanf("%d", &vetor[i]);
        chaves[i] = i;
    }

    printf("\n");
    merge_sort(vetor, chaves, 0, r);
    for(int i = 0; i < m; i++){
        int num;
        scanf("%d", &num);
        printf("%d\n", binary_search(vetor, chaves, n, num));
    }
}