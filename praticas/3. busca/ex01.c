// 1) Reescreva a função de busca binária na versão recursiva.

/* Busca Binária
- Muito mais eficiente que a Busca Sequencial Ordenada
- Assume-se vetor ordenado
- Aplica-se a estratégia de “Divisão e Conquista”

Análise de Complexidade:
- O(1), melhor caso: elemento encontrado no meio.
- O(log2 n), pior caso: elemento encontrado no último teste ou não existe.
- O(log2 n): caso médio.*/

/*
int buscaBinaria(int* v, int n, int x) {
    int inicio, fim, meio;
    inicio = 0;
    fim = n - 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (x < v[meio])
            fim = meio - 1;  // metade esquerda
        else {
            if (x > v[meio])
                inicio = meio + 1;  // metade direita
            else
                return meio;
        }
    }
    return -1;
}
*/

#include <stdio.h>
#include <stdlib.h>

int buscaBinariaRecursiva(int* v, int inicio, int fim, int x) {
    if (inicio > fim) return -1;    // não achou
    int meio = (inicio + fim) / 2;  // calcula o meio
    if (x < v[meio])
        return buscaBinariaRecursiva(v, inicio, meio - 1, x);  // metade esquerda
    else {
        if (x > v[meio])
            return buscaBinariaRecursiva(v, meio + 1, fim, x);  // metade direita
        else
            return meio;
    }
}

int main() {
    int v[10] = {2, 3, 12, 36, 45, 56};  // vetor ordenado
    int x = 56;                          // valor a ser buscado
    int n = 6;                           // tamanho do vetor
    int pos = buscaBinariaRecursiva(v, 0, n - 1, x);
    if (pos == -1)
        printf("Elemento %d nao encontrado.\n", x);
    else
        printf("Elemento %d encontrado na posicao %d.\n", x, pos);
    return 0;
}
