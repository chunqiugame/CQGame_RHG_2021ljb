#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"
void shell1() {
    printf("this is no shell");
}
void shell2() {
    system("ls");
}

void shell() {
    system("/bin/sh");
}

void overflow_() {
    char buffer[0x60];
	printf("this is no gift\n");
	printf("please input what you want say\n");
    read(0, buffer, 0x6d);
}

int main() {
    PWNINIT

    while(1)
		
        overflow_();
}
