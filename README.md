# LosowySYS
This a small "microkernel" that is written in C and Assembly, its more a proof of concept
***UEFI IS NOT SUPPORTED***

# Features
Clear the screen (in Red Green and Blue in a loop after some time)
Print ASCII onto the screen using VGA in the 0xB8000 Memory adress
Run bare metal on i386 (tested)
Run on QEMU (Tested)
Run on VirtualBox (Tested - Without UEFI)
Boots using GRUB

# How to run
1. Download the latest ISO file from releases and flash it to a CD Drive or a USB stick
2. Enter to the boot menu ***Make sure you're NOT using UEFI***
3. Enter LosowySYS in GRUB
4. You're now in LosowySYS

# VBox recommended settings
64MB RAM
any i386 CPU
Disabled UEFI

# Note
Some parts include the code from OSDev's wiki Bare Bones tutorial, mainly the assembly file
Please note that this is my first ever bootable custom written "OS" so it has tutorial parts
