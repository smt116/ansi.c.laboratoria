/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    int ilosc;

    do {
	pobierz_ilosc(&ilosc, "Podaj ilosc minut: ");
	if (!(ilosc > 0))
	    break;

	ile_jednostki(ilosc, '/', "h");
	ile_jednostki(ilosc, '%', "m");
	putchar('\n');
    } while (ilosc > 0);

    return 0;
}
