#include <stdio.h>
#include <string.h>


int main(int ac, char **av) {
	int fd;
	char buff[100];
	int i = 0;
	int len = strlen(av[1]);


	while (i < len) {
		buff[i] = av[1][i] - i;
		i++;
	}
	buff[i] = '\0';
	printf("[%s]\n", buff);
	return 0;
}
