#include "../include/GDT.h"


void setTheGDTAndReload(gdtptr* tosetto) { 
	thegdtptr.size = tosetto->size; 
	thegdtptr.offset = tosetto->offset;
	setTheGDT(); 
};

void getPTRForGDT(lowgdtdescriptor** thegdt, gdtptr* ourpointer) { 
	uint16_t gdtsizeforone = sizeof(lowgdtdescriptor); 
	uint16_t thelimit = 0; 
	for (int i = 0; thegdt[i] != NULL; i++) { 
		thelimit = gdtsizeforone + thelimit; 
	}; 
	thelimit = thelimit - 1; 
	ourpointer->size = thelimit; 
	ourpointer->offset = *thegdt; 
}; 
	
void primassignGDT(lowgdtdescriptor** thegdt, gdtptr* workwithptr, bool interrupts) { 
	asm("cli"); 
	getPTRForGDT(thegdt, workwithptr);
	setTheGDTAndReload(workwithptr); 
	if (interrupts) { 
		asm("sti");
	}; 
}; 	

void encodeGDTEntry(lowgdtdescriptor *res, gdtdescriptor descriptor) { 
	res->low_base = (descriptor.base & 0xFFFF); 
	res->middle_base = (descriptor.base >> 16) & 0xFF;
	res->high_base = (descriptor.base >> 24) & 0xFF; 
	res->low_limit = (descriptor.limit & 0xFFFF); 
	res->granularity = ((descriptor.limit >> 16) & 0x0F); 
	res->granularity |= (descriptor.granularity & 0xF0); 
	res->accessflag = descriptor.accessflag; 
};


void encodeGDT(gdtdescriptor** priorgdt, lowgdtdescriptor** res) { 
	for (int i = 0; (priorgdt[i] != NULL); i++) { 
		encodeGDTEntry(res[i], *priorgdt[i]); 
	}; 
}; 

void assignGDT(gdtdescriptor** priorgdt, lowgdtdescriptor** realgdt, gdtptr* workwithptr, bool interrupts) { 
	encodeGDT(priorgdt, realgdt); 
	primassignGDT(realgdt, workwithptr, interrupts); 
}; 

