#ifndef IDTPtrAndSetup 
#define IDTPtrAndSetup

#include <stdint.h> 

struct structidtptr { 
	uint16_t size; 
	uint32_t base; 
} __attribute__((packed)); 

typedef struct structidtptr idtptr;

void idt_reload(); 

#endif