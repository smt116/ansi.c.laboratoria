FLAGS = -Wall -ansi

main: main.o lib.o
	cc -o main main.o lib.o

main.o: main.c lib.o lib.h

lib.o: lib.c

clean:
	rm -f *.o *swp *~ main *.in

test: main
	echo "65" > 1.in
	echo "88" > 2.in
	echo "123" > 3.in
	./main < 1.in
	./main < 2.in
	./main < 3.in
