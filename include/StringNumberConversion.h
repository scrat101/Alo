#ifndef StringNumberConversion 
#define StringNumberConversion 

#include <stdbool.h>
#include <stddef.h> 
#include <stdint.h>
#include "CoreFunctions.h"

static int getnumofdigits(int num, int base);

static int pow(int num, int thepow);

static int findchar(char *thechars, char pattern);

static char* getjustnumdigits(char* thechars, char* res);

int atoi(char* thechars, int base);

char* itoa(int num, int base, char* chars);

#endif 