#include <stdio.h>

    int main () {
        char string [1001];
        int strSize = 0;

        scanf("%s", string);
        for (int i = 0; string[i] != '\0'; i++){
            strSize++;
        }

        for (int i = strSize - 1; i >= 0; i--){
            printf("%c", string[i]);
        }
    }