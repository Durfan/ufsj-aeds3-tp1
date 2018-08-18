#include "main.h"

float area(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
   return abs((Ax*(By-Cy) + Bx*(Cy-Ay)+ Cx*(Ay-By))/2.0);
}

int isInside(conjunto_t *CJT, node_t *C, node_t *I) {
    anchor_t Ax = CJT->Xa, Ay = 0;
    anchor_t Bx = CJT->Xb, By = 0;
    anchor_t Cx = C->tupla.x, Cy = C->tupla.y;
    anchor_t Ix = I->tupla.x, Iy = I->tupla.y;

    float AT = area (Ax, Ay, Bx, By, Cx, Cy);
    float A1 = area (Ix, Iy, Bx, By, Cx, Cy);
    float A2 = area (Ax, Ay, Ix, Iy, Cx, Cy);
    float A3 = area (Ax, Ay, Bx, By, Ix, Iy);
    printf(" %f\n", AT);
    return (AT == A1 + A2 + A3);
}

int findMAX(conjunto_t *CJT) {
    int nTRI = 0;
    int max = nTRI;
    conjunto_t *TMP = create();
    node_t *C = CJT->head;
    node_t *I = CJT->head->next;

    while (C != NULL) {
        while (I != NULL) {
            if (!isInside(CJT,C,I)) {
                nTRI++;
                insere(I->tupla,TMP);
            }
            I = I->next;
        }
        if (nTRI>=max) {
            max = nTRI;
            printCJT(TMP);
            dump(CJT);
            cpyCJT(TMP,CJT);
        }
        dump(TMP);
        nTRI = 0;
        C = C->next;
    }
    printf("\n Maximo: %d\n\n", max);
    printCJT(CJT);
    if (isEmpty(CJT)) return 0;
    else {
        CJT->total++;
        findMAX(CJT);
    }
}

void cpyCJT(conjunto_t *FROM, conjunto_t *TO) {
    node_t *copy = FROM->head;
    while (copy != NULL) {
        insere(copy->tupla,TO);
        copy = copy->next;
    }
}

void TRIcount(conjunto_t *CJT) {
    findMAX(CJT);
}

// Dev. Depreciado ------------------------------------

/* int determinate(conjunto_t *P, node_t *C) {
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
} */