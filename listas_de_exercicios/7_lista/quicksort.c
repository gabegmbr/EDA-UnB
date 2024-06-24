#include <stdio.h>
#include <stdlib.h>

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


int partition(int *arr, int l, int r){
    int pivot = r;
    int j = -1;
    for(int i = 0; i < r; i++){
        if(j > i) break;
        if(arr[i] <= arr[pivot]){
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j+1], &arr[pivot]);
    return j+1;
}

void mediana(int *arr, int l, int r){
    int meio = (l+r)/2;
    swap(&arr[meio], &arr[r-1]);
    if(arr[l] > arr[r-1]){
        swap(&arr[l], &arr[r-1]);
    }
    if(arr[l] > arr[r]){
        swap(&arr[l], &arr[r]);
    }
    if(arr[r-1] > arr[r]){
        swap(&arr[r-1], &arr[r]);
    }
}

void quickSort(int *arr, int l, int r){
    if (l <= r){
        if(r-l <= 100) return selection_sort(arr, l, r+1);
        mediana(arr, l, r);
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main (){
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}