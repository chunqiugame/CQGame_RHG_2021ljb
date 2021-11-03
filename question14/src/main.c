#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "pwnInit.h"
#include "unit.h"

unsigned int i=0;
struct student
{
char *name;
void (*func)(char *name);
};
struct student* student1[0x10];
void shell(char command[]) {
    system(command);
}
void echo(char content[])
{
printf("%s",content);
}

void overflow_() {
	
	puts("0.new");
	puts("1.free");
	puts("2.show");
	int idx = read_int();
        switch (idx)
        {
        case 0: {
            size_t size = read_int();
            if (size > 0x100) {
                printf("too large\n");
                exit(-1);
            }

            struct student *n;
            n = malloc(sizeof(*n));
            n->func = echo;
            n->name = malloc(size);
            read(0, n->name, size+0x100);
            student1[i++] = n;
            break;
        }
        case 1: {
            int index = read_int();
            if (index > i || index < 0)
                exit(-1);
            free(student1[index]->name);
            free(student1[index]);
            break;
        }
        case 2: {
            int index = read_int();
            if (index > i || index < 0)
                exit(-1);
            struct student *n;
            n = student1[index];
            n->func(n->name);
            break;
        }
        
        default:
            exit(-1);
        }
		
    
}

int main() {
    PWNINIT

    while(1)
		
        overflow_();
}
