.intel_syntax noprefix

.global getESP
.type getESP, @function 
getESP: 
	mov eax, esp 
	ret 
