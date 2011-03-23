/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
    int n;
    char znak;

    wczytaj_dane(&n, &znak,
		 "Podaj wymiar i znak\nwymiar czyli ilosc w rzedzie i kolumnie\n> n znak ");
    wybor_wzoru(n, znak);

    return 0;
}
