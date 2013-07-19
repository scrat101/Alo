#include <stddef.h> 

void inline setbit(byte* thebyte, size_t bitindex); 

void inline clearbit(byte* thebyte, size_t bitindex);

void inline togglebit(byte* thebyte, size_t bitindex);

size_t inline getbit(byte thebyte, size_t bitindex);
