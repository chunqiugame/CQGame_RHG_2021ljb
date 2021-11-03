#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"

void shell() {
    system("/bin/sh");
}

void overflow_() {
    char buffer[0x60];
	printf("this is your gift %p\n",&overflow_);
	printf("please input what you want say\n");
    read(0, buffer, 0x70);
}

int main() {
    PWNINIT

    while(1)
		
        overflow_();
}
