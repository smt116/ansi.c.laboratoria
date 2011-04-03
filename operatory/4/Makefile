FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "2 6" > 1.in
	echo "-100 100" > 2.in
	echo "10 100000" > 3.in
	./main < 1.in
	./main < 2.in
	./main < 3.in
