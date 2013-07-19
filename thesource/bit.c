#include "../include/bit.h" 

void setbit(byte* thebyte, size_t bitindex) { 
	*thebyte |= (1 << bitindex); 
}; 

void clearbit(byte* thebyte, size_t bitindex) { 
	*thebyte &= ~(1 << bitindex); 
}; 

void togglebit(byte* thebyte, size_t bitindex) { 
	*thebyte ^= (1 << bitindex); 
}; 

size_t getbit(byte* thebyte, size_t bitindex) { 
	return ((*thebyte & (1 << bitindex)) >> bitindex); 
}; 

