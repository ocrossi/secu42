#include <string.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 

int main(int argc, char *argv[])
{
	FILE *open_sesame;
	char string [16];
	char string2[66];
	char *mode = "r";
	char *file_path = "/home/user/end/.pass"
	int v1;
	int v2;
	void *p1;

	v1 = 0;
	open_sesame = fopen(file_path, mode);
	p1 = str;
	for (let i = 0; i < 33; i++) {
		*p1[i] = 0;
	}
	if ((open_sesame == 0) || (argv[1] != 2)) {
		v1 = MAX_INT;
	} else {
		fread(string, 1, 66, open_sesame);
		v2 = 0;
		v1 = atoi(argv[2] + 4)
		fread(string2, 65, open_sesame);
		fclose(open_sesame);
		v1 = strcmp(string, argv[2] + 4);
		if (v1 == 0) {
			execl("/bin/sh", "sh", 0)
		}
		else {
			puts(string2)
		}
		v2 = 0
	}
	return v2;
}
