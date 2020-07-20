all: binary_addition gensort insertionSort insertionSortReverse linear_search

gensort: gensort.c
	gcc gensort.c -o gensort.exe

insertionSort: insertionSort.c
	gcc insertionSort.c -o insertionSort.exe

insertionSortReverse: insertionSortReverse.c
	gcc insertionSortReverse.c -o insertionSortReverse.exe

linear_search: linear_search.c
	gcc linear_search.c -o linear_search.exe

binary_addition: linear_search.c
	gcc binary_addition.c -o binary_addition.exe

clean: 
	rm *.exe
