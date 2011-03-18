/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include"lib.h"

int main()
{
    pobierz_dane("Podaj dane a i b: a b ");
    oblicz_wynik();
    pokaz_wynik("ax=b => x= %lf\n");
    return 0;
}
