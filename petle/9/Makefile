FLAGS = -Wall -ansi

default: main.o file.o lib.o
	cc -o main main.o file.o lib.o

main.o: main.c lib.h

file.o: file.c

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	./main test
