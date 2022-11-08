#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *auth;
void *service;

int main(void) {
	char *var;
	int *res;

	while (1) {
		service = NULL;
		auth = NULL;
		printf("%p, %p \n", auth, service);	
		res = fgets(var, 0x80, stdin);
		if (res == 0)
			return (0);
		if ()
		malloc(4);
	}			
	return (0);
}
