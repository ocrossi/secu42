#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *auth;
void *service;
// void *reset;
// void *login;
//

int main(void) {
	char buffer[128];

	while (1) {
		printf("%p, %p \n", auth, service);	
		if (fgets(buff, 128, STDIN) == 0)
			return (0);

		if (strncmp("auth ", buffer, 5) == 0) {
			auth = malloc(4);
			auth[0] = 0;
			if (strlen(buffer) >= 30) {
				strcpy(auth, buffer + 5);
			}
		}
		if (strncmp("reset", buffer, 5)) {
			free(auth);
		}
		if (strncmp("service", buffer, 6)) {
			service = strdup(auth + 7);
		}
		if (strncmp("login", buffer, 5)) {
			if (auth + 32 != 0) {
				system("/bin/sh");
			}
			else {
				fwrite("Password:\n", 10, 1, stdout);
			}
		}
	}			
	return (0);
}
