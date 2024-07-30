/*
Algoritmos de Ordenação Sofisticados: Quick Sort

– Complexidade:
• O(n log n), melhor caso e caso médio.
• O(n2), pior caso: pivo escolhido fica sempre nas extremidades.

- Não é estável
- Insertion Sort é melhor quando o vetor já está ordenado (O(n))

Também conhecido como algoritmo de partição. Usa estratégia de “divisão e conquista”.
*/

#include <stdio.h>
#include <stdlib.h>

int particiona(int* v, int inicio, int fim) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while (esq < dir) {
        while (v[esq] <= pivo && esq <= fim) esq++; // avança posição da esquerda
        while (v[dir] > pivo && dir >= inicio) dir--; // recua posição da direita
        if (esq < dir) { // troca esq e dir se esq < dir
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int* v, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particiona(v, inicio, fim);  // separa o vetor em duas partes
        quickSort(v, inicio, pivo - 1);     // chama para o lado esquerdo
        quickSort(v, pivo + 1, fim);        // chama para o lado direito
    }
}



int main() {
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;
    quickSort(v, 0, 9);
    for (i = 0; i < 10; i++) printf("%d ", v[i]);
    return 0;
}
