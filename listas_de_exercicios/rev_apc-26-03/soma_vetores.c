#include <stdio.h>

int main(){
    int array1[10000];
    int array2[10000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &array1[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &array2[i]);
    }
    for(int i = 0; i < n; i++){
        array1[i] = array1[i] + array2[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d ", array1[i]);
    }
}