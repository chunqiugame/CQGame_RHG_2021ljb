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
	printf("please input what you want say");
    read(0, buffer, 0x80);
    printf(buffer);
}

int main() {
    PWNINIT

    while(1)
		
        overflow_();
}
