#include <stddef.h> 
#include <stdbool.h>
#include "TypeByte.h"

void setbit(EightBytes* thebyte, size_t bitindex); 

void clearbit(EightBytes* thebyte, size_t bitindex);

void togglebit(EightBytes* thebyte, size_t bitindex);

bool getbit(EightBytes thebyte, size_t bitindex);
