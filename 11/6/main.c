/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
    int n;

    wczytaj_wymiar(&n, "Podaj wymiar tablicy, n= ");
    double tab[n];
    wczytaj_tablice(n, tab, "\nPodaj %i element tablicy. ");
    minimum(n, tab, "Najmniejszy element tablicy to %lf\n");
    maksimum(n, tab, "Najwiekszy element tablicy to %lf\n");
    return 0;
}
