#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"
struct note {
    size_t size;
    void (*print)(char *buffer);
    char buffer[0];
};

struct note* note[0x10];
unsigned int i=0;

void shell() {
	printf("hhhh you must do it %c",note[2]->buffer[0]);
	if(note[2]->buffer[0]=='C')
	{
		system("/bin/sh");
	}
}

void work() {
    int idx = read_int();

    while(idx >= 0) {
        switch (idx)
        {
        case 0: {
            size_t size = read_int();
            if (size > 0x100) {
                printf("too large\n");
                exit(-1);
            }

            struct note *n;
            n = malloc(sizeof(*n) + size);
            n->size = size;
            n->print = puts;
            read(0, n->buffer, size+1);
            note[i++] = n;
            break;
        }
        case 1: {
            int index = read_int();
            if (index > i || index < 0 || !note[index])
                exit(-1);
            free(note[index]);
            note[index] = NULL;
            break;
        }
        case 2: {
            int index = read_int();
            if (index > i || index < 0 || !note[index])
                exit(-1);
            struct note *n;
            n = note[index];
            n->print(n->buffer);
            break;
        }
        default:
            exit(-1);
        }
        idx = read_int();
    }
}

int main() {
    PWNINIT
    work();
}
