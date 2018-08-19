#include "main.h"
#include <ctype.h>
#include <getopt.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char **argv) {

    struct rusage usage;
    struct timeval start, end;

    conjunto_t *P = create();

    char *in_file = NULL;
    char *out_file = NULL;
    int index;
    int opt;

    opterr = 0;

    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;

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
                else if (optopt == 'o') printf ("Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt)) printf ("Unknown option `-%c'.\n", optopt);
                else printf ("Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                exit(1);
        }
    }
    for (index = optind; index<argc; index++) printf ("Non-option argument %s\n", argv[index]);
    
    openFILE(in_file,P);

    debug(P);

    TRIcount(P);
    printf(" Total = %d", P->total);

    saveFILE(out_file,P);

    dump(P);
    delCJT(P);

    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;

    printf("\n Started at: %ld.%lds\n", start.tv_sec, start.tv_usec);
    printf(" Ended at: %ld.%lds\n", end.tv_sec, end.tv_usec);

  return 0; 
}