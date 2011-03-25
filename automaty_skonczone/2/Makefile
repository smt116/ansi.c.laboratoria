FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out *.o main ~swp

test: main
	./main < test/1.in > test/1.out
	./main < test/2.in > test/2.out
	echo "\n"
	cat test/1.out
	echo "\n"
	cat test/2.out
