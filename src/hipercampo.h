int isInside(conjunto_t *CJT, node_t *C, node_t *S);
int findMAX(conjunto_t *CJT, conjunto_t *plot);
void cpyCJT(conjunto_t *TO, conjunto_t *FROM);
void TRIcount(conjunto_t *CJT);
void winPLOT(node_t *win, conjunto_t *plot);

// Dev. Depreciado ------------------------------------
int isInside_byarea(conjunto_t *CJT, node_t *C, node_t *S);
int determinate(conjunto_t *P, node_t *C);
int BF_determinante(conjunto_t *P);
// ----------------------------------------------------