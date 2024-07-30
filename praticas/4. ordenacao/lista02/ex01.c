/*
1) Crie um programa que dado uma string de tamanho máximo 100, coloque as letras
dela em ordem crescente usando o algoritmo BubbleSort( ). Considere a string com
letras maiúsculas (caso seja necessário, use a função strupr( ) da biblioteca string.h).
No final, mostre a string resultante
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char str[100];
    int i, j, n, v[100];

    printf("Digite uma string: ");
    fgets(str, 100, stdin);       // le a string (melhor que gets(str))
    str[strlen(str) - 1] = '\0';  // para a saída não ficar com um enter no final da string

    n = strlen(str);           // tamanho da string
    for (i = 0; i < n; i++) {  // converte a string para um vetor de inteiros
        v[i] = str[i];         // cada elemento do vetor é um caractere da string
    }
    bubbleSort(v, n);          // ordena o vetor
    for (i = 0; i < n; i++) {  // converte o vetor de inteiros para uma string
        str[i] = v[i];
    }

    printf("\nString ordenada (normal): %s\n", str);
    printf("String ordenada (maiusculo): %s\n", strupr(str));
    printf("String ordenada (minusculo): %s\n", strlwr(str));
    return 0;
}
