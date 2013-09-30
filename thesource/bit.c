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

bool getbit(byte thebyte, size_t bitindex) { 
	return ((thebyte & (1 << bitindex)) >> bitindex); 
}; 

void setbitTwo(TwoBytes* thebyte, size_t bitindex) { 
	*thebyte |= (1 << bitindex); 
}; 

void clearbitTwo(TwoBytes* thebyte, size_t bitindex) { 
	*thebyte &= ~(1 << bitindex); 
}; 

void togglebitTwo(TwoBytes* thebyte, size_t bitindex) { 
	*thebyte ^= (1 << bitindex); 
}; 

bool getbitTwo(TwoBytes thebyte, size_t bitindex) { 
	return ((thebyte & (1 << bitindex)) >> bitindex); 
}; 

