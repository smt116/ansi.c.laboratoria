CFLAGS = -Wall -ansi

main: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.h lib.o

lib.o: lib.c

clean:
	rm -f *.o *~ main *.in

test: clean main
	echo "1 2 3" > main_1.in
	echo "-1 2 3" > main_2.in
	echo "0 1 2" > main_3.in
	echo "1.01 111 -900" > main_4.in
	echo "1.01 1.0045 -1.002" > main_5.in
	./main < main_1.in
	./main < main_2.in
	./main < main_3.in
	./main < main_4.in
	./main < main_5.in
