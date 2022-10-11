#include <stdio.h>

int g_m;

void p(char *s) {
	printf(&s);
	return;
}

void n() {
	char *s;

	fgets(&s, 0x200, stdin);
	p(s);
	if (g_m == 0x1025544) {
       		system("/bin/cat /home/user/level5/.pass");
	}
	return;
}

void main() {
	n();
	return;
}
