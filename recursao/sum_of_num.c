#include <stdio.h>

int recSum(int end){
    int sum;
    if(end == 1){
        return 1;
    }
    else{
        sum = end + recSum(end-1);
    }
    return sum;
}

int main(){
    int end = 5;
    int result = recSum(end);
    printf("%d\n", result);
}