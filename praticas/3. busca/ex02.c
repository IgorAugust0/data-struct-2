// 2) Refaça a função de busca linear, assumindo que o vetor possui chaves duplicadas.

/* 
Busca Sequencial Ordenada

Vantagem:
- Simplicidade
Desvantagem:
- Dados duplicados
- Alto custo computacional

Análise de Complexidade:
- O(1), melhor caso: elemento encontrado na primeira posição.
- O(n), pior caso: elemento encontrado na última posição (ou não encontrado).
- O(n): caso médio.
*/

#include <stdio.h>
#include <stdlib.h>

/*
int buscaLinear(int* v, int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (x == v[i]) return i;
    }
    return -1;
}
*/

/*
int buscaLinearRecursiva(int* v, int n, int x) {
    if (n == 0) return -1;
    if (x == v[n - 1]) return n - 1;
    return buscaLinearRecursiva(v, n - 1, x);
}
*/

int buscaLinearChavesDuplicadas(int* v, int n, int x) {
    int i;
    for (i = 0; i < n; i++) { 
        if (x == v[i]) return i; // achou
        if (x < v[i]) return -1; // não achou
    }
    return -1;
}

int main () {
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10};
    int x = 5;
    int n = 10;
    int pos = buscaLinearChavesDuplicadas(v, n, x);
    if (pos == -1)
        printf("Elemento %d nao encontrado.\n", x);
    else
        printf("Elemento %d encontrado na posicao %d.\n", x, pos);
    return 0;
}
