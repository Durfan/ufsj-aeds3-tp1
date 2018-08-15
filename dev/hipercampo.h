typedef unsigned short anchor_t;
typedef int info;
typedef struct point point_t;
typedef struct node node_t;

struct point {
    unsigned short x;
    unsigned short y;
};

struct node {
    point_t ponto;
    node_t *next;
};

typedef struct conjunto {
    anchor_t Xa;
    anchor_t Xb;
    node_t *head;
} conjunto;

conjunto *create();
void freeMEM();