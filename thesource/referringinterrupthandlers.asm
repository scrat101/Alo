.intel_syntax noprefix

.extern generalinterrupthandler


.macro InterruptMainStub interruptnum
	push 0
	pushad
	push gs
	push fs
	push es
	push ds 
	push \interruptnum
	mov ax, 0x10 
	mov gs, ax 
	mov fs, ax 
	mov es, ax 
	mov ds, ax
	call generalinterrupthandler 
	pop eax 
	pop ds 
	pop es 
	pop fs 
	pop gs 
	popad 
	add esp, 4
.endm	

.global irq0interrupthandler
.type irq0interrupthandler, @function
irq0interrupthandler:
 	/*xchg bx, bx*/ 
	cli
	InterruptMainStub 0
	sti
	iret 

.global irq1interrupthandler
.type irq1interrupthandler, @function
irq1interrupthandler:
 	/*xchg bx, bx*/ 
	cli
	push 0
	InterruptMainStub 1

.global irq2interrupthandler
.type irq2interrupthandler, @function
irq2interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 2

.global irq3interrupthandler
.type irq3interrupthandler, @function
irq3interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 3

.global irq4interrupthandler
.type irq4interrupthandler, @function
irq4interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 4

.global irq5interrupthandler
.type irq5interrupthandler, @function
irq5interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 5

.global irq6interrupthandler
.type irq6interrupthandler, @function
irq6interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 6

.global irq7interrupthandler
.type irq7interrupthandler, @function
irq7interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 7

.global irq8interrupthandler
.type irq8interrupthandler, @function
irq8interrupthandler:
 	/*xchg bx, bx*/
    cli 
	InterruptMainStub 8

.global irq9interrupthandler
.type irq9interrupthandler, @function
irq9interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 9

.global irq10interrupthandler
.type irq10interrupthandler, @function
irq10interrupthandler:
 	/*xchg bx, bx*/
    cli 
	InterruptMainStub 10

.global irq11interrupthandler
.type irq11interrupthandler, @function
irq11interrupthandler:
 	/*xchg bx, bx*/
    cli 
	InterruptMainStub 11

.global irq12interrupthandler
.type irq12interrupthandler, @function
irq12interrupthandler:
 	/*xchg bx, bx*/
    cli 
	InterruptMainStub 12

.global irq13interrupthandler
.type irq13interrupthandler, @function
irq13interrupthandler:
 	/*xchg bx, bx*/
    cli 
	InterruptMainStub 13

.global irq14interrupthandler
.type irq14interrupthandler, @function
irq14interrupthandler:
 	/*xchg bx, bx*/
    cli 
	InterruptMainStub 14

.global irq15interrupthandler
.type irq15interrupthandler, @function
irq15interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 15

.global irq16interrupthandler
.type irq16interrupthandler, @function
irq16interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 16

.global irq17interrupthandler
.type irq17interrupthandler, @function
irq17interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 17

.global irq18interrupthandler
.type irq18interrupthandler, @function
irq18interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 18

.global irq19interrupthandler
.type irq19interrupthandler, @function
irq19interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 19

.global irq20interrupthandler
.type irq20interrupthandler, @function
irq20interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 20

.global irq21interrupthandler
.type irq21interrupthandler, @function
irq21interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 21

.global irq22interrupthandler
.type irq22interrupthandler, @function
irq22interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 22

.global irq23interrupthandler
.type irq23interrupthandler, @function
irq23interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 23

.global irq24interrupthandler
.type irq24interrupthandler, @function
irq24interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 24

.global irq25interrupthandler
.type irq25interrupthandler, @function
irq25interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 25

.global irq26interrupthandler
.type irq26interrupthandler, @function
irq26interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 26

.global irq27interrupthandler
.type irq27interrupthandler, @function
irq27interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 27

.global irq28interrupthandler
.type irq28interrupthandler, @function
irq28interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 28

.global irq29interrupthandler
.type irq29interrupthandler, @function
irq29interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 29

.global irq30interrupthandler
.type irq30interrupthandler, @function
irq30interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 30

.global irq31interrupthandler
.type irq31interrupthandler, @function
irq31interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 31

.global irq32interrupthandler
.type irq32interrupthandler, @function
irq32interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 32

.global irq33interrupthandler
.type irq33interrupthandler, @function
irq33interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 33

.global irq34interrupthandler
.type irq34interrupthandler, @function
irq34interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 34

.global irq35interrupthandler
.type irq35interrupthandler, @function
irq35interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 35

.global irq36interrupthandler
.type irq36interrupthandler, @function
irq36interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 36

.global irq37interrupthandler
.type irq37interrupthandler, @function
irq37interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 37

.global irq38interrupthandler
.type irq38interrupthandler, @function
irq38interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 38

.global irq39interrupthandler
.type irq39interrupthandler, @function
irq39interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 39

.global irq40interrupthandler
.type irq40interrupthandler, @function
irq40interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 40

.global irq41interrupthandler
.type irq41interrupthandler, @function
irq41interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 41

.global irq42interrupthandler
.type irq42interrupthandler, @function
irq42interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 42

.global irq43interrupthandler
.type irq43interrupthandler, @function
irq43interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 43

.global irq44interrupthandler
.type irq44interrupthandler, @function
irq44interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 44

.global irq45interrupthandler
.type irq45interrupthandler, @function
irq45interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 45

.global irq46interrupthandler
.type irq46interrupthandler, @function
irq46interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 46

.global irq47interrupthandler
.type irq47interrupthandler, @function
irq47interrupthandler:
 	/*xchg bx, bx*/
    cli 
	push 0
	InterruptMainStub 47
	
