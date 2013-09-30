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
#include "../include/StringNumberConversion.h"
#include "../include/RegisterHandling.h"
 
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

void BasicSystemInitialization(multiboot_info_t* bootinfo) { 
	terminal_initialize();
	gdt_init(); 
	interrupts_init();
	keyboard_init(); 
}; 	

void alostart(multiboot_info_t* bootinfo, uint32_t magicnumber) { 
	int testnum = atoi("13", 10);
	uint8_t storage[256];
	BasicSystemInitialization(bootinfo); 
	if (!getbit((EightBytes)bootinfo->flags, 0)) {
		panic("Computer not supported: memory cannot be detected through grub!"); 
	};
	terminal_putstring("Hello, grand kernel world! :) :)\n");
	terminal_putstring("More will come of this.\n");
	printf("My name is %s. I am %d years old.", "Alex", 13);
	printf("%d in binary is %b.", 13, 13); 
	printf("%d in hexadecimal is %h.", 13, 13);
	printf("atoi(\"13\") = %d.", testnum); 
	printf("meminfo->flags = %b.", bootinfo->flags);  	
	printf("Enter number :"); 
	printf("ESP: %d.", getESP());
	printf("Input: %s", (const char*)getstr(storage));
	//keyboardEnableFreeTyping();
	//char letter = getchar();
	//int res = atoi(&letter, 10);
	/*printf("%d + %d = %d.", res, 4, atoi(res + 4, 10)); 
	keyboardsetLEDs(true, true, true);
	terminal_putstring("End."); 
	*/
}; 



 




 