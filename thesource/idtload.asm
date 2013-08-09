.intel_syntax noprefix

.extern theidtptr
.global idt_reload 
.type idt_reload, @function
idt_reload: 
	lidt [theidtptr] 
	ret
	