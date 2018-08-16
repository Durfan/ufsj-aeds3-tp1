#include "main.h"

void openFILE(char *file, conjunto_t *P) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf(COLOR_RED" Erro ao abrir arquivo!\n"COLOR_RESET);
        return;
    }
    tupla_t tupla;
    unsigned short Nline = 0;
    const size_t line_size = 300;
    char *line = malloc(line_size);
    while (fgets(line, line_size, fp) != NULL) {
        if (Nline == 0) sscanf(line, "%hu %hu %hu", &P->ncoords, &P->Xa, &P->Xb);
        else {
            sscanf(line, "%hu %hu", &tupla.x, &tupla.y);
            insere(tupla,P);
        }
        Nline++;
    }
    free(line);
    fclose(fp);
}

void saveFILE(char *file, conjunto_t *P) {

}