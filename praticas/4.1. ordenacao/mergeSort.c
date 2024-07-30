/*
Algoritmos de Ordenação Sofisticados: Merge Sort

– Complexidade:
• O(n log n): em todos os casos
• Não depende da ordem inicial do vetor
- Estável
- Gasto com memória extra (vetor auxiliar)

Utiliza “dividir para conquistar”: aplica em cada metade
a ordenação e depois intercala os subvetores ordenados.
*/

#include <stdio.h>
#include <stdlib.h>

int merge(int* v, int inicio, int meio, int fim) {
    int *aux, p1, p2, tam, i, j, k, f1, f2;
    f1 = f2 = 0;
    tam = fim - inicio + 1;
    p1 = inicio; // primeiro elemento da primeira metade
    p2 = meio + 1; // primeiro elemento da segunda metade
    aux = (int*)malloc(tam * sizeof(int)); // terceiro vetor 
    if (aux != NULL) {
        for (i = 0; i < tam; i++) {
            if (f1 == 0 && f2 == 0)  // nenhum dos subvetores acabou
            {
                if (v[p1] < v[p2]) { // combina ordenado
                    aux[i] = v[p1];
                    p1++;
                } else {
                    aux[i] = v[p2];
                    p2++;
                }
                if (p1 > meio) f1 = 1;  // vetor acabou?
                if (p2 > fim) f2 = 1;
            } else  // qual subvetor acabou?
            {
                if (f1 == 1) { // copia o restante do outro vetor
                    aux[i] = v[p2];
                    p2++;
                } else {
                    aux[i] = v[p1];
                    p1++;
                }
            }
        }  // fim for
        for (j = 0, k = inicio; j < tam; j++, k++)
            v[k] = aux[j];
    }
    free(aux);
}

int mergeSort(int* v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);   // metade da esquerda
        mergeSort(v, meio + 1, fim);  // metade da direita
        // intercala as duas metades ordenadas
        merge(v, inicio, meio, fim);
    }
}

int main() {
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;
    mergeSort(v, 0, 9);
    for (i = 0; i < 10; i++) printf("%d ", v[i]);
    return 0;
}