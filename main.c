#include "lista.h"
#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int agrc, char *argv[]) {
    // habilita a geração de números aleatórios
    srand(time(0));
    Lista l = lista_cria(20);
    lista_preenche(l, 50);
    lista_imprime(l);
    bucket_sort(l);
    lista_imprime(l);
    
    lista_destroi(l);
    return 0;
}