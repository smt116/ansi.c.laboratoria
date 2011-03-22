FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o main.c

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

