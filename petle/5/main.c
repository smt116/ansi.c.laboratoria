/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    int n;

    wczytaj_wymiar(&n, "Podaj wymiar tablicy, n= ");
    double tab[n];

    wczytaj_tablice(n, tab, "\nPodaj %i element tablicy. ");
    wypisz_tablice(n, tab, "\ntab[%i] = %lf");
    printf("\n");

    return 0;
}
