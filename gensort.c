#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
	int i, n, r;
	r = 10000;
	if(argc > 1) n = atoi(argv[1]);
	else exit(0);

	if(argc > 2) r = atoi(argv[2]);

	for(i = 0; i < n; i++) {
		printf("%d ", rand() % r);
	}
}
