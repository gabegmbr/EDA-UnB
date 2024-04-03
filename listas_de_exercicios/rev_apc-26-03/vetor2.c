#include <stdio.h>

int main(){
    int array[100000];
    int n;
    scanf("%d", &n);
    for(int h = 0; h < n; h++){
        scanf("%d", &array[h]);
    }
    int smol = array[0];
    int index;
    for (int i = 0; i < n; i++){
        if(array[i] < smol){
            smol = array[i];
            index = i;
        }
    }
    printf("%d\n", index);
}