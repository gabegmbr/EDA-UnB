#include <stdio.h>

long long int realizarSoma(long long int n, long long int i, long long int soma){
    long long int digito = (n/i)%10;
    if(digito == 0){
        return soma;
    }
    soma = soma+digito;
    i*=10;
    realizarSoma(n, i, soma);
}

int main(){
    long long int n;
    scanf("%lld", &n);
    long long int resultado = realizarSoma(n, 1, 0);
    printf("%lld\n", resultado);
}