#include "../include/interrupts.h" 

void UnassignInterruptToRoutine(uint8_t interrupt) {
	Mask_Interrupt_Line(interrupt);
	setidtdescriptor(interrupt, (uint32_t)0, 0x08, 0x8E); 
};

void AssignInterruptToRoutine(uint8_t interrupt, interrupthandler handler) {
	Demask_Interrupt_Line(interrupt); 
	setidtdescriptor(interrupt, (uint32_t)handler, 0x08, 0x8E); 
}; 

void generalinterrupthandler(InterruptData data) { 
	uint32_t num = (uint32_t)data.interruptnumber;
	if (((pic_get_isr() & (1 << num)) >> num)) {  
		if (interrupthandlers[num]) { 
			interrupthandlers[num](); 
		}; 
		pic_sendEOI(num);
	}
	else { 
		if (num > 7) { 
			pic_sendEOI(0); 
		}; 
	}; 
}; 	

void InvokeInterrupt(int interrupt) { 
	/*asm volatile("int %0" :: "Nd"(interrupt)) */; 
}; 	

void interrupts_init(void) { 
	pic_init();
	idt_init(); 
	for (int i = 0; i <= 47; i++) { 
		AssignInterruptToRoutine(i, referringinterrupthandlers[i]);	
	}; 	
	asm("sti"); 
};