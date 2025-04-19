#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

struct _heap {
    int cap;     // capacidade do vetor
    int ult;     // últim índice usado do vetor
    int *vetor;  // armazena os dados do heap
};
typedef struct _heap *Heap;


// Cria um heap que suporta "tamanho" elementos
Heap heap_cria(int tamanho);

// Libera toda a memória alocada para um heap
void heap_destroi(Heap heap);

// retorna true se o heap estiver vazio
bool heap_vazio(Heap heap);

// retorna true se o heap estiver cheio
bool heap_cheio(Heap heap);

// troca dois elementos de posição no heap
void heap_swap(Heap heap, int pos_1, int pos_2);

// Insere um elemento no heap
// 0-0: O(log n)
void heap_insere(Heap heap, int num);

// Remove o menor elemento do heap e o retorna
// 0-0: retorna -1 se estiver vazio
// 0-0: O(log n)
int heap_remove_min(Heap heap);

// imprime o vetor do heap
void heap_imprime(Heap heap);

#endif