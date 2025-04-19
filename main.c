#include "lista.h"
#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int agrc, char *argv[]) {
    // habilita a geração de números aleatórios
    srand(time(0));

    // cria structs para cronometragem
    struct timespec antes;
    struct timespec depois;

    // cria uma lista e a preenche com inteiros positivos aleatórios entre um intervalo
    // 100000
    // 1000000 
    // 100000000
    Lista l = lista_cria(100000000);
    lista_preenche(l, 10000);
    lista_ordenada(l);

    // ordena a lista
    clock_gettime(CLOCK_REALTIME, &antes);
    bucket_sort(l);
    clock_gettime(CLOCK_REALTIME, &depois);
    lista_ordenada(l);

    // calcula o tempo que demorou para ordenar a lista 
    long long tempo_ordenacao = (depois.tv_sec - antes.tv_sec) * 1000000000LL + (depois.tv_nsec - antes.tv_nsec);
    printf("Tempo para ordenar %d elementos: %lld nanosegundos\n", l->n_elem, tempo_ordenacao);

    lista_destroi(l);
    return 0;
}