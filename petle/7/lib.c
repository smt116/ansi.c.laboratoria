/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
void wczytaj_wymiar(int *n, char *prompt)
{
    printf(prompt);
    scanf("%i", n);
}

void wczytaj_tablice(int n, double *tab, char *prompt)
{
    int i;

    for (i = 0; i < n; i++) {
	printf(prompt, i);
	scanf("%lf", &tab[i]);
    }
}

void ilosc_dodatnich(int n, double tab[n], int *dodatnie, char *prompt)
{
    int i;

    for (i = 0; i < n; i++) {
	if (tab[i] >= 0) *dodatnie++;
    }

    printf(prompt, *dodatnie);
}
