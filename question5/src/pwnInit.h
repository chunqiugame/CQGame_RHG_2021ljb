#ifndef PROJECT_PWNINIT_H
#define PROJECT_PWNINIT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "unit.h"

void init() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    alarm(300);
}


#define PWNINIT init();

#endif //PROJECT_PWNINIT_H
