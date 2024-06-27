#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int frequencia;
    int candidato;
    int porcentagem;
    struct celula *prox;
} celula;

celula *pres, *sen, *depFed, *depEst;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort (int v[], int l, int r){
    int i = l;
    while(i != r-1){
        int menor = i;
        for(int j = i; j < r; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        swap(&v[i], &v[menor]);
        i++;
    }
}

void mediana(int *arr, int l, int r){
    int meio = (l+r)/2;
    swap(&arr[meio], &arr[r-1]);
    if(arr[l] > arr[r-1]){
        swap(&arr[l], &arr[r-1]);
    }
    if(arr[l] > arr[r]){
        swap(&arr[l], &arr[r]);
    }
    if(arr[r-1] > arr[r]){
        swap(&arr[r-1], &arr[r]);
    }
}

int partition(int *arr, int l, int r){
    int pivot = r;
    int j = -1;
    for(int i = 0; i < r; i++){
        if(j > i) break;
        if(arr[i] <= arr[pivot]){
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j+1], &arr[pivot]);
    return j+1;
}

int calcularDigitos(int n){
    int count = 0;
    while(n != 0){
        n = n/10;
        count++;
    }
    return count;
}

void quickSort(int *arr, int l, int r){
    if (l <= r){
        if(r-l <= 100) return selection_sort(arr, l, r+1);
        mediana(arr, l, r);
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

void enfileira (celula **f, int fr, int c){
    celula *novo = malloc(sizeof(celula));
    novo->frequencia = fr;
    novo->candidato = c;
    novo->prox = (*f);
    (*f) = novo;
}

void analisa(int *arr, int l, int r, int *votosPres){
    if(l < r){
        int frequencia = 0;
        int candidato = arr[l];
        int i;
        for(i = l; i < r && arr[i] == candidato; i++, frequencia++);
        int digitos = calcularDigitos(candidato);
        switch(digitos){
            case 2:
            enfileira(&pres, frequencia, candidato);
            votosPres+=frequencia;
            break;
            case 3:
            enfileira(&sen, frequencia, candidato);
            break;
            case 4:
            enfileira(&depFed, frequencia, candidato);
            break;
            case 5:
            enfileira(&depEst, frequencia, candidato);
            break;
        }
        analisa(arr, i, r, votosPres);
    }
}
int main (){
    pres = sen = depFed = depEst = NULL;
    int qtdSen, qtdDepFed, qtdDepEst;
    int votosPres = 0;
    scanf("%d %d %d", &qtdSen, &qtdDepFed, &qtdDepEst);
    int votos[10000];
    int candidato;
    int votosVal = 0;
    int votosInv = 0;
    while(scanf("%d", &candidato) == 1){
        if(candidato >= 10){
            votos[votosVal++] = candidato;
        } else{
            votosInv++;
        }
    }
    quickSort(votos, 0, votosVal-1);
    analisa(votos, 0, votosVal, &votosPres);
}