/*
2) Faça um programa que leia N indivíduos, onde cada indivíduo contem as seguintes
informações: nome e idade. Ordene-os pela idade usando o algoritmo
SelectionSort( ). No final, o algoritmo deve mostrar todos os indivíduos ordenados
(com suas respectivas informações).

Para esta questão, faça alocação dinâmica sobre um vetor de tamanho N, onde cada
posição há uma estrutura do tipo:

struct individuo{
int idade;
char nome[100];
};
typedef struct individuo Ind;


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
}*/

#include <stdio.h>
#include <stdlib.h>

typedef struct individuo {
    int idade;
    char nome[100];
} Ind;  // melhor que: typedef struct individuo Ind;

void selectionSort(Ind* v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {       // procurando se tem menor à direita
            if (v[j].idade < v[menor].idade) {  // atualiza a posição do novo menor
                menor = j;
            }
        }
        if (menor != i) {  // se o menor não for o primeiro, troca
            int aux = v[i].idade;
            v[i].idade = v[menor].idade;
            v[menor].idade = aux;
        }
    }
}

int main() {
    int n;   // n = numero de individuos
    Ind* v;  // vetor de estruturas

    printf("Digite o numero de individuos: ");
    scanf("%d", &n);
    printf("\n");
    v = (Ind*)malloc(n * sizeof(Ind));  // aloca o vetor de individuos

    for (int i = 0; i < n; i++) {                          // le os dados dos individuos
        printf("Digite o nome do individuo %d: ", i + 1);  // i + 1 para mostrar o numero do individuo a partir de 1 e não de 0
        scanf("%s", v[i].nome);
        printf("Digite a idade do individuo %d: ", i + 1);
        scanf("%d", &v[i].idade);
        printf("\n");
    }
    selectionSort(v, n);  // ordena o vetor
    printf("Individuos ordenados pela idade (mais novo ao mais velho): \n");

    for (int i = 0; i < n; i++) {  // mostra o vetor ordenado
        printf("\nIndividuo %d:\n", i + 1);
        printf("Nome: %s.\nIdade: %d. \n", v[i].nome, v[i].idade);
    }
    free(v);
    return 0;
}
