#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista.h"
#include "lista_encadeada.h"


int main(int agrc, char *argv[]) {
    // habilita a geração de números aleatórios
    srand(time(0));
    Linked l = linked_cria();
    linked_imprime(l);
    for (int i = 0; i < 20; i++) {
        int num = rand() % 50;
        linked_insere(l, num);
    }
    linked_imprime(l);

    linked_destroi(l);
    return 0;
}