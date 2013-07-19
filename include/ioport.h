#include <stdint.h> 

static inline void outb(uint8_t port, uint8_t theval); 

static inline uint8_t inb(uint8_t port); 

static inline void io_wait(void); 
