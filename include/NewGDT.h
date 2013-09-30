#ifndef NewGDT
#define NewGDT
#include <stdint.h>
#include "GDTPtrAndSetup.h"  

struct structgdtdescriptor {
	uint16_t limit_low; 
	uint16_t base_low;
	uint8_t base_middle; 
	uint8_t access; 
	uint8_t gran;  
	uint8_t base_high;
} __attribute__((packed));

typedef struct structgdtdescriptor gdtdescriptor;

gdtdescriptor thegdt[3]; 

gdtptr thegdtptr; 

void setgdtdescriptor(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

void SetGDTPtrToGDT(gdtdescriptor* gdt, gdtptr* thegdtptr, int numberofentries);

void gdt_init(void);
#endif