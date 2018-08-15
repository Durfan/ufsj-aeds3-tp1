#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include "main.h"
#include "files.h"

int main (int argc, char **argv) {

    conjunto *P = create();

    char *in_file = NULL;
    char *out_file = NULL;
    int index;
    int opt;

    opterr = 0;

    while ((opt = getopt (argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                printf ("Input file: \"%s\"\n", optarg);
                in_file = optarg;
            break;
            case 'o':
                printf ("Output file: \"%s\"\n", optarg);
                out_file = optarg;
            break;
            case '?':
                if (optopt == 'i') printf ("Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt)) printf ("Unknown option `-%c'.\n", optopt);
                else printf ("Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                exit(1);
        }
        for (index = optind; index < argc; index++) printf ("Non-option argument %s\n", argv[index]);
    }
    openFILE(in_file,P);
    if (DEBUG) { 
        printCJT(P);
        printf(" Xa = %hu\n", P->Xa);
        printf(" Xb = %hu\n", P->Xb);
        printf(" Pontos = %hu\n", P->Ncoords);
    }
  return 0;
}