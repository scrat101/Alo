#include "pic.h"
#include "idt.h" 
#include "ioport.h"
#include "NewGDT.h"
#include "keyboard.h"
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

typedef void (*interrupthandler)(void); 

interrupthandler referringinterrupthandlers[16] = {irq0interrupthandler, irq1interrupthandler, irq2interrupthandler, irq3interrupthandler, irq4interrupthandler irq5interrupthandler, irq6interrupthandler, irq7interrupthandler, irq8interrupthandler, irq9interrupthandler, irq10interrupthandler, irq11interrupthandler, irq12interrupthandler, irq13interrupthandler, irq14interrupthandler, irq15interrupthandler};

interrupthandler interrupthandlers[16] = {0, 0, keyboardhandler, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void generalinterrupthandler(void);

void interrupts_init(void); 