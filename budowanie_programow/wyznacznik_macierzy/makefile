CFLAGS = -Wall

full: testowy test

testowy: main.o wczytaj_macierz.o wyznacznik.o
	cc -o testowy main.c wczytaj_macierz.o wyznacznik.o

main.o: main.c definicje.h

test:
	echo "2 2 5 4 1" > a.in
	./testowy < a.in
	rm a.in

clean:
	rm -f *.o testowy *~
