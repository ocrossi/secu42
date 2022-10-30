#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av) {
	int res;
	char *cpy;

	res = atoi(av[1])
	if (res > 9)
		return 1;
	memcpy(cpy, av[2], res*4);
	if (res == 0x574f4c46)
		execl("/bin/sh", 0x8048580, 0);
	return 0;
}
