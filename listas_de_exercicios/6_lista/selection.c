#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void selection_sort (int v[], int l, int r){
    int i = l;
    while(i != r-1){
        int menor = i;
        for(int j = i; j < r; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        swap(&v[i], &v[menor]);
        i++;
    }
}

int main (){
    int vetor[10000] = {3, 1, 7, 5, 4, 8, 2, 6};
    int n = 0;
    int r = 0;
    while(scanf("%d", &n) != EOF){
        vetor[r] = n;
        r++;
    }
    selection_sort(vetor, 0, r);
    for(int i = 0; i < r; i++) printf("%d ", vetor[i]);
}