#include <stdio.h>

int main(){
    char string[1001];
    int i = 0;
    scanf("%s", string);
    for(; string[i] != '\0'; i++);
    printf("%d", i);
}