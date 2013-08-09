.intel_syntax noprefix

.extern generalinterrupthandler
 
.global irq0interrupthandler
.type irq0interrupthandler, @function 
irq0interrupthandler: 
cli
pushad
push 0
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret


.global irq1interrupthandler
.type irq1interrupthandler, @function 
irq1interrupthandler: 
cli
pushad
push 1 
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret


.global irq2interrupthandler
.type irq2interrupthandler, @function 
irq2interrupthandler: 
cli
pushad
push 2 
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq3interrupthandler
.type irq3interrupthandler, @function 
irq3interrupthandler: 
cli
pushad
push 2 
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq4interrupthandler
.type irq4interrupthandler, @function 
irq4interrupthandler: 
cli
pushad
push 4
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret


.global irq5interrupthandler
.type irq5interrupthandler, @function 
irq5interrupthandler: 
cli
pushad
push 5
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq6interrupthandler
.type irq6interrupthandler, @function 
irq6interrupthandler: 
cli
pushad
push 6
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq7interrupthandler
.type irq7interrupthandler, @function 
irq7interrupthandler: 
cli
pushad
push 7 
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret


.global irq8interrupthandler
.type irq8interrupthandler, @function 
irq8interrupthandler: 
cli
pushad
push 8
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq9interrupthandler
.type irq9interrupthandler, @function 
irq9interrupthandler: 
cli
pushad
push 9
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq10interrupthandler
.type irq10interrupthandler, @function 
irq10interrupthandler: 
cli
pushad
push 10 
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret


.global irq11interrupthandler
.type irq11interrupthandler, @function 
irq11interrupthandler: 
cli
pushad
push 11
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq12interrupthandler
.type irq12interrupthandler, @function 
irq12interrupthandler: 
cli
pushad
push 12
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq13interrupthandler
.type irq13interrupthandler, @function 
irq13interrupthandler: 
cli
pushad
push 13
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret


.global irq14interrupthandler
.type irq14interrupthandler, @function 
irq14interrupthandler: 
cli
pushad
push 14
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

.global irq15interrupthandler
.type irq15interrupthandler, @function 
irq15interrupthandler: 
cli
pushad
push 15
call generalinterrupthandler 
add esp, 4
popad
sti
032 iret

