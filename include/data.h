#ifndef INCLUDE_DATA_H
#define INCLUDE_DATA_H

typedef unsigned short anchor_t;
typedef unsigned short ncoords_t;
typedef unsigned short ponto_t;

typedef struct tupla {
    ponto_t x;
    ponto_t y;
} tupla_t;

typedef struct node {
    tupla_t p;
    struct node *next;
} node_t;

typedef struct conjunto {
    node_t *head;
    anchor_t Xa;
    anchor_t Xb;
    ncoords_t ncoords;
    int total;
} conjunto_t;

void debug(conjunto_t *CJT);
conjunto_t *create();
void insere(tupla_t tupla, conjunto_t *CJT);
void printCJT(conjunto_t *CJT);
int sizeCJT(conjunto_t *CJT);
void dump(conjunto_t *CJT, int del);
void delCJT(conjunto_t *CJT);
int isEmpty(conjunto_t *CJT);

//#pragma message __FILE__
#endif // INCLUDE_DATA_H