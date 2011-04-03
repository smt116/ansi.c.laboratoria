/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#define WYPISZ(ile, odmiana) printf("%i %s ", ile, odmiana);

void pobierz_ilosc(int *ilosc, char *prompt) {
    printf(prompt);
    scanf("%i", ilosc);
}

void ile_jednostki(int ilosc, char znak,
		   char *odm_pojedyncza, char *odm_mnoga) {
    int ile;

    switch (znak) {
    case '/':
	ile = ilosc / 7;
	break;
    case '%':
	ile = ilosc % 7;
	break;
    default:
	ilosc = 0;
	break;
    }

    switch (ilosc) {
    case 1:
	WYPISZ(ile, odm_pojedyncza);
	break;
    default:
	WYPISZ(ile, odm_mnoga);
	break;
    }
}
