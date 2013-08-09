#ifndef BasicIO 
#define BasicIO

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include "TypeByte.h" 
#include "StringNumberConversion.h"

typedef enum vga_color { 
	COLOR_BLACK = 0, 
	COLOR_BLUE = 1, 
	COLOR_GREEN = 2, 
	COLOR_CYAN = 3, 
	COLOR_RED = 4, 
	COLOR_MAGENTA = 5, 
	COLOR_BROWN = 6, 
	COLOR_LIGHT_GREY = 7, 
	COLOR_DARK_GREY = 8, 
	COLOR_LIGHT_BLUE = 9, 
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11, 
	COLOR_LIGHT_RED = 12, 
	COLOR_LIGHT_MAGENTA = 13, 
	COLOR_LIGHT_BROWN = 14, 
	COLOR_WHITE = 15 
} vga_color; 

byte makecolor(vga_color fg, vga_color bg);

TwoBytes make_vgaentry(char c, byte color);
size_t strlen(const char* str);

static const size_t VGA_WIDTH = 80; 
static const size_t VGA_HEIGHT = 24; 

size_t terminal_row; 
size_t terminal_column; 
byte terminal_color; 
TwoBytes* terminal_buffer; 

void terminal_initialize();	

void MoveTerminalBuffer1Row(TwoBytes* buffer);

void ScrollDown(int amount);

void terminal_setcolor(byte color);

void terminal_setcolortoall(byte color);

void terminal_putentryat(char c, byte color, size_t x, size_t y);

void terminal_putchar(const char c);
void terminal_putstring(const char* str);

void printf(const char* str, ...); 

#endif