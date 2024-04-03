#include <stdio.h>
int main () {
    int n;
    int array[10000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    for(int i = 0; i < n; i++){
        if(array[i]%2 == 0){
            printf("%d ", array[i]);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        if(array[i]%2 != 0){
            printf("%d ", array[i]);
        }
    }
}