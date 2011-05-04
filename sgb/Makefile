DATADIR = .
INCLUDEDIR = .
LIBDIR = .
BINDIR = .
CWEBINPUTS = .

SYS = -DSYSV
CFLAGS = -g -I$(INCLUDEDIR) $(SYS)
STD = -std=c99
LDFLAGS = -L. -L$(LIBDIR)
LDLIBS = -lgb
LOADLIBES = $(LDLIBS)
##########
PL = polish_ladders
OBJS = gb_flip.o gb_sort.o gb_dijk.o gb_graph.o gb_words.o gb_io.o
##########

default: pl

lib: libgb.a

libgb.a: $(OBJS)
	ar rcv libgb.a $(OBJS)
	- ranlib libgb.a

gb:
	@ echo "-----------------"
	@ echo "\n---GB_GRAPH---\n"
	$(CC) $(STD) -c gb_graph.c
	@ echo "\n---GB_SORT---\n"
	$(CC) $(STD) -c gb_sort.c
	@ echo "\n---GB_DIJK---\n"
	$(CC) $(STD) -c gb_dijk.c
	@ echo "\n---GB_WORDS---\n"
	$(CC) $(STD) -c gb_words.c
	@ echo "\n---GB_FLIP---\n"
	$(CC) $(STD) -c gb_flip.c
	@ echo "\n---GB_PLIO---\n"
	$(CC) $(STD) -c gb_io.c
	@ echo "-----------------\n"
	rm *.a -rf
	make lib
	@ echo "-----------------\n"

pl: gb 
	@ echo ".:: POLISH LADDERS ::."
	$(CC) $(CFLAGS) $(STD) $(LDFLAGS) $(PL).c $(LDLIBS) -o $(PL)

test:
	@ echo ".:: TEST ::."
	@ echo "żyzny\ndurny\nkulać\nkonno" > test.in
	@ echo
	./$(PL) < test.in
	rm -rf test.in
	make clean

tar: veryclean
	rm -rf plSGB.tar.gz
	tar -zcf plSGB.tar.gz *

clean:
	rm -rf *~ *swp .*swp *.a *.o

veryclean: clean
	rm -rf *.in *.out $(PL)
