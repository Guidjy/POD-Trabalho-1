#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "lista.h"

void bubble_sort(Lista lista);

void insertion_sort(Lista lista);

void quick_sort(Lista lista, int inicio, int fim);

void heap_sort(Lista lista);

void counting_sort(Lista lista);

void bucket_sort(Lista lista);

#endif