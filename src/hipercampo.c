#include "main.h"

int PQR(conjunto_t *P, node_t *Q, node_t *R) {
    if ((Q == R) || (Q->p.y < R->p.y)) return 0;
    signed long PaQR, PbQR;

    PaQR = Q->p.y*(R->p.x-Q->p.x)-(Q->p.x-P->Xa)*(R->p.y-Q->p.y);
    PbQR = Q->p.y*(R->p.x-Q->p.x)-(Q->p.x-P->Xb)*(R->p.y-Q->p.y);
    if (!PaQR || !PbQR) return 0; // colinear

    PaQR = (PaQR > 0)? 1 : 2; // clock wise 1, counter clock 2
    PbQR = (PbQR > 0)? 1 : 2; // clock wise 1, counter clock 2
    if (PaQR == 1 && PbQR == 2) return 1; // inside
    
    return 0;
}

int findMAX(conjunto_t *CJT, conjunto_t *plot) {
    if (isEmpty(CJT)) return 0;
    conjunto_t *AUX = create();
    conjunto_t *MAX = create();
    node_t *Q = CJT->head;
    node_t *R = CJT->head;
    node_t *win = NULL;
    int dots = 0; 
    int moredots = dots;

     do {
        R = CJT->head;
        while (R != NULL) {
            if (PQR(CJT,Q,R)) {
                dots++;
                insere(R->p,AUX);
            }
            R = R->next;
        }
        if (dots >= moredots) {
            moredots = dots;
            win = Q;
            dump(MAX,0);
            cpyCJT(AUX,MAX);
        }
        dots = 0;
        dump(AUX,0);
        Q = Q->next;
    } while (Q != NULL);

    if (win) insere(win->p,plot);

    dump(CJT,0);
    cpyCJT(MAX,CJT);
    
    dump(MAX,1);
    dump(AUX,1);
    CJT->total++;
    
    return findMAX(CJT,plot);
}

void cpyCJT(conjunto_t *FROM, conjunto_t *TO) {
    node_t *copy = FROM->head;
    while (copy != NULL) {
        insere(copy->p,TO);
        copy = copy->next;
    }
}

void soluciona(conjunto_t *CJT) {
    conjunto_t *plot = create();
    plot->Xa = CJT->Xa;
    plot->Xb = CJT->Xb;

    findMAX(CJT,plot);
    plotGraph(plot);
    dump(plot,1);
}

void solucao(conjunto_t *CJT) {
    printf(COLOR_YELL" Triangulos possiveis: %d\n"COLOR_RESET, CJT->total);
}