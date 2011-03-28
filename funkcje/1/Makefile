FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o -lm

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	echo "3.0 4.0" > 1.in
	echo "5.0 5.0" > 2.in
	echo "1.0 6.0" > 3.in
	echo "\n"
	./main < 1.in
	./main < 2.in
	./main < 3.in
