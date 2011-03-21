FLAGS = -Wall -ansi

default: input.c output.c
	cc -c input.c
	cc -c output.c

input.o: input.c

output.o: output.c

clean:
	rm -f *~

cleano:
	rm -f *.o

indent:
	indent -kr *.c
