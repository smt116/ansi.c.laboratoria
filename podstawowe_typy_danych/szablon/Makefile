FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o main.c

main.o: main.c lib.o lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out main ~swp

