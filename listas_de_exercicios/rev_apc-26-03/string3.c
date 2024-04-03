#include <stdio.h>

int main () {
    int n = 3;
    int big = 0;
    char string[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", string);
        for (int j = 1; string[j] != '\0'; j++){
            if(j >= big) big = j;
        }
    }
    printf("%d", ++big);
}