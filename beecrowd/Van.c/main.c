#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alunos{

    char nome[50];
    char regiao;
    int custo;


}Alunos;

int comparar(Alunos a, Alunos b) {
    if (a.regiao != b.regiao) {
        return a.regiao - b.regiao; // Ordena por região em ordem alfabética
    }
    return a.custo - b.custo; // Ordena por custo em ordem crescente se as regiões forem iguais
}


void insertionSort(int ap, Alunos alunos[]){

for(int i = 1 ; i < ap ; i++){
    Alunos temp = alunos[i];
    int j = i - 1;
    while ((j >= 0) && comparar(alunos[j], temp) > 0){
        alunos[j+1] = alunos[j];
        j--;
    }
    alunos[j + 1] = temp;
 }
}



int main (){
    
    int alunosPresentes; 
    
    while(scanf("%d", &alunosPresentes) != EOF){
    Alunos alunos[alunosPresentes];

    for(int i = 0 ; i < alunosPresentes ; i++){
        scanf("%s", alunos[i].nome);
        scanf(" %c", &alunos[i].regiao);
        scanf("%d", &alunos[i].custo);
    }

     insertionSort(alunosPresentes, alunos);

    for (int i = 0; i < alunosPresentes ; i++){
        printf("%s\n", alunos[i].nome);
      }
    }

    return 0;
}