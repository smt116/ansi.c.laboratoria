FLAGS = -Wall -ansi

default: main.o lib.o ascii.o
	cc -o main main.o lib.o ascii.o

main.o: main.c lib.h

lib.o: lib.c

ascii.o: ascii.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

