#include "lista.h"
#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int agrc, char *argv[]) {
    // habilita a geração de números aleatórios
    srand(time(0));

    // cria uma lista e a preenche com inteiros positivos aleatórios entre 0 e 50
    Lista l = lista_cria(20);
    lista_preenche(l, 50);
    lista_imprime(l);
    if (lista_ordenada(l)) {
        printf("Lista está ordenada (:\n");
    } else {
        printf("Lista não está ordenada ):\n");
    }

    // ordena a lista
    bucket_sort(l);
    lista_imprime(l);
    if (lista_ordenada(l)) {
        printf("Lista está ordenada (:\n");
    } else {
        printf("Lista não está ordenada ):\n");
    }
    
    lista_destroi(l);
    return 0;
}