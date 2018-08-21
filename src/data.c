#include "main.h"

void debug(conjunto_t *CJT) {
    if (DEBUG) {
        printCJT(CJT);
        printf("\n Ancoras: %hu,0 <-> %hu,0 -> Pontos: %hu\n", CJT->Xa, CJT->Xb, CJT->ncoords);
    }
}

conjunto_t *create() {
    conjunto_t *CJT = (conjunto_t*) malloc(sizeof(conjunto_t));
    if (!CJT) return NULL;
    CJT->head = NULL;
    CJT->Xa = 0;
    CJT->Xb = 0;
    CJT->ncoords = 0;
    CJT->total = 0;
    return CJT;
}

void insere(tupla_t tupla, conjunto_t *CJT) {
    node_t *node = (node_t*) malloc(sizeof(node_t));
    if (!node) return;
    node->p = tupla;
    node->next = CJT->head;
    CJT->head = node;
}

void printCJT(conjunto_t *CJT) {
    if (isEmpty(CJT)) {
        printf (" Conjunto Vazio!\n");
        return;
    }
    printf (" P = { ");
    node_t *read = CJT->head;
    while (read != NULL) {
        printf ("%d,%d ", read->p.x, read->p.y);
        read = read->next;
    }
    printf ("}\n");
}

int sizeCJT(conjunto_t *CJT) {
    int size = 0;
    node_t *node = CJT->head;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

void dump(conjunto_t *CJT, int del) {
    if (del) {
        free(CJT);
        return;
    }
    if (isEmpty(CJT)) return;
    node_t *del_node;
    while (CJT->head != NULL) {
        del_node = CJT->head;
        CJT->head = CJT->head->next;
        free(del_node);
    }
}

int isEmpty(conjunto_t *CJT) {
    return (CJT->head == NULL);
}