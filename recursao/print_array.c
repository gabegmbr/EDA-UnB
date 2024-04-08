#include <stdio.h>

void printArray(int arr[], int n, int iterations){ 
    if(n >= iterations){
        return;
    }
    printf("%d ", arr[n]);
    printArray(arr, ++n, iterations);
}

int main(){
    int iterations = 6;
    int array[6] = {2, 4, 6, 8, 10, 12};
    printf("The elements in the array are: ");
    printArray(array, 0, iterations);
}