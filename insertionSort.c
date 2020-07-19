#include <stdio.h>

void sort(int *keys, int len) {
	int i, j, val;
	for (i = 1; i < len; i++) {
		val = keys[i];
		for (j = i-1; j >= 0 && val < keys[j]; j--) {
			keys[j+1] = keys[j];
		}
		keys[j+1] = val;
	}
}

int main() {
	int i, len;
	int keys[100];

	for(i = 0; i < 100; i++) {
		if(scanf("%d", &keys[i]) == EOF) break;
	}
	len = i;
	printf("\n");

	sort(keys, len);
	for(i = 0; i < len; i++) {
		printf("%d, ", keys[i]);
	}
	printf("\n");
}
