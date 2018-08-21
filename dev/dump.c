/* Dev. Depreciado ------------------------------------

int isInside_byarea(conjunto_t *CJT, node_t *C, node_t *S);
int determinate(conjunto_t *P, node_t *C);
int BF_determinante(conjunto_t *P);
void TRIcount2(conjunto_t *CJT);

float area(int Ax, int Ay, int Bx, int By, int Cx, int Cy) {
   return ((Ax*(By-Cy) + Bx*(Cy-Ay) + Cx*(Ay-By))/2.0);
}

int isInside_byarea(conjunto_t *CJT, node_t *C, node_t *S) {
    anchor_t Ax = CJT->Xa, Ay = 0;
    anchor_t Bx = CJT->Xb, By = 0;
    anchor_t Cx = C->ponto.x, Cy = C->ponto.y;
    anchor_t Sx = S->ponto.x, Sy = S->ponto.y;

    float AT = area(Ax, Ay, Bx, By, Cx, Cy);
    float A1 = area(Sx, Sy, Bx, By, Cx, Cy);
    float A2 = area(Ax, Ay, Sx, Sy, Cx, Cy);
    float A3 = area(Ax, Ay, Bx, By, Sx, Sy);
  
    printf(" A = %d,%d\n", Ax,Ay);
    printf(" B = %d,%d\n", Bx,By);
    printf(" C = %d,%d\n", Cx,Cy);
    printf(" I = %d,%d : %d\n", Sx, Sy, (AT==A1+A2+A3) ? 1:0);
    printf(" AT = %f\n", AT);
    printf(" A1 = %f\n", A1);
    printf(" A2 = %f\n", A2);
    printf(" A3 = %f\n", A3);
    printf(" A1+A2+A3 = %f\n\n", A1+A2+A3);

    return (AT == A1 + A2 + A3);
}

int determinate(conjunto_t *P, node_t *C) {
   return (P->Xa*(- C->ponto.y) + 1 * (P->Xb*C->ponto.y));
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

int findMAX(conjunto_t *CJT, conjunto_t *plot) {
    node_t *Q = CJT->head;
    node_t *R = CJT->head;

    while (Q != NULL) {
        while (R != NULL) {
            if (Q != R && Q->ponto.y > R->ponto.y) {
                if (PQR(CJT,Q,R)) insere(R->ponto,plot);
            }
            R = R->next;
        }
        Q = Q->next;
    }
}

int isInside(conjunto_t *CJT, node_t *C, node_t *S) {
    int Ax = CJT->Xa;
    int Bx = CJT->Xb;
    int Cx = C->ponto.x, Cy = C->ponto.y;
    int Sx = S->ponto.x, Sy = S->ponto.y;
    int AS_x = S->ponto.x-Ax;
    int AS_y = S->ponto.y;

    bool S_AB = (Bx-Ax)*AS_y*AS_x > 0;

    if (((Cx-Ax)*AS_y - Cy*AS_x > 0 ) == S_AB) return false;
    if (((Cx-Bx)*Sy - Cy*(Sx-Bx) > 0) != S_AB) return false;

    return true;
}


void TRIcount2(conjunto_t *CJT) {
    conjunto_t *WIN = create();
    int AIJ,BIJ;
    tupla_t Pa, Pb;
    node_t *Q = CJT->head;
    node_t *R = CJT->head;
    Pa.x = CJT->Xa;
    Pa.y = 0;
    Pb.x = CJT->Xb;
    Pb.y = 0;

    while (Q != NULL) {
        while (R != NULL) {
            if (Q != R && Q->ponto.y > R->ponto.y) {
                AIJ = cross_product(Pa, Q, R);
                BIJ = cross_product(Pb, Q, R);
                if (AIJ == 1 && BIJ == 2) {
                    insere(R->ponto,WIN);
                }
            }
            R = R->next;
        }
        Q = Q->next;
    }
}

// ---------------------------------------------------- */