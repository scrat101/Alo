#include "../include/keyboard.h" 

void keyboardhandler(void) { 
	terminal_putchar(keyboard_us[inb(0x60)]); 
}; 