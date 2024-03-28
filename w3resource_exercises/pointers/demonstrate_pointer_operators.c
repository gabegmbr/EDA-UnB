#include <stdio.h>

int main () {
    printf("Pointer: Demonstrate the use of & and * operators : \n");
    printf("---------------------------------------------------\n");
    
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    printf("m = %d\n", m);
    printf("fx = %lf\n", fx);
    printf("cht = %c\n\n", cht);

    printf("Using & operator: \n");
    printf("address of m = %p\n", &m);
    printf("address of fx = %p\n", &fx);
    printf("address of cht = %p\n", &cht);

}