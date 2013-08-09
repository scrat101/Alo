#include "../include/NewGDT.h"

void setgdtdescriptor(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
	/* Taking care of the bases.. */
	thegdt[num].base_low = (base & 0xFFFF); 
	thegdt[num].base_middle = (base >> 16) & 0xFF; 
	thegdt[num].base_high = (base >> 24) & 0xFF; 
	
	/*  Lets do the limits... */
	thegdt[num].limit_low = limit & 0xFFFF;  
	thegdt[num].gran = ((limit >> 16) & 0x0F); 
	
	/* And finally the access flags... */
	thegdt[num].gran |= (gran & 0xF0); 
	thegdt[num].access = access; 
}; 

void SetGDTPtrToGDT(gdtdescriptor* gdt, gdtptr* thegdtptr, int numberofentries) {
	thegdtptr->base = gdt; 
	thegdtptr->size = (sizeof(gdtdescriptor) * numberofentries) - 1; 
}; 	

void gdt_init(void) {
	SetGDTPtrToGDT(&thegdt, &thegdtptr, 3); 
	setgdtdescriptor(0, 0, 0, 0, 0); 
	setgdtdescriptor(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); 
	setgdtdescriptor(2, 0, 0xFFFFFFFF, 0x92, 0xCF); 
	RefreshGDT();
}; 

