#include "main.h"

void plotGraph(conjunto_t *CJT) {
    FILE *temp = fopen("data.temp", "w");
    FILE *gnuplot = popen("gnuplot", "w");

    node_t *read = CJT->head;
    while (read != NULL) {
        fprintf(temp, "%hu 0\n", CJT->Xa);
        fprintf(temp, "%hu %hu\n\n", read->p.x, read->p.y);

        fprintf(temp, "%hu 0\n", CJT->Xb);
        fprintf(temp, "%hu %hu\n\n", read->p.x, read->p.y);
        read = read->next;
    }
    fclose(temp);

    fprintf(gnuplot, "set terminal png size 2400,1800\n");
    if (!CJT->ncoords) fprintf(gnuplot, "set output 'output.png'\n");
    else fprintf(gnuplot, "set output 'input.png'\n");
    fprintf(gnuplot, "set title \"Debug\"\n");
    fprintf(gnuplot, "plot 'data.temp' w lp\n");


    fflush(gnuplot);
    pclose(gnuplot);
}