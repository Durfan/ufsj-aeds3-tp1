#include "main.h"

int isInside(conjunto_t *CJT, node_t *C, node_t *S) {
    int Ax = CJT->Xa;
    int Bx = CJT->Xb;
    int Cx = C->tupla.x, Cy = C->tupla.y;
    int Sx = S->tupla.x, Sy = S->tupla.y;
    int AS_x = S->tupla.x-Ax;
    int AS_y = S->tupla.y;

    bool S_AB = (Bx-Ax)*AS_y*AS_x > 0;

    if (((Cx-Ax)*AS_y - Cy*AS_x > 0 ) == S_AB) return false;
    if (((Cx-Bx)*Sy - Cy*(Sx-Bx) > 0) != S_AB) return false;

    return true;
}

int findMAX(conjunto_t *CJT, conjunto_t *AUX, conjunto_t *MAX, conjunto_t *plot) {
    if (isEmpty(CJT)) return 0;
    node_t *C = CJT->head;
    node_t *S;
    node_t *win = NULL;
    int dots = 0;
    int max = dots;

    while (C != NULL) {
        S = CJT->head;
        while (S != NULL) {
            if (S != C && isInside(CJT,C,S)) {
                dots++;
                insere(S->tupla,AUX);
            }
            S = S->next;
        }
        if (dots>=max) {
            max = dots;
            win = C;
            dump(MAX);
            cpyCJT(AUX,MAX);
        }
        dots = 0;
        dump(AUX);
        C = C->next;
    }
    if (win != NULL) winPLOT(win,plot);
    printCJT(MAX);
    dump(CJT);
    cpyCJT(MAX,CJT);
    CJT->total++;
    
    return findMAX(CJT,AUX,MAX,plot);
}

void cpyCJT(conjunto_t *FROM, conjunto_t *TO) {
    node_t *copy = FROM->head;
    while (copy != NULL) {
        insere(copy->tupla,TO);
        copy = copy->next;
    }
}

void TRIcount(conjunto_t *CJT) {
    conjunto_t *AUX = create();
    conjunto_t *MAX = create();
    conjunto_t *plot = create();
    AUX->Xa = CJT->Xa;
    AUX->Xb = CJT->Xb;
    MAX->Xa = CJT->Xa;
    MAX->Xb = CJT->Xb;
    plot->Xa = CJT->Xa;
    plot->Xb = CJT->Xb;

    sort(CJT);
    findMAX(CJT,AUX,MAX,plot);
    printCJT(plot);
    plotGraph(plot);
    
    dump(AUX);
    dump(MAX);
    delCJT(AUX);
    delCJT(MAX);
}

void winPLOT(node_t *win, conjunto_t *plot) {
    insere(win->tupla,plot);
}

// Dev. Depreciado ------------------------------------
/*
float area(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
   return ((Ax*(By-Cy) + Bx*(Cy-Ay) + Cx*(Ay-By))/2.0);
}

int isInside(conjunto_t *CJT, node_t *C, node_t *S) {
    anchor_t Ax = CJT->Xa, Ay = 0;
    anchor_t Bx = CJT->Xb, By = 0;
    anchor_t Cx = C->tupla.x, Cy = C->tupla.y;
    anchor_t Ix = I->tupla.x, Iy = I->tupla.y;

    float AT = area(Ax, Ay, Bx, By, Cx, Cy);
    float A1 = area(Ix, Iy, Bx, By, Cx, Cy);
    float A2 = area(Ax, Ay, Ix, Iy, Cx, Cy);
    float A3 = area(Ax, Ay, Bx, By, Ix, Iy);

    printf(" A = %d,%d\n", Ax,Ay);
    printf(" B = %d,%d\n", Bx,By);
    printf(" C = %d,%d\n", Cx,Cy);
    printf(" I = %d,%d : %d\n", Ix, Iy, (AT==A1+A2+A3) ? 1:0);
    printf(" AT = %f\n", AT);
    printf(" A1 = %f\n", A1);
    printf(" A2 = %f\n", A2);
    printf(" A3 = %f\n", A3);
    printf(" A1+A2+A3 = %f\n\n", A1+A2+A3);

    return (AT == A1 + A2 + A3);
}

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
 */