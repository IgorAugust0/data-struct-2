/*
Algoritmos de Ordenação Básicos: Selection Sort
– Complexidade:
• O(n^2), sempre.

– Descrição:
Procura o menor à direita de i, e atualiza a nova posição do menor,
trazendo o menor para primeira posição, e assim sucessivamente.
*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* v, int n) {
    int i, j, menor, aux;

    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) menor = j;
        }
        if (i != menor) {
            aux = v[menor];
            v[menor] = v[i];
            v[i] = aux;
        }
    }
}

int main() {
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(v, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
