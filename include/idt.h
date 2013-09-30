#ifndef idt
#define idt
#include <stdint.h>
#include "IDTPtrAndSetup.h" 

struct structidtentry {
	uint16_t base_low; 
	uint16_t sel; 
	uint8_t iszero; 
	uint8_t flags; 
	uint16_t base_high; 
} __attribute__((packed)); 

typedef struct structidtentry idtentry; 

idtentry theidt[256]; 
idtptr theidtptr; 

void setidtdescriptor(int num, uint32_t base, uint16_t sel, uint8_t flags);
 
void SetIDTPtrToIDT(idtentry* idt, idtptr* ouridtptr, int numberofentries);

void SetIDTToZeros(void); 

void idt_init(void); 
#endif