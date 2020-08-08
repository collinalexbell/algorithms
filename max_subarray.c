#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

struct SubArray {
	int start;
	int end;
	int sum;
}

struct SubArray cross_max_subarray(int *A, int start, int mid, int end) {
	int right_max, left_max, right_sum, left_sum, sum, i;
	left_sum = right_sum = INT_MIN;
	left_max = mid;
	right_max = mid + 1;

	left_sum = 0;
	sum = 0;
	for(i = left_max; i >= start; i--) {
		sum = sum + A[i];
		if(sum > left_sum) {
			left_sum = sum;
			left_max = i;
		}
	}

	right_sum = 0;
	sum = 0;
	for(i = right_max; i < end; i++) {
		sum = sum + A[i];
		if(sum > right_sum) {
			right_sum = sum;
			right_max = i+1;
		} 
	}

	return struct SubArray{left_max, right_max, left_sum + right_sum};
}

struct SubArray max_subarray(int *A, int start, int end) {
	int mid;
	struct SubArray left, right, cross;
	if(end-start == 1) {
		return SubArray{start, end, A[start]};
	}

	mid = (end-start)/2
	left = max_subarray(A, start, mid);
	right = max_subarray(A, mid, end);
	cross = cross_max_subarray(A, start, mid, end);

	if(left.sum >= right.sum && left.sum >= cross.sum) return left;
	if(right.sum >= left.sum && right.sum >= cross.sum) return right;
	return cross;
	
}

int main(int argc, char** argv) {
	int i, v, len;

	struct SubArray result;

	int A[10000];

	v = atoi(argv[1]);

	len = 0;
	while(len < 10000 && scanf("%d", &A[len]) != EOF) {
		len++;
	}


	for(i = 0; i < len; i++) {
		printf("%d, ", A[i]);
	}
	printf("\n");


	result = max_subarray(A, 0, len);

	printf("\n\nresult: A[%d:%d] == %d\n", result.start, result.end, result.sum);
}


