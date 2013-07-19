#include "../include/BasicIO.h"

byte makecolor(vga_color fg, vga_color bg) { 
	return fg | bg << 4; 
};   

TwoBytes make_vgaentry(char c, byte color) { 
	TwoBytes c16 = c; 
	TwoBytes color16 = color; 
	return c16 | color16 << 8; 
}; 

size_t strlen(const char* str) { 
	size_t ind = 0; 
	while (str[ind] != 0) { 
		ind++; 
	}; 
	return ind;
}; 
	

void terminal_initialize() { 
	terminal_row = 0; 
	terminal_column = 0; 
	terminal_color = makecolor(COLOR_LIGHT_GREY, COLOR_BLACK); 
	terminal_buffer = (TwoBytes*) 0xB8000; 
	for (size_t y = 0; y < VGA_HEIGHT; y++) { 
		for (size_t x = 0; x < VGA_WIDTH; x++) { 
			terminal_buffer[y * VGA_WIDTH + x] = make_vgaentry(' ', terminal_color); 
		}; 
	}; 
};   	


void MoveTerminalBuffer1Row(TwoBytes* buffer) { 
	for (size_t height = 1; height < VGA_HEIGHT; height++) { 
		size_t rowstart = height * VGA_WIDTH; 
		for (size_t xpos = 0; xpos < VGA_WIDTH; xpos++) {
			size_t curpos = rowstart + xpos; 
			buffer[curpos - VGA_WIDTH] = terminal_buffer[curpos];
			buffer[curpos] = make_vgaentry(' ', terminal_color); 
		}; 
	}; 
};

void ScrollDown(int amount) { 
	for (int i = 1; i <= amount; i++) { 
		MoveTerminalBuffer1Row(terminal_buffer); 
	}; 
}; 

void terminal_setcolor(byte color) { 
	terminal_color = color; 
}; 

void terminal_setcolortoall(byte color) { 
	for (size_t height = 0; height < VGA_HEIGHT; height++) { 
		size_t start = height * VGA_HEIGHT; 
		for (size_t xpos = 0; xpos < VGA_WIDTH; xpos++) { 
			size_t pos = start + xpos;
			byte thechar = ((byte*)terminal_buffer[pos])[1];
			terminal_buffer[pos] = make_vgaentry(thechar, color); 
		}; 
	}; 
}; 	
			

void terminal_putentryat(char c, byte color, size_t x, size_t y) { 
	terminal_buffer[y * VGA_WIDTH + x] = make_vgaentry(c, color); 
};     

void terminal_putchar(const char c) { 
	if (c == '\n') { 
		terminal_row++; 
		if (terminal_row == VGA_HEIGHT) { 
			ScrollDown(1); 
			terminal_row = 23; 
		}; 	
		terminal_column = 0; 
		return; 
	}; 
	if (terminal_column++ == VGA_WIDTH) { 
		terminal_putchar('\n'); 
		
	}; 
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row); 
}; 

void terminal_putstring(const char* str) { 
	size_t strlength = strlen(str); 
	for (size_t i = 0; i < strlength; i++) { 
		terminal_putchar(str[i]); 
	}; 
}; 

void printf(const char *str, ...) { 
	va_list arglist; 
	va_start(arglist, str); 
	int p = 0; 
	while (str[p] != NULL) { 
		if (str[p] == '%') { 
			const char nextone = str[p + 1]; 
			if (nextone == '%') { 
				terminal_putchar('%');
			}; 
			if (nextone == 's') { 
				terminal_putstring(va_arg(arglist,  const char*)); 
			};
			if (nextone == 'd') { 		
				terminal_putstring(integertochar(va_arg(arglist, int), "                  ")); 
			}; 
			p++;
			p++;
		} 
		else { 
			terminal_putchar(str[p]); 
			p++; 
		}; 
	};
	terminal_putchar('\n'); 
	va_end(arglist);
}; 	