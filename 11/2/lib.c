/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>

void wczytaj_dane(char *prompt, int *x, int *y, char *znak)
{
    printf(prompt);
    scanf("%i %i %c", x, y, znak);
}

void drukuj_szachownice(int x, int y, char znak)
{
    unsigned i, k;

    for (i = 1; i <= y; i++) {
	if (!(i % 2))
	    printf(" ");

	for (k = 1; k <= x; k++) {
	    printf("%c ", znak);
	}
	printf("\n");
    }
}
