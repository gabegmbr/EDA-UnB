#include <stdio.h>
#include <string.h>

void fillWithX(char ordString[], int j, int len){
    if(j > len){
        return;
    }
    strcat(ordString, "x");
    fillWithX(ordString, ++j, len);
}

void ordenateString(char string[], char ordString[], int i, int j, int len){
    if(i > len){
        fillWithX(ordString, j, len);
        return;
    }
    if (string[i] != 'x'){
        ordString[j] = string[i];
        j++;
    }
    ordenateString(string, ordString, ++i, j, len);
}

int main(){
    char string[101];
    char orderedString[101];
    scanf("%100s", string);
    int len = strlen(string);
    if(len == 0){
        return 0;
    }
    ordenateString(string, orderedString, 0, 0, len);
    printf("%s\n", orderedString);
}