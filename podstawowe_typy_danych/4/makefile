CFLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.o lib.h

lib.o: lib.c

clean:
	rm -f *.o *.in *.out *~ *swp main

test: main
	echo "14-03-2011" >1.in
	echo "10-10-1999" >2.in
	./main <1.in
	./main <2.in
