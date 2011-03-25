FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "4 0 -1 2.312 2" > 1.in
	echo "2 -1 1" > 2.in
	echo "\n"
	./main < 1.in
	./main < 2.in
