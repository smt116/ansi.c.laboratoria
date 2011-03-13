CFLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.o lib.h

lib.o: lib.c

clean:
	rm -f *.o *.in *.out *~ *swp main
