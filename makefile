CC = gcc -g
all: merge_sort binary_addition gensort insertion_sort insertion_sort_reverse linear_search selection_sort

gensort: gensort.c
	$(CC) gensort.c -o gensort.exe

insertion_sort: insertion_sort.c
	$(CC) insertion_sort.c -o insertion_sort.exe

insertion_sort_reverse: insertion_sort_reverse.c
	$(CC) insertion_sort_reverse.c -o insertion_sort_reverse.exe

linear_search: linear_search.c
	$(CC) linear_search.c -o linear_search.exe

binary_addition: linear_search.c
	$(CC) binary_addition.c -o binary_addition.exe

selection_sort: selection_sort.c
	$(CC) selection_sort.c -o selection_sort.exe

merge_sort: merge_sort.c
	$(CC) merge_sort.c -o merge_sort.exe

clean: 
	rm *.exe
