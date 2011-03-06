CFLAGS = -Wall -ansi

default: clear test
	rm -f *.o *~ main

main: main.o lib.o
	cc -o main main.o lib.o

clear:
	clear

clean:
	rm -f *.o *~ *.swp main

test: clean main
	clear
	echo "1 10 2" > 1.in
	echo "2 4 0.5" > 2.in
	clear
	./main < 1.in
	./main < 2.in
	rm ?.in
