CFLAGS = -Wall -ansi

default: clear test
	rm -f *.o *~

main: main.o lib.o
	cc -o main main.o lib.o

clear:
	clear

clean:
	rm -f *.o *~ main

test: clean main
	clear
	echo "1 2 3" > main_1.in
	echo "-1 2 3" > main_2.in
	echo "0 1 2" > main_3.in
	echo "1.01 111 -900" > main_4.in
	echo "1.01 1.0045 -1.002" > main_5.in
	clear
	./main < main_1.in
	./main < main_2.in
	./main < main_3.in
	./main < main_4.in
	./main < main_5.in
	rm main_?.in
