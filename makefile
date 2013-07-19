all: x86 

x86: AloMain.o BasicIO.o bit.o ioport.o CoreFunctions.o StringNumberConversion.o AloMain.o WillSetupForCCode.o
	../../bin/i386-elf-gcc -T LinkerScript.ld ObjectFiles/BasicIO.o ObjectFiles/bit.o ObjectFiles/ioport.o ObjectFiles/CoreFunctions.o ObjectFiles/StringNumberConversion.o ObjectFiles/AloMain.o ObjectFiles/WillSetupForCCode.o -ffreestanding -O2 -nostdlib -lgcc -o BinFiles/AloImage2.bin  
	cp BinFiles/AloImage2.bin isodir/boot/AloImage.bin 
	grub-mkrescue isodir --output="Images/AloIsoImage2.iso"
	
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

WillSetupForCCode.o: Startup/WillSetupForCCode.asm
	../../bin/i386-elf-as Startup/WillSetupForCCode.asm -o ObjectFiles/WillSetupForCCode.o