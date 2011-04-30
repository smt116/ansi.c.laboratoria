FLAGS = -Wall 
STD = -std=c99

MAIN = main
LIB = lib
TITLE = zlicz_krawedzie
FILES = enwords_ansi.dat plwords_ansi.dat plwords_utf.dat main.c lib.c lib.h Makefile README

default: obj compile clean

compile:
	cc $(STD) -o $(TITLE) $(MAIN).o $(LIB).o

obj:
	cc $(STD) -c *.c

$(MAIN).o: $(MAIN).c $(LIB).h

$(LIB).o: $(LIB).c $(LIB).h

tar: veryclean
	mkdir $(TITLE)/
	cp $(FILES) $(TITLE)/.
	tar -zcf $(TITLE).tar.gz $(TITLE)/
	rm -rf $(TITLE)/

clean:
	rm -f *~ *.o *swp .*swp

veryclean: clean
	rm -rf $(TITLE) $(TITLE).tar.gz *.in *.out

test: default clean
	@ echo "\n.:: ZLICZANIE KRAWEDZI ::."
	@ echo "\nAngielskie slowa (ANSI): "
	@ ./$(TITLE) enwords_ansi.dat
	@ echo "\n\nPolskie slowa (ANSI): "
	@ ./$(TITLE) plwords_ansi.dat
	@ echo "\n\nPolskie slowa (UTF-8): "
	@ ./$(TITLE) plwords_utf.dat
