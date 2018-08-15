#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "data.h"

void debug(conjunto *coords) {
    if (DEBUG) { 
        printCJT(coords);
        printf(" Xa = %hu\n", coords->Xa);
        printf(" Xb = %hu\n", coords->Xb);
        printf(" Pontos = %hu\n", coords->Ncoords);
    }
}

conjunto *create() {
    conjunto *P = (conjunto*) malloc(sizeof(conjunto));
    if (!P) return NULL;
    P->Xa = 0;
    P->Xb = 0;
    P->Ncoords = 0;
    P->head = NULL;
    return P;
}

void insere(point_t xy, conjunto *coords) {
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if (!node) return;
    node->xy = xy;
    node->next = coords->head;
    coords->head = node;
}

void printCJT(conjunto *coords) {
    if (!sizeCJT(coords)) {
        printf (" Conjunto Vazio!\n");
        return;
    }
    printf (" Coordenadas = { ");
    node_t *read = coords->head;
    while ( read != NULL ) {
        printf ("%d,%d ", read->xy.x, read->xy.y);
        read = read->next;
    }
    printf ("}\n");
}

int sizeCJT(conjunto *coords) {
    int size = 0;
    node_t *node = coords->head;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

void freeMEM(conjunto *coords) {
    if (isEmpty(coords)) return;
    node_t *node = coords->head;
    node_t *del_node;
    while ( node != NULL ) {
        del_node = node;
        node = node->next;
        free(del_node);
    }
    free(coords);
}

int isEmpty(conjunto *coords) {
    return (coords->head == NULL);
}