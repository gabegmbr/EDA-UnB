#include <stdio.h>

long int fib[80] = {0};

long int fibonacci(int i){
    if (i <= 2){
        return 1;
    }
    if (fib[i-1] == 0){
        fib[i-1] = fibonacci(i-1);
    }
    if (fib[i-2] == 0){
        fib[i-2] = fibonacci(i-2);
    }
    fib[i] = fib[i-1] + fib[i-2];
    return fib[i];
}


