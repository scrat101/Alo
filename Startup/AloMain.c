#if !defined(_cplusplus) 
	#include <stdbool.h> 
#endif 

#include <stddef.h> 
#include <stdint.h> 
#include <stdarg.h>
#include "../include/multiboot.h" 
#include "../include/System.h"
#include "../include/bit.h" 
 
 
/*void reboot(void) { 
	((void (*)(void))(120))();
};
*/ 


void alostart(multiboot_info_t* info) { 
	terminal_initialize(); 
	if (getbit((uint8_t*)&info->flags, 0) == 0) {
		panic("Computer not supported: memory cannot be detected through grub!"); 
	}; 
	for (int i = 1; i <= 40; i++) { 
		terminal_putstring("Hello, grand kernel world! :) :)\n");
		terminal_putstring("More will come of this.\n");
		//printf("My name is %s. I am %d years old.", "Alex", 13);
	}; 	
	terminal_putstring("End."); 
}; 



 



