#include <stdint.h>
#include "../include/sleep.h"

#define loops 10000000

void sleep(uint32_t milisecs) {
    for (volatile uint32_t x = 0; x < milisecs * loops; x++) {

    }

}