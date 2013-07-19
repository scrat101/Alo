#include "../include/bit.h" 

inline void setbit(byte* thebyte, size_t bitindex) { 
	*thebyte |= (1 << bitindex); 
}; 

inline void clearbit(byte* thebyte, size_t bitindex) { 
	*thebyte &= ~(1 << bitindex); 
}; 

inline void togglebit(byte* thebyte, size_t bitindex) { 
	*thebyte ^= (1 << bitindex); 
}; 

inline size_t getbit(byte thebyte, size_t bitindex) { 
	return ((thebyte & (1 << bitindex)) >> bitindex); 
}; 

