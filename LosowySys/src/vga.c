#include "../include/vga.h"

size_t termrow;
size_t termcolumn;
uint8_t termcolor;
uint16_t* termbuffer = (uint16_t*)VGAMEM;

uint8_t vga_entry_color(enum vgcolors fg, enum vgcolors backg) {
    return fg | (backg << 4);
}

uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t)uc | ((uint16_t)color << 8);   
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}




void terminit(void)
{
    termrow = 0;
    termcolumn = 0;
    termcolor = vga_entry_color(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
    for (size_t y = 0; y < VGAHEIGHT; y++) {
        for (size_t x = 0; x < VGAWIDTH; x++) {
            const size_t index = y * VGAWIDTH + x;
            termbuffer[index] = vga_entry(' ', termcolor);

        }
    }
}

void terminal_setcolor(uint8_t color) {
    termcolor = color;

}

// void writecolorful(unsigned char c, unsigned char fcolour, unsigned char bcolour, int x, int y) {
//     uint16_t attrib = (bcolour << 4) || (fcolour & 0x0F);
//    volatile uint16_t * where;
//    where = 
// }

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGAWIDTH + x;
    termbuffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
    terminal_putentryat(c, termcolor, termcolumn, termrow);
    if (++termcolumn == VGAWIDTH) {
        termcolumn = 0;
        if (++termrow == VGAHEIGHT)
        termrow = 0;
    }
}


void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++) 
        terminal_putchar(data[i]);
    
}

void terminal_writestring(const char* data) {
    terminal_write(data, strlen(data));
}

void changebg(enum vgcolors bg) {
    termcolor = vga_entry_color(VGA_COLOR_WHITE, bg);
    for (size_t y = 0; y < VGAHEIGHT; y++) {
        for (size_t x = 0; x < VGAWIDTH; x++) {
            terminal_putentryat(' ', termcolor, x, y);
        }
    }
}