#include <stdio.h>

void insertion_sort(int v[], int l, int r){
    for(int i = l+1; i < r; i++){
        int elem = v[i];
        int j;
        for(j = i; j > l && elem < v[j-1]; j--){
                v[j] = v[j-1];
        }
        v[j] = elem;
    }
}

int main (){
    int vetor[60000] = {3, 1, 7, 5, 4, 8, 2, 6};
    int n = 0;
    int r = 0;
    while(scanf("%d", &n) != EOF){
        vetor[r] = n;
        r++;
    }
    insertion_sort(vetor, 0, r);
    for(int i = 0; i < r; i++) printf("%d ", vetor[i]);
}