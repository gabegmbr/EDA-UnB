#include <stdio.h>

int repetidos(int *v, int qtd, int index){
    int repeated = -1;
    for (int i = 0; i < qtd; i++) if(v[i] == v[index]) repeated++;
    return repeated;
}
