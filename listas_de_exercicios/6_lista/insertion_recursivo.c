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

int compara(int *v, int j, int elem){
    if(j > 0 && v[j-1] > elem) {
        v[j] = v[j-1];
        j--;
        compara(v, j, elem);
    } else return j;
}

void sort(int *v, int n, int i){
    if(i == n-1) return;
    i++;
    int elem = v[i];
    v[compara(v, i, elem)] = elem;
    sort(v, n, i);
}

void ordena(int *v, int n){
    sort(v, n, 0);
}