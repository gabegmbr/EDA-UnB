#include <stdio.h>
#include <string.h>

int main (){
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    char string[n][81];
    char comp[p][81];
    int contained = -1;

    for (int i = 0; i < n; i++){
        scanf("%s", string[i]);
    }
    for (int i = 0; i < p; i++){
        scanf("%s", comp[i]);
    }

    for (int i = 0; i < p; i++){
        for(int j = 0; j < n && contained != 0; j++){
            contained = strcmp(comp[i], string[j]);
        }
    }
    if(contained == 0){
        printf("1");
    }
    else{
        printf("0");
    }
    
    return 0;
}