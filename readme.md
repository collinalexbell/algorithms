# Algorithms
This is a monorepo containing my workthrough of the Introduction to Algorithms book excercises and main algorithms.

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
#                         data points (defaults to 100) 
#     max random val                                   |
#                   |                                  |
#  n data points    |                                  | 
#               |   |                                  |
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
I wrote real code.
[linear_search.c](./linear_search.c)

```C
int linear_search(int *A, int v, int len) {
  int i;
  for(i = 0; i < len; i++) {
    if(A[i] == v) {
      return i;
    }
  }
  return -1;
}
```

## 2.1-4

### Question
Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n+1)-element array C. State the problem formally and write pseudocode for adding the two integers.

### Answer

__Input:__ 2 _n_ bit arrays A = {a1, a2,...., an}, B = {b1, b2,....,bn}

__Output:__ An _n+1_ bit array C = {c1, c2,...., c(n+1)} that represents the sum of A & B


```C
void binary_addition(int *a, int *b, int *c, int len) {
        int i, sum, carry;
        carry = 0;
        for(i = len-1; i >= 0; i--) {
                sum = a[i] + b[i] + carry;
                c[i] = sum % 2;
                carry = sum / 2;
        }
}
```

# 2.2

## 2.2-1

### Question
Express the function `n^3/1000 - 100n^2 - 100n + 3` in terms of Θ-notation

### Answer
Θ(n^3)

## 2.2-2

### Question
Consider sorting n numbers stored in array A by first finding the smallest element of A and exchanging it with the element in A[1]. The find the second smallest element of A, and exchange it with A[2]. Continue in this manner for the first n-1 elements of A. Write (pseudo) code for this algorithim, wich is known as __selection sort__. What loop invariant does this algorithm maintain? Why does it need to run for only the first n-1 elements rather than for all n elements? Give the best-case and worst-case running times of selection sort in Θ-notation.

### Answer
```C
void selection_sort(int *keys, int len) {
  int i, j, min, tmp;
  for(i = 0; i < len-1; i++){
    min = i;

    // Find smallest
    for(j = i; j < len; j++) {
      if(keys[j] < keys[min]) {
        min = j;
      }
    }

    // Swap
    tmp = keys[i];
    keys[i] = keys[min];
    keys[min] = tmp;
  }
}
```

The loop invariant for the first loop is that keys[0:i] are sorted and are all less than any key in keys[i:len].

The loop invariant for the second loop is that min is the index of the smallest key in keys[i:j]. 

The second part of the first loop invariant ensures that all keys[0:len-1] are less than the last key and therefore all keys are sorted.

The best case and worst case are Θ(n^2). Even in the best case, the algorithm doesn't know that `i == min` ahead of time, so the second loop will still run an average of n/2-1 times.

## 2.2-3

### Question
Consider linear search again. How many elements of the input sequence need to be checked on the average, assuming that the element being searched for is equally likely to be any element in the array? How about in the worst case? What are the average-case and worst-case running times of linear search in Θ-notation? Justify your answers

### Answer

On average, n/2 items needed to be checked in linear search. This is because each item has a 1/n chance of the item. By the first n/2th item, there will be a 50% chance the item will have been found and the probability distribution is symetrical about the n/2 mark. Therefore, n/2 items will be checked on average.

Worst case senario, the item is not in the array and therefore n items will have to be considered to know that is the case. 

Θ(n) for both worst and average case because the `1/2` coefficient is dropped in Θ-notation
