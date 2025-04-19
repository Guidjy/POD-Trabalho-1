#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


linked linked_cria() {
    // aloca memória para a estrutura da lista
    linked nova = (linked) malloc(sizeof(struct _lista_encadeada));
    if (nova == NULL) {
        printf("Erro na alocação de memória do descritor da lista encadeada\n");
        return NULL;
    }
    // inicializa as variaveis do descritor
    nova->n_elem = 0;
    nova->pri = NULL;

    return nova;
}


void linked_destroi(linked lista);


bool linked_vazia(linked lista) {
    return lista->n_elem == 0;
}


// aloca memória para um novo nó
static No no_cria(int num) {
    No novo = (No) malloc(sizeof(struct _no));
    if (novo == NULL) {
        printf("Erro na alocação de memória para um nó");
        return NULL;
    }
    novo->dado = num;

    return novo;
}


void linked_insere(linked lista, int num) {
    // aloca memória para um novo nó
    No novo = no_cria(num);
    if (novo == NULL) {
        return;
    }
    // encadeia o novo nó
    novo->prox = lista->pri;
    lista->pri = novo;
}

// yur


