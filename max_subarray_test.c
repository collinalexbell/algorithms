#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void run(int n) {
	time_t times [4];
	char brute_force [256];
	char recursive [256];

 	sprintf(brute_force, "./gensort.exe %d 1000 | ./max_subarray_brute_force.exe", n);
 	sprintf(recursive, "./gensort.exe %d 1000 | ./max_subarray.exe", n);

	times[0] = time(NULL);
	system(brute_force);
	times[1] = time(NULL);

	times[2] = time(NULL);
	system(recursive);
	times[3] = time(NULL);

	printf("recursive: %ld, brute_force: %ld\n", times[3]-times[2], times[1]-times[0]);
}

int main() {
	for(int n = 1000; n < 10000000; n = n*10) {
		run(n);
	}
}
