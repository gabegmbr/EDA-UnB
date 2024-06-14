#include <stdio.h>
#include <stdlib.h>

int pq[101];
int n = 0;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void fixUp(int k){
    while(k>1 && pq[k/2] > pq[k]){
        swap(&pq[k], &pq[k/2]);
        k = k/2;
    }
}

void pqInsert(int x){
    pq[++n] = x;
    fixUp(n);
}

void fixDown(int k, int x){
    while(2*k <= x){
        int j = 2*k;
        if(j < x && pq[j+1] < pq[j]) j++;
        if(pq[k] < pq[j]) break;
        swap(&pq[k], &pq[j]);
        k = j;
    }
}

int pqRemove(){
    swap(&pq[1], &pq[n]);
    fixDown(1, n-1);
    return pq[n--];
}

void pqChange(int k, int x){
    if (pq[k] > x){
        pq[k] = x;
        fixUp(k);
    } else {
        pq[k] = x;
        fixDown(k, n);
    }
}

void imprimePq(int x){
    for(int i = 1; i <= x; i++)
        printf("%d", pq[i]);
    printf("\n");
}

int main(){
    int escolha, num;
    while(scanf("%d %d", &escolha, &num) == 2){
        if(escolha == 1){
            if(n == 100){
                int maior = n;
                int k = (n/2);
                while(k != 0){
                    k--;
                    if(pq[k*2] > pq[maior]){
                        maior = k*2;
                    }
                    if(pq[k*2+1] > pq[maior]){
                        maior = k*2+1;
                    }
                }
                if (num < pq[maior]){
                    pqChange(maior, num);
                }

            } else{
                pqInsert(num);
            }
        }
        if(escolha == 2){
            int i = 0;
            int *aux = malloc(sizeof(int)*num);
            while(i < num){
                aux[i++] = pqRemove();
                printf("%d ", aux[i-1]);
            }
            printf("\n");
            for(i = 0; i < num; i++) pqInsert(aux[i]);
            free(aux);
        }
    }
}