#include <stdio.h>

__attribute__ ((constructor)) void test() {
	printf("salut\n");
}

void test1() {
	printf("salut\n");
}

int main() {
	printf("salut1");
	//test();
}
