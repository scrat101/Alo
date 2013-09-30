#ifndef bit
#define bit
#include <stddef.h> 
#include <stdbool.h>
#include "TypeByte.h"

void setbit(byte* thebyte, size_t bitindex); 

void clearbit(byte* thebyte, size_t bitindex);

void togglebit(byte* thebyte, size_t bitindex);

bool getbit(byte thebyte, size_t bitindex);

void setbitTwo(TwoBytes* thebyte, size_t bitindex);

void clearbitTwo(TwoBytes* thebyte, size_t bitindex);

void togglebitTwo(TwoBytes* thebyte, size_t bitindex);

bool getbitTwo(TwoBytes thebyte, size_t bitindex);


#endif