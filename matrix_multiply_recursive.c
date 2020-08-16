#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000000

int** create_array(int n) {
    int* values = calloc(n*n, sizeof(int));
    int** rows = malloc(n*sizeof(int*));
    for (int i=0; i<n; ++i)
    {
        rows[i] = values + i*n;
    }
    return rows;
}

void destroy_array(int** arr)
{
    free(*arr);
    free(arr);
}

struct Point {
	int row;
	int col;
};

int** matrix_multiply(int** A, int** B, struct Point startA, struct Point startB, int n) {
	int** C = create_array(n);
	if(n == 1) {
		C[0][0] = A[startA.row][startA.col] * B[startB.row][startB.col];
		return C;
	}

	return C;
}

int main(int argc, char** argv) {
	int i, j, n;
	int eof;

	if(argc < 2) {
		fprintf(stderr, "usage: ./matrix_multiply_naive.exe <n>\n");
		exit(1);
	}

	n = atoi(argv[1]);	
	if(n < 0 || n > MAX_N) {
		fprintf(stderr,"invalid n:%d for (n x n)	 matrix", n);
	}

	int** A = create_array(n);
	struct Point startA = {0,0};
	struct Point startB = {0,0};
	int** B = create_array(n);
	int** C;


	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			eof = scanf("%d", &B[i][j]);
		}
	}

	if(eof == EOF) {
		fprintf(stderr, "not enough data provided to stdin\n");
		exit(1);
	}


	C = matrix_multiply(A, B, startA, startB, n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}
