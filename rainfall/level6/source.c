#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	n() {
	system("/bin/cat /home/user/level7/.pass");
	return; 
}

void	m() {
	puts("Nope\n");
	return;
}

void main(int ac, char **av) {
	char *s;
	void **p;

	s = malloc(0x40);
	p = (void **)malloc(4);
	*p[0] = m;
	s = strcpy(s, av[1]);
	(**p)();
	return;
}

