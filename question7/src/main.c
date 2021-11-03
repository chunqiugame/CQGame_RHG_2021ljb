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
int check_passwd(char *passwd)
{
	unsigned char len; 
	char dest[0x10];
	len=strlen(passwd);
	if(len<=3 || len>8 )
	{
		printf("passwd error");
		return 0;
	}
	else
	{
		printf("nice");
		strcpy(dest,passwd);
	}
}
void login() {
    char user[0x60];
	char passwd[0x150];
	printf("please input your username\n");
	read(0,user,0x20);
	printf("please input your passwd\n");
	read(0,passwd,0x14f);
	return check_passwd(passwd);
}

int main() {
    PWNINIT

    while(1)
		
        login();
}
