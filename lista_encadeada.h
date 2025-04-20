#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdbool.h>

/* estrutura de um nó da lista encadeada */
struct _no {
    int dado;          /* dado contido no nó */
    struct _no *prox;  /* ponteiro para o próximo nó da lista */
};
typedef struct _no *No;

/* estrutura do descritor da lista encadeada */
struct _lista_encadeada {
    int n_elem;  /* número de elementos na lista */
    No pri;      /* ponteiro para o primeiro elemento da lista */
};
typedef struct _lista_encadeada *Linked;


/* cria uma lista encadeada */
Linked linked_cria();

/* libera toda a memória alocada para uma lista encadeada */
void linked_destroi(Linked lista);

/* retorna true se a lista encadeada estiver vazia */
bool linked_vazia(Linked lista);

/* insere um elemento no início da lista */
void linked_insere(Linked lista, int num);

/* remove o primeiro elemento da lista e retorna-o */
int linked_remove(Linked lista);

/* imprime uma lista encadeada */
void linked_imprime(Linked lista);

#endif
