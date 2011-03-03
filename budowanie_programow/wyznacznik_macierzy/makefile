CFLAGS = -Wall -ansi

default: clean main test
	rm -f *.o *~

main: main.o wczytaj_macierz.o wyznacznik.o
	cc -o main main.c wczytaj_macierz.o wyznacznik.o

test:
	echo "2 2 5 4 1" > a.in
	./main < a.in
	rm *.in

clean:
	rm -f *.o main *~
