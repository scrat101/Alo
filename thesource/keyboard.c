#include "../include/keyboard.h"

uint8_t getchar(void) { 
	printf("Getchar before loop!");
	Demask_Interrupt_Line(33); 
	uint8_t res;
	printf("Getchar before loop!");
	while (currentchar == 0);
	printf("Getchar is in middle!");
	Mask_Interrupt_Line(33);	
	printf("Getchar is in middle!");
	asm("cli"); 
	res = currentchar;
	currentchar = 0; 
	asm("sti");
	printf("Getchar has returned!");
	return res; 
}; 

uint8_t* getstr(uint8_t* storage) { 
	uint8_t res = getchar(); 
	int count = 0;
	while (res != '\n') { 
		storage[count] = res; 
		count++; 
		res = getchar(); 
	}; 
	return storage;
}; 
	
void keyboardsendcommand(uint8_t com, bool additional, uint8_t val) {
	outb(0x60, com);
	io_wait();
	while (keyboardgetoutput() == 0xFE) { 
		outb(0x60, com);
		io_wait();
	};	
	if (additional) { 
		outb(0x60, val);
		io_wait();
		while (keyboardgetoutput() == 0xFE) { 
			outb(0x60, val);
			io_wait(); 
		}; 	
	}; 	
}; 	

uint8_t keyboardgetoutput(void) { 
	return inb(0x60);
}; 

void keyboardsetLEDs(bool ScrollLock, bool NumberLock, bool CapsLock) { 
	uint8_t res = 0; 
	if (ScrollLock) { 
		setbit(&res, 0); 
	};
	if (NumberLock) { 
		setbit(&res, 1); 
	};
	if (CapsLock) { 
		setbit(&res, 2); 
	};
	keyboardsendcommand(0xED, true, res); 
}; 

void keyboardEnableFreeTyping(void) {
	Demask_Interrupt_Line(33);
};	

void keyboardDisableFreeTyping(void) { 
	Mask_Interrupt_Line(33);
};  	
	
void keyboardhandler(void) { 
	uint8_t res = keyboardgetoutput(); 
	switch (res) { 
		case 0x00: 
			panic("Error, key detection error!"); 
			return;
		case 0xAA: 
			printf("Keyboard self-test passed!"); 
			return;
		case 0xEE: 
			printf("Keyboard responded to echo command!"); 
			return;
		case 0xFA: 
			printf("Keyboard command acknowledged"); 
			return;
		case 0xFC: 
			panic("Keyboard self-test failed!"); 
			return;
		case 0xFD: 
			panic("Keyboard self-test failed!"); 
			return;
		case 0xFE: 
			printf("Keyboard wants command to be sent again..."); 
			return;
		case 0xFF: 
			panic("Key detection error!"); 
			return;
	}; 
	if (res < 128) { 
		if (res == '\b') { 
			if (terminal_column > 0) { 
				terminal_column--;
			} 
			else { 
				terminal_row--; 
				terminal_column = VGA_WIDTH; 
			}; 
			terminal_putentryat(' ', terminal_color, terminal_column, terminal_row);
		}
		else {
			terminal_putchar(keyboard_us[res]); 
			currentchar = keyboard_us[res]; 
		};
	};	
}; 

void keyboard_init(void) {  
	setidtdescriptor(33, (uint32_t)keyboardhandler, 0x08, 0x8E); 
}; 	
