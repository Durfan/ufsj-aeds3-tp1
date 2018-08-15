#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "data.h"

void openFILE(char *file, conjunto *coords) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf(COLOR_RED" Erro ao abrir arquivo!\n"COLOR_RESET);
        return;
    }
    point_t ponto;
    unsigned short Nline = 0;
    const size_t line_size = 300;
    char *line = malloc(line_size);
    while (fgets(line, line_size, fp) != NULL) {
        if (Nline == 0) sscanf(line, "%hu %hu %hu", &coords->Ncoords, &coords->Xa, &coords->Xb);
        else {
            sscanf(line, "%hu %hu", &ponto.x, &ponto.y);
            insere(ponto,coords);
        }
        Nline++;
    }
    free(line);
    fclose(fp);
}