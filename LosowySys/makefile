vga:
	i686-elf-gcc -c src/vga.c  -o vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
sleep:
	i686-elf-gcc -c src/sleep.c  -o sleep.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
kernel:
	i686-elf-gcc -c src/kernel.c  -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
assembly:
	i686-elf-as src/bootstrap.s -o boot.o
link:
	i686-elf-gcc -T src/linker.ld -o losowysys.bin -ffreestanding -O2 -nostdlib boot.o kernel.o vga.o sleep.o

clean:
	rm -rf *.o *.bin


all:
	make vga && make sleep && make kernel && make assembly && make link