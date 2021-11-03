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

void fmt() {
    char buffer[0x100];
	puts("fmt is so fun\n");
    read(0, buffer, 0x100);
	printf(buffer);
}

int main() {
    PWNINIT

    while(1)
		
        fmt();
}
