/*
3) Considerando a mesma estrutura acima, faça a ordenação do vetor usando o
algoritmo InsertionSort( ), ordenando os indivíduos em relação ao tamanho do nome.
No final, o algoritmo deve mostrar todos os indivíduos ordenados (com suas
respectivas informações).

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
}*/

#include <stdio.h>
#include <stdlib.h>

typedef struct individuo {
    int idade;
    char nome[100];
    
} Ind;  // melhor que: typedef struct individuo Ind;

void insertionSort (Ind* v, int n) {
    for (int i = 1; i < n; i++) {  // vai da segunda posição em diante
        Ind aux = v[i];
        int j = i;
        while (j > 0 && v[j - 1].nome > aux.nome)  // enqto existe alguém maior
        {                                // que aux, faz o deslocamento para direita
            v[j] = v[j - 1];
            j--;  // duplicando esse elemento
        }
        v[j] = aux;  // local correto em que posso substituir
    }
}

int main() {
    int n; // n = numero de individuos
    Ind* v; // vetor de estruturas

    printf("Digite o numero de individuos: ");
    scanf("%d", &n);
    printf("\n");

    v = (Ind*)malloc(n * sizeof(Ind));

    for (int i = 0; i < n; i++) {
        printf("Digite o nome do individuo %d: ", i + 1);
        scanf("%s", v[i].nome);
        printf("Digite a idade do individuo %d: ", i + 1);
        scanf("%d", &v[i].idade);
        printf("\n");
    }

    insertionSort(v, n);
    printf("Individuos ordenados em ordem alfabetica: \n");

    for (int i = 0; i < n; i++) {
        printf("\nIndividuo %d:\n", i + 1);
        printf("Nome: %s\n", v[i].nome);
        printf("Idade: %d\n", v[i].idade);
        printf("\n");
    }

    free(v);
    return 0;
}
