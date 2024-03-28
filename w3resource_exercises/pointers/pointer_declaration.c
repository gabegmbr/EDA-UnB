#include <stdio.h>

int main(){
    printf("Pointer: Show the basic declaration of pointer : \n");
    printf("------------------------------------------------ \n");
    int m = 10;
    int n, o;
    int *z = &m;
    printf("Here m=%d, n and o are two integer variable and *z is an integer \n\n", m);
    printf("z stores the address of m = %p \n\n", z);
    printf("*z stores the value of m = %d \n\n", *z);
    printf("&m is the address of m = %p \n\n", &m);
    printf("&n stores the address of n = %p \n\n", &n);
    printf("&o stores the address of o = %p \n\n", &o);
    printf("&z stores the address of z = %p \n\n", &z);
}