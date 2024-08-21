#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char palavra[500];
    int i = 0, tamanho, igual = 0;

    do{
    scanf ("%s", palavra);
    tamanho = strlen(palavra);
    tamanho--;

    while(i <= tamanho){
        if (palavra[i] != palavra[tamanho]){
            igual++;
        }
        i++;
        tamanho--;
    }
    if (igual == 0){
        printf ("SIM\n");
    } else {
        printf ("NAO\n");
    }
    }while(strcmp(palavra, "FIM") == 0);

    return 0;
}