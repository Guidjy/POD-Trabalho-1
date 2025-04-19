#include "lista.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


Lista lista_cria(int tamanho) {
    // aloca memória para a estrutura de uma nova lista
    Lista nova = (Lista) malloc(sizeof(struct _lista));
    if (nova == NULL) {
        printf("Erro na alocação de memória para a struct da lista\n");
        return NULL;
    }
    nova->cap = tamanho;
    nova->n_elem = 0;
    // aloca memória para os elementos da lista
    nova->vetor = (int*) malloc(sizeof(int) * tamanho);
    if (nova->vetor == NULL) {
        printf("Erro na alocação de memória para os elementos da lista");
        free(nova);
        return NULL;
    }
    return nova;
}


void lista_destroi(Lista lista) {
    free(lista->vetor);
    free(lista);
}


bool lista_cheia(Lista lista) {
    return lista->n_elem == lista->cap;
}


static void aumenta_cap_vetor(Lista lista) {
    lista->cap *= 2;
    lista->vetor = realloc(lista->vetor, lista->cap * sizeof(int));
    if (lista->vetor == NULL) {
        printf("Erro na realocação de memória do vetor da lista\n");
    }
}


void lista_insere(Lista lista, int num) {
    if (lista_cheia(lista)) {
        aumenta_cap_vetor(lista);
    }
    lista->vetor[lista->n_elem] = num;
    lista->n_elem++;
}


int lista_max(Lista lista) {
    int maior = 0;
    for (int i = 0; i < lista->n_elem; i++) {
        if (i == 0 || maior < lista->vetor[i]) {
            maior = lista->vetor[i];
        }
    }
    return maior;
}


void lista_preenche(Lista lista, int intervalo) {
    for (int i = 0; i < lista->cap; i++) {
        lista->vetor[i] = rand() % intervalo;
    }
    lista->n_elem = lista->cap;
}


void lista_swap(Lista lista, int pos_1, int pos_2) {
    // verifica se os índices de posição são válidos
    if ((0 <= pos_1 && pos_1 < lista->n_elem) && (0 <= pos_2 && pos_2 < lista->n_elem)) {
        int temp = lista->vetor[pos_1];
        lista->vetor[pos_1] = lista->vetor[pos_2];
        lista->vetor[pos_2] = temp;
    }
}


bool lista_ordenada(Lista lista) {
    for (int i = 1; i < lista->n_elem; i++) {
        if (lista->vetor[i] < lista->vetor[i-1]) {
            return false;
        }
    }
    return true;
}


void lista_imprime(Lista lista) {
    printf("[");
    for (int i = 0; i < lista->n_elem - 1; i++) {
        printf("%d, ", lista->vetor[i]);
    }
    printf("%d]\n", lista->vetor[lista->n_elem - 1]);
}