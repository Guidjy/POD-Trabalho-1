#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "heap.h"


Heap heap_cria(int tamanho) {
    // aloca memória para a estrutura de um novo heap
    Heap novo = (Heap) malloc(sizeof(struct _heap));
    if (novo == NULL) {
        printf("Erro na alocação de memória para a estrutura do heap\n");
        return NULL;
    }
    novo->cap = tamanho + 1;
    novo->ult = 0;
    
    // aloca memória para o vetor do heap (posição 0 do vetor é ignorada)
    novo->vetor = (int*) malloc(sizeof(int) * (tamanho + 1));
    if (novo->vetor == NULL) {
        free(novo);
        printf("Erro na alocação de memória para o vetor do heap\n");
        return NULL;
    }

    return novo;
}


void heap_destroi(Heap heap) {
    free(heap->vetor);
    free(heap);
}


bool heap_vazio(Heap heap) {
    return heap->ult == 0;
}


bool heap_cheio(Heap heap) {
    return heap->ult == heap->cap-1;  
}


void heap_swap(Heap heap, int pos_1, int pos_2) {
    // verifica se os índices de posição são válidos
    if ((1 <= pos_1 && pos_1 <= heap->ult) && (1 <= pos_2 && pos_2 <= heap->ult)) {
        int temp = heap->vetor[pos_1];
        heap->vetor[pos_1] = heap->vetor[pos_2];
        heap->vetor[pos_2] = temp;
    }
}


void heap_insere(Heap heap, int num) {
    // para inserir um valor x em um heap binário, devemos inseri-lo após o último elemento
    // e depois comparar com seu pai, trocando-os de posição se houver necessidade.
    // Tal processo é repetido até que x seja maior ou igual ao seu pai, ou até
    // atingir a posição 1 do vetor
    if (heap_cheio(heap)) {
        printf("Heap cheio. Não se pode inserir mais elementos\n");
        return;
    }
    heap->ult++;
    int i = heap->ult;
    // vai subindo o heap até achar um pai >= num ou até chegar a 1
    while (i > 1 && heap->vetor[i/2]  > num) {
        // manda o pai para baixo 
        heap->vetor[i] = heap->vetor[i/2];
        i /= 2;
    }
    // insere num na posição descoberta
    heap->vetor[i] = num;
}


int heap_remove_min(Heap heap) {
    // movemos o último valor contido no heap (pivô) para a posição 1 do vetor. Em seguida,
    // comparamos o pivô com seus filhos, trocando-o com o menor deles se houver necessidade.
    // Esse procedimento é repetido até que o pivô seja menor ou igual aos seus filhos ou até
    // o pivô atingir uma posição que não tenha filhos.
    if (heap_vazio(heap)) {
        printf("Heap vazio. Não se pode remover elementos\n");
        return -1;
    }

    int removido = heap->vetor[1];
    heap->vetor[1] = heap->vetor[heap->ult];
    heap->ult--;

    // desce o heap trocando o pivô com seus filhos se necessário, até achar a posição final do pivô
    int i = 1;
    while (2 * i <= heap->ult) {
        int menor_filho = 2 * i;
    
        // verifica se há filho direito e se ele é menor que o esquerdo
        if (menor_filho + 1 <= heap->ult && heap->vetor[menor_filho + 1] < heap->vetor[menor_filho]) {
            menor_filho++;
        }
    
        // se o pivô já está na posição correta, termina
        if (heap->vetor[i] <= heap->vetor[menor_filho]) {
            break;
        }
    
        // troca com o menor filho
        heap_swap(heap, i, menor_filho);
        i = menor_filho;
    }
    

    return removido;
}


void heap_imprime(Heap heap) {
    if (heap_vazio(heap)) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 1; i < heap->ult; i++) {
        printf("%d, ", heap->vetor[i]);
    }
    printf("%d]\n", heap->vetor[heap->ult]);
}