#include "main.h"

void chkFILE(char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf(COLOR_RED" Erro ao abrir arquivo!\n"COLOR_RESET);
        return;
    }
    ncoords_t ncoords;
    tupla_t tupla;
    anchor_t Xa;
    anchor_t Xb;
    unsigned short Nline = 0;
    const size_t line_size = 300;
    char *line = malloc(line_size);
    while (fgets(line, line_size, fp) != NULL) {
        if (Nline == 0) {
            sscanf(line, "%hu %hu %hu", &ncoords, &Xa, &Xb);
            if (!NisValide(ncoords)) showerro(0,Nline);
            if (!PisValide(Xa)) showerro(1,Nline);
            if (!PisValide(Xb)) showerro(2,Nline);
        }
        else {
            sscanf(line, "%hu %hu", &tupla.x, &tupla.y);
            if (!PisValide(tupla.x)) showerro(3,Nline);
            if (!PisValide(tupla.y)) showerro(4,Nline);
        }
        Nline++;
    }
    free(line);
    fclose(fp);
}

void showerro(int erro, int line) {
    switch (erro) {
        case (0):
            printf(COLOR_RED" ERRO! Linha %d => Numero de coordenadas invalido.\n"COLOR_RESET, line);
            ask();
        break;
        case (1):
            printf(COLOR_RED" ERRO! Linha %d => Ancora Xa invalida.\n"COLOR_RESET, line);
            ask();
        break;
        case (2):
            printf(COLOR_RED" ERRO! Linha %d => Ancora Xb invalida.\n"COLOR_RESET, line);
            ask();
        break;
        case (3):
            printf(COLOR_RED" ERRO! Linha %d => Ponto X invalido.\n"COLOR_RESET, line);
            ask();
        break;
        case (4):
            printf(COLOR_RED" ERRO! Linha %d => Ponto Y invalido.\n"COLOR_RESET, line);
            ask();
        break;
        default:
            printf(COLOR_RED" ERRO! Linha %d => Desconhecido.\n"COLOR_RESET, line);
            ask();
        break;
    }
}

void ask() {
    char q;
    printf(" Continuar? (s/n): ");
    getchar();
    q = getchar();
    if (q == 'n') exit(1);
}