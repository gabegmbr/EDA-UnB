#include <stdio.h>
#include <stdlib.h>

int i = 0;
int j = 0;
int soma = 0;
void ultrapassa(int *v, int lastPosition, int excedeu){
    
    soma = soma+v[j];
    j++;
    if(soma > excedeu){
        lastPosition = i;
        soma = 0;
    }
    if(v[j] == 0){
        printf("%d", v[lastPosition]);
        v[lastPosition] = 0;
    }
    ultrapassa(v, lastPosition, excedeu);
}

int main(){
    //scanf section
    int size = 1;
    int limite;
    int *v = calloc(size, sizeof(int));
    for(;; i++){
        scanf("%d", &v[i]);
        if(v[i] == 0) break;
        v = realloc(v, sizeof(int) * (++size)); //increase array size
    }
    scanf("%d", &limite);
    ultrapassa(v, 0, limite);
    free(v);
}