FLAGS = -Wall -ansi

default: main.o lib.o ../libs/input.o
	cc -o main main.o lib.o ../libs/input.o

main.o: main.c lib.o ../libs/input.o lib.h

lib.o: lib.c

clean:
	rm -f *~ main *.in *.out *swp *.o
