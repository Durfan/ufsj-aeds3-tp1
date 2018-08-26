#include "main.h"

void plotGraph(conjunto_t *CJT) {
    FILE *temp = fopen("data.temp", "w");

    node_t *read = CJT->head;
    while (read != NULL) {
        fprintf(temp, "%hu 0\n", CJT->Xa);
        fprintf(temp, "%hu %hu\n\n", read->p.x, read->p.y);

        fprintf(temp, "%hu 0\n", CJT->Xb);
        fprintf(temp, "%hu %hu\n\n", read->p.x, read->p.y);
        read = read->next;
    }
    fclose(temp);

    FILE *gnuplot = popen("gnuplot", "w");

    fprintf(gnuplot, "set terminal svg enhanced mouse size 1280,1280\n");
    if (!CJT->ncoords) fprintf(gnuplot, "set output 'output.svg'\n");
    else fprintf(gnuplot, "set output 'input.svg'\n");
    fprintf(gnuplot, "set title \"Solucao da entrada\"\n");
    fprintf(gnuplot, "set style line 12 lc rgb '#808080' lt 0 lw 1\n");
    fprintf(gnuplot, "set grid back ls 12\n");
    fprintf(gnuplot, "plot 'data.temp' w lp\n");

    fflush(gnuplot);
    pclose(gnuplot);
}