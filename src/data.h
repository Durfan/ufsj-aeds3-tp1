typedef unsigned short anchor_t;
typedef unsigned short Ncoords_t;
typedef int info;
typedef struct point point_t;
typedef struct node node_t;

struct point {
    unsigned short x;
    unsigned short y;
};

struct node {
    point_t xy;
    node_t *next;
};

typedef struct conjunto {
    anchor_t Xa;
    anchor_t Xb;
    Ncoords_t Ncoords;
    node_t *head;
} conjunto;

conjunto *create();
void insere(point_t xy, conjunto *coords);
void printCJT(conjunto *coords);
int sizeCJT(conjunto *coords);
void freeMEM();