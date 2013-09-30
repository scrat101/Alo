#include "../include/idt.h"

void setidtdescriptor(int num, uint32_t base, uint16_t sel, uint8_t flags) { 
	theidt[num].base_low = base & 0xFFFF; 
	theidt[num].base_high = base >> 16; 
	theidt[num].iszero = 0; 
	theidt[num].sel = sel; 
	theidt[num].flags = flags; 
}; 

void SetIDTPtrToIDT(idtentry* ouridt, idtptr* ouridtptr, int numberofentries) {
	ouridtptr->base = (uint32_t)ouridt; 
	ouridtptr->size = (sizeof(idtentry) * numberofentries) - 1; 
}; 	

void SetIDTToZeros(void) { 
	for (int i = 0; i < 256; i++) {
		setidtdescriptor(i, 0, 0, 0); 
	}; 
}; 

void idt_init(void) { 
	SetIDTToZeros(); 
	SetIDTPtrToIDT(&theidt, &theidtptr, 256); 
	idt_reload(); 
}; 