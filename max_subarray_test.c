#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run(int n) {
	struct timeval times[4];
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
	pclose(gensort);

	gettimeofday(&times[0], NULL);
	FILE* brute_force_f = popen("./max_subarray_brute_force.exe", "w");
	for(int i = 0; i < n; i++) {
		fprintf(brute_force_f, "%d ", A[i]);
	}
	fprintf(brute_force_f, "\n");
	pclose(brute_force_f);
	wait(NULL);
	gettimeofday(&times[1], NULL);


	gettimeofday(&times[2], NULL);
	FILE* recursive_f = popen("./max_subarray.exe", "w");
	for(int i = 0; i < n; i++) {
		fprintf(recursive_f, "%d ", A[i]);
	}
	fprintf(recursive_f, "\n");
	pclose(recursive_f);
	wait(NULL);
	gettimeofday(&times[3], NULL);



	long int millis[4];
	for(int i = 0; i < 4; i++) {
		millis[i] = times[i].tv_sec * 1000000 + times[i].tv_usec;
	}
	printf("brute_force time: %ld\n", millis[1]-millis[0]);
	printf("recursive time: %ld\n", millis[3]-millis[2]);
	free(A);
}

int main() {
	for(int n = 10; n < 1000; n++) {
		run(n);
	}
}
