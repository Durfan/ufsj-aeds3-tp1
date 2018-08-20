typedef unsigned short anchor_t;
typedef unsigned short ncoords_t;
typedef unsigned short ponto_t;
typedef unsigned short inTRI_t;

typedef struct tupla {
    ponto_t x;
    ponto_t y;
    inTRI_t nTRI;
} tupla_t;

typedef struct node {
    tupla_t tupla;
    struct node *next;
} node_t;

typedef struct conjunto {
    int total;
    anchor_t Xa;
    anchor_t Xb;
    ncoords_t ncoords;
    node_t *head;
} conjunto_t;

void debug(conjunto_t *CJT);
conjunto_t *create();
void insere(tupla_t tupla, conjunto_t *CJT);
void printCJT(conjunto_t *P);
int sizeCJT(conjunto_t *P);
void dump(conjunto_t *CJT, int del);
void delCJT(conjunto_t *CJT);
int isEmpty(conjunto_t *CJT);