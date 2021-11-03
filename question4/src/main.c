#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"
#include <ctype.h>

char buffer[0x100] = {};

int main() {
    PWNINIT
    read_n(buffer, 0x100);
    for (int i=0; i<0x100; i++) {
        if (buffer[i] && !isprint(buffer[i]) && buffer[i] != 0xa) {
            printf("bad value at %d: %c\n", i, buffer[i]);
            exit(-1);
        }
    }
	printf("I get your new shellcode");
	void (*func)(void);
    func = buffer;
    func();
}