#include <stdio.h>
#include <math.h>

int i = 1;
int d = 1;

void printMidDash(int size){
    if(d == size-1){
        d = 1;
        return;
    }
    printf("-");
    d++;
    printMidDash(size);
}

void Subinterval(int subSize, int n){
    printf(".");
    if (i == subSize-1){
        printf("-");
        i = 1;
        return;
    }
    if(i%2 != 0){
        printf("-");
    }
    if(i%2 == 0){
        if(i == subSize/2){
            printMidDash(n-1);
        }
        printf("--");
    }
    printf("\n");
    i++;
    Subinterval(subSize, n);
}

void printRuler(int subSize, int n){
    if(n <= 0) return;
    if(n == 1){
        printf(".-\n");
        return;
    }
    Subinterval(subSize, n);
    printf("\n");
    printf(".");
    d = -1;
    printMidDash(n);
    printf("\n");
    Subinterval(subSize, n);
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int iterations = pow(2, n)-1;
    int subSize = pow(2, n)/2;
    printRuler(subSize, n);
}