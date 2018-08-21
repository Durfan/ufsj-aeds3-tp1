#include "main.h"

void chkFILE(char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf(COLOR_RED" Erro ao abrir arquivo!\n"COLOR_RESET);
        return;
    }
    bool erro = false;
    ncoords_t NC;
    tupla_t p;
    anchor_t Xa;
    anchor_t Xb;
    unsigned short Nline = 0;
    const size_t line_size = 300;
    char *line = malloc(line_size);
    while (fgets(line, line_size, fp) != NULL) {
        line[strcspn(line, "\n")] = 0;
            if (Nline == 0) {
                sscanf(line, "%hu %hu %hu", &NC, &Xa, &Xb);
                if (!NisValide(NC)) { erro = true; showerro(0,Nline); }
                if (!PisValide(Xa)) { erro = true; showerro(1,Nline); }
                if (!PisValide(Xb)) { erro = true; showerro(2,Nline); }
            }
            else {
                sscanf(line, "%hu %hu", &p.x, &p.y);
                if (!PisValide(p.x)) { erro = true; showerro(3,Nline); }
                if (!PisValide(p.y)) { erro = true; showerro(4,Nline); }
            }
            Nline++;
    }
    free(line);
    fclose(fp);
    // printf(" Linhas: %d\n", Nline);
    if (Nline-1>NC) { erro = true; showerro(5,Nline); }
    if (erro) ask();
}

void showerro(int erro, int line) {
    char *s_erros[] = {"Maximo de coordenadas","Ancora Xa",
                        "Ancora Xb","Ponto X","Ponto Y",
                        "Pontos excedidos"};
    printf(COLOR_RED" ERRO: %s. => Linha %d\n"COLOR_RESET, s_erros[erro], line+1);
}

void ask() {
    char q;
    printf(" Continuar? (s/n): ");
    q = getchar();
    if (q == 'n') exit(1);
}