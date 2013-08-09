#ifndef GDTPtrAndSetup 
#define GDTPtrAndSetup

#include <stdint.h> 

struct structgdtptr { 
	uint16_t size; 
	uint32_t base; 
} __attribute__((packed)); 

typedef struct structgdtptr gdtptr;

void RefreshGDT(); 

#endif