#ifndef interrupts
#define interrupts
#include "pic.h"
#include "idt.h" 
#include "ioport.h"
#include "NewGDT.h"
#include "keyboard.h"
#include "CoreFunctions.h"
#include <stdint.h>


void irq0interrupthandler(void);

void irq1interrupthandler(void);

void irq2interrupthandler(void);

void irq3interrupthandler(void);

void irq4interrupthandler(void);

void irq5interrupthandler(void);

void irq6interrupthandler(void);

void irq7interrupthandler(void);

void irq8interrupthandler(void);

void irq9interrupthandler(void);

void irq10interrupthandler(void);

void irq11interrupthandler(void);

void irq12interrupthandler(void);

void irq13interrupthandler(void);

void irq14interrupthandler(void);

void irq15interrupthandler(void);

void irq16interrupthandler(void);

void irq17interrupthandler(void);

void irq18interrupthandler(void);

void irq19interrupthandler(void);

void irq20interrupthandler(void);

void irq21interrupthandler(void);

void irq22interrupthandler(void);

void irq23interrupthandler(void);

void irq24interrupthandler(void);

void irq25interrupthandler(void);

void irq26interrupthandler(void);

void irq27interrupthandler(void);

void irq28interrupthandler(void);

void irq29interrupthandler(void);

void irq30interrupthandler(void);

void irq31interrupthandler(void);

void irq32interrupthandler(void);

void irq33interrupthandler(void);

void irq34interrupthandler(void);

void irq35interrupthandler(void);

void irq36interrupthandler(void);

void irq37interrupthandler(void);

void irq38interrupthandler(void);

void irq39interrupthandler(void);

void irq40interrupthandler(void);

void irq41interrupthandler(void);

void irq42interrupthandler(void);

void irq43interrupthandler(void);

void irq44interrupthandler(void);

void irq45interrupthandler(void);

void irq46interrupthandler(void);

void irq47interrupthandler(void);


typedef void (*interrupthandler)(void); 

typedef struct InterruptData { 
	uint32_t interruptnumber;
	uint32_t gs; 
	uint32_t fs; 
	uint32_t es; 
	uint32_t ds; 
	uint32_t edi; 
	uint32_t esi;  
	uint32_t ebp2; 
	uint32_t esp; 
	uint32_t ebp; 
	uint32_t ebx; 
	uint32_t edx; 
	uint32_t ecx; 
	uint32_t eax;
    uint32_t eip, cs, eflags, useresp, ss;  
	uint32_t errorcode;
} InterruptData;

static interrupthandler referringinterrupthandlers[] = {irq0interrupthandler, irq1interrupthandler, irq2interrupthandler, irq3interrupthandler, irq4interrupthandler, irq5interrupthandler, irq6interrupthandler, irq7interrupthandler, irq8interrupthandler, irq9interrupthandler, irq10interrupthandler, irq11interrupthandler, irq12interrupthandler, irq13interrupthandler, irq14interrupthandler, irq15interrupthandler, irq16interrupthandler, irq17interrupthandler, irq18interrupthandler, irq19interrupthandler, irq20interrupthandler, irq21interrupthandler, irq22interrupthandler, irq23interrupthandler, irq24interrupthandler, irq25interrupthandler, irq26interrupthandler, irq27interrupthandler, irq28interrupthandler, irq29interrupthandler, irq30interrupthandler, irq31interrupthandler, irq32interrupthandler, irq33interrupthandler, irq34interrupthandler, irq35interrupthandler, irq36interrupthandler, irq37interrupthandler, irq38interrupthandler, irq39interrupthandler, irq40interrupthandler, irq41interrupthandler, irq42interrupthandler, irq43interrupthandler, irq44interrupthandler, irq45interrupthandler, irq46interrupthandler, irq47interrupthandler};

static interrupthandler interrupthandlers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 


void UnassignInterruptToRoutine(uint8_t interrupt);

void AssignInterruptToRoutine(uint8_t interrupt, interrupthandler handler);

void generalinterrupthandler(InterruptData data);

void interrupts_init(void); 
#endif