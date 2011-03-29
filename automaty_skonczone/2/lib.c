/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include "lib.h"

void pobieranie_tekstu(char *prompt) {
    printf(prompt);

    char znak;
    znak = getchar();

    while (znak != EOF) {
	switch(znak) {
	    case '/': usun_komentarz(&znak); break;
	    case '"': ignoruj_cudzyslow(&znak); break;
	    default: putchar(znak); break;
	}

	znak = getchar();
    }
}

void usun_komentarz(char *znak) {
    char znak1, znak2;
    znak1 = *znak;
    znak2 = getchar();

    /* wlasciwie tutaj ladniej wygladalaby
     * instrukcja case of... potem to zamienie */
    if (znak1 == '/' && znak2 == '/') {
	while (znak2 != '\n') {
	    znak2 = getchar();
	}
    } else {
	if (znak2 == '*') {
	    while (!(znak1 == '*' && znak2 == '/')) {
		znak1 = znak2;
		znak2 = getchar();
	    }
	} else {
	    putchar(znak1);
	}
    }
}

void ignoruj_cudzyslow(char *znak) {
    char znak1, znak2;
    znak1 = *znak;
    znak2 = getchar();

    while(!(znak1!='\\' && znak2=='"')) {
	putchar(znak1);
	znak1 = znak2;
	znak2 = getchar();
    }
    putchar(znak1);
    putchar(znak2);
}
