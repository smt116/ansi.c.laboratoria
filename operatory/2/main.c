/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
	int ilosc;

	do {
		pobierz_ilosc(&ilosc, "Podaj ilosc dni: ");
		if(!(ilosc>0)) break;

		ile_jednostki(ilosc, '/', "tydzien", "tygodni");
		ile_jednostki(ilosc, '%', "dzien", "dni");
		putchar('\n');
	} while(ilosc>0);

    return 0;
}
