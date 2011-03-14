FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.o lib.h

lib.o: lib.c

clean:
	rm -f *.o *.in *.out *swp *~ main

test: main
	echo "190 cm" > 1.in
	echo "74.8 in" > 2.in
	./main < 1.in > 1.out
	./main < 2.in > 2.out
	cat 1.out
	cat 2.out
