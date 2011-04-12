/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    int a, b;

    wczytaj_dane(&a, &b, "Podaj przedzial, a b = ");
    liczby_w_przedziale(a, b, "Liczby w przedziale ( %i , %i ) to: \n",
		"W przedziale ( %i , %i ) nie ma liczb calkowitych\n",
		"%i > %i, do dzialania a musi byc mniejsze niz b\n");

    return 0;
}
