#include <stdio.h>


void ordenate(int *v, int i, int j, int length){
    if (i == length){

    }
    if (v[i] == j){
        v[v[i]] = v[i];
        ordenate(v, ++i, 0, length);
    }
    else{
        ordenate(v, i, ++j, length);
    }
}

int main (){
    int vetor[5] = {2, 3, 1, 4, 0};
    ordenate(vetor, 0, 0, 5);
}