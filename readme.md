# Algorithms
This is a monorepo containing my workthrough of the Introduction to Algorithms book excersizes and main algorithms.

## Caveats
- All algorithms and exercises are written in C. There is no psuedo-code here.
- The makefile generates `.exe` file extensions because they are easier to track in `.gitignore`.

## How to run
```bash
# generate all the implemetation exe's
make
```

Sorting algorithms require data to be passed in via stdin. The `gensort.exe` program can be used to generate random data to sort. 

```bash
#                           data points (defaults to 100) 
#     max random val                                     |
#                   |                                    |
#  n data points    |                                    | 
#               |   |                                    |
./gensort.exe   50  100  |        ./insertionSort.exe  50
```

# 2.1

## 2.1-1

### Question
Using Figure 2.2 as a model, illustrate the operation of INSERTION-SORT on the array A = {31, 41, 59, 26, 41, 58}

### Answer
```
{31, 41*, 59, 26, 41, 58}

{31, 41, 59*, 26, 41, 58}

{31, 41, 59, 26*, 41, 58}
 ||  ||  ||  ||
 | --^ --^ --^|
 ^------------

{26, 31, 41, 59, 41*, 58}
             ||  ||
	     | --^|
	     ^----

{26, 31, 41, 41, 59, 58*}
                 ||  ||
		 | --^|
		 ^----

{26, 31, 41, 41, 58, 59}
```

## 2.1-2

### Question
Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of non-decreasing order

### Answer
[insertionSortReverse.c](../implementations/insertionSortReverse.c)
```
7c7
<     for (j = i-1; j >= 0 && val < keys[j]; j--) {
---
>     for (j = i-1; j >= 0 && val > keys[j]; j--) {
```

## 2.1-3

### Question
Consider the searching problem:

__Input:__ A sequence of _n_ numbers _A = {a1, a2,...., an}_ and a value _v_

__Output:__ An index _i_ such that _v = A[i]_ or the special value `NIL` if _v_ does not appear in _A_

Write pseudocode for __linear search__, wich scans through the sequence, looking for _v_. Using a loop invariant, prove that your algorithm is correct. Make sure that your loop invariant fulfills the three necessary properties.


### Answer
```
FIND(A, v)
	for(i = 0 until A.length)
		if(A[i] == v) 
			return v
	return NIL
```

## 2.1-4

### Question
Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n+1)-element array C. State the problem formally and write pseudocode for adding the two integers.

### Answer

__Input:__ 2 _n_ bit arrays A = {a1, a2,...., an}, B = {b1, b2,....,bn}

__Output:__ An _n+1_ bit array C = {c1, c2,...., c(n+1)} that represents the sum of A & B


```
SUM_BITS(A, B)
	C = Array[A.length + 1]
	carry = 0
	for i = 0 until A.length
		C[i] = (A[i] + B[i] + carry) % 2
		carry = (A[i] + B[i] + carry) / 2
	return C
```

