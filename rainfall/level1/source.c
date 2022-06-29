#include <stdio.h>

void run(void) {
	fwrite("Good... Wait what?\n", 1, 0x13, _stdout);
	system("/bin/sh");
	return;
}

void main(void) {
	char input[76];
	
	gets(input);
	return ;
}
