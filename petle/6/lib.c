/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>

void wczytaj_wymiar(int *n, char *prompt) {
    printf(prompt);
    scanf("%i", n);
}

void wczytaj_tablice(int n, double *tab, char *prompt) {
    int i;

    for (i = 0; i < n; i++) {
	printf(prompt, i);
	scanf("%lf", &tab[i]);
    }
}

void minimum(int n, double tab[n], char *prompt) {
    int min = 0, i;

    for (i = 0; i < n; i++) {
	if (tab[i] < tab[min])
	    min = i;
    }
    printf(prompt, tab[min]);
}

void maksimum(int n, double tab[n], char *prompt) {
    int max = 0, i;

    for (i = 0; i < n; i++) {
	if (tab[i] > tab[max])
	    max = i;
    }
    printf(prompt, tab[max]);
}
