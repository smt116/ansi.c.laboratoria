FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "2 0" > 1.in
	echo "60 0" > 2.in
	echo "12399 234 11 23 0" > 3.in
	./main < 1.in
	./main < 2.in
	./main < 3.in
