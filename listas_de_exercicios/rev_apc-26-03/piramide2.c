#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    int ast = 1;
    int spc = a-1;
    for(int columns = 1; columns <= a; columns++){
        for(int c = 0; c < spc; c++){
            printf(" ");
        }
        spc--;
        for(int b = 0; b < ast; b++){
            printf("*");
        }
        ast = ast+2;
        printf("\n");
    }
}

/*
  * - 2 espaços 1 asterisco 
 *** - 1 espaço 3 asteriscos
***** - nenhum espaço 5 asteriscos
*/