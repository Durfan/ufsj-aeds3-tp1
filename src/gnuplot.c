#include "main.h"

void plotGraph(conjunto_t *CJT) {
    int i;
    
    FILE *temp = fopen("data.temp", "w");
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    char *commands[] = {"set title \"Debug\"", "plot 'data.temp' w lp"};
    int Ncommands = 2;

    node_t *read = CJT->head;
    while (read != NULL) {
        fprintf(temp, "%hu 0\n", CJT->Xa);
        fprintf(temp, "%hu %hu\n\n", read->tupla.x, read->tupla.y);

        fprintf(temp, "%hu 0\n", CJT->Xb);
        fprintf(temp, "%hu %hu\n\n", read->tupla.x, read->tupla.y);
        read = read->next;
    }
    fclose(temp);
//  fprintf(gnuplotPipe, "set xrange [0:10000]\n");
//  fprintf(gnuplotPipe, "set yrange [0:10000]\n");
    fprintf(gnuplotPipe, "p %hu,0\n", CJT->Xa);
    fprintf(gnuplotPipe, "p %hu,0\n", CJT->Xb);
    for (i=0; i<Ncommands; i++) {
        fprintf(gnuplotPipe, "%s\n", commands[i]);
    }
    fflush(gnuplotPipe);
}