#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


Linked linked_cria() {
    /* aloca memória para a estrutura da lista */
    Linked nova = (Linked) malloc(sizeof(struct _lista_encadeada));
    if (nova == NULL) {
        printf("Erro na alocação de memória do descritor da lista encadeada\n");
        return NULL;
    }
    /* inicializa as variaveis do descritor */
    nova->n_elem = 0;
    nova->pri = NULL;

    return nova;
}


void linked_destroi(Linked lista) {
    /* libera todos os nós da lista */
    No p = lista->pri;
    No p_prox;
    while (p != NULL) {
        p_prox = p->prox;
        free(p);
        p = p_prox;
    }
    /* libera o descritor da lista */
    free(lista);
}


bool linked_vazia(Linked lista) {
    return lista->n_elem == 0;
}


/* aloca memória para um novo nó */
static No no_cria(int num) {
    No novo = (No) malloc(sizeof(struct _no));
    if (novo == NULL) {
        printf("Erro na alocação de memória para um nó");
        return NULL;
    }
    novo->dado = num;
    novo->prox = NULL;

    return novo;
}


void linked_insere(Linked lista, int num) {
    /* aloca memória para um novo nó */
    No novo = no_cria(num);
    if (novo == NULL) {
        return;
    }
    /* encadeia o novo nó */
    novo->prox = lista->pri;
    lista->pri = novo;
    lista->n_elem++;
}


int linked_remove(Linked lista) {
    /* verifica se a lista está vazia */
    if (linked_vazia(lista)) {
        printf("Lista vazia. Não se pode mais remover elementos\n");
        return -1;
    }
    /* desencadeia o nó */
    No removido = lista->pri;
    lista->pri = lista->pri->prox;
    lista->n_elem--;
    /* libera o nó e retorna seu dado */
    int dado = removido->dado;
    free(removido);
    return dado;
}


void linked_imprime(Linked lista) {
    No p;
    if (linked_vazia(lista)) {
        printf("[]\n");
        return;
    }
    printf("[");
    p = lista->pri;
    while (p->prox != NULL) {
        printf("%d, ", p->dado);
        p = p->prox;
    }
    printf("%d]\n", p->dado);
}
