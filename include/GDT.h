#ifndef GDT 
#define GDT

#include "GDTPtrAndSetup.h" 
#include <stdint.h> 
#include <stdbool.h> 
#include <stddef.h> 


typedef struct gdtdescriptor { 
	uint32_t base __attribute__((packed)); 
	uint16_t limit __attribute__((packed)); 
	uint8_t accessflag __attribute__((packed)); 
	uint8_t granularity __attribute__((packed)); 
} gdtdescriptor __attribute__((packed)); 

typedef struct lowgdtdescriptor { 
	uint16_t low_limit __attribute__((packed)); 
	uint16_t low_base __attribute__((packed));
	uint8_t middle_base __attribute__((packed)); 
	uint8_t accessflag __attribute__((packed)); 
	uint8_t granularity __attribute__((packed));  
	uint8_t high_base __attribute__((packed)); 
} lowgdtdescriptor __attribute__((packed)); 

extern gdtptr thegdtptr;

void setTheGDTAndReload(gdtptr* tosetto);

void getPTRForGDT(lowgdtdescriptor** thegdt, gdtptr* ourpointer);
	
void primassignGDT(lowgdtdescriptor** thegdt, gdtptr* workwithptr, bool interrupts);

void encodeGDTEntry(lowgdtdescriptor *res, gdtdescriptor descriptor);


void encodeGDT(gdtdescriptor** priorgdt, lowgdtdescriptor** res);

void assignGDT(gdtdescriptor** priorgdt, lowgdtdescriptor** realgdt, gdtptr* workwithptr, bool interrupts);



#endif