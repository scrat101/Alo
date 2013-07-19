    .set ALIGN, 1<<0 
    .set MEMINFO, 1<<1 
    .set FLAGS, ALIGN | MEMINFO
    .set MAGIC, 0x1BADB002 # This magic number will let GRUB ID us as a multiboot kernel.  
    .set CHECKSUM, -(MAGIC + FLAGS) 
    
    .section .multiboot 
    .align 4	
    .long MAGIC 
    .long FLAGS 
    .long CHECKSUM 
    
    .section .bootstrap_stack 
    
    stack_bottom: 
    .skip 16384 
    stack_top: 
    
    .section .text 
	.global _start 
	.type _start, @function
    
    _start: 
    	
    	movl $stack_top, %esp 
    	
    	call alostart 
    	
    	cli 
    	
    	hang: 
    		hlt 
			jmp hang 
    	.size _start, . - _start