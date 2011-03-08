CFLAGS = -Wall -ansi

default: test
	rm -f *.o *~ main

main: main.o lib.o
	cc -o main main.o lib.o -lm

clean:
	rm -f *.o *~

test: clean main
	clear
	echo "-1" > 1.in
	echo "0" > 2.in
	echo "2" > 3.in
	echo "-1.02" > 4.in
	echo "256" > 5.in
	echo "4.016" > 6.in
	clear
	./main < 1.in
	./main < 2.in
	./main < 3.in
	./main < 4.in
	./main < 5.in
	./main < 6.in
	rm ?.in
