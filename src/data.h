typedef unsigned short anchor_t;
typedef unsigned short ncoords_t;
typedef unsigned short ponto_t;

typedef struct tupla {
    ponto_t x;
    ponto_t y;
} tupla_t;

typedef struct node {
    tupla_t tupla;
    struct node *next;
} node_t;

typedef struct conjunto {
    anchor_t Xa;
    anchor_t Xb;
    ncoords_t ncoords;
    node_t *head;
} conjunto_t;

void debug(conjunto_t *P);
conjunto_t *create();
void insere(tupla_t tupla, conjunto_t *P);
void printCJT(conjunto_t *P);
int sizeCJT(conjunto_t *P);
void freeMEM(conjunto_t *P);
int isEmpty(conjunto_t *P);