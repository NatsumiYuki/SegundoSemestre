#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Palindromo(char p[50], int tam, int i){
  if (i <= tam){
    if (p[i] != p[tam]){
       return 0;
    } else {
        return Palindromo(p, i+1, tam-1);
     }
  }
}

int main(){
    char palavra[50];
    int tamanho;
    int i = 0;

    while(strcmp(palavra,"FIM") != 0){
    scanf ("%s", palavra);

    tamanho = strlen(palavra);
    tamanho--;

    if (Palindromo(palavra, tamanho, i)){
        printf ("SIM\n");
    } else {
        printf ("NAO\n");
    }
    }
    return 0;
}