FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "123 0" > 1.in
	echo "123 44 2 1291 22 -1" > 2.in
	./main < 1.in
	./main < 2.in
