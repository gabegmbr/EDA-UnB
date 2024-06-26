#include <stdio.h>
#include <stdlib.h>


/*
pseudocodigo 

presidente: 2 digitos
senador: 3 digitos
dep. fed: 4 digitos
dep. est: 5 digitos

listas encadeadas: presidentes, senadores, depFeds, depEsts
algoritmo de ordenação: merge sort adaptado para listas encadeadas
função mergeSort deverá ser adaptada para ordenar dois campos diferentes, "dados" e "candidato";
mergeSort mode 1 = ordenação pelo campo "candidato";
mergeSort mode 2 = ordenação pelo campo "dados";

- receber quantidade de senadores, dep. fed, e dep. est.
- iniciar caso de teste:
    - receber número do candidato;
    - chamar função calcularDigitos, que vai retornar para a variável digitos;
    - se digitos é menor que 2 ou candidato é menor que zero, votosInv++;
    - se digitos é maior que 2:
        (usar case ao invés de if)
        se digitos é igual a 2:
            buscar nº do presidente na lista encadeada presidentes
            se busca é positiva, busca->dados++ e votosVal++;
            se busca é nula, enfileirar novo presidente.
        se digitos é igual a 3:
            buscar nº do presidente na lista encadeada senadores
            se busca é positiva, busca->dados++ e votosVal++;
            se busca é nula, enfileirar novo senador.
        se digitos é igual a 4:
            buscar nº do presidente na lista encadeada depFeds
            se busca é positiva, busca->dados++ e votosVal++;
            se busca é nula, enfileirar novo deputado federal.
        se digitos é igual a 5:
            buscar nº do presidente na lista encadeada depEsts
            se busca é positiva, busca->dados++ e votosVal++;
            se busca é nula, enfileirar novo deputado estadual.
        importante: ao inserir novo candidato, ordenar lista pelo campo "candidato".
    fim do caso de teste quando scanf == EOF
- printar votos válidos e inválidos
- cálculo para determinar o presidente:
    percorrer lista para calcular quantidade total de votos para presidente;
    percorrer lista novamente para calcular porcentagem de voto de cada presidente.
    percorrer a lista NOVAMENTE à procura do candidato com porcentagem maior que 51%.
    guardar o candidato numa variável auxiliar que deve ser inicializada = NULL;
    se a variável auxiliar for == NULL, printar "Segundo turno";
    caso contrário, printar o valor do candidato armazenado na variável auxiliar.
    
    (essa definitivamente não é a maneira mais eficiente de realizar isso)
- ordenar todas as listas pelo campo "dados"

*/
typedef struct celula {
    int dado;
    int candidato;
    int porcentagem;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x, int c){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->candidato = c;
    novo->prox = (*f);
    (*f) = novo;
}

int calcularDigitos(int n){
    int count;
    while(n != 0){
        n = n/10;
        count++;
    }
    return count;
}

int main (){

}