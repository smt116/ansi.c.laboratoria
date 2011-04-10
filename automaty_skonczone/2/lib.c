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
	    case '/': usun_komentarze(&znak); break;
	    case '\'': ignoruj_przedzial(&znak, '\''); break;
	    case '\"': ignoruj_przedzial(&znak, '\"'); break;
	    default: putchar(znak); break;
	}

	znak = getchar();
    }
}

void usun_komentarze(char *znak) {
    char znak1, znak2;
    znak1 = *znak;
    znak2 = getchar();

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

void ignoruj_przedzial(char *znak, char przedzial) {
    char znak1, znak2;
    znak1 = *znak;
    znak2 = getchar();

    while(!(znak1!='\\' && znak2==przedzial)) {
	putchar(znak1);
	znak1 = znak2;
	znak2 = getchar();
    }
    putchar(znak1);
    putchar(znak2);
}
