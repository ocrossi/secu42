#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av) {
	char a = 1;
	char *b = malloc(8);
	long int *c = malloc(50);
	long double *d = malloc(8);
 
	printf("%lu\n", sizeof(a));
	printf("%lu\n", sizeof(b));
	printf("%lu\n", sizeof(c));
	printf("%lu\n", sizeof(d));

	return 0;
}
