#include "main.h"

void openFILE(char *file, conjunto_t *CJT) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf(COLOR_RED" Erro ao abrir arquivo!\n"COLOR_RESET);
        return;
    }
    tupla_t ponto;
    unsigned short Nline = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0;
        if (Nline == 0) sscanf(line, "%hu %hu %hu", &CJT->ncoords, &CJT->Xa, &CJT->Xb);
        else {
            sscanf(line, "%hu %hu", &ponto.x, &ponto.y);
            insere(ponto,CJT);
        }
        Nline++;
    }
    fclose(fp);
}

void saveFILE(char *file, conjunto_t *CJT) {
    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        printf(COLOR_RED" Erro ao criar arquivo!"COLOR_RESET);
    return;
    }
    fprintf(fp, "%d", CJT->total);
    fclose(fp);
}

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
    if (!CJT->ncoords) { 
        fprintf(gnuplot, "set output 'output.svg'\n");
        fprintf(gnuplot, "set title \"Saida\"\n");
    }
    else {
        fprintf(gnuplot, "set output 'input.svg'\n");
        fprintf(gnuplot, "set title \"Entrada\"\n");
    }
    fprintf(gnuplot, "set style line 12 lc rgb '#808080' lt 0 lw 1\n");
    fprintf(gnuplot, "set grid back ls 12\n");
    fprintf(gnuplot, "plot 'data.temp' w lp\n");

    fflush(gnuplot);
    pclose(gnuplot);
}