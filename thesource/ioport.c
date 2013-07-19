#include "../include/ioport.h"

static inline void outb(uint8_t port, uint8_t theval) { 
	asm volatile("outb %0, %1" : : "a"(theval), "Nd"(port)); 
}; 

static inline uint8_t inb(uint8_t port) { 
	uint8_t res; 
	asm volatile("inb %1, %0" : "=a"(res) : "Nd"(port)); 
	return res; 
}; 

static inline void io_wait(void) { 
	asm volatile("jmp 1f\n\t" 
				 "1:jmp 2f\n\t" 
				 "2:"); 
}; 


