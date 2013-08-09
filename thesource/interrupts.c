#include "../include/interrupts.h" 

void AssignInterruptToRoutine(uint8_t interrupt, interrupthandler handler) {
	setidtdescriptor(interrupt, handler, 0x08, 0xE); 
	Demask_Interrupt_Line(interrupt); 
}; 

void generalinterrupthandler(uint32_t code) { 
	if (((pic_get_isr() & (1 << code)) >> code)) {  
		if (interrupthandlers[code]) { 
			interrupthandlers[code](); 
		}; 
		pic_sendEOI(code);
	}
	else { 
		if (code > 7) { 
			pic_sendEOI(0); 
		}; 
	}; 
}; 	

void interrupts_init(void) { 
	pic_init();
	idt_init(); 
	for (int i = 0; i < 16; i++) { 
		AssignInterruptToRoutine(i, referringinterrupthandlers[i]);
	}; 	
	asm("sti"); 
};