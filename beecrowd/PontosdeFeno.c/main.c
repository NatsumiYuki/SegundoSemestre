#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char word[100];
    int value;
} Position;

typedef struct {
    char palavra[300];
} string;

bool procuraPalavra(Position *positions, char *palavra, int numWords, int *posicao) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(positions[i].word, palavra) == 0) {
            *posicao = i;
            return true;
        }
    }
    return false;
}

int main() {
    int numberWords, numberDescriptions;
    scanf("%d %d", &numberWords, &numberDescriptions);

    Position positions[1000];
    for (int i = 0; i < numberWords; i++) {
        scanf("%s %d", positions[i].word, &positions[i].value);
    }

    while (numberDescriptions--) {
        int totalSalary = 0;
        string dictionary[10000];
        int wordIndex = 0;

        char line[256];
        while (strcmp(line, ".") != 0) {
           
            scanf(" %[^\n]", line);

            char *word = strtok(line, " ");
            while (word != NULL) {
                strcpy(dictionary[wordIndex++].palavra, word);
                word = strtok(NULL, " ");
            }
        }

        int posicao;
        for (int j = 0; j < wordIndex; j++) {
            if (procuraPalavra(positions, dictionary[j].palavra, numberWords, &posicao)) {
                totalSalary += positions[posicao].value;
            }
        }

        printf("%d\n", totalSalary);
    }

    return 0;
}
