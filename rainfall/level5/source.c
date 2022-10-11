#include <stdio.h>
#include <stdlib.h>

void	o() {
	system("/bin/sh");
	exit(1);
}

void	n() {
	char s[512];

	fgets(&s, 0x200, stdin);
	printf(s);
	exit(1);
}

void main() {
	n();
	return;
}
