#include "../include/CoreFunctions.h"

void hang(void) { 
	asm("cli"); 
	asm("hlt"); 
}; 

void panic(const char *msg) { 
	printf("Fatal error: %s.", msg); 
	hang(); 
}; 
