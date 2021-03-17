#ifndef INCLUDE_HIPERCAMPO_H
#define INCLUDE_HIPERCAMPO_H

int PQR(conjunto_t *P, node_t *Q, node_t *R);
int findMAX(conjunto_t *CJT, conjunto_t *plot);
void cpyCJT(conjunto_t *TO, conjunto_t *FROM);
void soluciona(conjunto_t *CJT);
void solucao(conjunto_t *CJT);

//#pragma message __FILE__
#endif // INCLUDE_HIPERCAMPO_H