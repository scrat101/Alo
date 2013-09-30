.intel_syntax noprefix
#This assembly code has the header that lets GRUB recognize us as a kernel, sets up a stack, calls alomain, and if it returns, goes in an infinite loop. 

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
    
	#This creates a stack
    stack_bottom: 
    .skip 16384 
    stack_top: 
    
	.section .data 
		Endmessage:	
			.asciz "End of OS execution; going to infinite loop." 
	#Entry point for the operating system  
    .section .text 
	.global _start 
	.type _start, @function
    
    _start: 
	
    	
    	mov esp, stack_top  #Esp is used by C as a pointer to the stack, so when our C code is called, the stack will be operational. 
		push ebx
		push eax
    	call alostart 
		pop eax 
		pop ebx 
    	push [Endmessage] 
		call printf 
    	cli 
    	
    	hang: 
    		hlt 
			jmp hang 
		.size _start, . - _start
