/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include "lib.h"

/* funkcja wczytuje wymiar i znak
 * (wieksza uniwersalnosc) */
void wczytaj_dane(int *x, char *znak, char *prompt) {
    printf(prompt);
    scanf("%i %c", x, znak);
}

/* wybor_wzoru wywoluje odpowiednia funkcje do rysowania */
void wybor_wzoru(int x, char znak) {
    int i;

    for (i = 1; i <= 4; i++) {
	switch (i) {
	    case 1: wzor_1(x, znak); break;
    	    case 2: wzor_2(x, znak); break;
            case 3: wzor_3(x, znak); break;
	    case 4: wzor_4(x, znak); break;
	}
    }
}

/* funkcje rysujace */
void wzor_1(int x, char znak) {
    int i, k;
    for (i = 1; i <= x; i++) {
	k = i;
	while (k--) {
	    putchar(znak);
	}
	printf("\n");
    }
}
void wzor_2(int x, char znak) {
    int i, k;
    for (i = x; i >= 1; i--) {
	k = i;
	while (k--) {
	    putchar(znak);
	}
	printf("\n");
    }
}
void wzor_3(int x, char znak) {
    int i, k;
    for (i = x; i >= 1; i--) {
	k = 0;
	while (k < x - i) {
	    putchar(' ');
	    k++;
	}
	k = i;
	while (k--) {
	    putchar(znak);
	}
	printf("\n");
    }
}
void wzor_4(int x, char znak) {
    int i, k;
    for (i = 1; i <= x; i++) {
	k = x - i;
	while (k--) {
	    putchar(' ');
	}
	k = i;
	while (k--) {
	    putchar(znak);
	}
	printf("\n");
    }
}
