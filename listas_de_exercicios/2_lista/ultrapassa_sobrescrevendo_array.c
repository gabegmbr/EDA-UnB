#include <stdio.h>
#include <stdlib.h>

int i = 0;
int j = 0;
void ultrapassa(int *v, int j, int limite){
    int soma = 0;
    for (; j < i && soma < limite; j++){
        soma = soma+v[j];
    }
    if(j != i && soma != 0){
        ultrapassa(v, j, limite);
    }
    if(soma > limite && v[j] != 0){
        printf("%d\n", v[j-1]);
    }
    return;
}

int main(){
    //scanf section
    int size = 1;
    int limite;
    int *v = calloc(size, sizeof(int));
    for(i = 0;; i++){
        scanf("%d", &v[i]);
        if(v[i] == 0) break;
        v = realloc(v, sizeof(int) * (++size)); //increase array size
    }
    scanf("%d", &limite);
    ultrapassa(v, 0, limite);
    free(v);
}