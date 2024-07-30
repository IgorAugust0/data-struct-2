/*
Algoritmos de Ordenação Básicos: Bubble Sort
– Complexidade:
• O(n), melhor caso: vetor ordenado crescente
• O(n^2), pior caso: vetor ordenado decrescente
• O(n^2), caso médio: desordenado

– Descrição: 
Carrega o maior elemento para a última posição,
depois o segundo maior elemento para a penúltima posição, 
e assim por diante.
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* v, int n) {
    int i, aux, fim, troca;
    fim = n;
    do {
        troca = -1;
        for (i = 0; i < fim - 1; i++) {  // troca sempre que o elemento da esquerda for maior
            if (v[i] > v[i + 1])         // realiza a troca
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                troca = i;  // marca se houve a troca
            }
        }
        fim--;
    } while (troca != -1);  // enquanto tiver acontecido troca
}

int main() {
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(v, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
