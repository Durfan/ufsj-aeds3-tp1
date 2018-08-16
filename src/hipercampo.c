#include "main.h"

#include <stdlib.h>

int determinate(conjunto_t *P, node_t *C) {
   return (P->Xa*(- C->tupla.y) + 1 * (P->Xb*C->tupla.y));
}

int BF_determinante(conjunto_t *P) {
    int triangles = 0;
    node_t *C = P->head;

    while (C != NULL) {
        if (determinate(P,C)) triangles++;
        C = C->next;
    }
    return triangles;
}