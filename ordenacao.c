#include "ordenacao.h"
#include "lista.h"
#include "lista_encadeada.h"
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>


void bubble_sort(Lista lista) {
    int i, j;
    for (i = 1; i < lista->n_elem; i++) {
        for (j = 0; j < lista->n_elem - 1; j++) {
            if (lista->vetor[j] > lista->vetor[j+1]) {
                lista_swap(lista, j, j+1);
            }
        }
    }
}


void insertion_sort(Lista lista) {
    int i, j, pivo;
    /* percorre a parte da direita, começando do 1 pois o elemento em 0 está na parte da esquerda (ordenada) */
    for (i = 1; i < lista->n_elem; i++) {
        pivo = lista->vetor[i];
        j = i - 1;  /* índice do elemento mais a direita da parte da direita */
        /* percorre a parte esquerda, deslocando cada elemento um índice para a direita, até achar um elemento menor que o pivo */
        while (j >= 0 && lista->vetor[j] > pivo) {
            lista->vetor[j+1] = lista->vetor[j];
            j--;
        }
        /* insere o pivo na parte da direita */
        lista->vetor[j+1] = pivo;
    }
}


/* retorna um índice j, no qual será colocado o pivô, tal que:
     > lista[inicio] ... lista[j-1] <= lista[j]
     > lista[j+1] ... lista[fim] > lista[j]
   (usado pelo quicksort) */
static int particao(Lista lista, int inicio, int fim) {
    int pivo = lista->vetor[inicio];
    int i = inicio + 1;
    int j = fim;

    /* procedimentos são repetidos até que i > j */
    while (i <= j) {
        /* i avança até encontrar um elemento maior que o pivô */
        while (i <= j && lista->vetor[i] <= pivo) {
            i++;
        }
        /* j recua até encontrar um elemento menor ou igual ao pivô */
        while (lista->vetor[j] > pivo) {
            j--;
        }
        /* troca os elementos em i e j */
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
        /* chama quicksort nas partições esquerda e direita */
        quick_sort(lista, inicio, j - 1);
        quick_sort(lista, j + 1, fim);
    }
}


void heap_sort(Lista lista) {
    int i;
    /* cria um heap binário */
    Heap heap = heap_cria(lista->n_elem);
    if (heap == NULL) return;

    /* insere todos os elementos da lista no heap */
    for (i = 0; i < lista->n_elem; i++) {
        heap_insere(heap, lista->vetor[i]);
    }

    /* remove todos os elementos do heap e os inserem de volta na lista */
    for (i = 0; i < lista->n_elem; i++) {
        lista->vetor[i] = heap_remove_min(heap);
    }

    heap_destroi(heap);
}


void counting_sort(Lista lista) {
    int i;
    /* descobre o limite superior do intervalo de números da lista */
    int lim_sup = lista_max(lista);
    /* inicializa o vetor de número de instâncias de cada elemento na lista */
    int *c = (int*)malloc((lim_sup+1) * sizeof(int));
    for (i = 0; i < lim_sup+1; i++) {
        c[i] = 0;
    }
    /* percorre a lista para contar o número de instâncias de cada elemento na lista */
    for (i = 0; i < lista->n_elem; i++) {
        c[ lista->vetor[i] ]++;
    }
    /* realiza a soma acumulado do vetor de n_instâncias */
    for (i = 1; i <= lim_sup; i++) {
        c[i] += c[i-1];
    }
    /* ordenação da lista */
    int *aux = (int*)malloc(lista->cap * sizeof(int));
    for (i = lista->n_elem - 1; i >= 0; i--) {
        c[lista->vetor[i]]--;
        aux[c[lista->vetor[i]]] = lista->vetor[i];  /* rasclart 0-0. pag 48 */
    }
    /* copia a lista auxiliar para a original */
    for (i = 0; i < lista->n_elem; i++) {
        lista->vetor[i] = aux[i];
    }
    free(c);
    free(aux);
}


void bucket_sort(Lista lista, int algoritmo) {
    int i, j, k, pos, vetori;
    long long temp;
    /* inicializa o vetor de buckets */
    Linked *buckets = (Linked*) malloc(sizeof(struct _lista_encadeada) * lista->n_elem);
    for (i = 0; i < lista->n_elem; i++) {
        buckets[i] = linked_cria();
    }

    /* obtem maior valor da lista */
    k = lista_max(lista);
    /* enche os buckets */
    for (i = lista->n_elem - 1; i >= 0; i--) {
        vetori = lista->vetor[i];
        temp = (long long)lista->vetor[i] * lista->n_elem;  /* para prevenir overflow */
        pos = temp / (k + 1);
        linked_insere(buckets[pos], lista->vetor[i]);
    }

    /* ordena e concatena os buckets */
    j = 0;
    for (i = 0; i < lista->n_elem; i++) {
        /* passa todos os elementos de buckets[i] para a lista bucket */
        Lista bucket = lista_cria(buckets[i]->n_elem);
        while (!linked_vazia(buckets[i])) {
            lista_insere(bucket, linked_remove(buckets[i]));
        }
        
        /* seleciona algoritmo de ordenação */
        switch(algoritmo) {
            case 0:
                insertion_sort(bucket);
                break;
            case 1:
                bubble_sort(bucket);
                break;
            case 2:
                quick_sort(bucket, 0, bucket->n_elem - 1);
                break;
            case 3:
                heap_sort(bucket);
                break;
            case 4:
                counting_sort(bucket);
                break;
            default:
                insertion_sort(bucket);
                break;
        }

        /* concatena o bucket ordenado a lista original */
        for (k = 0; k < bucket->n_elem; k++) {
            lista->vetor[j] = bucket->vetor[k];
            j++;
        }
        lista_destroi(bucket);
        linked_destroi(buckets[i]);
    }
    free(buckets);
}
