#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[]) {
	void *tab1;
	void *tab2;

	tab1 = malloc(8);
	tab1[0] = 1;
	tab1[1] = malloc(8);
	tab2 = malloc(8);

	strcpy(*tab1, 

	return 0;
}
