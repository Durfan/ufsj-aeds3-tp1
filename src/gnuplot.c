#include "main.h"

void plotGraph(conjunto_t *CJT) {
    int i;
    
    FILE *temp = fopen("data.temp", "w");
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    char *commands[] = {"set title \"Debug\"", "plot 'data.temp'"};
    int Ncommands = 2;

    node_t *read = CJT->head;
    while (read != NULL) {
        fprintf(temp, "%f %f\n", (float)read->tupla.x, (float)read->tupla.y);
        read = read->next;
    }
    printf("teste");
    for (i=0; i<Ncommands; i++) {
        fprintf(gnuplotPipe, "%s\n", commands[i]);
    }
}