all: merge_sort binary_addition gensort insertion_sort insertion_sort_reverse linear_search selection_sort

gensort: gensort.c
	gcc gensort.c -o gensort.exe

insertion_sort: insertion_sort.c
	gcc insertion_sort.c -o insertion_sort.exe

insertion_sort_reverse: insertion_sort_reverse.c
	gcc insertion_sort_reverse.c -o insertion_sort_reverse.exe

linear_search: linear_search.c
	gcc linear_search.c -o linear_search.exe

binary_addition: linear_search.c
	gcc binary_addition.c -o binary_addition.exe

selection_sort: selection_sort.c
	gcc selection_sort.c -o selection_sort.exe

merge_sort: merge_sort.c
	gcc merge_sort.c -o merge_sort.exe

clean: 
	rm *.exe
