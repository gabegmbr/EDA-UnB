#include <stdio.h>

int add(int *a, int *b){
    *a = *a+*b;
    return *a;
}

int main(){
    int a = 5;
    int b = 6;
    int result = add(&a, &b);
    printf("The sum of the entered numbers is : %d\n", result);
}