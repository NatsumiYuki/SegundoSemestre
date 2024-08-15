#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char palavra[50];
    int i = 0, tamanho, igual = 0;

    printf ("Insira a palavra:\n");
    scanf ("%s", palavra);

    tamanho = strlen(palavra);
    // 0
    tamanho--;

    while(i <= tamanho){
        if (palavra[i] != palavra[tamanho]){
            igual++;
        }
        i++;
        tamanho--;
    }

    if (igual == 0){
        printf ("SIM");
    } else {
        printf ("NAO");
    }
    return 0;
}