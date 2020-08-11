#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run(int n) {
	time_t times [4];
	char gensort_cmd [256];
	int len;
	
	sprintf(gensort_cmd, "./gensort.exe %d 1000", n);
	FILE* gensort = popen(gensort_cmd, "r");

	int* A = (int*) malloc(sizeof(int) * n);

	len = 0;
	while(len < n && fscanf(gensort, "%d", &A[len]) != EOF) {
		len++;
	}
	wait(NULL);

	// This is garbage, I can just use popen and wait()
	/*
	times[0] = time(NULL);
	pid_t proc = fork();
	if(proc == 0) {
		// run max subarray using pipe and sh
		printf("in a seperate process\n");
		exit(0);
	} else {
		wait(NULL);
	}
	times[1] = time(NULL);

	times[2] = time(NULL);
 	proc = fork();
	if(proc == 0) {
		printf("in a seperate process\n");
		exit(0);
	} else {
		wait(NULL);
	}
	times[3] = time(NULL);
	*/


	printf("recursive: %ld, brute_force: %ld\n\n", times[3]-times[2], times[1]-times[0]);
}

int main() {
	for(int n = 10000; n < 1000000; n = n*2) {
		run(n);
	}
}
