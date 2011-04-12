FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "-10 10" > 1.in
	echo "0 0" > 2.in
	echo "1 2" > 3.in
	echo "4 1" > 4.in
	echo "\n"
	./main < 1.in
	./main < 2.in
	./main < 3.in
	./main < 4.in
