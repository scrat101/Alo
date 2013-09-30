#include "../include/ioport.h"

inline void outb(uint16_t port, uint8_t theval) { 
	asm volatile("outb %0, %1" : : "a"(theval), "Nd"(port)); 
}; 

inline uint8_t inb(uint16_t port) { 
	uint8_t res; 
	asm volatile("inb %1, %0" : "=a"(res) : "Nd"(port)); 
	return res; 
}; 

inline void io_wait(void) { 
	asm volatile("jmp 1f\n\t" 
				 "1:jmp 2f\n\t" 
				 "2:"); 
}; 


