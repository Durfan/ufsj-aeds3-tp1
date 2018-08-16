#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "files.h"
#include "hipercampo.h"

#define COLOR_RED   "\x1b[31m"
#define COLOR_YELL  "\x1b[33m"
#define COLOR_BLUE  "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#define DEBUG 1

typedef enum {false,true} bool;