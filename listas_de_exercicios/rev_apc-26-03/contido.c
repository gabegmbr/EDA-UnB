#include <stdio.h>
#include <stdbool.h>

int main (){
    int array[100000] = {1, 2, 3, 4, 5};
    int n = 5;
    int x = 5;
    bool pertence = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; i++){
        if (array[i] == x){
            pertence = true;
        }
    }
    if(pertence == true){
        printf("pertence\n");
    }
    else{
        printf("nao pertence\n");
    }
}