#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"


int main() {
    PWNINIT

    char *buffer = malloc(0x30);
    read_n(buffer, 0x30);
	int choice=atol(buffer+0x10);
    switch(choice){
		case 1:
		printf("where is shell");
		break;
		case 2:
		read_n(buffer, 0x30);
		break;
		case 3:
		return 0;
		break;
		case 156322:
		system("/bin/sh");
		break;
	}

    return 1;
}
