#include <stdio.h>
#include <stdlib.h>

int main (){
    int n = 9;
    int i = 0;
    int f = 0;
    scanf("%d", &n);
    char *str = malloc(sizeof(char)*(n));
    scanf("%s", str);
    while(str[i] != '\0'){
        n--;
        if(str[i] != str[n]) f--;
        i++;
    }
    if(f == 0) printf("1");
    else printf("0");
    free(str);
}