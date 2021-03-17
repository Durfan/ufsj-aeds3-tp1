#ifndef INCLUDE_MAIN_H
#define INCLUDE_MAIN_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#include "data.h"
#include "files.h"
#include "hipercampo.h"
#include "valida.h"

#define NisValide(ncoords) (( ncoords >= 1 && ncoords <= 100 ) ? 1 : 0)
#define PisValide(dot) (( dot > 0 && dot <= 10000 ) ? 1 : 0)

#define COLOR_RED   "\x1b[31m"
#define COLOR_YELL  "\x1b[33m"
#define COLOR_BLUE  "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#define DEBUG 1

typedef enum {false,true} bool;

//#pragma message __FILE__
#endif // INCLUDE_MAIN_H