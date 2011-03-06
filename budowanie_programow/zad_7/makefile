CFLAGS = -Wall -ansi

default: test
	rm -f *.o *~ main

main: main.o lib.o
	cc -o main main.o lib.o -lm

clean:
	rm -f *.o *~

test: clean main
	clear
	echo "-1 -2 0 1" > 1.in
	echo "0 22" > 2.in
	echo "2" > 3.in
	echo "-1.02 1.0001" > 4.in
	echo "256" > 5.in
	echo "4.016" > 6.in
	clear
	./main < 1.in > test/1.out
	./main < 2.in > test/2.out
	./main < 3.in > test/3.out
	./main < 4.in > test/4.out
	./main < 5.in > test/5.out
	./main < 6.in > test/6.out
	rm ?.in
	clear
	diff test/1.out test/1.check
	diff test/2.out test/2.check
	diff test/3.out test/3.check
	diff test/4.out test/4.check
	diff test/5.out test/5.check
	diff test/6.out test/6.check
	rm test/*.out
