#include <stdio.h>
#include <stdlib.h>

int binary_search(int v[], int n, int num){
    int inicio = 0;
    int fim = n-1;
    int meio;
    while(inicio <= fim){
        meio = inicio + (fim - inicio) / 2;
        if(v[meio] == num) return meio;
        if(num > v[meio]) inicio = meio + 1;
        else fim = meio - 1;
    }
    if(v[meio] < num) return meio+1;
    else return meio;
}

int main (){
    int n = 5;
    int m = 4;
    scanf("%d %d", &n, &m);
    int *vetor = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) 
        scanf("%d", &vetor[i]);
    
    for(int i = 0; i < m; i++){
        int num;
        scanf("%d", &num);
        printf("%d\n", binary_search(vetor, n, num));
    }
}