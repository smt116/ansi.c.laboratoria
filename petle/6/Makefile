FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "4 1 9 0.1112 -3.12" > 1.in
	echo "5 0 1 2 0 1" > 2.in
	echo "3 -1 0 3" > 3.in
	echo "\n"
	./main < 1.in
	./main < 2.in
	./main < 3.in
