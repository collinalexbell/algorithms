all: gensort insertionSort insertionSortReverse

gensort: gensort.c
	gcc gensort.c -o gensort.exe

insertionSort: insertionSort.c
	gcc insertionSort.c -o insertionSort.exe

insertionSortReverse: insertionSortReverse.c
	gcc insertionSortReverse.c -o insertionSortReverse.exe

clean: 
	rm *.exe
