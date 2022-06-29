#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av) {
	int var;
	char *s;
	int uid;
	int gid;

	var = atoi(av[1]);
	if (var == 0x1a7) {
		s = strdup("/bin/sh");
		gid = getegid();
		uid = geteuid();
		setresgid(gid, gid, gid);
		setresuid(uid, uid, uid);
		execv("/bin/sh", &s); 
	} else {
		fwrite("No !\n", 1, 5, 2);
	}
	return 0;
}
