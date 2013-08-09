#include "ioport.h" 
#include <stdint.h> 

#define PIC1 0x20 
#define PIC2 0xA0 
#define PIC1_COMMANDPORT PIC1 
#define PIC1_DATAPORT (PIC1+1) 
#define PIC2_COMMANDPORT PIC2 
#define PIC2_COMMANDPORT (PIC2+1) 
#define PIC_EOI 0x20
#define MODE_8086 0x01 
#define PIC_READ_IRR 0x0A 
#define PIC_READ_ISR 0x0B

uint16_t pic_get_irq_reg(uint8_t combyte); 

uint16_t pic_get_isr(void); 

uint16_t pic_get_irr(void); 

void disable_pic(void); 

void pic_sendEOI(uint8_t interruptline); 

void pic_map(uint8_t offset); 

void Mask_Interrupt_Line(uint8_t line); 

void Demask_Interrupt_Line(uint8_t line); 

void pic_init(void);
