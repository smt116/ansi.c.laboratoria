CFLAGS = -Wall -ansi

main: main.o lib.o
	cc -o main main.o lib.o -lm

main.o:	main.c lib.o lib.h

lib.o: lib.c 

clean:
	rm -f *.o *.in *~ main
test:
	echo "-1" > 1.in
	echo "0" > 2.in
	echo "2" > 3.in
	echo "-1.02" > 4.in
	echo "256" > 5.in
	echo "4.016" > 6.in
	./main < 1.in
	./main < 2.in
	./main < 3.in
	./main < 4.in
	./main < 5.in
	./main < 6.in
