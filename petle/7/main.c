/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    int n, dodatnie = 0;

    wczytaj_wymiar(&n, "Podaj wymiar tablicy, n= ");
    double tab[n];

    wczytaj_tablice(n, tab, "\nPodaj %i element tablicy. ");
    ilosc_dodatnich(n, tab, &dodatnie, 
		    "Ilosc dodatnich elementow tablicy wynosi %i\n");
    
    return 0;
}
