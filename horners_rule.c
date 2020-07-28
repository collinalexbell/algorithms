#include <stdio.h>
#include <stdlib.h>

int horners_rule(int *a, int x, int k, int len) {
	if(k < len) {
		return a[k] + x * horners_rule(a, x, k+1, len);	
	} 
	return 0;
}

int main(int argc, char** argv) {
	int i, x, len, result;

	int a[100];

	if(argc < 2) {
		printf("usage: ./horners_rule.exe <x>");
		exit(1);
	}

	x = atoi(argv[1]);

	len = 0;
	while(len < 100 && scanf("%d", &a[len]) != EOF) {
		len++;
	}


	for(i = 0; i < len; i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");


	result = horners_rule(a, x, 0, len);

	printf("\n\nresult: y=%d\n", result);
}


