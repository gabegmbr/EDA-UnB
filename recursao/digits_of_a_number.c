#include <stdio.h>

int digits(int i, int dec, int num){
    printf("%d ", dec);
    int operation = num%dec;
    if (operation == num){
        printf("check \n");
        return i;
    }
    i++;
    digits(i, dec*10, num);
}
int main(){
    printf("Insert a number: ");
    int num;
    scanf("%d", &num);
    int result = digits(0, 1, num);
    printf("The number of digits in the number is: %d", result);
}