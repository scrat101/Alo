#ifndef ioport
#define ioport
#include <stdint.h> 

inline void outb(uint16_t port, uint8_t theval); 

inline uint8_t inb(uint16_t port); 

inline void io_wait(void); 

#endif