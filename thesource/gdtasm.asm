.intel_syntax noprefix


.global RefreshGDT 	 
.type RefreshGDT, @function 
.extern thegdtptr
RefreshGDT: 
	lgdt [thegdtptr]
	mov ax, 0x10 
	mov ds, ax
	mov es, ax 
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:finish
	finish:
		ret 
		
