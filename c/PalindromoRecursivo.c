#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Palindromo(char p[50], int tam, int i){
  if (i <= tam){
    if (p[i] != p[tam]){
       return 0;
    } else {
        return Palindromo(p, i++, tam--);
     }
  }
}

int main(){
    char palavra[50];
    int tamanho;
    int i = 0;

    printf ("Insira uma palavra:\n");
    scanf ("%s", palavra);

    tamanho = strlen(palavra);
    tamanho--;

    if (Palindromo(palavra, tamanho, i)){
        printf ("P\n");
    } else {
        printf ("NP\n");
    }

    return 0;
}