/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include"lib.h"

int main()
{
    pobierz_dane("Podaj dane: a b ");
    oblicz_wynik();
    pokaz_wynik("%lf * x = %lf => x= %lf\n",
		"Nie mozna dzielic przez zero!\n");
    return 0;
}
