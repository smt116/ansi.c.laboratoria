/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
	unsigned x, y;

	wczytaj_wymiary(&x, &y, "Podaj wymiary. x y = ");
	
	rysuj_prostokat(x, y);
	rysuj_owal(x, y);

    return 0;
}
