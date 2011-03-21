/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

/* POBIERADNIE LICZB */
int pobierz_calkowita(char *prompt)
{
    int liczba;
    printf(prompt);
    scanf("%i", &liczba);
    return liczba;
}

double pobierz_rzeczywista(char *prompt)
{
    double liczba;
    printf(prompt);
    scanf("%lf", &liczba);
    return liczba;
}

/* POBIERANIE BITOW */

unsigned czytajBity(char *prompt)
{
    unsigned liczba = 0;
    short bit;

    printf(prompt);

    while ((bit = getchar()) != EOF && bit != '\n') {
	switch (bit) {
	case '0':
	    break;
	case '1':
	    liczba << 1;
	    break;
	default:
	    printf("ERROR\n");
	    break;
	}
    }

    return liczba;
}
