/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#define GODZINA 60

void pobierz_ilosc(int *ilosc, char *prompt) {
    printf(prompt);
    scanf("%i", ilosc);
}

void ile_jednostki(int ilosc, char znak, char *jednostka) {
    int ile;

    switch (znak) {
    case '/':
	ile = ilosc / GODZINA;
	break;
    case '%':
	ile = ilosc % GODZINA;
	break;
    default:
	ilosc = 0;
	break;
    }

    printf("%i%s ", ile, jednostka);
}
