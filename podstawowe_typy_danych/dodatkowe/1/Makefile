FLAGS = -Wall -ansi

default: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h

lib.o: lib.c

clean:
	rm -f *~ *.in *.out main ~swp *.o

test: main
	echo "4 2" > 1.in
	echo "0.1 45" > 2.in
	echo "91 9.1231" > 3.in
	./main <1.in>1.out
	./main <2.in>2.out
	./main <3.in>3.out
	cat 1.out
	cat 2.out
	cat 3.out
