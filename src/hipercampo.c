#include "main.h"

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

float area(int x1, int y1, int x2, int y2, int x3, int y3) {
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

int isInside(conjunto_t *P, node_t *C, node_t *I) {   

   float A = area (P->Xa, 0, P->Xb, 0, C->tupla.x, C->tupla.y);
   float A1 = area (I->tupla.x, I->tupla.y, P->Xb, 0, C->tupla.x, C->tupla.y);
   float A2 = area (P->Xa, 0, I->tupla.x, I->tupla.y, C->tupla.x, C->tupla.y);
   float A3 = area (P->Xa, 0, P->Xb, 0, I->tupla.x, I->tupla.y);
   return (A == A1 + A2 + A3);
}

int findMAX(conjunto_t *P) {
    int triangles;
    node_t *C = P->head;
    node_t *I = P->head;
    tupla_t max = P->head->tupla;

    while (C != NULL) {
        if (triangles > C->tupla.inside ) max = C->tupla;
        triangles = 0;
        while (I != NULL) {
            if (isInside(P,C,I)) triangles++;
            I = I->next;
        }
        C->tupla.inside = triangles;
        C = C->next;
    }
    printf(COLOR_YELL" (TESTE)Tupla com maior possibilidade: %hu,%hu"COLOR_RESET, max.x, max.y);
    return triangles;
}