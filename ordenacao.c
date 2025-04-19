#include "ordenacao.h"
#include "lista.h"
#include "heap.h"
#include <stdlib.h>


void bubble_sort(Lista lista) {
    for (int i = 1; i < lista->n_elem; i++) {
        for (int j = 0; j < lista->n_elem - 1; j++) {
            if (lista->vetor[j] > lista->vetor[j+1]) {
                lista_swap(lista, j, j+1);
            }
        }
    }
}


void insertion_sort(Lista lista) {
    // percorre a parte da direita, começando do 1 pois o elemento em 0 está na parte da esquerda (ordenada)
    for (int i = 1; i < lista->n_elem; i++) {
        int pivo = lista->vetor[i];
        int j = i - 1;  // índice do elemento mais a direita da parte da direita
        // percorre a parte esquerda, deslocando cada elemento um índice para a direita, até achar um elemento menor que o pivo
        while (j >= 0 && lista->vetor[j] > pivo) {
            lista->vetor[j+1] = lista->vetor[j];
            j--;
        }
        // insere o pivo na parte da direita
        lista->vetor[j+1] = pivo;
    }
}


// retorna um índice j, no qual será colocado o pivô, tal que:
//     > lista[inicio] ... lista[j-1] <= lista[j]
//     > lista[j+1] ... lista[fim] > lista[j]
// (usado pelo quicksort)
static int particao(Lista lista, int inicio, int fim) {
    int pivo = lista->vetor[inicio];
    int i = inicio + 1;
    int j = fim;

    // procedimentos são repetidos até que i > j
    while (i <= j) {
        // i avança até encontrar um elemento maior que o pivô
        while (i <= j && lista->vetor[i] <= pivo) {
            i++;
        }
        // j recua até encontrar um elemento menor ou igual ao pivô
        while (lista->vetor[j] > pivo) {
            j--;
        }
        // troca os elementos em i e j
        if (i <= j) {
            lista_swap(lista, i, j);
            i = i + 1;
            j = j - 1;
        }
    }

    lista_swap(lista, inicio, j);
    return j;
}


void quick_sort(Lista lista, int inicio, int fim) {
    if (inicio < fim) {
        int j = particao(lista, inicio, fim);
        // chama quicksort nas partições esquerda e direita
        quick_sort(lista, inicio, j - 1);
        quick_sort(lista, j + 1, fim);
    }
}


void heap_sort(Lista lista) {
    // cria um heap binário
    Heap heap = heap_cria(lista->n_elem);
    if (heap == NULL) return;

    // insere todos os elementos da lista no heap
    for (int i = 0; i < lista->n_elem; i++) {
        heap_insere(heap, lista->vetor[i]);
    }

    // remove todos os elementos do heap e os inserem de volta na lista
    for (int i = 0; i < lista->n_elem; i++) {
        lista->vetor[i] = heap_remove_min(heap);
    }

    heap_destroi(heap);
}


void counting_sort(Lista lista) {
    // descobre o limite superior do intervalo de números da lista
    int lim_sup = lista_max(lista);
    // inicializa o vetor de número de instâncias de cada elemento na lista
    int c[lim_sup+1];
    for (int i = 0; i < lim_sup+1; i++) {
        c[i] = 0;
    }
    // percorre a lista para contar o número de instâncias de cada elemento na lista
    for (int i = 0; i < lista->n_elem; i++) {
        c[ lista->vetor[i] ]++;
    }
    // realiza a soma acumulado do vetor de n_instâncias
    for (int i = 1; i <= lim_sup; i++) {
        c[i] += c[i-1];
    }
    // ordenação da lista
    int aux[lista->cap];
    for (int i = lista->n_elem - 1; i >= 0; i--) {
        c[lista->vetor[i]]--;
        aux[c[lista->vetor[i]]] = lista->vetor[i];  // rasclart 0-0. pag 48
    }
    // copia a lista auxiliar para a original
    for (int i = 0; i < lista->n_elem; i++) {
        lista->vetor[i] = aux[i];
    }
}


void bucket_sort(Lista lista) {
    // buckets é um vetor de listas (buckets)
    Lista buckets[lista->n_elem];
    //for (int i = 0; i < lista->n_elem; i++) {
    //}
    // maior valor da lista
    int k = lista_max(lista);
    // enchendo os buckets
    int pos;
    for (int i = lista->n_elem - 1; i <= 0; i--) {
        // calcula em qual posição do vetor (bucket) deve se inserir
    }

}