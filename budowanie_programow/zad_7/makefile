CFLAGS = -Wall -ansi

default: test
	rm -f *.o *~

main: main.o helpers.o
	cc -o main main.o helpers.o -lm

clean:
	rm -f *.o *~

test: clean main
	clear
	echo "-1 -2 0" > main_1.in
	echo "0" > main_2.in
	echo "2" > main_3.in
	echo "-1.02 1.0001" > main_4.in
	echo "256" > main_5.in
	echo "4.016" > main_6.in
	clear
	./main < main_1.in
	./main < main_2.in
	./main < main_3.in
	./main < main_4.in
	./main < main_5.in
	./main < main_6.in
	rm main_?.in
