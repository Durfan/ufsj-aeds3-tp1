#include "main.h"
#include <stdlib.h>

void debug(conjunto_t *P) {
    if (DEBUG) { 
        printCJT(P);
        printf(" Xa = %hu\n", P->Xa);
        printf(" Xb = %hu\n", P->Xb);
        printf(" Pontos = %hu\n", P->ncoords);
    }
}

conjunto_t *create() {
    conjunto_t *P = (conjunto_t*) malloc(sizeof(conjunto_t));
    if (!P) return NULL;
    P->Xa = 0;
    P->Xb = 0;
    P->ncoords = 0;
    P->head = NULL;
    return P;
}

void insere(tupla_t tupla, conjunto_t *P) {
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if (!node) return;
    node->tupla = tupla;
    node->next = P->head;
    P->head = node;
}

void printCJT(conjunto_t *P) {
    if (!sizeCJT(P)) {
        printf (" Conjunto Vazio!\n");
        return;
    }
    printf (" Coordenadas = { ");
    node_t *read = P->head;
    while (read != NULL) {
        printf ("%d,%d ", read->tupla.x, read->tupla.y);
        read = read->next;
    }
    printf ("}\n");
}

int sizeCJT(conjunto_t *P) {
    int size = 0;
    node_t *node = P->head;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

void freeMEM(conjunto_t *P) {
    if (isEmpty(P)) return;
    node_t *node = P->head;
    node_t *del_node;
    while (node != NULL) {
        del_node = node;
        node = node->next;
        free(del_node);
    }
    free(P);
}

int isEmpty(conjunto_t *P) {
    return (P->head == NULL);
}