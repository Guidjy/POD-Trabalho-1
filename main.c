#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista.h"
#include "ordenacao.h"

int main(int argc, char *argv[]) {
    /* habilita a geração de números aleatórios */
    srand(time(0));

    /* variáveis para cronometragem */
    clock_t inicio, fim;
    double tempo_gasto;

    /* cria uma lista e a preenche com inteiros positivos aleatórios */
    Lista l = lista_cria(atoi(argv[2]));
    lista_preenche(l, 100000);
    lista_ordenada(l);

    /* seleciona algoritmo baseado no argumento */
    int algoritmo = 0; /* default: insertion sort */
    if (argc >= 2) {
        if (strcmp(argv[1], "insertion") == 0) {
            algoritmo = 0;
        } else if (strcmp(argv[1], "bubble") == 0) {
            algoritmo = 1;
        } else if (strcmp(argv[1], "quick") == 0) {
            algoritmo = 2;
        } else if (strcmp(argv[1], "heap") == 0) {
            algoritmo = 3;
        } else if (strcmp(argv[1], "counting") == 0) {
            algoritmo = 4;
        }
    }

    /* ordena a lista */
    inicio = clock();
    bucket_sort(l, algoritmo);
    fim = clock();
    lista_ordenada(l);

    /* calcula o tempo gasto */
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo para ordenar %d elementos usando %s sort: %f segundos\n", l->n_elem, argv[1], tempo_gasto);

    lista_destroi(l);
    return 0;
}
