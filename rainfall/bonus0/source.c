#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

// void p(char *var, char *print) {
// 	char *read;
// 	char *index;
//
// 	index = 0;
// 	puts(print);
// 	read(0, 0x1000, read);
// 	index = strchr(read, '\n');
// 	read = index;
// 	strncpy(var, read, 20);
// 	return;
// }
//
// void pp(char *s) {
// 	char *var1;
// 	char *var2;
// 	int len;
//
// 	p(var1, '-');
// 	p(var2, '-');
// 	strcpy(s, var1);
// 	len = strlen(s);
// 	strcat(s, var2);
// 	return;
// }
//
void p(void *ptr, char *text) {
	char *str;

	puts(text);
	read(0, str, 4096);
	strchr(str, '\n') = 0;
	strncpy(ptr ,str, 20);
	return;
}

void pp(char *s) {
	char p1[20];
	char p2[20];

	p(p1, " - ");
	p(p2, " - ");
	strcpy(s, p1);
	char space = " ";
	int len = strlen(s);
	strcat(s, p2);
	return
}

int main(int ac, char **av) {
	char *s;

	pp(s);
	puts(s);
	return 0;
}
