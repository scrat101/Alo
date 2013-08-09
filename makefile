all: x86 

x86: AloMain.o BasicIO.o bit.o ioport.o CoreFunctions.o StringNumberConversion.o gdtasm.o NewGDT.o idt.o idtload.o AloMain.o WillSetupForCCode.o referringinterrupthandlers.o interrupts.o keyboard.o
	../../bin/i386-elf-gcc -T LinkerScript.ld ObjectFiles/BasicIO.o ObjectFiles/bit.o ObjectFiles/ioport.o ObjectFiles/CoreFunctions.o ObjectFiles/StringNumberConversion.o ObjectFiles/gdtasm.o ObjectFiles/NewGDT.o ObjectFiles/idt.o ObjectFiles/idtload.o referringinterrupthandlers.o interrupts.o keyboard.o ObjectFiles/AloMain.o ObjectFiles/WillSetupForCCode.o -ffreestanding -O2 -nostdlib -lgcc -o BinFiles/AloImage8.bin  
	cp BinFiles/AloImage7.bin isodir/boot/AloImage.bin 
	grub-mkrescue isodir --output="Images/AloIsoImageIDTTest.iso"
	
AloMain.o: Startup/AloMain.c 
	../../bin/i386-elf-gcc -c Startup/AloMain.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/AloMain.o

bit.o: thesource/bit.c 
	../../bin/i386-elf-gcc -c thesource/bit.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/bit.o

ioport.o: thesource/ioport.c 
	../../bin/i386-elf-gcc -c thesource/ioport.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/ioport.o

CoreFunctions.o: thesource/CoreFunctions.c 
	../../bin/i386-elf-gcc -c thesource/CoreFunctions.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/CoreFunctions.o

StringNumberConversion.o: thesource/StringNumberConversion.c 
	../../bin/i386-elf-gcc -c thesource/StringNumberConversion.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/StringNumberConversion.o

BasicIO.o: thesource/BasicIO.c 
	../../bin/i386-elf-gcc -c thesource/BasicIO.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/BasicIO.o

GDT.o: thesource/GDT.c 
	../../bin/i386-elf-gcc -c thesource/GDT.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/GDT.o

WillSetupForCCode.o: Startup/WillSetupForCCode.asm
	../../bin/i386-elf-as Startup/WillSetupForCCode.asm -o ObjectFiles/WillSetupForCCode.o

gdtasm.o : thesource/gdtasm.asm 
	../../bin/i386-elf-as thesource/gdtasm.asm -o ObjectFiles/gdtasm.o
	
NewGDT.o: thesource/NewGDT.c 
	../../bin/i386-elf-gcc -c thesource/NewGDT.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/NewGDT.o

idt.o: thesource/idt.c 
	../../bin/i386-elf-gcc -c thesource/idt.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/idt.o

idtload.o: thesource/idtload.asm 
	../../bin/i386-elf-as thesource/idtload.asm -o ObjectFiles/idtload.o
	
referringinterrupthandlers.o: thesource/referringinterrupthandlers.asm 
	../../bin/i386-elf-as thesource/referringinterrupthandlers.asm -o ObjectFiles/referringinterrupthandlers.o

interrupts.o: thesource/interrupts.c 
	../../bin/i386-elf-gcc -c thesource/interrupts.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/interrupts.o
	
keyboard.o: thesource/keyboard.c 
	../../bin/i386-elf-gcc -c thesource/keyboard.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -o ObjectFiles/keyboard.o
