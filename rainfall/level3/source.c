#include <stdio.h>
#include <stdlib.h>

int g_m;

void	v() {
	char 	*str;

	fgets(&str, 0x200, stdin);
	printf(&str);
	if (g_m == 0x40) {
		fwrite("Wait what?!\n", 1, 0xc, stdout);
        	system("/bin/sh");
	}
	return;
}

void main() {
	v();
	return;
}
