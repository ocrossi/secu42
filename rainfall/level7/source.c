#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c;

void m() {
	time_t res = time(0);
	printf("%s - %d\n", c, res);
}


int main(int ac, char *av[]) {
	void *tab1;
	void *tab2;
	void *file;

	tab1 = malloc(8);
	tab1[0] = 1;
	tab1[1] = malloc(8);
	tab2 = malloc(8);
	tab2[0] = 2;
	tab2[1] = malloc(8);

	strcpy(tab1[1], av[1]);
	strcpy(tab2[1], av[2]);
	file = fopen("/home/user/level8/.pass", "r");
	fgets(file, 0x44, c);
	puts("~~");
	return 0;
}
