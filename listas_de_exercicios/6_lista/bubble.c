#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int v[], int l, int r){
    int swp = 1;
    while(r != l && swp != 0){
        swp = 0;
        for(int i = l; i < r-1; i++){
            if(v[i] > v[i+1]){
                swap(&v[i+1], &v[i]);
                swp++;
            }
        }
        r--;
    }
}

int main (){
    int vetor[10000] = {3, 1, 7, 5, 4, 8, 2, 6};
    int n;
    int r = 0;
    while(scanf("%d", &n) != EOF){
        vetor[r] = n;
        r++;
    }
    bubble_sort(vetor, 0, r);
    for(int i = 0; i < r; i++) printf("%d ", vetor[i]);
}