/*
Algoritmos de Ordenação Básicos: Insertion Sort
– Complexidade
• O(n), melhor caso: vetor ordenado crescente
• O(n^2), pior caso: vetor ordenado decrescente
• O(n^2), caso médio: desordenado

– Descrição:
Pega o elemento a ser ordenado, e depois procura a posição certa
para inseri-lo enquanto o aux for menor que os vizinhos à esquerda.
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {  // vai da segunda posição em diante
        aux = v[i];
        j = i;
        while (j > 0 && v[j - 1] > aux)  // enqto existe alguém maior
        {                                // que aux, faz o deslocamento para direita
            v[j] = v[j - 1];
            j--;  // duplicando esse elemento
        }
        v[j] = aux;  // local correto em que posso substituir
    }
}

int main() {
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSort(v, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
