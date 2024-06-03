#include <stdio.h>
#include <stdlib.h>
void merge(int *v, int ini, int meio, int fim){
    int tamanho = fim+1 - ini;
    int tmp[tamanho];

    int i = ini;
    int j = meio+1;
    int k = 0;

    while(i <= meio && j <= fim){
        if(v[i] <= v[j]){
            tmp[k] = v[i];
            k++;
            i++;
        } else {
            tmp[k] = v[j];
            k++;
            j++;
        }
    }
    while(i <= meio) tmp[k++] = v[i++];
    while(j <= fim) tmp[k++] = v[j++];
    k = 0;
    i = ini;
    for(; i <= fim; i++, k++){
        v[i] = tmp[k];
    }
}

void merge_sort(int *v, int ini, int fim){
    if(ini >= fim) return;
    
    int meio = (fim+ini)/2;
    merge_sort(v, ini, meio);
    merge_sort(v, meio+1, fim);
    merge(v, ini, meio, fim);
}

int main (){
    int n;
    int r = -1;
    scanf("%d", &n);
    int *vetor = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++, r++){
        scanf("%d", &vetor[i]);
    }
    merge_sort(vetor, 0, r);
    for(int i = 0; i <= r; i++) printf("%d ", vetor[i]);
    free(vetor);
}