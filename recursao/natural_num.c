#include <stdio.h>

int printNatNum(int n){
    if (n <= 50){
        printf("%d\n", n);
        printNatNum(n+1);
    }
}

int main (){
    int n = 1;
    printNatNum(n);
}