#if !defined(_cplusplus) 
	#include <stdbool.h> 
#endif 

#include <stddef.h> 
#include <stdint.h> 
#include <stdarg.h>
#include "../include/multiboot.h" 
#include "../include/System.h"
#include "../include/bit.h" 
//#include "../include/memory.h"  
#include "../include/NewGDT.h" 
#include "../include/interrupts.h"

 
/*void reboot(void) { 
	((void (*)(void))(120))();
};
*/ 

/*
void gdt_init() { 
	thegdt[0] = 1; 
	thegdt[1] = 1; 
	thegdt[2] = 1; 
	thegdt[3] = NULL;
	thebeginninggdt[0]->base = 0; 
	thebeginninggdt[0]->limit = 0; 
	thebeginninggdt[0]->accessflag = 0; 
	thebeginninggdt[0]->granularity = 0; 
	thebeginninggdt[1]->base = 0; 
	thebeginninggdt[1]->limit = 0xffffffff; 
	thebeginninggdt[1]->accessflag = 0x9A; 
	thebeginninggdt[1]->granularity = 0xCF; 
	thebeginninggdt[2]->base = 0; 
	thebeginninggdt[2]->limit = 0xffffffff; 
	thebeginninggdt[2]->accessflag = 0x92; 
	thebeginninggdt[2]->granularity = 0xCF; 
	thebeginninggdt[3] = NULL; 
	assignGDT(thebeginninggdt, thegdt, &testptr, false); 
}; */


void alostart(multiboot_info_t* meminfo) { 
	terminal_initialize();
	for (int i = 0; i < 90000;  i++);
	setbit((EightBytes)meminfo->flags, 0);
	/*if (!getbit((EightBytes)meminfo->flags, 0)) {
		panic("Computer not supported: memory cannot be detected through grub!"); 
	};*/
	gdt_init(); 
	interrupts_init();
	for (int i = 1; i <= 40; i++) { 
		terminal_putstring("Hello, grand kernel world! :) :)\n");
		terminal_putstring("More will come of this.\n");
		//printf("My name is %s. I am %d years old.", "Alex", 13);
	}; 	
	terminal_putstring("End."); 
}; 



 




 