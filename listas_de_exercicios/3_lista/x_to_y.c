#include <stdio.h>

void x_to_y(char *s, int i){
    if(s[i] == '\0'){
        return;
    }
    if(s[i] == 'x'){
        printf("y");
        x_to_y(s, ++i);
    }
    else{
        printf("%c", s[i]);
        x_to_y(s, ++i);
    }
}

int main(){
    char line[1000];
    scanf("%s", line);
    x_to_y(line, 0);
}