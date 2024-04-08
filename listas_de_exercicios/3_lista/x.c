#include <stdio.h>
#include <string.h>

char orderedString[110];

void fillWithX(int j, int len){
    if(j > len){
        return;
    }
    strcat(orderedString, "x");
    fillWithX(++j, len);
}

void ordenateString(char string[], int i, int j, int len){
    if(i > len){
        fillWithX(j, len);
        return;
    }
    if (string[i] != 'x'){
        orderedString[j] = string[i];
        j++;
    }
    ordenateString(string, ++i, j, len);
}

int main(){
    char string[110];
    scanf("%100s", string);
    int len = strlen(string);
    if(len == 0){
        return 0;
    }
    ordenateString(string, 0, 0, len);
    printf("%s\n", orderedString);
}