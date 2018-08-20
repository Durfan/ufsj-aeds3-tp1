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
    printf(" Total = %d", CJT->total);
    fclose(fp);
}