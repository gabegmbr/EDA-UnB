#include <stdio.h>

void printSession(){
    for (int i = 64+5; i > 64; i--){
        for (int j = 1; j <= 5; i++){
            printf("0%d ", j);
        }
        printf("%c ", i);
        printf("\n");
    }
}

int main(){
    printSession();
}