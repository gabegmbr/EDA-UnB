#include <stdio.h>

void orderString(char s[], int i){
    if(s[i] == '\0'){
        return;
    }
    if(s[i] == 'x'){
        orderString(s, ++i);
        printf("x");
    }
    else{
        printf("%c", s[i]);
        orderString(s, ++i);
    }
}

int main(){
    char string[1000];
    scanf("%s", string);
    orderString(string, 0);
}