#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"
char black[] = "BINSHbinsha";

void run_shellcode() {
    void (*func)(void);
    char buffer[0x50] = {};
    read_n(buffer, 0x50);
    for (int i=0; i<strlen(black); i++) {
        if(strchr(buffer, black[i]) != NULL) {
            exit(0);
        }
    }
	printf("I get your shellcode");
    func = buffer;
    func();
}

int main() {
    PWNINIT
    run_shellcode();   
}