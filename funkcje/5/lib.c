/*
 * Maciej Małecki
 * smt116@gmail.com
 */

#include "lib.h"

void wczytaj_wymiary(unsigned *x, unsigned *y, char *prompt)
{
    printf(prompt);
    scanf("%u %u", x, y);
}

void rysuj_prostokat(unsigned x, unsigned y)
{
    unsigned wysokosc, szerokosc;

    for (wysokosc = 1; wysokosc <= y; wysokosc++) {
	for (szerokosc = 1; szerokosc <= x; szerokosc++) {
	    if (szerokosc % x < 2 || wysokosc % y < 2) {
		putchar('*');
	    } else {
		putchar(' ');
	    }
	}
	putchar('\n');
    }
}

void rysuj_owal(unsigned x, unsigned y)
{
    unsigned wysokosc, szerokosc;

    for (wysokosc = 1; wysokosc <= y; wysokosc++) {
	for (szerokosc = 1; szerokosc <= x; szerokosc++) {
	}
	putchar('\n');
    }
}


void rysuj_strzalke(unsigned x, unsigned y);
void rysuj_diament(unsigned x, unsigned y);
