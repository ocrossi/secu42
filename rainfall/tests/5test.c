#include <stdio.h>
#include <stdlib.h>

void	o() {
	printf("we are in O!!\n");
	system("/bin/sh");
	exit(1);
}

void	n() {
	char s[512];

	fgets(s, 0x200, stdin);
	printf(s);
	exit(1);
}

int main() {
	n();
	return 0;
}
