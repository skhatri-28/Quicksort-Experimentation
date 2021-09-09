quicksort: main.c quicksort.c quicksort.h 
	gcc main.c quicksort.c quicksort.h -lm

a: quicksort
	./a.out sort -a
b: quicksort
	./a.out sort -b
c: quicksort
	./a.out sort -c
d: quicksort
	./a.out sort -d
ad: quicksort
	./a.out sort -ad
abd: quicksort 
	./a.out sort -abd
acd: quicksort
	./a.out sort -acd
abc: quicksort
	./a.out sort -abc
bcd: quicksort
	./a.out sort -bcd
all: quicksort
	./a.out sort -all

clean: 
	rm ./a.out
