#include "../include/pic.h" 

uint16_t pic_get_irq_reg(uint8_t combyte) { 
	outb(PIC1_COMMANDPORT, combyte); 
	outb(PIC2_COMMANDPORT, combyte); 
	return (inb(PIC2_COMMANDPORT) << 8) | inb(PIC1_COMMANDPORT); 
}; 

uint16_t pic_get_isr(void) {
	return pic_get_irq_reg(PIC_READ_ISR);
}; 

uint16_t pic_get_irr(void) {
	return pic_get_irq_reg(PIC_READ_IRR); 
};
	
void disable_pic(void) { 
	outb(0xA1, 0xFF); 
	outb(0x21, 0xFF); 
}; 

void pic_sendEOI(uint8_t irq) { 
	if (irq >= 8) { 
		outb(PIC2_COMMAND, PIC_EOI); 
	}; 
	outb(PIC1_COMMAND, PIC_EOI);  
}; 

void pic_map(uint8_t offset) { 
	uint8_t info1, info2; 
	
	info1 = inb(PIC1_DATA); 
	info2 = inb(PIC2_DATA); 
	
	/* Signal the PICs to start their initialization sequence. */
	outb(PIC1_COMMAND, 0x11); 
	io_wait(); /* The io_wait stuff is to give time for the PIC to process the commands before we proceed. */
	outb(PIC2_COMMAND, 0x11); 
	io_wait(); 
	
	/* Now where the interrupts are mapped */ 
	outb(PIC1_DATA, offset); 
	io_wait(); 
	outb(PIC2_DATA, offset + 8); 
	io_wait(); 
	
	/*  Tell that master PIC which IRQ is to be used to interact with the slave PIC and tell the slave its cascade identity */ 
	outb(PIC1_DATA, 4); 
	io_wait(); 
	outb(PIC2_DATA, 2); 
	io_wait(); 
	
	
	outb(PIC1_COMMAND, MODE_8086); 
	io_wait(); 
	outb(PIC1_COMMAND, MODE_8086); 
	io_wait(); 
	
	/* Now restore the saved masks (although if this is called as part of system initialization, it's pointless to do so */ 
	
	outb(PIC1_DATA, info1);
	outb(PIC2_DATA, info2); 
	
	/* We're done! */ 
}; 

void Mask_Interrupt_Line(uint8_t line) { 
	uint16_t port; 
	uint16_t res; 
	
	if (line >= 8) { 
		port = PIC2_DATA; 
		line = line - 8; 
	} 
	else { 
		port = PIC1_DATA; 
	}; 
	res = inb(port); 
	setbit(&res, line); 
	outb(port, res); 
}; 
	

void Demask_Interrupt_Line(uint8_t line) { 
	uint16_t port; 
	uint16_t res; 
	
	if (line >= 8) { 
		port = PIC2_DATA; 
		line = line - 8; 
	} 
	else { 
		port = PIC1_DATA; 
	}; 
	res = inb(port); 
	clearbit(&res, line); 
	outb(port, res); 
};

void pic_init(void) { 
	pic_map(32); /* This will map our interrupts ABOVE the vectors reserved for exceptions. */
	for (int i = 0; i < 16; i++) { 
		Mask_Interrupt_Line(i); 
	}; 
}; 


