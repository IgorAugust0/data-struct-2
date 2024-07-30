// 3) Refaça a função de busca ordenada, assumindo que o vetor possui chaves duplicadas.

/* Busca Sequencial Ordenada
Vantagem:
- Dados duplicados
Desvantagem:
- Custo de ordenação

É comum não percorrer todo o vetor!

Análise de Complexidade:
- O(1), melhor caso: elemento encontrado na primeira posição.
- O(n), pior caso: elemento encontrado na última posição (ou não encontrado).
- O(n): caso médio.*/

#include <stdio.h>
#include <stdlib.h>


int buscaOrdenada(int* v, int n, int x) {
    int i = 0;
    while (i < n && v[i] < x) i++;

    if (x == v[i])
        return i;
    else
        return -1;
}

int buscaOrdenadaChavesDuplicadas(int* v, int n, int x) {
    int i = 0;
    while (i < n && v[i] <= x) i++;

    if (x == v[i - 1])
        return i - 1;
    else
        return -1;
}

int buscaOrdenadaRecursiva(int* v, int n, int x) {
    if (n == 0) return -1;
    if (x == v[n - 1]) return n - 1;
    return buscaOrdenadaRecursiva(v, n - 1, x);
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10};
    int n = 10;
    int x = 8;

    printf("Posicao: %d\n", buscaOrdenada(v, n, x));
    printf("Posicao: %d\n", buscaOrdenadaChavesDuplicadas(v, n, x));
    printf("Posicao: %d\n", buscaOrdenadaRecursiva(v, n, x));

    return 0;
}