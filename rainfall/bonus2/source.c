#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int language = 0;

//lang set to en_US.UTF-8
//can set input to nl or fi if we change env variable LANG
void greetuser(lang) {
	char *s;
	
 	if (language == 1)	
 	if (language == 2)
	else
 	strcat(s, lang);
	puts(s);
	return;	 
}

void main(int ac, char **av) {
	void *p;
	char *tlang;
	int res;

	if (ac < 2)
		return ;
	memset(p ,0, 0x19);
	strncpy(p, av[1], 0x28);
	strncpy((((char *)p) + 40), av[1], 0x20);
	tlang = gentenv("LANG");
	if (tlang ==  NULL)
		return;
	res = memcmp(tlang, "fi", 2);
	if (res == 0) {
		language = 1;
	}
	else {
		res = memcmp(tlang, "nl", 2);
		if (res == 0) {
			language = 2;
		}
	}
	memcpy(p, tlang, 0x13);
	greetuser(tlang);
	return;
}
