#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

struct _lista {
    int cap;         // capacidade máxima da lista
    int n_elem;      // número de elementos na lista
    int *vetor;      // vetor de inteiros
};
typedef struct _lista *Lista;

// cria uma lista que suporta "tamanho" elementos
Lista lista_cria(int tamanho);

// libera tgoda a memória alocada para uma lista
void lista_destroi(Lista lista);

// retorna true se a lista estiver cheia
bool lista_cheia(Lista lista);

// insere um inteiro na lista
void lista_insere(Lista lista, int num);

// retorna o maior valor da lista
int lista_max(Lista lista);

// preenche a lista com valores aleatórios em um intervalo
void lista_preenche(Lista lista, int intervalo);

// troca dois elementos de posição
void lista_swap(Lista lista, int pos_1, int pos_2);

// imprime os elementos de uma Lista
void lista_imprime(Lista lista);

#endif