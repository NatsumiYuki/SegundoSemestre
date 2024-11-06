#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para ordenar as palavras em cada frase pelo comprimento em ordem decrescente
void insertionSort(char frase[][50], int tam) {
    char temp[50];

    // Insertion sort para ordenar as palavras pelo comprimento
    for (int i = 1; i < tam; i++) {
        strcpy(temp, frase[i]);
        int j = i - 1;

        // Desloca palavras menores para frente para ordenar em ordem decrescente de comprimento
        while (j >= 0 && strlen(frase[j]) < strlen(temp)) {
            strcpy(frase[j + 1], frase[j]);
            j--;
        }
        strcpy(frase[j + 1], temp);
    }
}

int main() {
    int N;
    char frase[50][50], *pt, fraseCompleta[1000];
    
    // Lê o número de casos de teste
    scanf("%d", &N);
    getchar(); // Limpa o '\n' após o número

    for (int i = 0; i < N; i++) {
        int tam = 0; // Contador para o número de palavras na frase atual

        // Lê uma frase completa
        fgets(fraseCompleta, sizeof(fraseCompleta), stdin);
        fraseCompleta[strcspn(fraseCompleta, "\n")] = '\0'; // Remove o '\n' ao final

        // Tokeniza a linha e armazena cada palavra em `frase`
        pt = strtok(fraseCompleta, " ");
        while (pt) {
            strcpy(frase[tam++], pt); // Armazena cada palavra separadamente em `frase`
            pt = strtok(NULL, " ");
        }

        // Ordena as palavras da frase pelo comprimento
        insertionSort(frase, tam);

        // Imprime as palavras ordenadas com espaço entre elas
        for (int j = 0; j < tam; j++) {
            printf("%s", frase[j]);
            if (j < tam - 1) {
                printf(" ");
            }
        }
        printf("\n"); // Quebra de linha após cada caso de teste
    }

    return 0;
}
