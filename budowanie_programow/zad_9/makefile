CFLAGS = -Wall -ansi

main: main.o lib.o
	cc -o main main.o lib.o -lm

main.o: main.c lib.o lib.h

lib.o: lib.c

clean:
	rm -f *.o *~ *.swp main *.in

test: clean main
	echo "1 10 2" > 1.in
	echo "2 4 0.5" > 2.in
	./main < 1.in
	./main < 2.in
