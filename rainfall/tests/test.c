#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int myprint(int Narg, ...) {
	int i;
	va_list ap;

	va_start(ap, Narg);

	//printf("allo %d", Narg);

	for (i = 0; i<Narg; i++) {
		printf("en int %d\n", va_arg(ap, int));
		printf("en float %f\n", va_arg(ap, double));

	}
	va_end(ap);
	return 0;
}

void	test_vul() {
	char input[10];
	int var = 0x11223344;

	printf("target addr is %x\n", (unsigned)&var);
	printf("val at target addr is 0x%x\n", var);
	
	printf("please enter a string :");
	fgets(input, sizeof(input) - 1, stdin);

	printf(input);
	
	printf("data at the address targeted 0x%x\n", var);

}

int main(int ac, char **av) {
	int m = 123;

	//printf("%x%n\n", 0x10000, &m);
	//printf("%d\n", m);
	

	//myprint(1, 2, 3.5);
	//myprint(2, 2, 3.5, 3, 4.5);

	test_vul();
/*
	char input[100];

	fgets(input, sizeof(input) - 1, stdin);

	printf(input);
*/
	return 0;
}
