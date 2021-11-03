#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "unit.h"

int read_n(char *buffer, int buf_size) {
    int i, result;
    for (i = 0; i < buf_size - 1; i++) {
        result = (int) read(STDIN_FILENO, buffer + i, 1);
        if (result != 1) {
            exit(1);
        } else if (buffer[i] == '\n') {
            break;
        }
    }
    buffer[i] = 0;
    return i;
}

int read_size(char *buffer, unsigned int buf_size){
    unsigned int size = 0;
    read(STDIN_FILENO, &size, 4);
    if(size > buf_size) {
        puts("input size is too long");
        exit(1);
    }
    return (int) read(STDIN_FILENO, buffer, size);

}

int read_int(){
    char buffer[32];
    read_n(buffer, 32);
    return atoi(buffer);
}
