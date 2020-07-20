all: gensort insertionSort insertionSortReverse linear_search

gensort: gensort.c
	gcc gensort.c -o gensort.exe

insertionSort: insertionSort.c
	gcc insertionSort.c -o insertionSort.exe

insertionSortReverse: insertionSortReverse.c
	gcc insertionSortReverse.c -o insertionSortReverse.exe

linear_search: linear_search.c
	gcc linear_search.c -o linear_search.exe

clean: 
	rm *.exe
