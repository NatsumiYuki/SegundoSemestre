#include <stdio.h>      
#include <string.h>     
#include <stdlib.h>      


typedef struct {
    char number[250];    
} Phone;


Phone phoneList[100050];


int comparePhones(Phone *a, Phone *b) {
    //A ceta esta apontando tal qual um ponteiro
    int result = strcmp(a->number, b->number); 

    // Retorna o valor adequado para ordenar em ordem decrescente
    if (result == 0)
        return 0;          // Retorna 0 se os números são iguais
    else if (result < 0)
        return 1;          // Retorna 1 se 'a' é menor que 'b' (para ordem decrescente)
    else
        return -1;         // Retorna -1 se 'a' é maior que 'b' (para ordem decrescente)
}

int main() {
   int numberOfPhones, i, j;  

    
    while (scanf("%d", &numberOfPhones) != EOF) {
        i = 0;                       
         int auxNumberOfPhones = numberOfPhones;  

        // Lê cada número de telefone e armazena em 'phoneList'
        while (numberOfPhones--)
            scanf("%s", phoneList[i++].number);  // Lê o número e incrementa o índice

        int totalSavings = 0;  // Inicializa a variável para contar os caracteres economizados

        // Ordena a lista de telefones em ordem decrescente para facilitar a comparação de prefixos
        qsort(phoneList, i, sizeof(Phone), comparePhones);

        // Percorre a lista de números de telefone para comparar prefixos entre pares consecutivos
        for (i = 1; i < auxNumberOfPhones; ++i) {
           int prefixLength = 0;  
            // Compara cada caractere entre dois números consecutivos até encontrar uma diferença
            while (phoneList[i].number[prefixLength] == phoneList[i - 1].number[prefixLength])
                ++prefixLength;            

            totalSavings += prefixLength;   // Adiciona o comprimento do prefixo encontrado ao total de economia
        }

        
        printf("%u\n", totalSavings);
    }

    return 0; 
