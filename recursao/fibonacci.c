#include <stdio.h>

int calcFib(int n){
    if (n == 1) return 1;
    if (n == 0) return 0;
    return calcFib(n-2)+calcFib(n-1);
}

int main () {
    int n = 10;
    int result = calcFib(n);
    printf("%d", result);
}