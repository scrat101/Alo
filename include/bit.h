#include <stddef.h> 
#include "TypeByte.h"

void setbit(byte* thebyte, size_t bitindex); 

void clearbit(byte* thebyte, size_t bitindex);

void togglebit(byte* thebyte, size_t bitindex);

size_t getbit(byte* thebyte, size_t bitindex);
