#include <stdio.h>

int main(){
    int a, b, c, sum;
    scanf("%d %d %d", &a, &b, &c);
    sum = a+b+c;

   if(sum == 0 || sum == 3){
    printf("empate");
   }

   if(sum == 2){
    if (a == 0){
        printf("A");
    }
    if (b == 0){
        printf("B");
    }
    if (c == 0){
        printf("C");
    }
   }

   if(sum == 1){
    if (a == 1){
        printf("A");
    }
    if (b == 1){
        printf("B");
    }
    if (c == 1){
        printf("C");
    }
   }
   
}