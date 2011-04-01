/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
	char liczba[100];
	unsigned dlugosc;

	pobierz_liczbe(liczba, &dlugosc, "Podaj liczbe: ");
    drukuj_liczbe_od_tyly(&dlugosc, liczba, "Liczba odtylu:\n");

    return 0;
}
