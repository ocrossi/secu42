#include <stdio.h>
#include <string.h>

void p() {
	int control;
	char *src;
	
	fflush(stdout);
	gets(&src);
	if ((control & 0xb0000000) == 0xb0000000) {
		printf("(%p)\n", control);
		exit(1);
	}
	puts(&src);
	strdup(&src);
	return;
}


void main() {
	p();
	return;
}
