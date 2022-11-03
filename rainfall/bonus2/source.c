#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int language = 0;

void greetuser() {
	
}

void main(int ac, char **av) {
	void *p;
	char *tlang;
	int res;

	if (ac < 2)
		return ;
	memset(p ,0, 0x19);
	strncpy(p, av[1], 0x28);
	strncpy((((char *)p) + 40), av[1], 0x20);
	tlang = gentenv("LANG");
	if (tlang ==  NULL)
		return;
	res = memcmp(tlang, "fi", 2);
	if (res == 0)
		language = 1;
	else {
		res = memcmp(tlang, "nl", 2);
		if (res == 0)
			language = 2;
	}
	memcpy(p, "en_US.UTF-8", 0x13);
	greetuser();
	return;
}
