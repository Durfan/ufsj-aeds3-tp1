#include "main.h"
#include <getopt.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char **argv) {

    struct rusage ru;
    struct timeval start, end;
    struct timeval utime;
    struct timeval stime;

    gettimeofday (&start, NULL);
    system("@cls||clear");
    
    conjunto_t *P = create();

    char *in_file = NULL;
    char *out_file = NULL;
    int index;
    int opt;

    opterr = 0;

    while ((opt = getopt (argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                printf (" Input file: \"%s\"\n", optarg);
                in_file = optarg;
            break;
            case 'o':
                printf (" Output file: \"%s\"\n", optarg);
                out_file = optarg;
            break;
            case '?':
                if (optopt == 'i') printf (" Option -%c requires an argument.\n", optopt);
                else if (optopt == 'o') printf (" Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt)) printf (" Unknown option `-%c'.\n", optopt);
                else printf (" Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                exit(1);
        }
    }
    for (index = optind; index<argc; index++) printf (" Non-option argument %s\n", argv[index]);
    
    chkFILE(in_file); 
    openFILE(in_file,P);

    plotGraph(P); 
    debug(P);

    soluciona(P);
    solucao(P),
    saveFILE(out_file,P);

    dump(P,1);

    gettimeofday (&end, NULL);
    getrusage(RUSAGE_SELF, &ru);

    utime = ru.ru_utime;
    stime = ru.ru_stime;

    printf(COLOR_YELL);
    printf(" gettime  => %ld\xC2\xB5s\n", ((end.tv_sec-start.tv_sec)*1000000L+end.tv_usec)-start.tv_usec);
    printf(" ru_utime => %lds %ld\xC2\xB5s\n", (int64_t)utime.tv_sec, (int64_t)utime.tv_usec);
    printf(" ru_stime => %lds %ld\xC2\xB5s\n", (int64_t)stime.tv_sec, (int64_t)stime.tv_usec);
    printf(COLOR_RESET);

  return 0; 
}